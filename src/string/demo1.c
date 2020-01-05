#include <stdio.h>
#include <string.h>

void main(){
    char str1[15];
    char str2[15];
    int ret;

    memcpy(str1, "abcdef", 6);
    memcpy(str2, "ABCDEF", 6);

    ret = memcmp(str1, str2, 5); //比较
    if(ret > 0){
        printf("str2 小于 str1");
    }else if(ret > 0){
        printf("str1 小于 str2");
    }else{
        printf("str1 等于 str2");
    }

    printf("\n");
    int len = strlen(str2);
   printf("|%s| 的长度是 |%d| \n", str2, len);

    const char haystack[20] = "jikexSchoolueyuan";
    const char needle[10] = "School";
    char *ret2;
    ret2 = strstr(haystack, needle);
    printf("子字符串是： %s\n", ret2);
}