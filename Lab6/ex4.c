#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
void funct(int signo) {
    if (signo == SIGUSR1)
        printf("Received SIGUSR1\n");
    else if (signo == SIGKILL)
        printf("Received SIGKILL\n");
    else if (signo == SIGSTOP)
        printf("Received SIGSTOP\n");
}

void main()
{
    if (signal(SIGUSR1, funct) == SIG_ERR)
        printf("Can't catch SIGUSR1\n");
    if (signal(SIGKILL, funct) == SIG_ERR)
        printf("Can't catch SIGKILL\n");
    if (signal(SIGSTOP, funct) == SIG_ERR)
        printf("Can't catch SIGSTOP\n");
    while(1){

    }

}