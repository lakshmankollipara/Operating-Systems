#define size 10
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<stdio.h>
#include<stdlib.h>
int obtain_shm(int key,int s)
{
return shmget(key,s,IPC_CREAT|0777);
}
void *shm_at(int id)
{
shmat(id,0,0);
}
int *buf,buf_id,i;
int in=0,out=0;
char ch;
create()
{
buf=shm_at(buf_id);
for(i=0;i<10;i++)
{
buf[in]=rand()%100;
printf("\n %d produced \n",buf[in]);
in=(in+1);
}
}
producer()
{
buf=shm_at(buf_id);
sleep(1);
while(1)
{
sleep(1);
buf[in]=rand()%100;
printf("\n %d produced \n",buf[out]);
in=(in+1)%size;
}
}
consumer()
{
buf=shm_at(buf_id);
while(1)
{
sleep(1);
printf("\n %d consumed\n",buf[out]);
out=(out+1)%size;
}
}
suspend()
{
while(1)
{
ch=getchar();
if(ch=='q')
system("killall a.out");
}
}
int main()
{
buf_id=obtain_shm(100,10);
create();
if(fork()==0)
suspend();
else
{
if(fork()==0)
{
producer();
}
else
{
consumer();
}
}
}

