#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int start = atoi(argv[1]);
    int end = atoi(argv[2]);
    int isPrime;
    pid_t pid = fork();
    if (pid == 0) {
        for (int i = start; i <= end; i++) {
            if (i <= 1) {
                continue;
            }
            isPrime = 1;
            for (int j = 2; j <= i / 2; j++) {
                if (i % j == 0) {
                    isPrime = 0;
                    break;
                }
            }
            if (isPrime) {
                printf("%d ", i);
            }
        }
        exit(0);
    } else {
        wait(NULL);
    }

    return 0;
}
