#define _OPEN_THREADS
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


void *func(void* arg)
{   pthread_t this_thr;
    this_thr = pthread_self();
    int *N;
    N = (int*)arg;
    printf("Thread number %ls \n", N);
    pthread_cancel(this_thr);    
    return NULL;
}


void main() {
    int N;
    scanf("%d", &N);
    pthread_t main_thr;
    main_thr = pthread_self();

    for (int i = 0; i < N; i++){
            int *arg = malloc(sizeof(*arg));
            *arg = i+1;
            if (pthread_create(&main_thr, NULL, func, arg) == 0){
                printf ("Thread has created \n");
            }

    }


}
