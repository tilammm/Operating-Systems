#include <stdio.h>
#include <string.h> 
int main()
{
   char s[1000];
   int begin, count = 0;
   fgets(s, sizeof(s), stdin);
   count = strlen(s);
 
   for (begin = count-1; begin >= 0; begin--) {
      printf("%c", s[begin]);
 
   }
   return 0;
}