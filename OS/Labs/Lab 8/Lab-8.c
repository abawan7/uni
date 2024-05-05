#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int lap = 0;
int numOfLaps, lapTimeLimit;
int hours = 0, minutes = 0, seconds = 0, lapSeconds = 0;
void calculatetotaltime(int sig_num) {
  if (sig_num == SIGCHLD) {
    printf("received SIGCHLD\n");
    printf("Total Time in Seconds : %d\n", lapTimeLimit * numOfLaps);
  }
}
int main() {
  pid_t parentID = getpid();
  int STATE = 1;

  printf("Enter Number of Laps: ");
  scanf("%d", &numOfLaps);
  printf("Enter Each Lap Time: ");
  scanf("%d", &lapTimeLimit);
  if (signal(SIGCHLD, calculatetotaltime) == SIG_ERR) {
    printf("couldn't catch signal\n");
  }
  pid_t pid = fork();
  if (pid == 0) {
    printf("Child 1 with ID: %d\n", getpid());
    while (STATE) {
      seconds++;
      lapSeconds++;
      if (seconds == lapTimeLimit) {
        lap++;
        printf("Lap %d completed\n", lap);
        seconds = 0;
      }
      if (lap == numOfLaps) {
        STATE=0;
        exit(0);
      }
    }

  } else {
    wait(NULL);
  }
  return 0;
}