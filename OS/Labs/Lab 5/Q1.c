#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    int fd[2];
    pid_t childPid;
    pipe(fd);
    childPid = fork();
    char temp[1024];
    int bytesRead;
    char *msg = "Hi There";
    if (childPid == 0) {
        close(fd[1]);
        bytesRead = read(fd[0], temp, sizeof(temp) - 1);
        temp[bytesRead] = '\0';
        for (int i = 0; i < bytesRead; i++) {
            if ('a' <= temp[i] && temp[i] <= 'z') {
                temp[i] = temp[i] - 32;
            } else if ('A' <= temp[i] && temp[i] <= 'Z') {
                temp[i] = temp[i] + 32;
            }
        }
        printf("Child Process: %s \n", temp);
        exit(0);
    } else { 
        close(fd[0]);
        write(fd[1], msg, strlen(msg));
        printf("Parent Process: %s \n", msg);
        close(fd[1]);
        wait(NULL);
    }

    return 0;
}
