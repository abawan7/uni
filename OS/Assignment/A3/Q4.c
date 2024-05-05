#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
sem_t S1;
int counter=0;
void* worker()
{
	int i;
	for(i=0;i<100;i++)
	{
		sem_wait(&S1);
		++counter;
		sem_post(&S1);
	}
	
}
int main(int argc,char*argv[])
{
sem_init(&S1,0,1);

pthread_t thread1;
pthread_t thread2;

pthread_create(&thread1,NULL,worker,NULL);
pthread_create(&thread2,NULL,worker,NULL);

pthread_join(thread1,NULL);
pthread_join(thread2,NULL);
printf("counter value is : %d",counter);
printf("\n");

return 0;

}

