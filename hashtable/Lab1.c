#include <stdio.h>
#include <stdlib.h>

struct data
{
    int key;
    int value;
};

struct data *array;
int capacity = 10;
int size = 0;

// this function gives a unique hash code to the given key
int hashcode(int key)
{
    return (key % capacity);
}

int if_prime(int n);

// to get the next prime number greater than or equal to n
int get_prime(int n)
{
    if (n % 2 == 0)
    {
        n++;
    }
    while (!if_prime(n))
    {
        n += 2;
    }
    return n;
}

// to check if the given input is prime or not
int if_prime(int n)
{
    int i;
    if (n <= 1)
    {
        return 0;
    }
    for (i = 2; i * i <= n; i++) 
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void init_array()
{
    int i;
    capacity = get_prime(capacity);
    array = (struct data *)malloc(capacity * sizeof(struct data));
    for (i = 0; i < capacity; i++)
    {
        array[i].key = 0;
        array[i].value = 0;
    }
}

// to insert a key in the hash table
void insert(int key)
{
    int index = hashcode(key);
    if (array[index].value == 0)
    {
        // key not present, insert it
        array[index].key = key;
        array[index].value = 1;
        size++;
        printf("\n Key (%d) has been inserted \n", key);
    }
    else if (array[index].key == key)
    {
        // updating already existing key
        printf("\nKey (%d) already present, hence updating its value \n", key);
        array[index].value += 1;
    }
    else
    {
        // key cannot be inserted as the index is already containing some other key
        printf("\nELEMENT CANNOT BE INSERTED\n");
    }
}

void remove_element(int key)
{
    int index = hashcode(key);
    if (array[index].value == 0)
    {
        printf("\n This key does not exist\n");
    }
    else if (array[index].key == key)
    {
        array[index].key = 0;
        array[index].value = 0;
        size--;
        printf("\n key(%d) has been removed \n", key);
    }
    else
    {
        printf("\n Key not found at expected position \n");
    }
}

void display()
{
    int i;
    for (i = 0; i < capacity; i++)
    {
        if (array[i].value == 0)
        {
            printf("\n Array[%d] has no elements\n", i);
        }
        else
        {
            printf("\n Array[%d] has elements -:\n key(%d) and value (%d) \t", i, array[i].key, array[i].value);
        }
    }
}

int size_of_hashtable()
{
    return size;
}

int main()
{
    int choice, key, n, c;
    init_array();
    do
    {
        printf("\n Implementation of hash table in C \n");
        printf("MENU -: \n1. Inserting item into hash table"
               "\n2. Removing items from hash table"
               "\n3. Check the size of hash table"
               "\n4. Display a hash table"
               "\n \n Please enter your choice :-");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Inserting element in Hash Table: \n");
            printf("Enter key-: \t");
            scanf("%d", &key);
            insert(key);
            break;

        case 2:
            printf("\n Deleting in Hash Table \n Enter the key you want to delete : ");
            scanf("%d", &key);
            remove_element(key);
            break;

        case 3:
            n = size_of_hashtable();
            printf("\n The size of hash table is :- %d\n", n);
            break;

        case 4:
            display();
            break;

        default:
            printf("\n Wrong input \n");
            break;
        }
        printf("Do you want to continue? (press 1 for yes)\t");
        scanf("%d", &c);
    } while (c == 1);

    free(array);
    return 0;
}
