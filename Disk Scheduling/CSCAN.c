//Programmer Name: Sharvil Prabhudesai 20co41
//Program title : CSCAN
#include<stdio.h>
#include<stdlib.h>
int array[25],n,head,i,j,k,TotalHeadMovement=0, maxrange,difference,temp,array1[20],array2[20],temp1=0,temp2=0;

void input(){ 
    printf("Enter the maximum range of Disk: ");
    scanf("%d",&maxrange);
    printf("Enter the number of array requests: ");
    scanf("%d",&n);
    printf("Enter the initial head position: ");
    scanf("%d",&head);
    printf("Sequence in which request is scheduled is : ");
    for(i=1;i<=n;i++)      {
        scanf("%d",&temp);  
        if(temp>head)        {
            array1[temp1]=temp; //temp1 is the index variable of array1[]
            temp1++; //incrementing temp1
        }
        else   {   
            array2[temp2]=temp; //temp2 is the index variable of array2[]
            temp2++;
        }
    }  
}

void CSCAN() {
    for(i=0;i<temp1-1;i++)    {
        for(j=i+1;j<temp1;j++)   {
            if(array1[i]>array1[j])    {
                temp=array1[i];
                array1[i]=array1[j];
                array1[j]=temp;
            }
        }
    }
    
    for(i=0;i<temp2-1;i++)  {
        for(j=i+1;j<temp2;j++) {
            if(array2[i]>array2[j]) {
                temp=array2[i];
                array2[i]=array2[j];
                array2[j]=temp;
            }
        }
    }    
    for(i=1,j=0;j<temp1;i++,j++) {
        array[i]=array1[j]; 
    }
    array[i]=maxrange;
    array1[i+1]=0;
    for(i=temp1+3,j=0;j<temp2;i++,j++) {
        array[i]=array2[j];
    }
    array[0]=head;
    for(j=0; j<=n+1; j++) {   
        difference = abs(array[j+1]-array[j]);
        TotalHeadMovement = TotalHeadMovement + difference;
    }

    printf("Sequence in which request is scheduled is : ");
     for(j=1; j<=n+2; j++) {   
        printf("%d ", array[j]);
    }
    printf("\nTotal Disk Head Movement : %d \n", TotalHeadMovement);
}

int main()
{
    printf("\nCSCAN Disk Scheduling \n\n");  
    input();
    CSCAN();
    return 0;
}

