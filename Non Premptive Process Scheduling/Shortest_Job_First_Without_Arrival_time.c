//Programmer Name: Sharvil Prabhudesai 20co41
//Program Title : To implement Shortest Job first without arrival time. 

#include<stdio.h>
int main ()
{
	int n,i,j,l,t;
	printf("SHORTEST JOB FIRST WITHOUT ARRIVAL\n\n");
	printf("Enter the number of processes:");
	scanf("%d",&n);
	int bt[n],wt[n],tt[n];
	float awt=0,att=0;
	int btt;
	int p[n];
	for(i=0;i<n;i++)
{ 		p[i]=i+1;
		printf("enter the burst time for Process P%d : ",p[i]);
		scanf("%d",&bt[i]);
		btt=btt+bt[i];
}



//using bubbble sort
for(i=0;i<n;i++)
{
for (j = 0; j < n - i - 1; j++)
{   if (bt[j] >bt[j + 1])
    		{   t=bt[j];
    		     bt[j]=bt[j+1];
    		     bt[j+1]=t;
       		     l=p[j];
      		     p[j]=p[j+1];
     		     p[j+1]=l;
	  	}
	}
}
		
	wt[0]=0,tt[0]=bt[0];
	for(i=1;i<n;i++)
	{
		wt[i]=wt[i-1]+bt[i-1];
		awt=awt+wt[i];
	}
	for(i=1;i<n;i++)
	{
		tt[i]=tt[i-1]+bt[i];
		att=att+tt[i];
		
	}
	printf("_____________________________________________________________________\n");
	printf("Process\t |  Burst time\t | waiting time\t | turnaround time|\n");
	printf("_____________________________________________________________________\n");
		for(i=0;i<n;i++)
	{
		printf("%d\t | %d\t\t | %d\t\t | %d\t\t  |\n",p[i],bt[i],wt[i],tt[i]);
	}
	printf("___________________________________________________________\n");
	printf("\nAverage Waiting time = %f\n",(awt/n));
	printf("\nAverage Turnaround time = %f",(att+tt[0])/n);
	
	
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
        printf(" %d", p[i]);
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
