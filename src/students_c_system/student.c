#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct student{
    int id;
    int age;
    char *name;
    float score;
}studentType;

//全局数组
struct student studentArr[100];

struct student initStudent(){
    struct student *st = (struct student*)malloc(sizeof(struct student));
    //st->id=0;
    // st->age=0;
    // st->name="";
    // st->score=0;
    // st->nextT = NULL;
    return *st;
}

struct student initStudentByData(int id,int age,char *name,float score){
    char deststr[30];
    strcpy(deststr, name);
    printf("%s",deststr);
    struct student st = {id,age,deststr,score};
    return st;
};

void addStudent(struct student t){
    int i;
    for(i=0;i<100;i++){
        if(studentArr[i].id<=0){
            studentArr[i] = t;
            break;
        }
    }
}

void delStudentById(int id){
    int i;
    int delFlag=0;
    for(i=0;i<100;i++){
        if(studentArr[i].id>=0 && studentArr[i].id==id){
            studentArr[i] = initStudent();
            printf("删除学生信息成功！\n");
            delFlag=1;
            break;
        }
    }

    if(!delFlag){
        printf("无此ID号学生信息，删除失败！\n");
    }
}

void getStudentById(int id){
    if(id<=0){
        printf("ID号输入错误！\n");
    }

    int findFlag = 0;
    int i;
    for(i=0;i<100;i++){
        if(studentArr[i].id>0 && studentArr[i].id==id){
            struct student tmp = studentArr[i];
            printf("ID:%d,姓名:%s,年龄:%d,分数:%2.f \n",tmp.id,tmp.name,tmp.age,tmp.score);
            findFlag = 1;
            break;
        }
    }

    if(!findFlag){
        printf("无此ID号学生信息，查找失败！\n");
    }
}

void getAllStudent(){
    int i;
    for(i=0;i<100;i++){
        if(studentArr[i].id>0){
            struct student tmp = studentArr[i];
            printf("ID:%d,姓名:%s,年龄:%d,分数:%2.f \n",tmp.id,tmp.name,tmp.age,tmp.score);
        }else{
            break;
        }
    }
}
