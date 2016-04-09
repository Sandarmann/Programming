/*
 * Useful things for this project
 * function atoi(argument) will take a string and turn it into an integer. This is helpful for taking arguments passed to main
 * libraries sys/types.h sys/stat.h unistd.h will allow us to create a struct using the stat from sys. Which can give us information regarding a file which we use to print out the files size in bytes
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define ENCODE 1
#define DECODE 0
#ifndef MODE
	#define MODE ENCODE
#endif
int DEBUG = 0;
struct stat filestats;

int pad_buffer(char* buffer, unsigned int bufsize, unsigned int rbuf_index);
int unpad_buffer(char* buffer, unsigned int bufsize);
void transpose_buffer(char* buffer, char* outputBuffer, unsigned int dim);
int dump_buffer(char *buffer, unsigned int bufsize, unsigned int bytes, FILE *output_path);


int main(int argc, char *argv[]){
	if(argc < 4){
		printf("Missing arguments");
		return 1;
	}
	int arraySize = atoi(argv[1]);
	char *input = argv[2];
	char *output = argv[3];
	if(argc == 5){
		printf("The size of block array '%d' \n", atoi(argv[1]));
		printf("The input file '%s' \n", argv[2]);
		printf("The output file '%s' \n", argv[3]);
		printf("Debug allowed '%d' \n", atoi(argv[4]));
		DEBUG = 1;
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

	char buffer[arraySize * arraySize];    //This will be the buffer used to create the string with padding etc....
	char rBuffer[arraySize * arraySize];
	int err;
	if ((err = stat(input, &filestats)) < 0) {
		   printf("error statting file! Error: %d\n", err);
	}

	if(DEBUG){
		printf("Size of input is: %lld bytes\n", filestats.st_size);
	}
	int padding;
	int dumped;
	int bufferSize = arraySize * arraySize;
	if(MODE == ENCODE){
		int n = 0;
		int c;
		while((c=fgetc(INPUT)) != EOF){
			buffer[n%bufferSize] = (char) c; //Adding modulus so it never tries to insert into memory elsewhere
			n++;
			if(n%bufferSize == 0){
				transpose_buffer(buffer,rBuffer, arraySize);
				dumped = dump_buffer(rBuffer, bufferSize, bufferSize, OUTPUT);
				if(DEBUG){
					printf("number of bytes dumped %d \n", dumped);
				}
			}	
		}
			int index = n%bufferSize;

			padding = pad_buffer(buffer, bufferSize, index);
			transpose_buffer(buffer,rBuffer, arraySize);
			dumped = dump_buffer(rBuffer, bufferSize, bufferSize, OUTPUT);
			if(DEBUG){
				printf("number of bytes added %d \n", padding);
				printf("number of bytes dumped %d \n", dumped);
			}

	}else {	
		int numOfArrays = (int) filestats.st_size / bufferSize;
		int n = 0;
		int c;
		//We should take the division of the byte size of the file. Then on the lst number then we do the unpad
		while((c=fgetc(INPUT)) != EOF){
			buffer[n%bufferSize] = (char) c; //Same logix as above if statement
			n++;
			if(n%bufferSize == 0 && n / bufferSize < numOfArrays){
				transpose_buffer(buffer,rBuffer, arraySize);
				dumped = dump_buffer(rBuffer, bufferSize, bufferSize, OUTPUT);
				if(DEBUG){
					printf("number of bytes dumped %d \n", dumped);
				}
			}
		}
				transpose_buffer(buffer,rBuffer, arraySize);
				padding = unpad_buffer(rBuffer,bufferSize);
				dumped = dump_buffer(rBuffer, bufferSize, padding, OUTPUT);
				if(DEBUG){
					printf("number of bytes added %d \n", padding);
					printf("number of bytes dumped %d \n", dumped);
				}
	}

	fclose(INPUT);
	fclose(OUTPUT);
	return 0;
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
		char trans = buffer[i];
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
