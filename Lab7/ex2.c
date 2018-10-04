#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, *ptr;


    scanf("%d", &N);

    ptr = (int*) malloc(N * sizeof(int));  

    for(i = 0; i < N; ++i)
    {
        *(ptr + i) = i;
    }
    for (i = 0; i < N; ++i)
    {
       printf ("%d\n", *(ptr + i)); 
    }
    free(ptr);
    

    
    return 0;
}