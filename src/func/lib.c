#include <stdio.h>

extern int a1;
extern int b1;
int max(){
    printf("run in lib.c \n");
    return a1>b1?a1:b1;
}