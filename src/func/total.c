#include <stdio.h>

int add(int a ,int b){
    printf("run in total.c \n");
    return a+b;
}

int sub(int a,int b){
    printf("run in total.c \n");
    return a-b;
}

int sum(int a, int b){
    printf("run in total.c \n");
    return a*b;
}

int sumxy(){
	extern int x;
	extern int y;
	printf("run in total.c \n");
    return x*y;
}