#include<stdio.h>
// #include<conio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*top = NULL; // Initially the list is empty
void push(int);
void pop();
void display();
int main()
{
    int choice, value;
    printf("\nlMPLEMENTING STACKS USING LINKED LISTS\n");
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
}
void push(int value)
{
    struct Node *newNode;
    newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    if(top == NULL)
    {
        top=newNode;
        newNode->next = NULL;
    }
    else
    {
        newNode->next=top;
        newNode->next=NULL;
    }
    printf("Node is Inserted\n\n");
}
void pop()
{
    if(top == NULL)
    {
        printf("\nEMPTY STACK\n");
    }
    else
    {
        struct Node *temp = top;
        printf("\nPopped Element :%d", temp->data); printf("\n'");
        top = temp->next;
        free(temp);
    }
}
void display()
{
    // Print the stack
    if(top == NULL)
    {
        printf("\nEMPTY STACK\n");
    }
    else
    {
        printf("The stack is \n");
        struct Node *temp =top;
        while(temp->next != NULL)
        {
            printf("%d--->",temp->data);
            temp = temp -> next;
        }
        printf("%d--->NULL\n",temp->data);
    }
}