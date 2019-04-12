#include <stdio.h>
#include <ctype.h>

void main(){
    char s = 's';
    int b = 5;
    char *str = "abcd";
    printf("%d,%d,%d\n",isalnum(s),isalnum(b),isalnum(*str));//是一个数字或一个字母，则该函数返回非零值，否则返回 0。
    printf("%d,%d,%d \n",isalpha(s),isalpha(b),isalpha(*str));
}
