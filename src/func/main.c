#include <stdio.h>
#include "total.h"

void main(){
    int ret;
    ret = add(20,8);
    printf("%d \n",ret);

    ret = sub(20,8);
    printf("%d \n",ret);

    ret = sum(20,8);
    printf("%d \n",ret);
}
