
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    printf("int size : %lu \n", sizeof (int));
    printf("float size %lu \n", sizeof(float));
    printf("max float size %lu \n", sizeof(FLT_MAX));
    printf("char:%lu \n",sizeof(char));
    printf("char[8]:%lu \n",sizeof(char[8]));
    printf("double:%lu \n",sizeof(double));
    printf("double:%lu \n",sizeof(true));
    

    if(true){

    }
    return 0;
}