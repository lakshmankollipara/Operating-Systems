#include<stdio.h>
main()
{
FILE *f;
char c;
f=fopen("a.txt","w");
printf("enter the characters :\n");
c=getchar();
while(c!='#')
{
fputc(c,f);
c=getchar();
}
fclose(f);
f=fopen("a.txt","r");
printf("the file contents are :\n");
while(!feof(f))
{
c=getc(f);
printf("%c",c);
}
fclose(f);
}
