#include<stdio.h>
#include<stdlib.h>
#include "headers.h"
#include<stdbool.h>
int main(int argc,char *argv[])
{
int array[argc-3];
int i,j=0;
for(i=1;i<argc-2;i++)
{
array[j]=atoi(argv[i]);
j++;
}
bool order=atoi(argv[argc-2]);
int pos=atoi(argv[argc-1]);
sort(array,order,pos,argc-3);
print(array,argc-3);
findhighest(array,pos,argc-3);
return 0;
}
