#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int *arr;
void *worker(void *terms) {
  int N = *(int *)terms;
  arr[0] = 0;
  arr[1] = 1;
  int i;
  for (i = 2; i < N; i++) {
    arr[i] = arr[i - 1] + arr[i - 2];
  }

  return (int *)arr;
}
int main(int argc, char *argv[]) {
  int terms = atoi(argv[1]);
  arr = malloc(terms * sizeof(int));
  pthread_t thread;
  pthread_create(&thread, NULL, worker, &terms);
  pthread_join(thread, NULL);
  int i;
  printf("the fibonacci sequence is : ");
  for (i = 0; i < terms; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}
