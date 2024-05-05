#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "merge_sort.h"

int main(int argc, char *argv[]) {
    int size = argc-1;
    int arr[size];
    for (int i = 0; i < size; i++) {
        arr[i] = atoi(argv[i + 1]);
    }
    int m = size / 2;
    pid_t pid = fork();
    if (pid == 0) {
        mergeSort(arr, 0, m - 1);
        exit(0);
    } else {
        mergeSort(arr, m, size - 1);
        wait(NULL);
        merge(arr, 0, m - 1, size - 1);
    }
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
