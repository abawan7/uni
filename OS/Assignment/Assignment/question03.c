#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
  struct timeval starttime, endtime;
  double e, s;
  pid_t pid;
  gettimeofday(&starttime, NULL);
  s = starttime.tv_usec;
  pid = fork();
  if (pid == 0) {
    execvp(argv[1], &argv[1]);
  } else if (pid >= 1) {
    wait(NULL);
    gettimeofday(&endtime, NULL);
    e = endtime.tv_usec;
  } else {
    printf("failed to create child process\n");
  }
  double elapsed_time;
  elapsed_time = e - s;
  elapsed_time=elapsed_time/10000;
  printf("The Time elapsed is : %f\n", elapsed_time);
  return 0;
}
