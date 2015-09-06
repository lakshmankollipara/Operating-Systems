#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
int bufid,*buf;
int lock=0,waiting[10];
char ch;
suspend()
{
while(1)
{
ch=getchar();
if(ch=='q')
{
system("killall a.out");
}
}
}
process(int i,int n)
{
int x=0;
int key,j;
while(1)
{
sleep(1);
waiting[i]=1;
key=1;
while(waiting[i] && key)
key=testandset(lock);
waiting[i]=0;
(*buf)++;
x++;
j=(i+1)%n;
while(j!=i && !waiting[j])
j=(j+1)%n;
if(i==j)
lock=0;
else
waiting[j]=0;
printf("\nValue of shared variable in process %d is %d\n",i,*buf);
printf("\nValue of non-shared variable in process %d is %d\n",i,x);
}
}
int testandset(int lock)
{
int temp;
temp=lock;
lock=1;
return temp;
}
main()
{
int n,i;
bufid=shmget(15,1,IPC_CREAT | 0777);
buf=shmat(bufid,NULL,NULL);
*buf=0;
printf("\nEnter no of processes : ");
scanf("%d",&n);
if(fork()==0)
{
suspend();
}
else
{
for(i=0;i<n;i++)
{
if(fork()==0)
process(i,n);
else
continue;
}
}
}
