#include <stdio.h>
#include <stdlib.h>

void main()
{
    //system("PATH");

    char *env_p = getenv("JAVA");
    if (env_p)
        printf("PATH = %s\n", env_p);
    printf("ok");

    int *p1 = calloc(4, sizeof(int));    // 分配并清零 4 个 int 的数组
    int *p2 = calloc(1, sizeof(int[4])); // 等价，直接命名数组类型
    int *p3 = calloc(4, sizeof *p3);     // 等价，免去重复类型名

    // if (p2)
    // {
    //     for (int n = 0; n < 4; ++n) // 打印数组
    //         printf("p2[%d] == %d\n", n, p2[n]);
    // }

    free(p1);
    free(p2);
    free(p3);


    srand(time(NULL)); // 以当前时间为随机生成器的种子
    int random_variable = rand();
    random_variable = rand();
    printf("\n Random value on [0,%d]: %d\n", RAND_MAX, random_variable);
 
}