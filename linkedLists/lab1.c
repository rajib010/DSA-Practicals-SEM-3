#include<stdio.h>
#include<stdlib.h>

void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();
struct node {
    int info;
    struct node *next;
};
struct node *start = NULL;

int main() {
    int ch;
    while (1) {
        printf("\n--Choose the option to perform the operation--");
        printf("\n1. Create");
        printf("\n2. Display");
        printf("\n3. Insert at the beginning ");
        printf("\n4. Insert at the end ");
        printf("\n5. Insert at the specified position ");
        printf("\n6. Delete at the beginning ");
        printf("\n7. Delete at the end ");
        printf("\n8. Delete at the specified position ");
        printf("\n9. Exit ");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insert_begin();
                break;
            case 4:
                insert_end();
                break;
            case 5:
                insert_pos();
                break;
            case 6:
                delete_begin();
                break;
            case 7:
                delete_end();
                break;
            case 8:
                delete_pos();
                break;
            case 9:
                exit(0);
            default:
                printf("\nInvalid choice");
                break;
        }
    }
    return 0;
}

void create() {
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    if(temp == NULL) {
        printf("\nOut of Memory space.");
        exit(0);
    }
    printf("\nEnter the data value for the node: ");
    scanf("%d", &temp->info);
    temp->next = NULL;
    if(start == NULL) {
        start = temp;
    } else {
        ptr = start;
        while(ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void display() {
    struct node *ptr;
    if(start == NULL) {
        printf("\nList is empty");
        return;
    } else {
        ptr = start;
        printf("\nList elements are:\t");
        while(ptr != NULL) {
            printf("%d ", ptr->info);
            ptr = ptr->next;
        }
    }
}

void insert_begin() {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data value for the node: ");
    scanf("%d", &temp->info);

    if(start == NULL) {
        start = temp;
        temp->next = NULL;
    } else {
        temp->next = start;
        start = temp;
    }
}

void insert_end() {
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data value for the node: ");
    scanf("%d", &temp->info);

    if(start == NULL) {
        start = temp;
    } else {
        ptr = start;
        while(ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void insert_pos() {
    struct node *ptr, *temp;
    int i, pos;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the position for the new node to be inserted: ");
    scanf("%d", &pos);
    printf("\nEnter the data value of the node: \t");
    scanf("%d", &temp->info);

    temp->next = NULL;
    ptr = start;
    if(pos == 1) {
        temp->next = start;
        start = temp;
        return;
    }
    for(i = 1; i < pos - 1; i++) {
        ptr = ptr->next;
        if(ptr == NULL) {
            printf("\nPosition not found");
            return;
        }
    }
    temp->next = ptr->next;
    ptr->next = temp;
}

void delete_begin() {
    struct node *ptr;
    if(start == NULL) {
        printf("\nList is empty");
    } else {
        ptr = start;
        start = start->next;
        printf("\nThe deleted element is: %d", ptr->info);
        free(ptr);
    }
}

void delete_end() {
    struct node *temp, *ptr;
    if(start == NULL) {
        printf("\nList is empty");
    } else {
        ptr = start;
        while(ptr->next != NULL) {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = NULL;
        printf("\nThe deleted element is: %d", ptr->info);
        free(ptr);
    }
}

void delete_pos() {
    struct node *ptr, *temp;
    int i, pos;
    printf("\nEnter the position of the node to be deleted: ");
    scanf("%d", &pos);
    ptr = start;
    if(pos == 1) {
        start = start->next;
        printf("\nThe deleted element is: %d", ptr->info);
        free(ptr);
        return;
    }
    for(i = 1; i < pos; i++) {
        temp = ptr;
        ptr = ptr->next;
        if(ptr == NULL) {
            printf("\nPosition not found");
            return;
        }
    }
    temp->next = ptr->next;
    printf("\nThe deleted element is: %d", ptr->info);
    free(ptr);
}
