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

    while (1) {
        int count = 1;
        pid_t pid;
        int i;
        char command[50];
        printf("Input a command : ");
        scanf("%[^\n]%*c", command);
        for (i = 0; command[i] != '\0'; i++) {
            if (command[i] == ' ') {
                count++;
            }
        }
        count++;
        char *p[count];
        p[0] = strtok(command, " ");
        if (strcmp(p[0], "exit") != 0) {
            int z = 0;
            while (p[z] != NULL) {
                z++;
                p[z] = strtok(NULL, " ");
            }
            p[z + 1] = NULL;
            if (strcmp(p[0], "cd") == 0) {
                chdir(p[1]);
            }
            pid = fork();
            if (pid > 0) {
                wait(NULL);
            } else {
                execvp(p[0], p);
            }
        }
        else
        {
            break;
        }
    }

    return 0;
}