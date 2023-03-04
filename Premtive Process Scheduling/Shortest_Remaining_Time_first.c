//Programmer Name: Sharvil Prabhudesai 20co41
//Program title : Shortst remaining time first
#include<stdio.h>
int main()
{	int i,t=0,bt[20],wt[20],tt[20],rem_bt[20],n,p[20],at[20],ft=0,small;
	int  count=0;
	float awt=0,att=0;
	printf("Shortst remaining time first\n\n");
	printf("enter the number of processes :");
	scanf("%d",&n);
	printf("enter the burst time and arrival time  for %d process \n",n);
	for(i=1;i<=n;i++){ 
		p[i]=i;
		printf("enter the burst time for process for process %d : ",i);
		scanf("%d",&bt[i]);
		printf("enter the arrival time for process for process %d :",i);
		scanf("%d",&at[i]);
		rem_bt[i]=bt[i];
	}
	rem_bt[9]=999;


	for(t=0;count!=n;t++){
		small=9;
		for(i=1;i<=n;i++){
			if(at[i]<=t && rem_bt[i]<rem_bt[small]   && rem_bt[i]>0 ){
				small=i;
			}
		}
		rem_bt[small]--;
		if(rem_bt[small]==0){
			count++;
			ft=t+1;
			wt[small]=ft-bt[small]-at[small];
			awt=awt+wt[small];
			tt[small]=wt[small]+bt[small];
			att=att+tt[small];
		}
	}


		printf("_________________________________________________________\n");
		printf("| Process | Burst Time | Waiting Time | Turnaround time |\n");
		printf("_________________________________________________________\n");
		for(i=1 ; i<=n ; i++)
		{
		printf("| %d\t  |%3d\t\t | %3d\t\t | %3d\t\t | \n",p[i],bt[i],wt[i],tt[i]);
		}
		printf("_________________________________________________________");
		printf("\naverage waiting time: %f \n average turn around time:%f",(awt/n),(att/n));
		return 0;
}

