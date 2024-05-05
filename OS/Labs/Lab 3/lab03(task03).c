#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    for (int i = 0; i < n; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            printf("Child's PID: %d, Parent's PID: %d\n", getpid(), getppid());
            if (i == n - 1) {
                exit(0);
            }
        } else {
            wait(NULL); 
            exit(0);
        }
    }
    return 0;
}
