#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
int bufid,*buf,turn;
int flag[2];
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
p1()
{
int x=0;
while(1)
{
sleep(1);
flag[0]=1;
turn=1;
while((turn==1)&&(flag[1]));
(*buf)++;
x++;
flag[0]=0;
printf("\n value of shared varaible in p1 is %d\n",*buf);
printf("\n value of non shared variable in p1 is %d\n",x);
}
}
p2()
{
int x=0;
while(1)
{
sleep(1);
flag[1]=1;
turn=0;
while((turn==0)&&(flag[0]));
(*buf)++;
x++;
flag[1]=0;
printf("\n value of shared variable in p2 is %d\n",*buf);
printf("\n value of non shared variable in p2 is %d\n",x);
}
}
main()
{
bufid=shmget(50,1,IPC_CREAT|0777);
buf=shmat(bufid,NULL,NULL);
*buf=0;
flag[0]=0;
flag[1]=0;
if(fork()==0)
{
suspend();
}
else{
if(fork()==0)
p1();
else
p2();
}
}

