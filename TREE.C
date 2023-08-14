#include<stdio.h>
#include<alloc.h>
#include<process.h>
#include<conio.h>
struct node
{
 int info;
 struct node *llink;
 struct node *rlink;
};
typedef struct node* NODE;

NODE getnode(void)
{
 NODE x;
 x=(NODE)malloc(sizeof(struct node));
 if(x==NULL)
 {
  printf("\nout of memory");
  exit(1);
 }
 return(x);
}

void freenode(NODE x)
{
 free(x);
}

void preorder(NODE root)
{
 if(root !=NULL)
 {
  printf("%d",root->info);
  preorder(root->llink);
  preorder(root->rlink);
 }
}

void inorder(NODE root)
{
 if(root !=NULL)
 {
  inorder(root->llink);
  printf("%d",root->info);
  inorder(root->rlink);
 }
}

void postorder(NODE root)
{
 if(root !=NULL)
 {
  postorder(root->llink);
  postorder(root->rlink);
  printf("%d",root->info);
 }
}

NODE insert(int item, NODE root)
{
 NODE temp,cur,prev;
 char direction[10];
 int i;
 temp=getnode();
 temp->info=item;
 temp->llink=temp->rlink=NULL;
 if(root==NULL)
   return temp;
 printf("\ngive the directions where you want to insert: ");
 gets(direction);
 prev=NULL;
 cur=root;
 /*find the position to insert */
 for(i=0;i<strlen(direction) && cur != NULL; i++)
 {
  prev=cur;
  cur=(direction[i]=='l')?cur->llink:cur->rlink;
 }
 if(cur!=NULL)
 {
  printf("Insertion not possible");
  freenode(temp);
  return(root);
 }
/* insert the node at the leaf level */
if(direction[--i]=='l')
 prev->llink=temp;
else
 prev->rlink=temp;
return root;
}

void main()
{
 NODE root = NULL;
 int choice,item,flag;
 for(;;)
 {
  clrscr();
  printf("\nyou can do the following...\n");
  printf("\n1. Insert");
  printf("\n2. Preorder");
  printf("\n3. Inorder");
  printf("\n4. Postorder");
  printf("\n5. Search");
  printf("\n6. Exit");
  printf("\n\nenter your choice..");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:
	  printf("\nenter the item to be inserted:");
	  scanf("%d",&item);
	  root=insert(item,root);
	  break;
   case 2:
	  if(root==NULL)
	    printf("\ntree is empty..");
	  else
	   {
	    printf("\npree order traversal is :\n");
	    preorder(root);
	    printf("\n");
	   }
	   break;
   case 3:
	   if(root==NULL)
	     printf("\ntree is empty");
	  else
	   {
	    printf("\nInorder traversal is :\n");
	    inorder(root);
	    printf("\n");
	   }
	   break;
   case 4:
	   if(root==NULL)
	       printf("tree is empty\n");
	  else
	   {
	    printf("\npostorder traversal is :\n");
	    postorder(root);
	    printf("\n");
	   }
	   break;
 /*  case 5:
	   if(root==NULL)
	    printf("\ntree is empty");
	  else
	   {
	    printf("\nenter item to search :\n");
	    scanf("%d",&item);
	    flag=0;
	    search(item,root,&flag);
	    if(flag==1)
	      printf("search successful\n");
	    else
	      printf("unsuccessful search\n");
	    }
	   break;   */
   default:
	    exit(0);
    }
  }
}

