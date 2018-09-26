#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
void funct() {
    printf("%s", "SIGINT signal \n");
    exit(0);
}

void main()
{
    signal(SIGINT, funct);
    while(1){
        
    }
        
}