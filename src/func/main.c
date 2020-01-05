#include <stdio.h>
#include "total.h"
#include "total.c"
#include "lib.c"

int x = 1;
int y = 2;

static int w; //静态全局变量 本文件内可用

void count();

int main(){
	// int x =10;//局部变量
	// int y =5;
    int ret;

    ret = add(20,8);
    printf("%d \n",ret);

    ret = sub(20,8);
    printf("%d \n",ret);

    ret = sum(20,8);
    printf("%d \n",ret);

	ret = sumxy();
    printf("%d \n",ret);

    ret = max();
    printf("%d \n",ret);

    auto int i;
    for(i=1;i<10;i++){
        count();
    }


    return 0;
}


void count(){
    static int count ;//静态局部变量
    count ++;
    printf("count num:%d\n", count);
}
