# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>

int main()
{
pid_t a =fork();
pid_t b =fork();

if (a ==0 && b == 0)
{
	int x= execlp("mkdir","mkdir","Demo_Folder",NULL);
	exit(0);
}	
else if( a == 0 && b > 0)
	
{ 
	pid_t c = wait(NULL);	
	int y= execlp("touch","touch","Demo_Folder/File1.txt","Demo_Folder/File2.txt",NULL);
	exit(0);
}	

else if (b == 0 && a > 1)
{	
	pid_t d = wait(NULL);	
	int f= execlp("cd","Demo_Folder",NULL);
	int z= execlp("ls","-1",NULL);
	exit(0);
}
else if (a > 1 && b > 1)
{
	pid_t e = wait(NULL);	
	
	exit(0);
}
	
	return 0;
}
