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
execlp("/bm/ls","ls",NULL);
}
else
{
wait(NULL);
printf("child completed\n");
exit(0);
}
}
