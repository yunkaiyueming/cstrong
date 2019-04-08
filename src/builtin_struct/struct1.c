#include <stdio.h>

struct stu{
    int num;
    char *name;
    char sex;
    float score;
 };
 //boy1={102,"Zhang ping",'M',78.5},*pstu;

struct stu boy1 = {102,"Zhang ping",'M',78.5};
struct stu *pstu;

void main(){
    pstu=&boy1;
    printf("结构体.访问：\n");
    printf("Number=%d\nName=%s\n",boy1.num,boy1.name);
    printf("Sex=%c\nScore=%f\n\n",boy1.sex,boy1.score);

    printf("*结构体指针.访问 \n");
    printf("Number=%d\nName=%s\n",(*pstu).num,(*pstu).name);
    printf("Sex=%c\nScore=%f\n\n",(*pstu).sex,(*pstu).score);

    printf("结构体指针->访问 \n");
    printf("Number=%d\nName=%s\n",pstu->num,pstu->name);
    printf("Sex=%c\nScore=%f\n\n",pstu->sex,pstu->score);
}