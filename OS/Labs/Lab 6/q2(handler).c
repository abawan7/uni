#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#define PIPE_PERM (S_IRUSR | S_IWUSR)
int main(int argc, char *argv[]) {
  int sum;
  mkfifo("myfifo", 0777);
  int arr[5] = {1, 2, 3, 4, 5};
  int fd = open("myfifo", O_WRONLY);
  write(fd, arr, sizeof(arr));
  sleep(3);
  fd = open("myfifo", O_RDONLY);
  read(fd, &sum, sizeof(int));
  printf("sum of array : %d\n", sum);
  close(fd);
  unlink("myfifo");
  return 0;
}
