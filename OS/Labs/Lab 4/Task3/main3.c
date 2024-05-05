# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>

int main ()
{
printf("%s", "Parent process \n");
printf("%d", getpid());
printf( " \n" );

if (fork()==0)
{

char *args[]={"./fib.out" ,"9",NULL};

printf("%s", "Child process \n");
printf("%d", getpid());
printf( " \n" );

execv(args[0],args);
}




}
