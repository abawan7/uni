#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
    int f1 = open(argv[1], O_RDONLY);
    char buffer[400];
    dup2(f1, 0);
    int f2 = open("output.txt", O_WRONLY);
    dup2(f2, 1);
    printf("%s", buffer);

    return 0;
}