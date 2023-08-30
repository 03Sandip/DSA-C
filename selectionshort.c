#include <stdio.h>

void selection_sort(int a[], int n); 

int main()
{
    int a[100], n, i;

    printf("No of Elements are: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]); 
    }

    selection_sort(a, n);

    printf("Sorted Array: "); 
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]); 
    }

    return 0; 
}

void selection_sort(int a[], int n) 
{
    int min, loc, temp, i, j;
    for (i = 0; i < n - 1; i++) 
    {
        min = a[i];
        loc = i;

        for (j = i + 1; j < n; j++) 
        {
            if (a[j] < min)
            {
                min = a[j];
                loc = j;
            }
        }

        if (loc != i)
        {
            temp = a[i];
            a[i] = a[loc];
            a[loc] = temp;
        }
    }
}
