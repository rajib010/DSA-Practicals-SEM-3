#include <stdio.h>
#include <stdlib.h>

#define maxsize 5

struct lqueue
{
    int queue[maxsize], front, rear;
} q;

void enqueue();
void dequeue();
void display();

int main()
{
    int value;
    int ch = 1;
    q.front = 0;
    q.rear = -1;
    while (1)
    {
        printf("\n 1 Enqueue \n");
        printf("\n 2 Dequeue \n");
        printf("\n 3 Display \n");
        printf("\n 4 Terminate \n");
        printf("\n Enter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\n Wrong choice, enter again");
            break;
        }
    }

    return 0;
}

void enqueue()
{
    int no;
    if (q.rear == maxsize - 1)
    {
        printf("\n Queue overflow");
        return;
    }
    q.rear++;
    printf("Enter new number : ");
    scanf("%d", &no);
    q.queue[q.rear] = no;
    printf("Elements of queue are: \n");
    display();
}

void dequeue()
{
    if (q.rear < q.front)
    {
        printf("Queue underflow");
        return;
    }
    printf("\nElement dequeued: %d", q.queue[q.front]);
    q.front++;
    printf("\nElements in queue are: \n");
    display();
}

void display()
{
    if (q.rear < q.front)
    {
        printf("\nQueue is empty\n");
        return;
    }
    printf("\nElements in queue are: \n");
    for (int i = q.front; i <= q.rear; i++)
    {
        printf("\t%d", q.queue[i]);
    }
    printf("\n");
}
