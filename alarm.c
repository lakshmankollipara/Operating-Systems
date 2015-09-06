#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#define BUFSIZE 100
void alrm_handler(int signo);
char buf[BUFSIZE]="OS\0";
int main(void)
{
int n;
if(signal(SIGALRM,alrm_handler)== SIG_ERR)
{
printf("illegal operation\n");
exit(1);
}
fprintf(stderr,"enter file name:");
alarm(5);
n=read(STDIN_FILENO,buf,BUFSIZE);
if(n>1)
printf("filename:%s\n",buf);
exit(0);
return 0;
}
void alrm_handler(int signo)
{
signal(SIGALRM,alrm_handler);
fprintf(stderr,"\nsignal %d received,defalut file name:%s\n",signo,buf);
exit(1);
}
