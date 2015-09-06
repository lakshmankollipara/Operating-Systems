#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
int status;
printf("Hello World done by parent\n");
status=fork();
if(status<0)
  {
  printf("Fork failed\n");
  exit(-1);
  }
 else if(status==0)
 {
 printf("Sleeping \n");
 sleep(10);
 printf("Child exiting\n");
 }
 else
 {
 printf("Waiting for child\n");
 wait(NULL);
 printf("Child woke up \n");
 exit(0);
 }
return 0;
}

