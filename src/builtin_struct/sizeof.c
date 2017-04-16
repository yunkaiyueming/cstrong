
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    printf("int size : %lu \n", sizeof (int));
    printf("float size %lu \n", sizeof(float));
    printf("max float size %lu \n", sizeof(FLT_MAX));
    return 0;
}