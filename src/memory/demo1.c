#include <stdio.h>
#include <stdlib.h>

struct stu{
    int num;
    char *name;
    char sex;
    float score;
} student;

main(){
    struct stu *ps;
    ps=(struct stu*)malloc(sizeof(struct stu));
    ps->num=102;
    ps->name="Zhang ping";
    ps->sex='M';
    ps->score=62.5;
    printf("Number=%d\nName=%s\n",ps->num,ps->name);
    printf("Sex=%c\nScore=%f\n",ps->sex,ps->score);
    free(ps);

    char *s = "helloworld";
    printf("%s \n",s);
}