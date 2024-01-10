#include <stdio.h>
#include <stdlib.h>
void insertAtBeginning(int);
void insertAtEnd(int);
void insertAtAfter(int, int);
void deleteBeginning();
void deleteEnd();
void deleteSpecific(int);
void display();
struct Node
{
    int data;
    struct Node *previous, *next;
} *head = NULL;
void main()
{
    int choice1, choice2, value, location;
    // Clrscr();
    while (1)
    {
        printf("\n***MENU***\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter your choice:");
        scanf("%d", &choice1);
        switch (choice1)
        {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &value);
            while (1)
            {
                printf("\nSelect from the following Inserting options\n");
                printf("1.At Beginning\n2.At End\n3.After a node\n4.cancel\nEnter your choice:");
                scanf("%d", &choice2);
                switch (choice2)
                {
                case 1:
                    insertAtBeginning(value);
                    break;
                case 2:
                    insertAtEnd(value);
                    break;
                case 3:
                    printf("Enter the location after which you want to insert:");
                    scanf("%d", &location);
                    insertAtAfter(value, location);
                    break;
                case 4:
                    goto EndSwitch;
                default:
                    printf("\nPlease select correct deleting option!!\n");
                    break;
                }
            }
        case 2:
            while (1)
            {
                printf("\nSelect from the following Deleting options\n");
                printf("1. At Beginning\n2. At End\n3. Specific Node\n4. Cancel\nEnter your choice:");
                scanf("%d", &choice2);
                switch (choice2)
                {
                case 1:
                    deleteBeginning();
                    break;

                case 2:
                    deleteEnd();
                    break;

                case 3:
                    printf("Enter the Nodevdiue to be deleted: ");
                    scanf("%d", &location);
                    deleteSpecific(location);
                    break;
                case 4:
                    goto EndSwitch;
                default:
                    printf("\nPlease select correct Deleting option!!!\n");
                }
            }
        EndSwitch:
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);

        default:
            printf("\nPlease select correct option\n");
        }
    }
}
void insertAtBeginning(int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->previous = NULL;
    if (head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head->previous = newNode;
        head = newNode;
    }
    printf("\nInsertion success!!");
}
void insertAtEnd(int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL)
    {
        newNode->previous = NULL;
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->previous = temp;
    }
    printf("\nInsertion success!!\n");
}
void insertAtAfter(int value, int location)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    if (head == NULL)
    {
        newNode->previous = NULL;
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        struct Node *temp1 = head, *temp2;
        while (temp1->data != location)
        {
            if (temp1->next == NULL)
            {
                printf("Given node is not iound in the list!!");
                goto EndFunction;
            }
            else
            {
                temp1 = temp1->next;
            }
        }
        temp2 = temp1->next;
        temp1->next = newNode;
        newNode->previous = temp1;
        newNode->next = temp2;
        temp2->previous = newNode;
        printf("\nInsertion success!!");
    }
EndFunction:
}
void deleteBeginning()
{
    if (head == NULL)
    {
        printf("List is Empty!!! Deletion not possible!!!");
    }
    else
    {
        struct Node *temp = head;
        if (temp->previous == temp->next)
        {
            head = NULL;
            free(temp);
        }
        else
        {
            head = temp->next;
            head->previous = NULL;
            free(temp);
        }
        printf("\nDeletion success!!");
    }
}
void deleteEnd()
{
    if (head == NULL)
    {
        printf("List is Empty!! Deletion not possible.!");
    }
    else
    {
        struct Node *temp = head;
        if (temp->previous == temp->next)
        {
            head = NULL;
            free(temp);
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->previous->next = NULL;
            free(temp);
        }
        printf("\nDeletion success!!");
    }
}
void deleteSpecific(int delvalue)
{
    if (head == NULL)
    {
        printf("List is Empty!!! Deletion not possible!!!");
    }
    else
    {
        struct Node *temp = head;
        while (temp->data != delvalue)
        {
            if (temp->next == NULL)
            {
                printf("\nGiven node is not found in the list!!");
                goto FunctionEnd;
            }
            else
            {
                temp = temp->next;
            }
        }
        if (temp == head)
        {
            head = NULL;
            free(temp);
        }
        else
        {
            temp->next->previous = temp->previous;
            free(temp);
        }
    }
    printf("\nDeletion success!!");
FunctionEnd:
}
void display()
{
    if (head == NULL)
    {
        printf("\nList is Empty!!!");
    }
    else
    {
        struct Node *temp = head;
        printf("\nList elements are: \n");
        printf("NULL <---");
        while (temp->next != NULL)
        {
            printf("%d <===>", temp->data);
            temp = temp->next;
        }
        printf("%d --->NULL", temp->data);
    }
}