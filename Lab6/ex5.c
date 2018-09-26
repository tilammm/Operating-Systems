#include <stdio.h>

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

static int received = 0;

void readUsual(int sig)
{
    if (sig == SIGTERM)
    {
        received = 1;
    }
}

int main()
{
    signal(SIGUSR1,readUsual);

    pid_t pid2 = fork();
    if (pid2==0)
    {
              while(!received){
                    printf("%s", "I'm alive\n");
                    sleep(1);
                    
                }

    }
    else
    {
		sleep(10);
        kill(0,SIGTERM);
    }

}