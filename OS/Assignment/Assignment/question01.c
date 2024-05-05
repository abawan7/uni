#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
  char command[50];
  int count = 0;
  char amper = '&';
  bool check = false;
  pid_t pid;
  char *token;
  printf("Input a command : ");
  scanf("%[^\n]%*c", command);
  token = strtok(command, " ");
  while (token != NULL) {
    count++;
    token = strtok(NULL, " ");
  }
  char *p[10];
  p[0] = strtok(command, " ");
  while (strcmp(p[0], "exit") != 0) {

    int i = 0;
    int z = 0;
    while (p[z] != NULL) {
      z++;
      p[z] = strtok(NULL, " ");
    }
    p[z + 1] = NULL;
    pid = fork();
    if (pid >= 1) {
      wait(NULL);
    } else {
      execvp(p[0], p);
    }
    printf("Input a command : ");
    scanf("%[^\n]%*c", command);
    char *p[10];
    p[0] = strtok(command, " ");
  }

  return 0;
}