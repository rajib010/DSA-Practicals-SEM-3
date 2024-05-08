#include <stdio.h>
#include <stdlib.h>
#define maxsize 5

struct stack
{
    int stack[maxsize], top;
} st;

void push();
void pop();
void display();

int main()
{
    int ch = 1;
    st.top = -1;
    while (1)
    {
        printf("/n 1 Push");
        printf("/n 2 Pop");
        printf("/n 3 Display");
        printf("/n 4 Terminate");
        printf("/n Enter your choice :");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf(" \n Wrong choice \n");
        }
    }

    return 0;
}

void push()
{
    int no;
    if (st.top == maxsize - 1)
    {
        printf("Stack overflow");
        return 0;
    }
    st.top++;
    printf("\n Enter new number");
    scanf("%d", &no);
    st.stack[st.top] = no;
    printf("/nElement of stack are /n");
    display();
    return 0;
}

void pop()
{
    if (st.top == -1)
    {
        printf("\n Stack underflow");
        return 0;
    }
    else
    {
        st.top--;
        printf("\n Elements in stack are : \n");
        display();
        return 0;
    }
}

void display()
{
    int i;
    if (st.top == -1)
    {
        printf("\n Stack underflow");
        return 0;
    }
    for (int i = st.top; i >= 0; i--)
    {
        printf("%d\t", st.stack[i]);
        return 0;
    }
}