#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
    char *s2 = (char *)calloc(20, sizeof(char));//分配内存空间&初始化20个sizeof(char)

    char *s1 = (char *)malloc(sizeof(char));
    memset(s1, 0, sizeof(char));
}