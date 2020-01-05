#include <ctype.h>
#include <stdio.h>

void main(){
    int data1 = '2';
    int data2 = 't';
    
    if(isdigit(data1)){
        printf("num true \n","1");
    }else{
        printf("num false \n","2");
    }
    
    if(isdigit(data2)){
        printf("num true");
    }else{
        printf("num false");
    }
}