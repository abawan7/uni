#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
    char *arr[5];
    arr[0] = argv[1];
    arr[1] = argv[2];
    arr[2] = argv[3];
    arr[3] = argv[4];
    arr[4] = NULL;

    int f1 = open(arr[2], O_RDONLY);
    dup2(f1, 0);
    int f2 = open(arr[4], O_WRONLY);
    dup2(f2, 1);

    execvp(arr[0], arr);

    return 0;
}