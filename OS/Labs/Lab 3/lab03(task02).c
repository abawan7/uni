#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int arr[10];
    int i, temp;

    if(argc != 11) {
        printf("Please enter 10 integers as command line arguments.\n");
        return 1;
    }

    for(i = 0; i < 10; i++) {
        arr[i] = atoi(argv[i + 1]);
    }

    pid_t child1, child2;

    child1 = fork();

    if(child1 == 0) {
        printf("I am Child 1 (with ID = %d and Parent’s ID = %d): ", getpid(), getppid());

        for (int a = 0; a < 9; a++) {
            for (int b = a + 1; b < 10; b++) {
                if (arr[a] > arr[b]) {
                    temp = arr[a];
                    arr[a] = arr[b];
                    arr[b] = temp;
                }
            }
        }

        for(int i = 0; i < 10; i++) {
            printf("%d ", arr[i]);
        }

        printf("\n");
        exit(0);
    } else {
        child2 = fork();

        if(child2 == 0) { // Child 2
            printf("I am Child 2 (with ID = %d and Parent’s ID = %d): ", getpid(), getppid());

            for (int a = 0; a < 9; a++) {
                for (int b = a + 1; b < 10; b++) {
                    if (arr[a] < arr[b]) {
                        temp = arr[a];
                        arr[a] = arr[b];
                        arr[b] = temp;
                    }
                }
            }

            for(int i = 0; i < 10; i++) {
                printf("%d ", arr[i]);
            }

            printf("\n");
            exit(0);
        } else {
            wait(NULL);
            wait(NULL);

            printf("Parent Process terminating and my ID = %d and parent’s ID = %d\n", getpid(), getppid());
        }
    }

    return 0;
}
