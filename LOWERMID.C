//UPPER middle TRIANGLE OF A MATRIX
#include<stdio.h>
#include<conio.h>
void main()
{
int a[5][5],i,j,sum=0;
clrscr();
printf("enter the matrix\n");
for(i=0;i<=4;++i)
{
 for(j=0;j<=4;++j)
 {
 scanf("%d",&a[i][j]);
 }
}
for(i=0;i<=4;++i)
{
 printf("\n");
 for(j=0;j<=4;++j)
 {
  if(i<=j && i+j<=5-1)
  {
   printf("%d\t",a[i][j]);
   sum=sum+a[i][j];
  }
  else
   printf("\t");
 }
printf("\n");
}
printf("\nsum of elements : %d",sum);
getch();
}