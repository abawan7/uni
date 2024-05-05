#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char *copied_file = argv[1];
    char *output_file = argv[2];
    char buffer[50];
    int fd[2];
    pipe(fd);
    pid_t child = fork();
    int n;
    if (child > 0) {
        close(fd[0]);
        int a = open(copied_file, O_RDONLY);
        n = read(a, buffer, 50);
        printf("[Parent: %d] - size of content to send: %d\n", getpid(), n);
        printf("content to send : %s\n", buffer);

        write(fd[1], &n, sizeof(int));
        write(fd[1], buffer, n);
        close(fd[1]);
    } else if (child == 0) {
        int a = open(output_file, O_WRONLY);
        read(fd[0], &n, sizeof(int));
        n = read(fd[0], buffer, n);
        printf("[Child: %d] - size of content to receive: %d\n", getpid(), n);
        write(a, buffer, n);
        printf("content to receive : %s\n", buffer);
        close(fd[0]);
    } else {
        printf("error\n");
    }
    return 0;
}