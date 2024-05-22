#include <stdio.h>
#include <stdlib.h>

#define len 8

void linearSearch(int arr[], int num)
{
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == num)
        {
            printf("Array element found at index (%d)\n", i);
            return;
        }
    }
    printf("Element not found in the array\n");
}

int binarySearch(int arr[], int num)
{
    int low = 0, high = len - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == num)
        {
            return mid;
        }
        else if (arr[mid] < num)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int num, ch;

    do
    {
        // initialize the array
        int array[] = {11, 17, 19, 21, 55, 87, 95, 100};
        printf("\nThe array is: \n");
        for (int i = 0; i < len; i++)
        {
            printf("%d ", array[i]);
        }
        printf("\n");

        printf("\nSelect the type of search you want to perform \n"
               "\n1. Linear Search"
               "\n2. Binary Search"
               "\n3. Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the element you want to search in the array: ");
            scanf("%d", &num);
            linearSearch(array, num);
            break;

        case 2:
            printf("Enter the element you want to search in the array: ");
            scanf("%d", &num);
            int result = binarySearch(array, num);
            if (result != -1)
            {
                printf("Array element found at index (%d)\n", result);
            }
            else
            {
                printf("Element not found in the array\n");
            }
            break;

        case 3:
            printf("Exiting the program.\n");
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }

        printf("Do you want to continue? (press 1 for yes): \t");
        scanf("%d", &ch);

    } while (ch == 1);

    return 0;
}
