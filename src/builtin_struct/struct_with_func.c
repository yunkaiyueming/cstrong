#include <stdio.h>
#include <stdlib.h>

typedef struct _Hello_t{
    char *name;
    void (*sayhello)(char *name);//结构体函数指针
}Hello;

void say(char *name){
    printf("%s \n", name);
}

void say2(char *name){
    printf("%s ahaha \n", name);
}


void main(){
    Hello *p = (Hello *)malloc(sizeof(Hello));
    p->sayhello = say;//函数say赋予结构体函数指针
    p->sayhello("张三"); 

    p->sayhello = say2;
    p->sayhello("张三");
}


/*
include<stdio.h>
#include<malloc.h>
struct Hello{
	void (*sayHello)(char* name); 
};
void sayHello(char* name){
	printf("你好，%s\n",name);
}
int main(){
	struct Hello* hello=(struct Hello *)malloc(sizeof(struct Hello));
	hello->sayHello=sayHello;//这个结构体有多少个函数，就要在这个有多少个结构体内，函数指针指向函数的声明。
	hello->sayHello("a");
	return 0;
}
*/
