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

            printf("������ѧ����Ϣ��\n");
            scanf("%d",&id);
            scanf("%d",&age);
            scanf("%s",name);
            scanf("%f",&score);

            struct student st = initStudentByData(id,age,name,score); 
            addStudent(st);
            printf("����ѧ����Ϣ�ɹ���\n");
        }else if (selPos==2){
            printf("������Ҫ��ѯѧ���ı�ţ�\n");
            scanf("%d",&id);
            getStudentById(id);
        }else if(selPos==3){
            printf("�������ѧ����Ϣ��\n");
            getAllStudent();
        }else if(selPos==4){
            printf("������Ҫɾ��ѧ����ţ�\n");
            scanf("%d",&id);
            delStudentById(id);
        }else if(selPos==5){
            showSystemDesc();
        }else if(selPos==6){
            printf("�ɹ��˳���ϵͳ \n");
            runFlag = 0;
        }
    }
}