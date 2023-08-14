#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define STACK_SIZE 5

	void push(int item, int*top,int s[])
	{
	   if(*top!= STACK_SIZE-1)
	   {
	     *top=*top+1;
	     s[*top]= item;
	     }
	   else
	   {
	      printf("\n Overflow stack");
	      getch();
	    }
	}

	int pop (int *top , int s[])
	{
	  int item ;

	  if(*top!=-1)
	  {
	    item = s[*top];
	    *top=*top-1;
	    return item;
	  }
	  else
	  {
	    printf("\n Empty stack ");
	    return 0 ;
	  }
       }

       void display (int*top,int s[])
       {
	int i;
	if(*top!=-1)
	{
	for(i=0;i<=*top;i++)
	{
	  printf("%d\t",s[i]);
	}
     }
       else
       printf("\n stack is empty");
      }
     int main ()
     {
       int choice,s[20],item,*top;
       char r;
       *top=-1;
       while(1)

       {
       printf("\n General stack Opreation");
       printf("\n 1 Push an item");
       printf("\n 2 Pop an item");
       printf("\n 3 Display the Content");
       printf("\n 4 Exit");
       printf("\n\n Enter your Choice");
       scanf("%d",&choice);
       switch(choice)
       {
	   case 1:
	    
	    printf("\n Enter the item to be inserted");
	    scanf("%d",&item);
	    push(item,top,s);
	    break;
	  case 2:
	    
	    printf("\n Deleted item is %d",pop(top,s));
	    getch();
	    break;
	  case 3:
	   
	    display(top,s);
	    getch();
	    break;

	  default:
	     exit (0);
	   }
	   }
	   return 0;
     }
