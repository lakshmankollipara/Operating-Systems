#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
int status;
printf("Before create\n");
status=fork();
printf("After create\n");
 if(status<0)
  {
  printf("Fork failed\n");
  exit(-1);
  }
 else if(status==0)
 {
 execlp(" /bm/ls ","ls",NULL);
 }
 else
 {
 wait(NULL);
 printf("Child complete \n");
 exit(0);
 }
return 0;
}

