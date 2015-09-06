#include<stdio.h>
int main()
{
int n,i,j,check,q;
float avgw,avgt;
printf("Enter the no of processes : ");
scanf("%d",&n);
int bt[n],temp[n],wt[n],tat[n];
for(i=0;i<n;i++)
{
printf("Enter burst time : ");
scanf("%d",&bt[i]);
}
printf("Enter time quantum : ");
scanf("%d",&q);
for(i=0;i<n;i++)
{
temp[i]=bt[i];
wt[i]=0;
}
start:
check=0;
for(i=0;i<n;i++)
{
if(temp[i]==0)
check++;
}
if(check==n)
goto last;
else
{
for(i=0;i<n;i++)
{
if(temp[i]-q>0)
{
for(j=0;j<n;j++)
{
if(j!=i)
{
if(temp[j]!=0)
wt[j]=wt[j]+q;
}
}
temp[i]=temp[i]-q;
}
else
{
for(j=0;j<n;j++)
{
if(j!=i)
{
if(temp[j]!=0)
wt[j]=wt[j]+temp[i];
}
}
temp[i]=temp[i]-temp[i];
}
}
goto start;
}
last:
for(i=0;i<n;i++)
{
tat[i]=bt[i]+wt[i];
avgt+=tat[i];
avgw+=wt[i];
}
avgw=avgw/n;
avgt=avgt/n;
printf("\nBurst Time\tWaiting Time\tTurn Around Time\n\n");
for(i=0;i<n;i++)
printf("%d\t\t%d\t\t%d\n",bt[i],wt[i],tat[i]);
printf("\nAverage Waiting Time = %f",avgw);
printf("\nAverage Turn Around Time = %f\n",avgt);
return 0;
}
