#include <stdio.h>
#include <signal.h>

void sighandler(int signum)
{
    printf("捕获信号 %d，跳出...\n", signum);
}

void sayhandler(int msg)
{
    printf("捕获信号 %d，say hello \n", msg);
}

void main()
{
    signal(SIGINT, sighandler);
    raise(2);

    signal(SIGILL, sayhandler);
    raise(4);
}