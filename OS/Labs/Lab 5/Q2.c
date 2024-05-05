#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int fd1[2], fd2[2],Sum = 0;;
    pipe(fd1);
    pipe(fd2);
    pid_t childPid;
    childPid = fork();
    int array[] = {1, 5, 7, 2, 15}; 
    int num_elements = sizeof(array) / sizeof(array[0]);
    int size = sizeof(int) * num_elements;
    if (childPid == 0) { 
        close(fd1[1]);
        close(fd2[0]);
        int temp[num_elements];
        read(fd1[0], temp, size);
        printf("Received Array Is: ");
        for (int i = 0; i < num_elements; i++) {
            printf("%d ", temp[i]);
            Sum += temp[i];
        }
        write(fd2[1], &Sum, sizeof(int));
        close(fd1[0]);
        close(fd2[1]);
        exit(0);
    } else { 
        close(fd1[0]);
        close(fd2[1]);
        write(fd1[1], array, size);
        close(fd1[1]);
        read(fd2[0], &Sum, sizeof(int));
        printf("\nThe sum of the array is: %d\n", Sum);
    }

    return 0;
}
