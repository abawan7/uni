#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/time.h>
#include<sys/wait.h>
#include<ctype.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#define PIPE_PERM (S_IRUSR | S_IWUSR)
int main(int argc,char*argv[])
{
  mkfifo("myfifo", 0777);
  char str[11]={"hello there"};
  int fd=open("myfifo", O_WRONLY);
  write(fd,str,11);
  close(fd);
  sleep(3);
  fd = open("myfifo", O_RDONLY);
  char arr[11];
  read(fd,&arr,11);
  printf("opposite cased-message : %s",arr);
  close(fd);
  unlink("myfifo");
  return 0;
}