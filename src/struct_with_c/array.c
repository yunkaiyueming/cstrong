#include <stdio.h>
#include <stdlib.h> //包含了exit函数
// #include "malloc.h"

#define bool int
#define true 1
#define false 0

//定义一个新的数据类型,并没有分配内存空间
struct Array
{
    int *pBase; //定义一个指向数组的指针
    int len;    //数组中能够存放的最大元素个数
    int cnt;    //当前数组中元素的个数
};

void Init_arr(struct Array *pArr, int len);             //初始化数组
bool append_arr(struct Array *pArr, int val);           //在数组后追加一个元素
bool Insert_arr(struct Array *pArr, int pos, int val);  //指定位置插入元素
bool Delete_arr(struct Array *pArr, int pos, int *val); //指定位置删除元素

bool IsFull_arr(struct Array *pArr);  //判断数组是否满
bool IsEmpty_arr(struct Array *pArr); //判断数组是否空

void show_arr(struct Array *pArr);       //打印数组中的元素
void Inversion_arr(struct Array *pArr);  //倒置数组中的元素
void SelectSort_arr(struct Array *pArr); //选择排序
void BubbleSort_arr(struct Array *pArr); //冒泡排序

/*********************************************************************************
  *Function: Init_arr；
  *Description： 创建并初始化一个数组；
  *Calls:  malloc()、printf()、exit()；
  *Called By:  none
  *Input:  参数一pArr是一个结构体指针变量，用来接受结构体变量的地址的；
           参数——len是说明创建的数组的容量，也就是能装元素的最大个数；
          //输入参数的说明，包括每个参数的作用、取值说明及参数间关系；
  *Output:  none
  *Return:  none
  *Others:  none
**********************************************************************************/
void Init_arr(struct Array *pArr, int len)
{
    pArr->pBase = (int *)malloc(sizeof(int) * pArr->len);
    if (NULL == pArr->pBase)
    {
        printf("分配内存失败");
        exit(-1); //终止程序
    }
    else
    {
        pArr->cnt = 0;
        pArr->len = len;
    }
    return; //加return的目的是为了告诉其他人，此函数到此已经写完了
}
/*********************************************************************************
  *Function: show_arr；
  *Description： 打印出数组中所有元素；
  *Calls:  printf()；
  *Called By:  none
  *Input:  参数一pArr是一个结构体指针变量，用来接受结构体变量的地址的；
  *Output:  none
  *Return:  none
  *Others:  none
**********************************************************************************/
void show_arr(struct Array *pArr)
{
    int i;
    printf("数组的最大元素个数：%d\n", pArr->len);
    printf("数组的当前元素个数：%d\n", pArr->cnt);
    for (i = 0; i < pArr->cnt; i++) //只要显示数组中有的元素
        printf("%d ", pArr->pBase[i]);
    printf("\n");
}
/*********************************************************************************
  *Function: append_arr；
  *Description： 在数组最后一个元素后面添加一个元素；
  *Calls:  IsFull_arr()；
  *Called By:  none
  *Input:  参数一pArr是一个结构体指针变量，用来接受结构体变量的地址的；
           参数——val，要添加的数据；
          //输入参数的说明，包括每个参数的作用、取值说明及参数间关系；
  *Output:  none
  *Return:  布尔量，1表示追加成功；0，追加失败；
  *Others:  none
**********************************************************************************/
bool append_arr(struct Array *pArr, int val)
{
    if (IsFull_arr(pArr)){
        //return false;
    }

    pArr->pBase[pArr->cnt++] = val;
    return true;
}

