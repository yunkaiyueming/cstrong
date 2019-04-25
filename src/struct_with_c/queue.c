#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

#ifndef __STACK_H_
#define __STACK_H_
typedef int elementype;
//定义一个节点
typedef struct Node
{
    elementype data;
    struct Node *pNext;
} NODE, *PNODE;

//构造一个栈
typedef struct stack
{
    PNODE pTop;    //栈顶指针
    PNODE pBottom; //栈底指针
} STACK, *PSTACK;
//函数声明区
void Create_Stack(PSTACK S);
void Push_Stack(PSTACK S, int val);
bool Pop_Stack(PSTACK S, int *val);
void Traverse_Stack(PSTACK S);
void Clear_Stack(PSTACK S);
#endif

//创建一个空栈，里面没有任何有效数据；
void Create_Stack(PSTACK S)
{
    S->pBottom = (struct Node *)malloc(sizeof(struct Node));
    if (NULL == S->pBottom)
    {
        printf("Memory allocation failure");
        exit(-1);
    }
    S->pTop = S->pBottom;
    S->pTop->data = 0;
    S->pTop->pNext = NULL; //防止出现野指针
}

//进栈
void Push_Stack(PSTACK S, int val)
{
    PNODE p = (struct Node *)malloc(sizeof(struct Node));
    if (NULL == p)
    {
        printf("Memory allocation failure");
        exit(-1);
    }
    p->data = val;
    p->pNext = S->pTop; //让p的指针域指向上一个节点
    S->pTop = p;        //让pTop指针指向栈顶元素
}

//打印出栈里面的元素
void Traverse_Stack(PSTACK S)
{
    PNODE p = S->pTop;
    printf("栈中的元素是：\n");
    while (p != S->pBottom)
    {
        printf("%d ", p->data);
        p = p->pNext;
    }
    printf("\n");
}

bool Is_Empty(PSTACK pS)
{
    if (pS->pTop == pS->pBottom)
        return true;
    else
        return false;
}

bool Pop_Stack(PSTACK S, int *val)
{
    if (Is_Empty(S))
        return false;
    else
    {
        PNODE p = S->pTop;
        *val = S->pTop->data;
        S->pTop = S->pTop->pNext; //使pTop指针指向栈顶元素；

        free(p);  //释放p指针所指向的那个节点的内存；
        p = NULL; //要养成好的习惯；
        return true;
    }
}

void Clear_Stack(PSTACK S)
{
    if (Is_Empty(S))
        return;
    else
    {
        PNODE p = NULL; //养成一好习惯，定义指针记得初始化；
        while (S->pTop != S->pBottom)
        {
            p = S->pTop;
            S->pTop = S->pTop->pNext;
            free(p);
            p = NULL;
        }
    }
}

void main()
{
    PSTACK stack = (PSTACK)malloc(sizeof(STACK));
    Create_Stack(stack);
    Push_Stack(stack, 10);
    Traverse_Stack(stack);

    Push_Stack(stack, 20);
    Push_Stack(stack, 30);
    Traverse_Stack(stack);

    int t;
    Pop_Stack(stack, &t);
    printf("退栈的栈顶元素为：%d \n", t);
    Traverse_Stack(stack);
}