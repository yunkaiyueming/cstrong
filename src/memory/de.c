#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

void out(int *p, int n){
    int i;
    for (i = 0; i < n; i++){
        printf("值=%d 地址=%d\n", *(p + i),(p+i));
    }
}

int main(void){
    //申请4个字节的堆内存空间，未初始化
    int *p = (int *)malloc(5 * sizeof(int));
    if (p == NULL)
        exit(1);
    *p = 1;
    *(p + 1) = 2;
    p[2] = 3;
    p[3] = 4;
    p[4] = 5;
    out(p, 5);
    printf("===============\n");

    //追加申请10个字节的内存空间，追加的空间也是未进行初始化的
    p = (int *)realloc(p, 20 * sizeof(int));
    if (p == NULL)
        exit(1);
    p[6] = 6;
    *(p + 6) = 7;
    *(p + 7) = 8;
    *(p + 8) = 9;
    *(p + 9) = 10;
    out(p, 20);

    free(p);
    //free之后，将指针置为空
    p = NULL;
    return 0;
}