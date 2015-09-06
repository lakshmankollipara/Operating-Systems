#include<sys/shm.h>
#include<sys/ipc.h>
#include<stdio.h>
int bufid,*buf,turn;
int flag[2];
char ch;
main()
{
bufid= shmget(50,1,IPC_CREAT|0777);
buf= shmat(bufid,NULL,NULL);
*buf=0;
flag[0]=flag[1]=0;
if(fork()==0)
{
suspend();
}
else 
{if((fork)==0)

pl();
else
p2();
}
}
suspend()
{
while(1)
{
ch=getchar();
if(ch=='q')
{
system("killall a.out");
}}}
p1()
{
int x=0;
while(1)
{
sleep(1);
flag[0]=0;
turn=1;
while((turn==1)&&(flag[1]));
(*buf)++;
x++;
flag[0]=0;
printf("shared vm %d ",&*buf);
printf("non shared vm %d",x);
}
}
p2()
{
int x=0;
while(1)
{
sleep(1);
flag[1]=0;
turn=1;
while((turn==1)&&(flag[0]));
(*buf)++;
x++;
flag[1]=0;
printf("shared vm %d ",&*buf);
printf("non shared vm %d",x);
}}
