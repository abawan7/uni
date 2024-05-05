#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        printf("Child PID: %d\n", getpid());
    } else {
        printf("Parent's Child PID: %d\n", pid);
    }
    return 0;
}
