#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *reallocation(void *ptr,size_t size) {
    void *newptr;
    if ( ptr == NULL){
        free (ptr);
        newptr = malloc(size);
        return newptr;
    }
    if (size == 0){
        free(ptr);
        return ptr;
    }
    newptr = malloc(size);
    memcpy(newptr, ptr, sizeof(newptr));
    free(ptr);
    return newptr;
}

int main() {
	printf("Enter original array size:");
	int n1=0;
	scanf("%d",&n1);
	int* a1 = (int*) calloc(n1, sizeof(int));
	int i;
	for(i=0; i<n1; i++){
		*(a1 + i)=100;
		printf("%d ",*(a1 + i) );
	}
	printf("\nEnter new array size: ");
	int n2=0;
	scanf("%d",&n2);
	a1 = reallocation(a1, n2);
    if (n2 > n1){
        for (i = n1; i < n2; i++){
            *(a1 + i) = 0;
        }
	}


	for(i=0; i<n2;i++){
		printf("%d ",*(a1 + i));
	}
	printf("\n");


	return 0;
}