#include<stdio.h>
#include<conio.h>
#include<process.h>
#define QUEUE_SIZE 5

int qfull(int r)
{
 return(r==QUEUE_SIZE-1)?1:0;
}
int insert_rear(int item, int q[], int *r)
{
 if(qfull(*r))
 {
  printf("queue overflow\n");
  getch();
  return;
 }
 q[++(*r)]=item;
 return;
}

int qempty(int f,int r)
{
 return(f>r)?1:0;
}

void delete_front(int q[], int *f,int *r)
{
 if(qempty(*f,*r))
 {
  printf("queue underflow\n");
  *f=0; *r=-1;
  getch();
  return;
  }
 printf("the element deleted is %d\n",q[(*f)++]);
 getch();
}

void display(int q[], int f, int r)
{
 int i;
 if(qempty(f,r))
 {
  printf("queue is empty\n");
  getch();
  return;
 }
 printf("contents of the queue is \n");
 for(i=f;i<=r;i++)
  printf("%d\t",q[i]);
 getch();
}

void main()
{
 int choice, item,f,r,q[10];
 clrscr();
 f=0;
 r=-1;
 for(;;)
 {
  clrscr();
  printf("\n general queue operations");
  printf("\n 1. Insert");
  printf("\n 2. Delete");
  printf("\n 3. Display");
  printf("\n 4. Exit");
  printf("\n Enter your choice");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:
	  printf("\nenter the item to be inserted:");
	  scanf("%d",&item);
	  insert_rear(item,q,&r);
	  break;
   case 2:
	  delete_front(q,&f,&r);
	  break;
   case 3:
	  display(q,f,r);
	  break;
   default:
	  exit(0);
  }
 }
}