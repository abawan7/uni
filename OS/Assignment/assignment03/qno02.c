#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void *worker(void *n) {
  int N = *(int *)n;
  int i;
  int j;
  bool flag = true;
  if (N <= 1) {
    printf("there are no prime numbers uptill this number\n");
  } else {
    printf("the prime numbers are : ");
    for (i = 2; i <= N; i++) {
      for (j = 2; j < i; j++) {
        if (i % j == 0) {
          flag = false;
        }
      }
      if (flag == true) {
        printf("%d ", i);
      } else {
        flag = true;
      }
    }
  }

  pthread_exit(NULL);
}
int main(int argc, char *argv[]) {
  int n = atoi(argv[1]);
  pthread_t thread;
  pthread_create(&thread, NULL, worker, &n);
  pthread_join(thread,NULL);
  return 0;
}
