#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
int main(int argc,char*argv[]){
    FILE *input;
	FILE *output;
	char ch;
	input = fopen(argv[1], "r");
	output = fopen(argv[2], "w+");
	do{
	ch=fgetc(input);
	if(ch>=48&&ch<=57)
	{
	fputc(ch,output);
	}
	}while(ch!=EOF);
	fclose (input);
	fclose (output);
	
	return 0;
}
