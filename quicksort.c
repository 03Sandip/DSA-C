#include <stdio.h>
#define max 100

int a[max], n, i, l, h;

void quick_sort(int a[], int l, int h); 
void main()
{
    void input(void);
    input();
}

void input(void)
{
    void quick_sort(int a[], int l, int h); 
    void output(int a[], int n);
    printf("How many elements in the array -- ");
    scanf("%d", &n);
    printf("\n");
    printf("Enter the elements : \n"); 
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
    }
    l = 0;
    h = n - 1;
    quick_sort(a, l, h); 
    printf("Sorted Array -- \n");
    output(a, n);
}

void quick_sort(int a[], int l, int h)
{
    int temp, key, low, high;
    low = l;
    high = h;
    key = a[(low + high) / 2];
    do
    {
        while (key > a[low])
        {
            low++;
        }

        while (key < a[high])
        {
            high--;
        }
        if (low <= high)
        {
            temp = a[low];
            a[low++] = a[high];
            a[high--] = temp;
        }
    } while (low <= high);
    if (l < high)
        quick_sort(a, l, high);
    if (low < h) 
        quick_sort(a, low, h); 
}

void output(int a[], int n)
{
    for (i = 0; i < n; i++) 
    {
        printf("%d\n", a[i]);
    }
}
