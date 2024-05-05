#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

#define PHILOSOPHERS 5
sem_t table;
void *philosopher(void *num) {
    long id = (long)num;
    long left_fork = id;
    long right_fork = (id + 1) % PHILOSOPHERS;

    while(1) {
        printf("Philosopher %ld is hungry and tries picking up forks %ld and %ld.\n", id + 1, left_fork + 1, right_fork + 1);
        sem_wait(&table);
        printf("Philosopher %ld picked up fork %ld.\n", id + 1, left_fork + 1);
        printf("Philosopher %ld picked up fork %ld.\n", id + 1, right_fork + 1);
        printf("Philosopher %ld is eating.\n", id + 1);
        sleep(1);
        printf("Philosopher %ld put down fork %ld.\n", id + 1, left_fork + 1);
        printf("Philosopher %ld put down fork %ld.\n", id + 1, right_fork + 1);
        sem_post(&table); // Release access to the table
        printf("Philosopher %ld is thinking.\n", id + 1);
        sleep(1); // Thinking
    }
}

int main() {
    pthread_t phil[PHILOSOPHERS];
    sem_init(&table, 0, PHILOSOPHERS - 1); // Initialize semaphore

    for(long i = 0; i < PHILOSOPHERS; i++) {
        pthread_create(&phil[i], NULL, philosopher, (void*)i);
    }

    for(int i = 0; i < PHILOSOPHERS; i++) {
        pthread_join(phil[i], NULL);
    }
    return 0;
}
