#include <stdio.h>
#include <limits.h>
#include <float.h>
int main() {
 int a;
 float b;
 double c;
 a = INT_MAX;
 b = FLT_MAX;
 c = DBL_MAX;
 printf( "%d, %f, %f, %ld, %ld, %ld\n", a, b, c, sizeof(a), sizeof(b), sizeof(c));
 return 0;
}