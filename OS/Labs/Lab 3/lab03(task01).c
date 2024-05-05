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

    pid_t child;
    child = fork();
    if(child < 0) {
        printf("Child process not created\n");
    } else if(child == 0) {
        for (int a = 0; a < 9; ++a) {
            for (int b = a + 1; b < 10; ++b) {
                if (arr[a] > arr[b]) {
                    temp = arr[a];
                    arr[a] = arr[b];
                    arr[b] = temp;
                }
            }
        }

        printf("Child ID: %d\n", getpid());
        printf("Array in ascending order is: ");
        for(int i = 0; i < 10; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        wait(NULL);
        printf("I am the parent with ID: %d\n", getpid());
    }

    return 0;
}
