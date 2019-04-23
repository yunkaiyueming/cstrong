#include <stdio.h>
#include "student.c"
#include "desc.c"

void main(){
    showSystemDesc();

    int id;
    int runFlag = 1;
    int selPos;
    while(runFlag){
        scanf("%d",&selPos);
        if(selPos==1){
            int age;
            char name[30];
            float score;

            printf("输入新学生信息：\n");
            scanf("%d",&id);
            scanf("%d",&age);
            scanf("%s",name);
            scanf("%f",&score);

            struct student st = initStudentByData(id,age,name,score); 
            addStudent(st);
            printf("新增学生信息成功！\n");
        }else if (selPos==2){
            printf("输入想要查询学生的编号：\n");
            scanf("%d",&id);
            getStudentById(id);
        }else if(selPos==3){
            printf("输出所有学生信息：\n");
            getAllStudent();
        }else if(selPos==4){
            printf("输入想要删除学生编号：\n");
            scanf("%d",&id);
            delStudentById(id);
        }else if(selPos==5){
            showSystemDesc();
        }else if(selPos==6){
            printf("成功退出该系统 \n");
            runFlag = 0;
        }
    }
}