#include <stdio.h>

typedef struct stu{
    char name[20];
    int age;
    char sex;
} STU;


//typedef type othername;
typedef struct book{
    int id;
    char bookname[20];
    char booknum;
}book_t;

struct stu body1, body2;
STU body1,body2;

struct book book1,book2;
book_t book3,book4;

#define TRUE  1//使用define定义数
#define book_d struct book //使用define定义类型 别名 define ohtername value
book_d book5,book6;

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