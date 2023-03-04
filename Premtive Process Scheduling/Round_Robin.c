//Programmer Name: Sharvil Prabhudesai 20co41
//Program title : Round Robin
#include<stdio.h>
int main()
{ 	int i,t=0,bt[10],wt[10],tt[10],rem_bt[10],n,ts,p[10];
	int  c;
	float awt=0,att=0;
	printf("Round Robin\n\n");
	printf("enter the number of processes :");
	scanf("%d",&n);
	printf("enter the burst time for %d process \n",n);
	for(i=1;i<=n;i++){
		p[i]=i;
		scanf("%d",&bt[i]);
		rem_bt[i]=bt[i];
	}
	printf("\n enter the time slice:");
	scanf("%d",&ts);

	while(1) {
		c=1;
		for(i=1;i<=n;i++){
			if(rem_bt[i]>0){
				c=0;
				if(rem_bt[i]>ts){
					t=t+ts;
					rem_bt[i]=rem_bt[i]-ts;
 
				}
				else{
					t=t+rem_bt[i];
					rem_bt[i]=0;
					wt[i]=t-bt[i];
				}
			}
		}
		if(c==1)
			break;
	}


	for(i=1;i<=n;i++){
		tt[i]=wt[i]+bt[i];
		awt=awt+wt[i];
		att=att+tt[i];
	}


	printf("_________________________________________________________\n");
	printf("| Process | Burst Time | Waiting Time | Turnaround time |\n");
	printf("_________________________________________________________\n");
	for(i=1 ; i<=n ; i++){
		printf("| %d\t  |%3d\t\t | %3d\t\t | %3d\t\t | \n",p[i],bt[i],wt[i],tt[i]);
	}
	printf("_________________________________________________________");
	printf("\naverage waiting time: %f \n average turn around time:%f",(awt/n),(att/n));

	return 0;
}

