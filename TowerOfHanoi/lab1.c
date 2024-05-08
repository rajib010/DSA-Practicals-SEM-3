#include <stdio.h>
#include <string.h>

void TOH(int n, char source, char temp, char destination)
{
    if (n > 0)
    {
        TOH(n - 1, source, destination, temp);
        printf("\n %c ==> %c", source, destination);
        TOH(n - 1, temp, source, destination);
    }
}

int main()
{
    int n;
    printf("Enter how many disks: ");
    scanf("%d", &n);
    TOH(n, 'S', 'T', 'D');
    return 0;
}
