#include <stdio.h>

#define ADD(a,b) a+b
#define N 100

#define M (n+n*3)
#undef M //终止其作用域可使用#undef

#define MAX(a,b) (a>b) ? a : b

int add(int a, int b ){
    return a+b;
}
//C语言提供了多种预处理功能，如宏定义、文件包含、条件编译等

int main(){
    int a =20;
    int b = 10;
    printf("%d \n", add(a,b));
    printf("%d \n", ADD(a,b));

    printf("%d \n", add(a,b)*add(a,b));
    printf("%d \n", ADD(a,b)*ADD(a,b)); //仅仅只是宏函数替换
    
    printf("%d \n", MAX(10,20));
    return 0;
}