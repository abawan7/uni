#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int n;
int sum = 0;
int avg = 0;
int max = 0;
int min = 0;
void *worker1(void *a) {
  int *N = (int *)a;
  int j;
  for (j = 0; j < n; j++) {
    sum = sum + N[j];
  }
  avg = sum / n;
  pthread_exit(a);
}
void *worker2(void *a) {
  int *N = (int *)a;
  min = N[0];
  int j;
  for (j = 1; j < n; j++) {
    if (N[j] < min) {
      min = N[j];
    }
  }
  pthread_exit(a);
}
void *worker3(void *a) {
  int *N = (int *)a;
  max = N[0];
  int j;
  for (j = 1; j < n; j++) {
    if (N[j] > max) {
      max = N[j];
    }
  }
  pthread_exit(a);
}
int main(int argc, char *argv[]) {
  n = argc - 1;
  int arr[n];
  int i;
  for (i = 0; i < n; i++) {
    arr[i] = atoi(argv[i + 1]);
  }
  pthread_t thread1;
  pthread_t thread2;
  pthread_t thread3;
  pthread_create(&thread1, NULL, worker1, &arr);
  pthread_create(&thread2, NULL, worker2, &arr);
  pthread_create(&thread3, NULL, worker3, &arr);
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  pthread_join(thread3, NULL);
  printf("The average  is %d\n", avg);
  printf("The minimum value is %d\n", min);
  printf("The maximum value is %d\n", max);
  return 0;
}
