#include <stdlib.h>
#include <stdio.h>

#ifndef main_task_num
#define main_task_num 20
#endif

#define M 10
#define Mstr int main(
    //宏定义 纯字符串替换
    
Mstr){
    printf("start \n");
    printf("%d %d", main_task_num, M);
    return 0;
}