#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void main() {
    int n = 1;

    pid_t pid1 = getpid();

    fork();

    pid_t pid2 = getpid();

    if (pid1 == pid2) {
        printf("Hello from parent [%d - %d]\n", pid1, n);
    } else {
        printf("Hello from child [%d - %d]\n", pid2, n);
    }


}
