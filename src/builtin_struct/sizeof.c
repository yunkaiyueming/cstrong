
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    printf("int size : %lu \n", sizeof (int));
    printf("float size %lu \n", sizeof(float));
    printf("max float size %lu \n", sizeof(FLT_MAX));
    printf("char:%lu \n",sizeof(char));
    printf("char[8]:%lu \n",sizeof(char[8]));
    printf("double:%lu \n",sizeof(double));
    
    struct people{
        int age;
        char* name;
        float id;
    };
    printf("struct people:%lu \n",sizeof(struct people));
    
    struct people p1;
    p1.name = "zhangsanzhangsanzhangsanzhangsanzhangsanzhangsan";
    printf("struct var p1:%lu \n",sizeof(p1));

    return 0;
}