#include <stdio.h>

void main(int argc, char **argv){

	printf("%d \n", argc);
	int i=0;
	while(argv[i]){
		printf("%c \n", argv[i]);
	}
	
	printf("end over \n");
}
