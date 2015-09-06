#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
int status;
status= fork();
printf("hello world\n");
if(status <0)
{
printf("fork failed");
exit(-1);
}
else if(status==0)
{
printf("sleeping....\n");
sleep(5);
printf("exiting...\n");
}
else
{
printf("waiting for child\n");
wait(NULL);
printf("child woke up\n");
exit(0);
}
}
