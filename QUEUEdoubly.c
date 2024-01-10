#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

// Function to push a new element at the beginning
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL) {
        head->prev = newNode;
    }

    head = newNode;
    printf("Pushed %d to the list.\n\n", value);
}

// Function to pop the element from the beginning
void pop() {
    if (head == NULL) {
        printf("The list is empty. Cannot pop.\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    printf("Popped %d from the list.\n", temp->data);
    free(temp);
}

// Function to display the elements in the list
void display() {
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, value;
    printf("\nlMPLEMENTING QUEUE USING DOUBLY LINKED LISTS\n");
    while(1)
    {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            push(value);
            break;

            case 2: pop();
            break;

            case 3: display();
            break;

            case 4: exit(0);
            break;

            default: printf("\nlnvalid Choice\n");
        }
    }
    return 0;
}

