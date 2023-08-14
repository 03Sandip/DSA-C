#include<stdio.h>
#include<conio.h>
#define STACK_SIZE 5

void push(int item,int *top,int s[])
{
 if(*top != STACK_SIZE - 1)
 {
  *top=*top+1;
  s[*top]=item;
 }
 else
 {
 printf("\n overflow of stack.");
 getch();
 }
}

int pop(int *top, int s[])
{
 int item;
 if(*top != -1)
 {
  item=s[*top];
  *top=*top-1;
  return(item);
 }
 else
 {
  printf("\nstack is empty.");
  return(0);
 }
}

void display(int *top,int s[])
{
 int i;
 if(*top != -1)
 {
  printf("\ncontents of the stack:\n");
  for(i=0;i<=*top;++i)
   printf("%d\t",s[i]);
 }
 else
 printf("\n stack is empty.");
}

void main()
{
 int choice,s[20],item,*top;
 char r;
 *top=-1;
 while(1)
 {
  clrscr();
  printf("\n General Stack Operation");
  printf("\n1.Push an item");
  printf("\n2.Pop an item");
  printf("\n3.Display the Contents");
  printf("\n4.Exit");
  printf("\n\nEnter your choice: ");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:
	  clrscr();
	  printf("\nenter the item to be inserted: ");
	  scanf("%d",&item);
	  push(item,top,s);
	  break;
  case 2:
	  clrscr();
	  printf("deleted item is %d",pop(top,s));
	  getch();
	  break;
  case 3:
	  clrscr();
	  display(top,s);
	  getch();
	  break;
   default:
	   exit(0);
  }
 }
}