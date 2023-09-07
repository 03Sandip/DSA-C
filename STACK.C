#include <stdio.h>
#include <stdlib.h> 
#define STACK_SIZE 5

void push(int item, int *top, int s[])
{
    if (*top != STACK_SIZE - 1)
    {
        *top = *top + 1;
        s[*top] = item;
    }
    else
    {
        printf("\nOverflow of stack.\n");
    }
}

int pop(int *top, int s[])
{
    int item;
    if (*top != -1)
    {
        item = s[*top];
        *top = *top - 1;
        return item;
    }
    else
    {
        printf("\nStack is empty.\n");
        return 0;
    }
}

void display(int *top, int s[])
{
    int i;
    if (*top != -1)
    {
        printf("\nContents of the stack:\n");
        for (i = 0; i <= *top; ++i)
            printf("%d\t", s[i]);
        printf("\n");
    }
    else
    {
        printf("\nStack is empty.\n");
    }
}

int main()
{
    int choice, s[STACK_SIZE], item, top = -1;
    char r;

    while (1)
    {
        printf("\nGeneral Stack Operation");
        printf("\n1. Push an item");
        printf("\n2. Pop an item");
        printf("\n3. Display the Contents");
        printf("\n4. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the item to be inserted: ");
            scanf("%d", &item);
            push(item, &top, s);
            break;
        case 2:
            printf("Deleted item is %d\n", pop(&top, s));
            break;
        case 3:
            display(&top, s);
            break;
        default:
            exit(0);
        }
    }

    return 0;
}
