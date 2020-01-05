#include <stdio.h>

int main()
{
#ifdef WIN32
    printf("win32");
    //提示编译失败
#error This programme cannot compile at Windows Platform

#endif
}