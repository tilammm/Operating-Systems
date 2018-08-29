#include <stdio.h>

void swap(int *a, int *b)
{
int temp;
temp = *b;
*b = *a;
*a = temp;   
}

 
int main()
{
int x, y;
scanf("%d, %d",&x,&y);
swap(&x, &y); 
printf("%d, %d", x, y);
return 0;
}
 
 