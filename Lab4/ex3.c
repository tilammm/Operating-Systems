#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define TRUE 1
void type_prompt() {
  printf("> ");
}
void read_command(char *command) {
   scanf("%s", command);
}
int main(void) {
   char command[10];
   while (TRUE) {
   type_prompt();
   read_command(command);
   system(command);
 }
}
