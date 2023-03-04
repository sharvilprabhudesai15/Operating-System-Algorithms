//Programmer Name: Sharvil Prabhudesai 20co41
//Program title : Deadlock Detection
#include<stdio.h>
int allocation[10][10],request[10][10],available[10];
int work[10],finish[10];
int i,j,n,m,k;

void input(){
	printf("Enter the Number of Processes : ");
	scanf("%d",&n);
	printf("Enter the Number of Resource Instances : ");
	scanf("%d",&m);
	printf("Enter the Allocation Matrix : \n");
	//Allocation matrix input
	for(i=0;i<n ; i++){
		for(j=0;j<m ;j++){
			scanf("%d",&allocation[i][j]);
		}
	}
	//Request matrixc input
	printf("Enter the Request Matrix : \n");
	for(i=0;i<n ; i++){
		for(j=0;j<m ;j++){
			scanf("%d",&request[i][j]);
		}
	}
	//Available Vector Input
	printf("Enter the Available Vector : \n");
	for(i=0;i<m ;i++){
			scanf("%d",&available[i]);
	}	
}

void display() {
    int i, j;
    printf("Process\t\t Allocation\tRequest\t\t Available");
    for (i = 0; i < n; i++) {
        printf("\nP%d\t\t ", i + 1);
        for (j = 0; j < m; j++) {
            printf("%d ", allocation[i][j]);
        }
        printf("\t\t");
        for (j = 0; j < m; j++) {
            printf("%d ", request[i][j]);
        }
        
        printf("\t\t  ");
        if (i == 0) {
            for (j = 0; j < m; j++)
                printf("%d ", available[j]);
        }
    }
}

void deadlock_detection(){
	int flag;
	//Making finish[i] = false , ie 0 for all i=0,1,...,n-1
	for(i=0;i<n ;i++){
			finish[i]=0;
	}
	//Initialising Work =available 
	for(i=0;i<m ;i++){
			work[i]=available[i];
	}
	for(j=0;j<3;j++){
		for(i=0;i<n;i++){
			flag=1;
			if(finish[i]==0){
				for(k=0;k<m;k++){
					if(request[i][k]>work[k]){
						flag=0;
						break;
					}
				}
				if(flag==1){
					finish[i]=1;
					 for(k=0;k<m;k++){
						work[k] = work[k] + allocation[i][k];
					}					
				}
			}
		}
	}
	
	flag=1;					// flag used to check if all finish of i == true
	for(i=0;i<n ;i++){
		if(finish[i]==0)
		{
			flag=0;
		}
	}
	if(flag==0){
		printf("\n\nSystem is in Deadlock state	!");
	}
	else{
		printf("\n\nSystem is not in Deadlock state	!");
	}
}


int main(){
	printf("Deadlock Detection \n\n");
	input();
	display();
	deadlock_detection();
	return 0;
	
}

