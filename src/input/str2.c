#include <stdio.h>

int var1 = 'd';
int var2 = '2';
int var3 = 't';
int var4 = ' ';

int main(){
if (isalpha(var1))
{
    printf("var1 = |%c| 是一个字母n", var1);
}
else
{
    printf("var1 = |%c| 不是一个字母n", var1);
}
if (isalpha(var2))
{
    printf("var2 = |%c| 是一个字母n", var2);
}
else
{
    printf("var2 = |%c| 不是一个字母n", var2);
}
if (isalpha(var3))
{
    printf("var3 = |%c| 是一个字母n", var3);
}
else
{
    printf("var3 = |%c| 不是一个字母n", var3);
}
if (isalpha(var4))
{
    printf("var4 = |%c| 是一个字母n", var4);
}
else
{
    printf("var4 = |%c| 不是一个字母n", var4);
}

return (0);
}