/*********************************************************************************
  *Function: IsFull_arr；
  *Description： 判断数组是否满；
  *Calls:  none；
  *Called By:  append_arr()，Insert_arr()；
  *Input:  参数一pArr是一个结构体指针变量，用来接受结构体变量的地址的；
  *Output:  none
  *Return:  布尔量，1表示数组满；0，数组不满；
  *Others:  none
**********************************************************************************/
bool IsFull_arr(struct Array *pArr) //true 与 false 一般用于返回bool类型的函数
{
    if (pArr->cnt == pArr->len)
    {
        return true;
    }
    else
        return false;
}
/*********************************************************************************
  *Function: Insert_arr；
  *Description： 在数组的第pos个元素前，插入val元素；；
  *Calls:  IsFull_arr()；
  *Called By: none；
  *Input:  参数一pArr是一个结构体指针变量，用来接受结构体变量的地址的；
           参数——pos，表示位置，在数组第pos元素前加入数据val；
		   参数——val，表示要插入的数据；
  *Output:  none
  *Return:  布尔量，1表示插入成功；0，插入失败；
  *Others:  none
**********************************************************************************/
bool Insert_arr(struct Array *pArr, int pos, int val)
{
    int i;
    if (IsFull_arr(pArr)) //为空不能进行插入操作
        //return false;
    if (pos < 1 || pos > pArr->cnt + 1) //插入的位置不能在第一个元素前面，也不可以在最后一个元素后面的后面插入
        return false;

    for (i = pArr->cnt - 1; i >= (pos - 1); i--)
        pArr->pBase[i + 1] = pArr->pBase[i];
    pArr->pBase[pos - 1] = val;
    pArr->cnt++;
    return true;
}
/*********************************************************************************
  *Function: IsEmpty_arr；
  *Description： 判断数组是否空；
  *Calls:  none；
  *Called By:  Delete_arr()；
  *Input:  参数一pArr是一个结构体指针变量，用来接受结构体变量的地址的；
  *Output:  none
  *Return:  布尔量，1表示数组空；0，数组不空；
  *Others:  none
**********************************************************************************/
bool IsEmpty_arr(struct Array *pArr)
{
    if (0 == pArr->cnt)
        return true;
    else
        return false;
}
/*********************************************************************************
  *Function: Delete_arr；
  *Description： 删除数组的第pos个元素
  *Calls:  IsFull_arr()；
  *Called By: none；
  *Input:  参数一pArr是一个结构体指针变量，用来接受结构体变量的地址的；
           参数——pos，数组的第pos个元素将被删除
		   参数——val，返回要删除的数据；
  *Output:  把删除的数据，返回给指针val
  *Return:  布尔量，1表示删除成功；0，删除失败；
  *Others:  none
**********************************************************************************/
bool Delete_arr(struct Array *pArr, int pos, int *val)
{
    int i;
    if (IsEmpty_arr(pArr))
        return false;
    if (pos > pArr->cnt || pos < 1)
        return false;

    *val = pArr->pBase[pos - 1];
    for (i = pos; i <= pArr->cnt - 1; i++)
        pArr->pBase[i - 1] = pArr->pBase[i];
    pArr->cnt--;
    return true;
}
/*********************************************************************************
  *Function: Inversion_arr；
  *Description： 倒置数组中的元素
  *Calls:  none；
  *Called By: none；
  *Input:  参数一pArr是一个结构体指针变量，用来接受结构体变量的地址的；
  *Output:  none
  *Return:  none
  *Others:  none
**********************************************************************************/
void Inversion_arr(struct Array *pArr)
{
    int i, j, temp;
    for (i = 0, j = pArr->cnt - 1; i < j; i++, j--) //i,j分别指向数组的首尾元素，没移动一次交换一次，直到不满足条件i<j;
    {
        temp = pArr->pBase[i];
        pArr->pBase[i] = pArr->pBase[j];
        pArr->pBase[j] = temp;
    }
}
/*********************************************************************************
  *Function: SelectSort_arr；
  *Description： 用选择排序算法对数组中元素进行排序
  *Calls:  none；
  *Called By: none；
  *Input:  参数一pArr是一个结构体指针变量，用来接受结构体变量的地址的；
  *Output:  把删除的数据，返回给指针val；
  *Return:  void
  *Others:  none
**********************************************************************************/
void SelectSort_arr(struct Array *pArr)
{
    int i, j, temp;
    for (i = 0; i < pArr->cnt - 1; i++)
    {
        for (j = i + 1; j < pArr->cnt; j++)
            if (pArr->pBase[i] > pArr->pBase[j])
            {
                temp = pArr->pBase[i];
                pArr->pBase[i] = pArr->pBase[j];
                pArr->pBase[j] = temp;
            }
    }
}
/*********************************************************************************
  *Function: BubbleSort_arr；
  *Description： 利用冒泡排序对数组中的元素进行排序
  *Calls:  IsFull_arr()；
  *Called By: none；
  *Input:  参数一pArr是一个结构体指针变量，用来接受结构体变量的地址的；
  *Output:  none
  *Return: none；
  *Others:  none
**********************************************************************************/
void BubbleSort_arr(struct Array *pArr)
{
    int i, j, temp;
    bool exchange = false;
    for (i = 0; i < pArr->cnt - 1; i++)
    {
        exchange = false; //开始前排序标志为false，代表没有交换；
        for (j = pArr->cnt - 1; j > i; j--)
        {
            if (pArr->pBase[j] < pArr->pBase[j - 1])
            {
                temp = pArr->pBase[j];
                pArr->pBase[j] = pArr->pBase[j - 1];
                pArr->pBase[j - 1] = temp;
                exchange = true;
            }
        }
        if (!exchange)
            return; //若一趟排序下来，数据没有交换说明，数据中的数据是有序的，就没有必要在进行循环了；
    }
}



int main()
{
    struct Array arr; //定义一个结构体变量，并分配内存在静态区；（静态区、堆，栈）
    printf("初始数组字节数： %d \n", sizeof(struct Array));
    //struct Array *pArr; //定义一个结构体指针，并为此指针分配了4字节的内存
    //pArr=(struct Array *)malloc(sizeof(struct Array)); //此时只是为pBsae指针，len,cnt变量分配了内存；
    //arr.pBase=(int *)malloc(sizeof(int)*arr.len);
    Init_arr(&arr, 2);
    show_arr(&arr);
    append_arr(&arr, 2);
    append_arr(&arr, 5);
    append_arr(&arr, 254);
    append_arr(&arr, 54);
    append_arr(&arr, 189);
    if (!append_arr(&arr, 18))
        printf("追加失败\n");

    if (!Insert_arr(&arr, 3, 99))
        printf("插入失败\n");

    show_arr(&arr);
    int DelElement = 0;
    int *p = &DelElement;
    Delete_arr(&arr, 2, p);
    printf("删除的元素是:%d\n", *p);
    show_arr(&arr);

    SelectSort_arr(&arr);
    printf("选择排序后\n");
    show_arr(&arr);


    Inversion_arr(&arr);
	printf("倒置后\n");
	show_arr(&arr);
	BubbleSort_arr(&arr);
	printf("冒泡排序后\n");
	show_arr(&arr);
	
    return 0;
}