//programmer name:sharvil Prabhudesai 
//program title: process synchronisation using semaphore
#include<stdio.h>
#include<stdlib.h>
#define buffer_size 5
int mutex=1,full=0,empty=5,in=0,out=0;
int buffer[buffer_size];
void wait(int s);
void  signal(int s );
void consumer();
void producer();
int main()
{
	int choice ;
	printf("process "
	printf("\n producer/consumer problem \n\n");
	do
	{
	printf("\n\n1.producer     2.consumer     3.exit");	
	printf("\nenter your choice :");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: producer();
				break;
		case 2:consumer();
				break;
		case 3:break;
		
		default: printf("invalid input\n\n");
				 break; 
	}
}while(choice!=3);
	  return 0;
  }			 
void producer()
{
	wait(empty);
	wait(mutex);
	int next_produced;
	if(((in+1)%buffer_size)==out)
	{
		printf("storage is full\n\n");
	}
		else
		{
			
			printf("enter a item to produced::");
			scanf("%d",&next_produced);
			buffer[in]=next_produced;
			in=(in+1)%buffer_size;
			
			printf("item produced is: %d",next_produced);
		}
		signal(mutex);
		signal(full);
		}
	
void consumer()
	{
		wait(full);
		wait(mutex);
		int next_consumed;
		if(in==out)
		{
			printf("storage is empty\n\n");
		}
		else 
		{	
			next_consumed=buffer[out];
			out=(out+1)%buffer_size;
			printf("item consumed  is: %d",next_consumed);
		}
		
		
		signal(mutex);
		signal(empty);
		
		
	}	
void signal(int s)
{
	s++;
}



void wait(int s)
{
	while(s<0)
	{
		printf("cannot add an item\n\n");
		exit(0);
	}
	s--;
}
