#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char*argv[])
{
	char ch;
	FILE *input=fopen(argv[1],"r");
	if(input==NULL)
	{
	printf("file not found\n");
	}
	else
	printf("File opened successfully!\n");
	
	do{
		ch = fgetc(input);
		printf("%c", ch);
	}while(ch!=EOF);
	
	fclose(input);
    return 0;
}
