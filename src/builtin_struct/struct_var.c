#include <stdio.h>

//结构体定义
struct school{
    int id;
    char *name;
};

struct book{
    int id;
    char *name;
}book_val;//book_val为结构体变量

typedef struct _people_t{
    int id;
    char name;
}People;//为结构体_people_t定义别名People

struct _people_t p2;
People p1;

struct {
    int id;
    char name;
}pvar;//匿名结构体直接定义一个结构体对象 只用一个变量pvar，不再用其他结构体变量时候用

void main(){

}