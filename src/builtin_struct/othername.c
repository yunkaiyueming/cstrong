#include <stdio.h>

typedef struct stu{
    char name[20];
    int age;
    char sex;
} STU;


struct stu body1, body2;
STU body1,body2;

void main(){
    struct stu s1;
    s1.age=20;//  (*结构指针变量).成员名
    printf("%d \n",s1.age);

    body1.age=20;//  (*结构指针变量).成员名
    printf("%d \n",body1.age);

    struct stu *s2;
    s2 = &body1;
    s2->age  = 30;
    printf("%d \n",s2->age);

    printf("%d \n",body1.age);
    printf("end over");
}