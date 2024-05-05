#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])

{
  int i;
  int sum = 0;
  int fd = open("myfifo", O_RDONLY);
  int arr[5];
  read(fd, arr, sizeof(arr));
  for (i = 0; i < 5; i++) {
    sum = sum + arr[i];
  }
  close(fd);
  fd = open("myfifo", O_WRONLY);
  write(fd, &sum, sizeof(int));
  close(fd);
  return 0;
}
