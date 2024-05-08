// a code to implement the circular queue

#include<stdio.h>
#include<stdlib.h>
#define MAX 10

struct cqueue{
    int cqueue[MAX], front, rear;
}cq;

void enqueue();
void dequeue();
void display();

int main(){
    int ch = 1;
    cq.front = MAX-1;
    cq.rear = MAX-1;
    printf("\n\n-- Choose the option --");
    printf("\n1. Insert/Enqueue");
    printf("\n2. Delete/dequeue");
    printf("\n3. Display");
    printf("\n4. Exit");
    while(1){
        printf("\n\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){
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
                exit(0);
        }
    }
    return 0;
}

void enqueue(){
    int value;
    if(cq.front == (cq.rear+1) % MAX){
        printf("\nCircular queue overflow.");
        return;
    }
    cq.rear = (cq.rear + 1) % MAX;
    printf("\nEnter new number: ");
    scanf("%d", &value);
    cq.cqueue[cq.rear] = value;
    // --> elements in queue
    display();
}
void dequeue(){
    if(cq.rear == cq.front){
        printf("\nStack underflow!!");
        return;
    }else{
        cq.front = (cq.front + 1) % MAX;
        printf("The dequeue item is: %d\n", cq.cqueue[cq.front]);
    // --> elements in queue
        display();
    }
}
void display(){
    if(cq.rear == cq.front){
        printf("\nStack underflow!!");
        return;
    }else{
        printf("Elements in queue are: ");
        for(int i = (cq.front + 1)%MAX; i != cq.rear; i = (i + 1)%MAX){
            printf("%d\t", cq.cqueue[i]);
        }
            printf("%d\t", cq.cqueue[cq.rear]);
    }
}