#include <stdio.h>

int main(){
	char ch1[10],ch2[10];
	//scanf("%s",ch1);

	int id;
    int age;
    char name[10];
    float score;

    scanf("%d",&id);
    scanf("%d",&age);
    scanf("%s",name);
    scanf("%f",&score);

	printf("%d,%d,%s,%.2f",id,age,name,score);
	return 0;
}