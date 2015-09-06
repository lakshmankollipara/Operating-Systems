#include<stdio.h>
main()
{
FILE *f,*f2,*f3;
int count=0,l,i;
char c;
f=fopen("a.txt","w");
printf("enter text to the file");
c=getchar();
while(c!='#')
{
fputc(c,f);
c=getchar();
}
fclose(f);
f=fopen("a.txt","r");
while(!feof(f))
{
c=fgetc(f);
if(c=='\n')
{count++ ; } }
fclose(f);
printf("enter the line number");
scanf("%d",&l);
if(l>count)
printf("invalid line number");
else
{
f=fopen("a.txt","r");
f2=fopen("b.txt","w");
i=0;
while(!feof(f))
{
c=fgetc(f);
fputc(c,f2);
if(c=='\n')
i++;
if(i==l)
break;
}
fclose(f2);
f3=fopen("c.txt","w");
while(!feof(f))
{
c=fgetc(f);
fputc(c,f3);
}
fclose(f);
fclose(f3);
printf("contents of file 2 are");
f2=fopen("b.txt","r");
while(!feof(f2))
{
c=fgetc(f2);
printf("%c",c);
}
fclose(f2);
f3=fopen("c.txt","r");
printf("contents of file 3 are");
while(!feof(f3))
{
c=fgetc(f3);
printf("%c",c);
}
fclose(f3);
}
}








