/*
 * Useful things for this project
 * function atoi(argument) will take a string and turn it into an integer. This is helpful for taking arguments passed to main
 * libraries sys/types.h sys/stat.h unistd.h will allow us to create a struct using the stat from sys. Which can give us information regarding a file which we use to print out the files size in bytes
 * */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
 #include <math.h>

#define ENCODE 1
#define DECODE 0
#ifndef MODE
	#define MODE ENCODE
#endif

int DEBUG = 0;
static int arraySize = 4;
static int bufferSize = 16;
struct stat filestats;

int pad_buffer(char* buffer, unsigned int bufsize, unsigned int rbuf_index);
int unpad_buffer(char* buffer, unsigned int bufsize);
void transpose_buffer(char* buffer, char* outputBuffer, unsigned int dim);
int dump_buffer(char *buffer, unsigned int bufsize, unsigned int bytes, FILE *output_path);
void columnar_cypher(char *buffer, char *rbuffer);
void viginere_cypher(char *buffer, char *rbuffer, char *key, int keyLength);


int main(int argc, char *argv[]){
	if(argc < 5){
		printf("Missing arguments");
		return 1;
	}
	int rounds = atoi(argv[1]);
	char *key = argv[2];
	char *input = argv[3];
	char *output = argv[4];
	if(argc == 6){
		printf("The number of rounds to do '%d' \n", atoi(argv[1]));
		printf("The key file '%s'", argv[2]);
		printf("The input file '%s' \n", argv[3]);
		printf("The output file '%s' \n", argv[4]);
		printf("Debug allowed '%d' \n", atoi(argv[5]));
		DEBUG = 1;
	}
	FILE *KEY;
	if ((KEY = fopen(key, "r")) == NULL){
		printf("Problem opening key file '%s', errno: '%d'\n", key, errno);
		return 1;
	}

	FILE *INPUT;
	if ((INPUT = fopen(input, "r")) == NULL){
		printf("Problem opening input file '%s', errno: '%d'\n", input, errno);
		return 1;
	}

	FILE *OUTPUT;
	if((OUTPUT = fopen(output, "a")) == NULL){ //Using the argument "a" will allow us to append to the file rather than just write one section
		printf("Problem opening output file '%s', errno: '%d'\n", output, errno);
		return 1;
	}

	int err;
	if ((err = stat(input, &filestats)) < 0) {
		   printf("error statting file! Error: %d\n", err);
	}

	if(DEBUG){
		printf("Size of input is: %lld bytes\n", filestats.st_size);
	}

	int symbol; //Character being read in
	char keyArray[128];
	int keyLength = 0; //Keylength monitored for looping;

	while((symbol = fgetc(KEY)) != EOF && keyLength < 128){  //reads in the key
		keyArray[keyLength] = symbol;
		keyLength ++;
	}

	char buffer[bufferSize];    //This will be the buffer used to create the string with padding etc....
	char rBuffer[bufferSize];  //designated my return buffer for use only as return.
	int n = 0; //n is used to keep track of index
	int c;  //c is character to be read in
	int padding; //For the below loop.

	int extraBlock = 0; //This will add an extra block to every input on encode because in the case that file size is perfect match to buffer 
	//			size we need an extra block and in the case of non exact match we need to add one because C floors it's division
	if(MODE == ENCODE){
		extraBlock = 1;
	}

	for(int i=0; i<(filestats.st_size/bufferSize + extraBlock);i++){
		while((c=fgetc(INPUT)) != EOF){ //this is fucking wrong;
			buffer[n%bufferSize] = (char) c;
			n++;
			if(n%bufferSize == 0){
				break;

			/*  	
				Ths break is very important because it stops the while loop from reading it all in and doing nothing with characters prior to the last 16

				Also learned that in c when using fgetc it will save your position when not in use. This is because it is a pointer so it saves your position in the
				memory for you to come back too.

				Now the reason my code was not working before is because this loop would get run to completion every time when it should be cut short for every
				16 bits of information read in.
			*/
			}
			if(DEBUG){
				printf("Value of n: '%c \n'", c); 
			}
		}

		/*
			This is the catch for initial padding on the last block of information. I have a check to the filesize/bufferSize +extraBlock -1 . 
			The extraBlock is necessary just for the encoding because otherwise it might not catch correctly. 
		*/
		if(i == (filestats.st_size/bufferSize + extraBlock)-1 && MODE == ENCODE){ 
			int index = n%bufferSize;
			padding = pad_buffer(buffer, bufferSize, index);
			if(DEBUG){
				printf("number of characters padded in ENCODE'%d'\n", padding); 
				printf("Should not be called more than once\n"); 
			}
		}

		for(int i=0; i<rounds; i++){
			if(MODE == ENCODE){ //This is the encoding section and we copy the mem of rBuffer to buffer because I like to not mix up dedicated buffers
				viginere_cypher(buffer, rBuffer, keyArray, keyLength);
				memcpy(buffer, rBuffer, bufferSize);
				columnar_cypher(buffer, rBuffer);
				memcpy(buffer, rBuffer, bufferSize);
			}else{
				columnar_cypher(buffer, rBuffer);
				memcpy(buffer, rBuffer, bufferSize);
				viginere_cypher(buffer, rBuffer, keyArray, keyLength);
				memcpy(buffer, rBuffer, bufferSize);
			}
		}


		int dumped = 0;  //characters to be dumped;

		/*
			This is my decode catch. It will check that it is the last block of information read in before running. Otherwise we can safely assume that every block
			prior to it is full of usefull information and can be output to file.
			The if will then run unpad buffer and use the padding returned to designate amount to be output.
		*/
		if(MODE == DECODE && i == (filestats.st_size/bufferSize + extraBlock)-1){
			//printf("DECODE\n");
			padding = unpad_buffer(buffer, bufferSize);
			if(DEBUG){
				printf("Should not be called more than once unpad \n"); 
				printf("number of characters padded in DECODE'%d'\n", padding); 
			}
			dumped = dump_buffer(buffer, bufferSize, padding, OUTPUT);
		}
		else{
			//printf("JUST DUMP IT\n");
			dumped = dump_buffer(buffer, bufferSize, bufferSize, OUTPUT);
		}

		if(DEBUG){
			printf("number of characters dumped in while loop'%df\n", dumped);
		}
	}

	fclose(KEY);
	fclose(INPUT);
	fclose(OUTPUT);
	return 0;
}


