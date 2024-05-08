#include <stdio.h>

int fiboSeries(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fiboSeries(n - 1) + fiboSeries(n - 2);
}

int main()
{
    int n, i;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Fibonacci Series up to %d terms:\n", n);
    for (i = 1; i < n; i++)
    {
        printf("%d ", fiboSeries(i));
    }
    return 0;
}
