#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int num = atoi(argv[1]);
    char temp[20],arg[20];
    sprintf(arg, "%d", num);
    int pipefd[2],s;
    pipe(pipefd);
    if (fork() == 0) {
        dup2(pipefd[1], STDOUT_FILENO);
        char *args[] = {"./square", arg, NULL};
        execv(args[0], args);
    } else {
        read(pipefd[0], temp, sizeof(temp));
        s = atoi(temp);
        printf("The square of %d is: %d\n", num, s);
    }
    return 0;
}
