// code to find the greatest common divisor

#include <stdio.h>
#include <conio.h>

int gcd(int m, int n)
{
    if (n == 0)
    {
        return m;
    }
    if (m < n)
    {
        return gcd(n, m);
    }
    return (gcd(n, m % n));
}

void main()
{
    int m, n, result;
    printf("Enter two numbers : \n");
    scanf("%d %d", &m, &n);
    result = gcd(m, n);
    printf("The greatest common divider (%d,%d)=%d\n", m, n, result);
}