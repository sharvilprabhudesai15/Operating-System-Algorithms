//Programmer Name: Sharvil Prabhudesai 20co41
//Program Title : To implement First come first serve without arrival time. 

#include<stdio.h>

int main()
{
	int i,j,n ;
	
	printf("FIRST COME FIRST SERVE WITHOUT ARRIVAL\n\n");
	printf("Enter Number of Processes : ");
	scanf("%d",&n);
	
	int p[n];	
	int bt[n];		
	int wt[n];		
	int tt[n];
	
	float avg_tt=0;
	float avg_wt=0;

	
	for(i=0 ; i < n ; i++){
		p[i]=i+1;
		
		printf("Enter the Burst time of Process P%d : ",p[i]);
		scanf("%d",&bt[i]);
		
	}
	printf("\n\n");
	
	wt[0] = 0;		//need to be initialised because of formula 
	tt[0]=bt[0];
	
	avg_wt+=wt[0];
	avg_tt+=tt[0];
	
	for(i=1 ; i < n ; i++){
		wt[i]=wt[i-1] + bt[i-1];
		tt[i]=tt[i-1]+bt[i];
		
		avg_wt+=wt[i];
		avg_tt+=tt[i];
	}
	printf("\n\n");
	
	printf("_________________________________________________________\n");
	printf("| Process | Burst Time | Waiting Time | Turnaround time |\n");
	printf("_________________________________________________________\n");
	for(i=0 ; i < n ; i++){
	printf("|   %d     |   %3d      |       %3d    |      %3d        | \n",p[i],bt[i],wt[i],tt[i]);
	}
	printf("_________________________________________________________");
	printf("\nAverage Waiting Time = %f",(avg_wt)/n);
	printf("\nAverage Waiting Time = %f",(avg_tt)/n);
	
	
	printf("\n\nGANTT CHART ");
	printf("\n\n");
	// print top bar
    printf(" ");
    for(i=0; i<n; i++) {
        for(j=0; j<bt[i]; j++){
			 printf("--");
        }
        printf(" ");
    }
    printf("\n|");
 
    // printing process id in the middle
    for(i=0; i<n; i++) {
        for(j=0; j<bt[i]- 1; j++){
			 printf(" ");
        }
        printf(" %d",p[i]);
        for(j=0; j<bt[i] - 1; j++) {
			printf(" ");
        }
        printf("|");
    }
    printf("\n ");
    // printing bottom bar
    for(i=0; i<n; i++) {
        for(j=0; j<bt[i]; j++) {
			printf("--");
        }
        printf(" ");
    }
    printf("\n");
 
    // printing the time line
    printf("0");
    for(i=0; i<n; i++) {
        for(j=0; j<bt[i]; j++){
			 printf("  ");
		}
        if(tt[i] > 9) {
			printf("\b"); // backspace : remove 1 space
		}
        printf("%d", tt[i]);
 
    }
    printf("\n");
	
	return 0;
}

