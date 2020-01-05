#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    char src[40];
    char dest[100];

    memset(dest, '\0', sizeof (dest));
    strcpy(src, "This is string.cc");
    strcpy(dest, src);

    printf("最终的目标字符串： %s\n", dest);

    char s = 'a';
    if(isalnum(s)>0){
        printf("true");
    }

    abort();
    exit(2);
    printf("abort end");
    
    return (0);
}