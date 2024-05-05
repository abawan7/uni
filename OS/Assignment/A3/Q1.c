#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
sem_t S1;
int turn=1;
void* factorial(void* n) {
	
    int fact = 1;
    int *N = (int*) n;
    int i;
    for ( i = 1; i <= N[0]; i++) {
        fact=fact*i;
    }
    while(1)
    {
    	sem_wait(&S1);
    	if(turn==N[0])
    	{
		printf("Thread [%d] : [%d]\n", *N, fact);
		turn++;
		sem_post(&S1);
   		break;
    	}
    	
    }
    
    sem_post(&S1);
}

int main(int argc, char* argv[]) {
	sem_init(&S1, 0, 1);
    int n = atoi(argv[1]);
    pthread_t threadID[n];
    int i;
    for ( i = 1; i <= n; i++) {
        int* arg = malloc(sizeof(int));
        *arg = i;
        pthread_create(&threadID[i-1], NULL, factorial, arg);
        pthread_join(threadID[i-1], NULL);
    }
    return 0;
}

/* gcc -o Q1 Q1.c
./Q1 5 */