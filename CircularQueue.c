#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 5

int qfull(int count)
{
    return (count == QUEUE_SIZE) ? 1 : 0;
}

int qempty(int count)
{
    return (count == 0) ? 1 : 0;
}

int insert_rear(int item, int q[], int *r, int *count)
{
    if (qfull(*count))
    {
        printf("Queue is Overflow\n");
        return 0;
    }
    *r = (*r % QUEUE_SIZE) + 1;
    q[*r] = item;
    (*count)++;
    return 0;
}

int delete_front(int q[], int *f, int *count)
{
    int t;
    if (qempty(*count))
    {
        printf("Queue underflow\n");
        return 0;
    }
    else
    {
        t = q[*f];
        *f = (*f % QUEUE_SIZE) + 1;
        (*count)--;
        return t;
    }
}

void display(int q[], int f, int count)
{
    int i, j;
    if (qempty(count))
    {
        printf("Queue is empty\n");
        return;
    }
    i = f;
    printf("Contents of the queue are:\n");
    for (j = 1; j <= count; j++)
    {
        printf("%d\t", q[i]);
        i = (i % QUEUE_SIZE) + 1;
    }
    printf("\n");
}

int main()
{
    int choice, item, f = 1, r = 0, q[QUEUE_SIZE], count = 0;

    for (;;)
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
            insert_rear(item, q, &r, &count);
            break;

        case 2:
            printf("Deleted item is %d\n", delete_front(q, &f, &count));
            break;

        case 3:
            display(q, f, count);
            break;

        default:
            exit(0);
        }
    }

    return 0;
}
