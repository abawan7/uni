#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
  int fd1[2];
  int fd2[2];
  pid_t child;
  int n = atoi(argv[1]);
  int i, x;
  x = pipe(fd1);
  x = pipe(fd2);
  while (n != 1) {
    child = fork();
    if (child >= 1) {
      x = write(fd1[1], &n, sizeof(int));
      wait(NULL);
      x = read(fd2[0], &n, sizeof(int));
    } else if (child == 0) {
      x = read(fd1[0], &n, sizeof(int));
      if (n % 2 == 0) {
        n = n / 2;
        printf("%d ", n);
      } else {
        n = n * 3 + 1;
        printf("%d ", n);
      }
      x = write(fd2[1], &n, sizeof(int));
      return 0;
    }
  }
}
