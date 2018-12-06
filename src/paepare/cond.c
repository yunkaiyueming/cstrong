#include <stdio.h>

#define NUM1 10
#define NUM2 20

int main()
{
#if _WIN32
    printf("win32");
    system("color 0c");
    printf("http://c.biancheng.net\n");
#elif __linux__
    printf("linux");
    printf("\033[22;31mhttp://c.biancheng.net\n\033[22;30m");
#else
    printf("other");
    printf("http://c.biancheng.net\n");
#endif
    printf("end over");


    #if (defined NUM1 && defined NUM2)
        //代码A
        printf("NUM1: %d, NUM2: %d\n", NUM1, NUM2);
    #else
        //代码B
        printf("Error\n");
    #endif
}