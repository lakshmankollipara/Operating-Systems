#include<stdio.h>
int main()
{
int p,i,j,prior[10],burst[10],burst1[10],wait=0,turn=0,sum=0,sum1=0,avg=0,avg1=0;
printf("enter the number of processes\n");
scanf("%d",&p);
printf("enter the burst time for %d processes\n",p);
for(i=0;i<p;i++)
{
scanf("%d",&burst[i]);
}
printf("enter the priorities of %d processes",p);
for(i=0;i<p;i++)
{
scanf("%d",&prior[i]);
}
for(i=0;i<p;i++)
{
for(j=i+1;j<p;j++)
{
if(prior[i]>prior[j])
{
burst1[i]=burst[i];
burst[i]=burst[j];
burst[j]=burst1[i];
}
}
}
printf("waiting time for 1 process is \n");
printf("%d\n",wait);
printf("turn around time for 1 process is \n");
printf("%d\n",burst[0]);
for(i=0;i!=(p-1);i++)
{
wait=wait+burst[i];
turn=wait+burst[i+1];
printf("waiting time for %d  process is \n",i+2);
printf("%d\n",wait);
sum=sum+wait;
printf("the turn around time for %d process is \n",i+2);
printf("%d\n",turn);
sum1=sum1+turn;
}
avg=sum/p;
avg1=(burst[0]+sum1)/p;
printf("the average waiting time is %d\n",avg);
printf("the average turn around time is %d\n",avg1);
}
