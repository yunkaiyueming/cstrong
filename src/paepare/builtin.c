/**
 * 
 * __LINE__  当前程序行的行号，表示为十进制整型常量
__FILE__  当前源文件名，表示字符串型常量
__DATE__转换的日历日期，表示为Mmm dd yyyy 形式的字符串常量，Mmm是由asctime产生的。
__TIME__ 转换的时间，表示"hh:mm:ss"形式的字符串型常量，是有asctime产生的。（asctime貌似是指的一个函数）
__STDC__ 编辑器为ISO兼容实现时位十进制整型常量
__STDC_VERSION__ 如何实现复合C89整部1，则这个宏的值为19940SL；如果实现符合C99，则这个宏的值为199901L；否则数值是未定义
__STDC_EOBTED__ (C99)实现为宿主实现时为1,实现为独立实现为0
__STDC_IEC_559__ (C99)浮点数实现复合IBC 60559标准时定义为1，否者数值是未定义
__STDC_IEC_559_COMPLEX__ (C99)复数运算实现复合IBC 60559标准时定义为1，否者数值是未定义
__STDC_ISO_10646__ (C99)定义为长整型常量，yyyymmL表示wchar_t值复合ISO 10646标准及其指定年月的修订补充，否则数值未定义
**/

#include <stdio.h>
int main(){
    printf("%d \n", __LINE__);
    printf("%s \n", __FILE__);
    printf("%s \n", __DATE__);
    printf("%s \n", __TIME__);
    return 0;
}