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
printf("process id is %d\n",getpid());
printf("parent process id is %d\n",getppid());
execlp("/bm/ls","ls",NULL);
}
else
{
printf("parent process id is %d\n",getppid());
printf("process id is %d\n",getpid());
wait(NULL);
printf("child completed\n");
exit(0);
}
}
