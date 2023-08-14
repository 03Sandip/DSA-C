#include<stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 5

int qfull(int r)
{
     return(r==QUEUE_SIZE-1)? 1: 0;
}

int insert_rear(int item, int q[],int*r)
{
     if(qfull(*r))
     {
        printf("Queue overflow\n");
           //getch();
          return 0; 
     }
     q[++(*r)]=item;
     return 0;
}

void insert_front(int item, int q[],int *f,int *r)
{
    if(*f==0 && *r==-1)
    q[++(*r)]=item;
else if (*f!=0)
      q[--(*f)]=item;
  else
  printf("front insertion not possible\n");
  //getch();
}

int qempty(int f, int r)
 {
     return(f > r)? 1 :0;
 }

 void delete_front(int q[], int *f, int *r)

 {
    if(qempty(*f,*r))
    {
        printf("Queue inderflow\n");
        *f=0; *r=-1;
       // return 0;
    }
    else{
        printf("The element deleteed is %d\n", q[(*r)--]);  // doubt
       //getch();
    }
 }

 void delete_rear(int q[], int* f, int* r)
 {
    if(qempty(*f,*r))
    {
        printf("Queue inderflow\n");
        *f=0; *r=-1;
        return 0;
    }
    else{
        printf("The element deleteed is %d\n", q[(*r)--]);  // doubt
       //getch();
    }
 }


 void display(int q[], int f ,int r)
  {
     int i;
 if(qempty(f,r))
 {
  printf("queue is empty\n");
   //getch();
  // return 0;
 }
  else
  {
  printf("contents of the queue is \n");
 for(i=f;i<=r;i++)
  printf("%d\t",q[i]);
  //getch();
  }
}

  int main()
{
 int choice, item,f,r,q[10];
 //clrscr();
 f=0;
 r=-1;
 for(;;)
 {
  //clrscr();
  printf("\n General queue operations");
  printf("\n 1. Insert Front");
  printf("\n 2. Insert Rear");
  printf("\n 3. delete  Front");
  printf("\n 4. delete  Rear");
  printf("\n 5.Display");
  printf("\n 6.Exit\n");
  printf("\n Enter your choice");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:
	  printf("\nenter the item to be inserted:");
	  scanf("%d",&item);
	  insert_front(item,q,&f,&r);
	  break;

   case 2:
	  printf("\nenter the item to be inserted:");
	  scanf("%d",&item);
	  insert_rear(item,q,&r);
	  break;

   case 3:
    delete_front(q ,&f, &r);
    break;

    case 4:
    delete_rear(q ,&f, &r);
    break;

    case 5:
    display(q,f,r);
    break;
    
   default:
	  exit(0);
  }
 }
   return 0 ;
}