void viginere_cypher(char *buffer, char *rbuffer, char *key, int keyLength){
	if(DEBUG){
		printf("The keylength is '%d' \n", keyLength);
	}

	for(int i=0; i<bufferSize; i++){
		if(MODE == ENCODE){
			rbuffer[i] = (char) (buffer[i] + key[i%keyLength]);
		}else{
			rbuffer[i] = (char) (buffer[i] + key[i%keyLength] * -1);
		}
	}
}


void columnar_cypher(char *buffer, char *rbuffer){
	transpose_buffer(buffer,rbuffer, arraySize);	
}

/*
 * This function takes in a buffer and pads it with the correct character
 * Returns number of bits added
 * The function needed to add to the buffer if f(x) = x % buffer size * buffer size + x/buffer size where x is index
 * */
int pad_buffer(char* buffer, unsigned int bufsize, unsigned int rbuf_index){
	buffer[rbuf_index] = 'X';
	int written = 1;
	for(int i=rbuf_index+1; i<bufsize; i++){
		if(DEBUG){
			printf("char overwritten: %c\n", buffer[i]); 
		}
		buffer[i] = '0';
		written++;
	}
	return written;
}
/*
 *This takes in buffer and buffer size, then removes all the characters added by pad buffer
 * I am going to go about this backwards....start at the end. Find first X and be done with it.
 * return the index of where we read up too
 * */
int unpad_buffer(char* buffer, unsigned int bufsize){
	for(int i = bufsize-1; i>0; i--){ //Iterate backwards through array til it finds the X then returns the index before it
		if(buffer[i] == 'X'){
			return i--;
		}
	}
	return 0;
}

/*
 *This takes in an input and output buffer of the same length as well as the dimensions of the buffer
 *No output is returned however all the transposition happens to the pointed to array. 
 * */
void transpose_buffer(char* buffer, char* outputBuffer, unsigned int dim){
	int length = dim * dim;
	for(int i=0; i < length; i++){
		int pos = (i%dim) * dim + (i/dim);
		outputBuffer[pos] = buffer[i];
	}
	if(DEBUG){
		printf("The length of the buffer '%d'\n", length);
	}
}

/*
 *Takes in a buffer and dumps the characters to the output file
 * It will then erase the buffer and return number of bytes written
 * We will need to check the charcaters so that we do not write out the trailing 0's for padding. 
 * */
int dump_buffer(char *buffer, unsigned int bufsize, unsigned int bytes, FILE *output_path){
	for(int i=0; i<bytes; i++){
		if(DEBUG){
			printf("The characters being written '%c'\n", buffer[i]);
		}	
	
		fprintf(output_path, "%c", buffer[i]);
	}
	memset(buffer, 0, bufsize);
	return bufsize;
}

