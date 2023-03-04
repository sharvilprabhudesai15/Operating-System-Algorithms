//Programmer Name: Sharvil Prabhudesai 20co41
//Program Title : To implement First come first serve with arrival time. 
#include <stdio.h>
#include <stdlib.h>

int process[20];
int priority[20];
int bt[20];
int at[20];
int wt[20];
int tt[20];
int n;
void fcfsArrival();
void sort();
void ganttChart();
void display();

int main()
{

printf("FIRST COME FIRST SERVE WITH ARRIVAL\n\n");
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter following process details:");
    int i;
    for (i = 0; i < n; i++)
    {
        printf("\nEnter arrival time of P%d : ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter burst time of P%d : ", i + 1);
        scanf("%d", &bt[i]);
        process[i] = i;
    }

    sort();
    fcfsArrival();
    ganttChart();
    display();

    return 0;
}

void fcfsArrival()
{
    int i;
    int time = 0;
    for (i = 0; i < n; i++)
    {
        if (at[process[i]] <= time)
        {
            wt[process[i]] = time - at[process[i]];
            tt[process[i]] = wt[process[i]] + bt[process[i]];
            time = time + bt[process[i]];
        }
        else
        {
            wt[process[i]] = 0;
            tt[process[i]] = bt[process[i]];
            time = at[process[i]] + bt[process[i]];
        }
    }
}

void sort()
{
    int j;
    int i;
    for (i = 1; i < n; i++)
    {
        for (j = 1; j < n; j++)
        {
            if (at[process[j]] < at[process[j - 1]])
            {
                int temp = process[j];
                process[j] = process[j - 1];
                process[j - 1] = temp;
            }
        }
    }
}

void ganttChart()
{
    printf("\nGantt chart is as follows:\n\n|");
    int i;
    int time = 0;
    for (i = 0; i < n; i++)
    {
        if (at[process[i]] <= time)
        {
            printf(" P%d |", process[i] + 1);
            time = time + bt[process[i]];
        }
        else
        {
            printf(" - |");
            time = at[process[i]];
            i--;
        }
    }
    printf("\n");
    time = 0;
    for (i = 0; i < n; i++)
    {
        if (at[process[i]] <= time)
        {
            printf("%d   ", time);
            time = time + bt[process[i]];
        }
        else
        {
            printf("%d   ", time);
            time = at[process[i]];
            i--;
        }
    }
    printf("%d\n\n", time);
}

void display()
{
    int i;
    float awt = 0;
    float att = 0;
    printf("The details of processes are as follows:\n\n");
    printf("Process   Arrival Time   Burst Time   Waiting Time   Turnaround Time\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d \t\t%d \t\t%d \t\t%d\t    %d\n", i + 1, at[i], bt[i], wt[i], tt[i]);
        awt = awt + wt[i];
        att = att + tt[i];
    }
    printf("\n\nAWT = %0.2f \nATT = %0.2f", (awt / n), (att / n));
}
