#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

typedef struct Node
{
    int data;           //数据域，用来存放数据域；
    struct Node *pNext; //定义一个结构体指针，指向下一次个与当前节点数据类型相同的节点
} NODE, *PNODE;         //NODE等价于 struct Node; PNODE等价于struct Node *； 此处用大写是为了与变量区分，可以让人容易变出是个数据类型

PNODE Create_List(void)
{
    int len; //存放链表的长度
    int i;   //循环变量
    int val; //用来临时存放用户输入的结点的值
    PNODE List;
    PNODE pHead = (PNODE)malloc(sizeof(NODE)); //分配一个头节点
    if (NULL == pHead)
    {
        printf("Memory allocation failure");
        exit(-1);
    }
    else
    {
        PNODE pTail = pHead;
        pHead->pNext = NULL;
    }
    return pHead;
}

PNODE Create_List_With_Length()
{
    int len; //存放链表的长度
    int i;   //循环变量
    int val; //用来临时存放用户输入的结点的值
    PNODE List;
    PNODE pHead = (PNODE)malloc(sizeof(NODE)); //分配一个头节点
    if (NULL == pHead)
    {
        printf("Memory allocation failure");
        exit(-1);
    }
    else
    {
        PNODE pTail = pHead;
        pHead->pNext = NULL;
        printf("please input the length of list: "); //需要一个指针始终指向链表的结尾
        scanf("%d", &len);
        for (i = 0; i < len; i++)
        {
            PNODE p = (PNODE)malloc(sizeof(NODE));
            if (NULL == p)
            {
                printf("Memory allocation failure");
                exit(-1);
            }
            else
            {
                printf("please input the value of list: ");
                scanf("%d", &val);
                p->data = val;
                pTail->pNext = p;
                p->pNext = NULL;
                pTail = p;
            }
        }
    }
    return pHead;
}

//链表的第pos有效元素前面插入元素val，首先我们应该找到第pos个元素前面一个元素的位置；
//当链表有3个元素时，pos=4，将不会进行插入操作
bool Insert_List(PNODE pHead, int pos, int val)
{
    int i = 0;
    PNODE p = pHead;
    while ((NULL != p) && (i < pos - 1)) //
    {
        p = p->pNext;
        i++;
    }
    if (p == NULL || i > pos - 1) //把链表为空的情况考虑进去了；i>pos-1 可以防止用户输入错误；
        return false;

    //程序执行到这之后，i=pos-1；p指针指向链表第pos个有效节点的前驱，即指向第pos-1节点；
    PNODE q = (PNODE)malloc(sizeof(NODE));
    q->data = val;
    q->pNext = p->pNext;
    p->pNext = q;
    return true;
}

//插入链表最后位置
bool Insert_List_With_End(PNODE pHead, int val)
{
    //PNODE p = pHead;
    int i = 0;
    while ((NULL != pHead && pHead->pNext != NULL))
    {
        pHead = pHead->pNext;
    }
    if (pHead == NULL) //把链表为空的情况考虑进去了；i>pos-1 可以防止用户输入错误；
    {
        printf("P is null\n");
    }

    PNODE q = (PNODE)malloc(sizeof(NODE));
    q->data = val;
    q->pNext = NULL;
    pHead->pNext = q;

    return true;
}

//删除链表数据
bool Delete_List(PNODE pHead, int pos, int *val)
{
    int i = 0;
    PNODE p = pHead;
    while ((NULL != p) && (i < pos - 1))
    {
        p = p->pNext;
        i++;
    }
    if (p == NULL || i > pos - 1) //把链表为空的情况考虑进去了；i>pos-1 可以防止用户输入错误；
        return false;

    //程序执行到这之后，i=pos-1；
    PNODE q = p->pNext; //q指向待删除的节点；
    *val = q->data;
    p->pNext = q->pNext; //修改链表指针指向；
    free(q);             //释放q所指向节点的内存；
    q = NULL;            //千万不可以忘记，否则会出现野指针；
}

//链表有效元素的个数
int Length_List(PNODE pHead)
{
    int len = 0; //定义变量要记得初始化；
    PNODE p = pHead->pNext;
    while (NULL != p)
    {
        len++;
        p = p->pNext;
    }
    return len;
}

//对链表中的元素进行排序 从大到小排序
void Sort_List(PNODE pHead)
{
    int i, j;
    int temp;
    int len = Length_List(pHead);
    PNODE p, q; //指向链表第一个有效元素

    for (i = 0, p = pHead->pNext; i < len - 1; i++, p = p->pNext)
    {
        for (j = i + 1, q = p->pNext; j < len; j++, q = q->pNext)
        {
            //交换数据
            if (p->data < q->data)
            {
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }
}

//遍历链表中的元素
void Foreach_List(PNODE pHead)
{
    //PNODE p = pHead;
    pHead = pHead->pNext;
    int i = 0;
    while (pHead != NULL)
    {
        i++;
        printf("第%d个元素：%d \n", i, pHead->data);
        pHead = pHead->pNext;
    }
}

void main()
{
    PNODE list = Create_List();
    Foreach_List(list);

    Insert_List(list, 1, 10);
    Insert_List(list, 2, 20);
    Insert_List(list, 1, 30);
    Foreach_List(list);

    printf("链表长度：%d \n", Length_List(list));
    Sort_List(list);
    printf("链表排序后：\n");
    Foreach_List(list);

    // list = Create_List_With_Length();
    // Foreach_List(list);
    // Insert_List(list, 1, 10);
    // Insert_List(list, 2, 20);
    // Insert_List(list, 1, 30);
    // Foreach_List(list);
    // printf("链表长度：%d \n", Length_List(list));
    // Sort_List(list);
    // Foreach_List(list);

    Insert_List_With_End(list, 40);
    Insert_List_With_End(list, 50);
    Foreach_List(list);
}