#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    char operator[2];
    char operand1[10], operand2[10];
    char send_buffer[50], receive_buffer[50];
    int fd1, fd2;

    mkfifo("myfifo", 0666);
    scanf("%s %s %s", operator, operand1, operand2);
    snprintf(send_buffer, sizeof(send_buffer), "%s %s %s", operator, operand1, operand2);

    fd1 = open("myfifo", O_WRONLY);
    write(fd1, send_buffer, strlen(send_buffer)+1);
    close(fd1);
    sleep(3);
    fd2 = open("myfifo", O_RDONLY);
    read(fd2, receive_buffer, sizeof(receive_buffer));
    close(fd2);

    printf("Result: %s\n", receive_buffer);

    return 0;
}
