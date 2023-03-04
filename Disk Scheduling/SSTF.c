//Programmer Name: Sharvil Prabhudesai 20co41
//Program title : SSTF
#include <stdio.h>
#include <stdlib.h>
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

void SSTF(){
    int TotalHeadMoment = 0, count = 0;
    printf("Sequence in which request is scheduled is : ");
    while (count != n){
        int min = 1000, d, index;
        for (i = 0; i < n; i++){
            d = abs(a[i] - head);
            if (min > d){
                min = d;
                index = i;
            }
        }
        printf("%d ", a[index]);
        TotalHeadMoment = TotalHeadMoment + min;
        head = a[index];
        a[index] = 9999;    
        count++;
    }
    printf("\n\nTotal head movement is %d \n", TotalHeadMoment);
}

int main() {
    printf("\nSSTF Disk Scheduling \n\n");  
    input();
	SSTF();
	return 0;
}
