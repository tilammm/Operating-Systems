#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void main()
{
  char string[] = "Hello, world!\n";
  char second[100];
  int fd[2];

  pipe(fd);

  if(fork()) {
    close(fd[0]);
    write(fd[1], string, sizeof(string));
  } else {
    close(fd[1]);
    read(fd[0], second, sizeof(second));
    close(fd[0]);
    printf("%s", string);
    printf("%s", second);
  }
}
