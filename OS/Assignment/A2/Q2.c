#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int acc_holder = argc - 1;
    int balance[acc_holder];
    for(int i = 0; i < acc_holder; i++) {
        balance[i] = atoi(argv[i+1]);
    }
    int choice, amount;
    for (int i = 0; i < acc_holder; ++i) {
        pid_t pid = fork();
        if (pid == 0) {
            while (1) {
                printf("\nWelcome Account Holder %d\n", i+1);
                printf("1. Deposit Money\n");
                printf("2. Withdraw Money\n");
                printf("3. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                if (choice == 1) {
                    printf("Enter amount to deposit: ");
                    scanf("%d", &amount);
                    balance[i] += amount;
                    printf("Deposited RS%d. New Balance is RS%d.\n", amount, balance[i]);
                } else if (choice == 2) {
                    printf("Enter amount to withdraw: ");
                    scanf("%d", &amount);
                    if (amount > balance[i]) {
                        printf("Insufficient funds. Current balance is RS%d.\n", balance[i]);
                    } else {
                        balance[i] -= amount;
                        printf("Withdrew RS%d. New Balance is RS%d.\n", amount, balance[i]);
                    }
                } else if (choice == 3) {
                    exit(0);
                }
            }
        } else if (pid > 0){
            wait(NULL);
        }
    }

    return 0;
}
