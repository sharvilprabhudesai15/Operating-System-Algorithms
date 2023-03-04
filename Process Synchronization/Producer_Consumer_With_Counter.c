//programmer name:sharvil Prabhudesai 
//program title: process synchronisation using semaphore

#include<stdio.h>
#include<stdlib.h>
int buffer_size;
int mutex=1,full=0,empty,in=0,out=0;
int counter=0;


int buffer[100];
void wait(int s);
void  signal(int s );
void consumer();
void producer();
int main()
{
	printf("PROCESS SYNCHRONISATION USING SEMAPHORE\n");
	printf("producer/consumer problem \n\n");
	printf("enter the buffer size:");
	scanf("%d",&buffer_size);
	empty=buffer_size;
	int choice;
	do
	{
	printf("\n1.producer     2.consumer     3.exit");	
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
	if(counter==buffer_size)
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
			counter++;
		}	
		signal(mutex);
		signal(full);
		
		}
	
	
	
	void consumer()
	{
		wait(full);
		wait(mutex);
		int next_consumed;
		if(counter==0)
		{
			printf("storage is empty\n\n");
		}
		else 
		{	
			next_consumed=buffer[out];
			out=(out+1)%buffer_size;
			printf("item consumed  is: %d",next_consumed);
			counter--;
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
			
