#include<stdio.h>
struct process
{
int pno;
float bt,wt,tat;
}p[10];

int main()
{
float wait=0;
float turn=0;
float sum=0;
int n,i;
float awt,atat;
printf("enter the tot num of processors ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\nproccess num and burst time ");
scanf("%d%f",&p[i].pno,&p[i].bt);
}
for(i=0;i<n;i++)
{p[i].wt=wait;
p[i].tat=p[i].wt+p[i].bt;
wait=wait+p[i].bt;
turn=turn+p[i].wt;
sum=sum+p[i].tat;
}
awt=turn/n;
printf("\naverage waiting time:%f",awt);
atat=wait/n;
printf("\naverage turn over time:%f\n",atat);
}

