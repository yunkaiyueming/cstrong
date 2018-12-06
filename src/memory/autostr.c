#include<stdio.h>
#include<malloc.h>

void out(int *p,int n)
{
    int i;
    for(i=0;i<n;i++)
    {   
        printf("%d",*(p+i));
        printf("---------------\n");
    }   

}

int main(void)
{
    printf("please input one number:");
    int n;
    scanf("%d",&n);
    //申请
    int *p = (int *)malloc(n * sizeof(int));
    //内存申请成功
    if(p != NULL){
        out(p,n);
        int i;
        for(i=0;i<n;i++){
            *(p+i)=i*i;
        }
        out(p,n);
        //释放掉堆内存
        free(p);
    }else{
        //内存申请失败
        printf("malloc is NULL!\n");
    }   
    return 0;
}