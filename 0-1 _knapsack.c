#include <stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int val[], int n) {
    if (n == 0 || W == 0)
        return 0;
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);
    else
        return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1));
}

int main() {
    int n, W;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int profit[n], weight[n];

    for (int i = 0; i < n; i++) {
        printf("Enter profit and weight for item %d: ", i + 1);
        scanf("%d %d", &profit[i], &weight[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    printf("Maximum profit: %d\n", knapSack(W, weight, profit, n));
    return 0;
}
