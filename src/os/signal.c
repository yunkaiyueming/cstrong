#include <stdio.h>
#include <signal.h>

void sighandler(int signum){
   printf("捕获信号 %d，跳出...n", signum);
}

void main(){
    signal(SIGINT, sighandler);
    raise(2);
}