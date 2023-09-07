#include <stdio.h>
#include <stdlib.h> 

#define QUEUE_SIZE 5

int qfull(int r)
{
    return (r == QUEUE_SIZE - 1) ? 1 : 0;
}

void insert_rear(int item, int q[], int *r)
{
    if (qfull(*r))
    {
        printf("Queue overflow\n");
        return;
    }
    q[++(*r)] = item;
}

int qempty(int f, int r)
{
    return (f > r) ? 1 : 0;
}

void delete_front(int q[], int *f, int *r)
{
    if (qempty(*f, *r))
    {
        printf("Queue underflow\n");
        *f = 0;
        *r = -1;
        return;
    }
    printf("The element deleted is %d\n", q[(*f)++]);
}

void display(int q[], int f, int r)
{
    int i;
    if (qempty(f, r))
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Contents of the queue:\n");
    for (i = f; i <= r; i++)
        printf("%d\t", q[i]);
    printf("\n");
}

int main()
{
    int choice, item, f = 0, r = -1, q[QUEUE_SIZE];

    while (1)
    {
        printf("\nGeneral Queue Operations");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the item to be inserted: ");
            scanf("%d", &item);
            insert_rear(item, q, &r);
            break;
        case 2:
            delete_front(q, &f, &r);
            break;
        case 3:
            display(q, f, r);
            break;
        default:
            exit(0);
        }
    }

    return 0;
}
