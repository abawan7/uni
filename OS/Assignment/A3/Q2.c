#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int buffer;
sem_t S1; 
sem_t S2; 
sem_t S3; 
void* producer(void* arg) {
    for(int i = 1; i <= 100; i++) {
        sem_wait(&S3);
        sem_wait(&S1);
        buffer = i;
        sem_post(&S1); 
        sem_post(&S2);
    }
    return NULL;
}

void* consumer(void* arg) {
    for(int i = 1; i <= 100; i++) {
        sem_wait(&S2); 
        sem_wait(&S1); 
        printf("Consumed: %d\n", buffer); 
        sem_post(&S1); 
        sem_post(&S3);
    }
    return NULL;
}

int main() {
    pthread_t prod_thread, cons_thread;
    
    sem_init(&S1, 0, 1); 
    sem_init(&S2, 0, 0); 
    sem_init(&S3, 0, 1); 

    pthread_create(&prod_thread, NULL, producer, NULL);
    pthread_create(&cons_thread, NULL, consumer, NULL);

    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);

    return 0;
}
