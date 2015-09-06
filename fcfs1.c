#include <stdio.h>
struct process
{
int id,arrival,burst;
};
void sort(struct process *a,int n)
{
int i,j,t;
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(a[j].arrival<a[i].arrival)
{
t=a[i].arrival;
a[i].arrival=a[j].arrival;
a[j].arrival=t;
}
}
}
}
int turnaround(struct process *a,int n)
{
int i,turn=0;
for(i=0;i<=n;i++)
{
turn=turn+a[i].burst;
}
i--;
turn=turn-a[i].arrival;
return(turn);
}
int time(struct process *a,int n)
{
int i,av=0;
for(i=0;i<n;i++)
{
av=av+a[i].burst;
}
av=av-a[i].arrival;
return(av);
}
void print(struct process *a,int n)
{
int i,j;
printf("Process\tArrival time\tCPU Burst\n");
for(i=0;i<n;i++)
{
j=i+1;
printf("  %d\t  %d\t\t    %d\n",j,a[i].arrival,a[i].burst);
}
}
int main()
{
int i,n,j,t,av=0;
float avg;
printf("Enter the no of process=");
scanf("%d",&n);
struct process p[n];
for(i=0;i<n;i++)
{
j=i+1;
printf("For %d process:\n",j);
printf("Arrival time=");
scanf("%d",&p[i].arrival);
printf("CPU Burst time=");
scanf("%d",&p[i].burst);
}
sort(p,n);
print(p,n);
for(i=0;i<n;i++)
{
j=turnaround(p,i);
printf("Turnaround time=%d\n",j);
}
for(i=0;i<n;i++)
{
av=av+time(p,i);
}
avg=(float)av/n;
printf("Average waiting time=%f\n",avg);
}
