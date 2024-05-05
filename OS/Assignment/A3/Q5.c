#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
sem_t S1;
int balance=1000;
void* worker(void*arg)
{
	int* id = (int*)arg;
	int i;
	for(i=0;i<5;i++)
	{
		sem_wait(&S1);
		balance=balance-200;
		printf("Thread [%d] subtracted 200$ : New balance = $%d\n", *id, balance);
		sem_post(&S1);
	}
	
}
int main(int argc,char*argv[])
{
sem_init(&S1,0,1);
int id[]={1,2,3};
pthread_t threadA;
pthread_t threadB;
pthread_t threadC;

pthread_create(&threadA,NULL,worker,&id[0]);
pthread_create(&threadB,NULL,worker,&id[1]);
pthread_create(&threadC,NULL,worker,&id[2]);

pthread_join(threadA,NULL);
pthread_join(threadB,NULL);
pthread_join(threadC,NULL);
printf("Current Balance is : %d$",balance);
printf("\n");

return 0;

}

