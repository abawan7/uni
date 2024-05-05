# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>

int main (int argc, char *argv[])
{

	char* arg=argv[1];
	
	printf("\nPassed argument: ");
	printf("%s",(arg) );
	printf("\n");
	
	int ans = atoi(arg);
	printf("\nInteger after conversion: %d", ans);	
	printf("\n");

	int i, n;

	int t1 = 0, t2 = 1;
	int nextTerm = t1 + t2;

//store argv 1 into n but as int
	n=ans;
	
	printf("Fibonacci Series: %d, %d, ", t1, t2);
	for (i = 3; i <= n; ++i) 
		{
			printf("%d, ", nextTerm);
			t1 = t2;
			t2 = nextTerm;
			nextTerm = t1 + t2;
		}

return 0;
}
