#include<stdio.h>
#include<unistd.h>
#include<errno.h>
int main()
{
int a,fd1[2],fd2[2],pid,num,n;
char line[30];
int STDOUT_FILEEND;
if(pipe(fd1)<0)
perror("pipe1 error\n");
if(pipe(fd2)<0)
perror("pipe2 error\n");
if((pid=fork())<0)
perror("fork error\n");
else if(pid>0)
{
close(fd1[0]);
write(fd1[1],"to child\n",10);
close(fd2[1]);
n=read(fd2[0],line,30);
printf("\nparent\n");
printf("from child %s",line);
}
else
{
close(fd1[1]);
n=read(fd1[0],line,30);
printf("child\n");
write(STDOUT_FILEEND,line,n);
close(fd2[0]);
write(fd2[1],"to parent",10);
}
exit(0);
}
