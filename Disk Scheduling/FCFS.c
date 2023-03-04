//Programmer Name: Sharvil Prabhudesai 20co41
//Program title : FCFS
#include <stdio.h>
#include<stdlib.h>
int i,n,a[50],head;

void input(){
    printf("Enter the size of the request array : ");
    scanf("%d",&n);
    printf("Enter the Request array : \n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
	
	printf("\nEnter the Current Head Position : ");
    scanf("%d",&head);
    printf("\n");
}

void FCFS()
{
	int TotalHeadMovement = 0;
	int distance, cur_track;

	for (i = 0; i < n; i++) {
		cur_track = a[i];
		distance = abs(cur_track - head);
		TotalHeadMovement = TotalHeadMovement + distance;
		head = cur_track;
	}

	printf("Total Disk Head Movement is : %d \n",TotalHeadMovement);

	printf("Sequence in which request is scheduled is : \n");

	for (int i = 0; i < n; i++) {
		printf("%d ",a[i]);
	}
}


int main()
{
    printf("\nFCFS Disk Scheduling \n\n");  
    input();
	FCFS();
	return 0;
}
