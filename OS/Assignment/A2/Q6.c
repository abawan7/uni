#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main() {
    char food_ready[] = "Food is ready";
    char order[] = "Order";
    char temp[100];
    int pipefd1[2],pipefd2[2];
    pid_t pid_cook = fork();
    if (pid_cook == 0) {
        read(pipefd2[0], temp, sizeof(temp));
        printf("Cook received: %s\n", temp);
        write(pipefd1[1], food_ready, sizeof(food_ready));
        exit(0);
    }
    pid_t pid_customer = fork();
    if (pid_customer == 0) {
        write(pipefd2[1], order, sizeof(order));
        read(pipefd1[0], temp, sizeof(temp));
        printf("Customer received: %s\n", temp);
        exit(0);
    }
    wait(NULL);
    wait(NULL);
    return 0;
}
