#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<stdbool.h>

int main(){

    FILE *input;
    FILE *output;
    char buff[100];

    input = fopen("argv[0]", "r");
	output = fopen("argv[1]", "w+");

    bool flag=true;
	while (!feof(input))
	{
		fscanf(input,"%s",buff);
		int i=0;
		while (buff[i]!='\0')
		{
			if((buff[i]>=65 && buff[i]<=90) || (buff[i]>=97 && buff[i]<=122))
			{
				flag=true;
			}
			else 
			{
				flag=false;
			}
			i++;
		}
		
		if (flag==false)
		{
			fputs(buff, input);
		}
	}
	
	fclose(input);
	fclose(output);
    
    return 0;
}