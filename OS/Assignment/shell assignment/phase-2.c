
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
  int s=0;
  int flag=1;
  int count=0;
  char arr[100];
  char *tokenarr[100];
  int size_of_hist_arr = 10;
  char *history[size_of_hist_arr];
  int commands = 0;
  int i = 0;
  pid_t pid;
  while (1) {
    fgets(arr, 100, stdin);
    for (i = 0; arr[i] != '\0'; i++) {
      s++;
      if (arr[i] == '&') {
        s = s - 2;
        flag = 1;
      }
      if (arr[i] == ' ') {
        count++;
      }
    }
    if (flag != 1) {
      count++;
    }
    int j = 1;
    //printing the history of commands
    if (strcmp(arr, "history\n") == 0) {
      if (commands == 0) {
        printf("there are no commands in the history\n");
      } else {
        for (i = commands - 1; i >= 0; i--) {
          printf("%d-%s", i + 1, history[i]);
        }
      }
    }
    // executing the most recent command
    else if (strcmp(arr, "!!\n") == 0) {
      if (commands == 0) {
        printf("there are no commands in the history\n");
      } else {
        char *command = history[commands - 1];
        char *token = strtok(command, " ");
        tokenarr[0] = token;
        while (token != NULL) {
          token = strtok(NULL, " ");
          tokenarr[j] = token;
          j++;
        }
        tokenarr[j] = NULL;
        pid = fork();
        if (pid >= 1) {
          wait(NULL);
        } else if (pid == 0) {
          execvp(tokenarr[0], tokenarr);
        } else {
          printf("failed to execute process\n");
        }
      }
    } 
    //executing Nth command
    else if (arr[0] == '!' && arr[1] >= '1' && arr[1] <= '9') {
      if (commands == 0) {
        printf("there are no commands in the history\n");
      } else {
        int index = atoi(&arr[1]);
        char *command = history[index - 1];
        printf("%s", command);
        char *token = strtok(command, " ");
        tokenarr[0] = token;
        while (token != NULL) {
          token = strtok(NULL, " ");
          tokenarr[j] = token;
          j++;
        }
        tokenarr[j] = NULL;
        pid = fork();
        if (pid >= 1) {
          wait(NULL);
        } else if (pid == 0) {
          execvp(tokenarr[0], tokenarr);
        } else {
          printf("failed to execute process\n");
        }
      }

    } 
    else  if (strcmp(arr, "exit\n") == 0)
    {
      break;
    }
    //adding the new command to history and executing it
    else {
      
      if (size_of_hist_arr == commands) {
        free(history[0]);
        for (i = 1; i < size_of_hist_arr; i++) {
          history[i - 1] = history[i];
        }
        commands--;
      }
      history[commands++] = strdup(arr);

      int count = 0;
    int s = 0;
       int flag;
      char *token = strtok(arr, " ");
      tokenarr[0] = token;
      while (token != NULL) {
        token = strtok(NULL, " ");
        tokenarr[j] = token;
        j++;
      }
      tokenarr[j] = NULL;
      pid = fork();
      if (pid >= 1) {
        if(flag!=1)
        {
          wait(NULL);
        }
        
      } else if (pid == 0) {
        execvp(tokenarr[0], tokenarr);
      } else {
        printf("failed to execute process\n");
      }
    } 
  }
  return 0;
}
