#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[]){
	
	char *input = argv[1];

	FILE *INPUT;
	if ((INPUT = fopen(input, "r")) == NULL){
		printf("Problem opening input file '%s', errno: '%d'\n", input, errno);
		return 1;
	}

	char c;
	//for(int i=0; i<16; c=fgetc(INPUT) != EOF){
	//	printf("c: '%c'\n", c);
	//}
	//
	int i;
	
	for(int k =0; k<3; k++){
		i=0;
		if(i<2){
			while((c=fgetc(INPUT)) != EOF ){ //this is fucking wrong;
				i++;
				printf("c: '%c'\n", c);
			}
		}
	}
}
