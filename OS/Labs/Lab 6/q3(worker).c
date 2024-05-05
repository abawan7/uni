#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    char operator;
    int operand1, operand2;
    char receive_buffer[50], send_buffer[50];
    int fd1, fd2;

    while(1) {
        fd1 = open("myfifo", O_RDONLY);
        read(fd1, receive_buffer, sizeof(receive_buffer));
        close(fd1);
        sscanf(receive_buffer, " %c %d %d", &operator, &operand1, &operand2);

        int result;
        switch(operator) {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                if (operand2 != 0) {
                    result = operand1 / operand2;
                } else {
                    printf("Error: Division by zero.\n");
                    continue;
                }
                break;
            default:
                printf("Error: Invalid operator.\n");
                continue;
        }
        snprintf(send_buffer, sizeof(send_buffer), "%d", result);
        fd2 = open("myfifo", O_WRONLY);
        write(fd2, send_buffer, strlen(send_buffer)+1);
        close(fd2);
    }

    return 0;
}
