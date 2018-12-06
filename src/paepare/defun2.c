#include <stdio.h>

#define SQ(y) ((y)*(y))

int main(){
    int i=1;
    while(i<=5){
        printf("%d^2 = %d\n", i, SQ(i++)); //宏和函数只是在形式上相似，本质上是完全不同的。
    }
    return 0;
}