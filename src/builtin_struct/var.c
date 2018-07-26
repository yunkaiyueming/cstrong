#include <stdio.h>

// 变量声明
extern int a1, b1;
extern int c1;
extern float f1;

void echo_var();
void add();

void main() {
    //type variable_list;
    int i, j, k;
    char c, ch;
    float f, salary;
    double d;

    printf("%d,%d,%d \n", i, j, k);
    printf("%d,%d,%d \n", c, ch);
    printf("%f,%f \n", f, salary);
    printf("%d \n", d);

    echo_var();
    add();
}

void echo_var() {
    //extern int d = 3, f = 5; // d 和 f 的声明, 这就是单纯的声明
    int d = 3, f = 5; // 定义并初始化 d 和 f
    float z = 22.22; // 定义并初始化 z
    char x = 'x'; // 变量 x 的值为 'x'

    printf("%d,%d,%f,%c\n", d, f, z, x);
}

void add() {
    /* 变量定义 */
    int a1, b1;
    int c1;
    float f1;

    /* 初始化 */
    a1 = 10;
    b1 = 20;

    c1 = a1 + b1;
    printf("value of c1 : %d \n", c1);

    f1 = 70.0 / 3.0;
    printf("value of f1 : %f \n", f1);
}