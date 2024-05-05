#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc,char*argv[])

{
  char newstr[100];
  int i;
  int fd = open("myfifo", O_RDONLY);
  read(fd, newstr, 100);

  for (i = 0; newstr[i] != '\0'; i++) {
    if (newstr[i] >= 'A' && newstr[i] <= 'Z') {
      newstr[i] = newstr[i] + 32;
    } else if (newstr[i] >= 'a' && newstr[i] <= 'z') {
      newstr[i] = newstr[i] - 32;
    }
  }
  close(fd);
  fd = open("myfifo", O_WRONLY);
  write(fd, newstr, strlen(newstr) + 1);
  close(fd);
  return 0;
}