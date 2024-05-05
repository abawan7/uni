#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
sem_t S1;
sem_t S2;
sem_t S3;
void *worker1() {
  sem_wait(&S1);
  int i;
  for (i = 0; i < 3; i++) {
    printf("a");
  }
  sem_post(&S3);
}
void *worker2() {
  sem_wait(&S2);
  printf("b");
  sem_post(&S1);
}
void *worker3() {
  sem_wait(&S3);
  printf("c");
  sem_post(&S2);
}
int main(int argc, char *argv[]) {
  sem_init(&S1, 0, 1);
  sem_init(&S2, 0, 0);
  sem_init(&S3, 0, 0);

  pthread_t thread1;
  pthread_t thread2;
  pthread_t thread3;

  int n = 10;
  while (n > 0) {
    int a = 3;
    while (a > 0) {
      pthread_create(&thread1, NULL, worker1, NULL);
      pthread_create(&thread2, NULL, worker2, NULL);
      pthread_create(&thread3, NULL, worker3, NULL);

      pthread_join(thread1, NULL);
      pthread_join(thread2, NULL);
      pthread_join(thread3, NULL);
      a--;
    }
    printf("\n");

    n--;
  }
  return 0;
}