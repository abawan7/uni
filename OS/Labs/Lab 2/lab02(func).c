#include<stdio.h>
#include<stdbool.h>
void sort(int array[],bool order,int position,int size)
{
int i,j,temp;
if(order==1)
{
for(i=0;i<size;i++)
{
for(j=i+1;j<size;j++)
{
if(array[i]>array[j])
{
temp=array[i];
array[i]=array[j];
array[j]=temp;
}
}
}
}
if(order==0)
{
for(i=0;i<size;i++)
{
for(j=i+1;j<size;j++)
{
if(array[i]<array[j])
{
temp=array[i];
array[i]=array[j];
array[j]=temp;
}
}
}
}
}
void findhighest(int array[],int position,int size)
{
sort(array,true,position,size);
int highest=array[position-1];
printf("highest is : %d\n",highest);
}
void print(int array[],int size)
{
printf("sorted array is : ");
int i;
for(i=0;i<size;i++)
{
printf("%d  ",array[i]);
}
}
