#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <unistd.h>
int main(int argc,char *argv[])
{
    printf("process id in main.c: %d\n", getpid());
    char *args[]={"",NULL};
    execv("./info",args);
    return 0;
}
