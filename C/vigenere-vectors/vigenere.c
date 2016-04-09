#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define DEBUG 0
#define ENCODE 1
#define DECODE 0
#ifndef MODE
	#define MODE ENCODE 
#endif

int main(int argc, char *argv[]){
		if(DEBUG){
			printf("The keyfile specified '%s' \n", argv[1]);
			printf("The cyphertext specified '%s' \n", argv[2]);
			printf("The decoded file specified '%s' \n", argv[3]);
		}

		if(argc < 4){
			printf("Missing arguments, make sure you correct yourself");
			return 1;
		}
		char *keyfile = argv[1];
		char *cyphertext = argv[2];
		char *decoded = argv[3];

		FILE *INPUT;
		if ((INPUT = fopen(keyfile, "r")) == NULL){
			printf("Problem opening keyfile file '%s', errno: $d\n", keyfile, errno);
			return 1;
		}

		FILE *CYPHER;
		if ((CYPHER = fopen(cyphertext, "r")) == NULL){
			printf("Problem opening cyphertext file '%s', errno: $d\n", cyphertext, errno);
			return 1;
		}

		FILE *OUTPUT;
			if ((OUTPUT = fopen(decoded, "w+")) == NULL){
				printf("Problem opening output file '%s'; errno: %d\n", decoded, errno);
				return 1;
			}

		int symbol; //Character being read in
		char encoded; //Character after encoding
		char key[128];
		int keyLength = 0; //Keylength monitored for looping;
		while((symbol = fgetc(INPUT)) != EOF && keyLength < 128){
			key[keyLength] = symbol;
			if(DEBUG){
				printf("'%c'", (char)symbol);
			}	
			keyLength ++;
		}

		if(DEBUG){
			printf("The keylength is '%d'", keyLength);
		}
		
		int i = 0;
		while((symbol = fgetc(CYPHER)) != EOF){
			if(MODE == ENCODE){
				encoded = (char)(symbol + (key[i%keyLength]));
			}else {
				encoded = (char)(symbol + (key[i%keyLength]*-1));
			}

			fprintf(OUTPUT, "%c", encoded);
			i++;
		}

		fclose(INPUT);
		fclose(CYPHER);
		fclose(OUTPUT);

		return 0;
}
