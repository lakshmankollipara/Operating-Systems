#include<stdio.h>
main()
{
char c,a;
FILE *f1,*f2,*f3;
int count , l,i=0;
printf("enter the choice\n1.merge\n2.split");
scanf("%d",a);
switch(a)
{
case 1:
f1 = fopen("a.txt","w");
c=getchar();
while(c!='#')
{
fputc(c,f1);
c=getchar();
}
fclose(f1);
f2=fopen("b.txt","w");
c=getchar();
while(c!='#')
{
fputc(c,f2);
c=getchar();
}
fclose(f2);
f1 = fopen("a.txt","a");
f2=fopen("b.txt","r");
while(!feof(f2))
{
c=fgetc(f2);
fputc(c,f1);
}
fclose(f2);
fclose(f1);
break;
case 2:
f1=fopen("a.txt","w");
printf("enter text to the file");
c=getchar();
while(c!='#')
{
fputc(c,f1);
c=getchar();
}
fclose(f1);
f1=fopen("a.txt","r");
while(!feof(f1));
{
if(c=='\n')
{count++ ; } }
fclose(f1);
printf("enter the line number");
scanf("%d",l);
if(l>count)
printf("invalid line number");
else
{
f1=fopen("a.txt","r");
f2=fopen("b.txt","w");
while(!feof(f1))
{
for( i=0;i<l;i++)
{
c=fgetc(f1);
fputc(c,f2);
}
fclose(f2);
f3=fopen("c.txt","w");
c=fgetc(f1);
fputc(c,f3);
}
fclose(f1);
fclose(f3);
}
break;
}
}





