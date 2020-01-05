#include <stdio.h>
#include <math.h>
#include <signal.h>

#define PI 3.14159265

int main()
{
    double x, ret, val;

    x = 45.0;
    val = PI / 180;
    ret = sin(x * val);
    printf("%lf 的正弦是 %lf 度 \n", x, ret);
    printf("%lf \n", pow(2, 10));
    printf("%lf \n", fabs(2 - 5));
    printf("%lf \n", floor(2.541535));//不大于 x 的最大整数值。
    printf("%lf \n", ceil(2.541535));//不小于 x 的最小整数值。
 
 
    printf("%d \n", SIG_DFL);
    printf("%d \n",SIG_ERR);
    return (0);
}