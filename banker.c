#include<stdio.h>
int n,r;
int matcheck(int need[n][r],int i,int avail[r])
{
int j;
for(j=0;j<r;j++)
{
if(need[i][j]>avail[j])
return 0;
}
return 1;
}
int main()
{
int i,j;
printf("Enter the no. of processes : ");
scanf("%d",&n);
printf("Enter the no. of resource types : ");
scanf("%d",&r);
int alloc[n][r],max[n][r],need[n][r];
int avail[r];
int finish[n],fintemp[n];
int count,check;
for(i=0;i<n;i++)
finish[i]=0;
printf("Enter the value of the allocated matrix : \n");
for(i=0;i<n;i++)
for(j=0;j<r;j++)
scanf("%d",&alloc[i][j]);
printf("Enter the value of the max resource matrix : \n");
for(i=0;i<n;i++)
for(j=0;j<r;j++)
scanf("%d",&max[i][j]);
for(i=0;i<n;i++)
for(j=0;j<r;j++)
need[i][j]=max[i][j]-alloc[i][j];
printf("Enter the available resource vector : \n");
for(i=0;i<r;i++)
scanf("%d",&avail[i]);
printf("\nThe Need Matrix\n");
for(i=0;i<n;i++)
{
printf("P%d  ",i);
for(j=0;j<r;j++)
printf("%d ",need[i][j]);
printf("\n");
}
//Checking Begins
do
{
check=0,count=0;
for(i=0;i<n;i++)
fintemp[i]=finish[i];
for(i=0;i<n;i++)
{
if(finish[i]==0)
{
if(matcheck(need,i,avail))
{
printf("\nProcess %d finishes",i);
for(j=0;j<r;j++)
{
avail[j]+=alloc[i][j];
need[i][j]=0;
finish[i]=1;
}
}
}
}
for(i=0;i<n;i++)
{
if(finish[i]==fintemp[i])
count++;
}
if(count==n)
check=1;
}while(check!=1);
count=0;
for(i=0;i<n;i++)
{
if(finish[i]==1)
count++;
}
if(count==n)
printf("\nSAFE State\n");
else
printf("\nUNSAFE State\n");
return 0;
}
