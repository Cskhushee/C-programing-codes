#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void insertAtBeginning (int) ;
void insertAtEnd(int) ;
void insertAtAfter (int, int);
void deleteBeginning();
void deleteEnd();
void deleteSpecific(int);
void display();
struct Node
{
    int data;
    struct Node *next;
}*head = NULL;
void main ()
{
    int choicel, choice2, value, location;
    //clrscr ();
    while (1)
    {   printf("\n***MENU***\n");
        printf ( "l. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
        scanf ("%d", &choicel) ;
        switch (choicel)
        {
            case 1: printf ("Enter the value to be inserted: ");
                    scanf("%d",&value);
                    while (1)
                    {
                        printf("\nSelect trom the following Inserting options\n");
                        printf("1. At Beginning\n2. At. End\n3. After a Node\n4. Cancel\n Enter your choice:\n");
                        scanf ("%d", &choice2) ;
                        switch (choice2)
                        {
                            case 1: insertAtBeginning (value);
                                    break;
                            case 2: insertAtEnd (value) ;
                                    break;
                            case 3: printf("\nEnter the location after which you want to enter after:\n");
                                    scanf ("%d", &location);
                                    insertAtAfter (value, location);
                                    break;
                            case 4: goto EndSwitch;
                            default:printf("\nPlease enter correct insertion option!!");
                        }
                    }
            case 2: while(1)
            {
                printf("\nSelect from the following Deleting options\n");
                printf("1.At Beginning\n2.At End\n3.Specific Node\n4. Cancel\nEnter your choice:");
                scanf("%d",&choice2);
                switch(choice2)
                {
                    case 1:
                        deleteBeginning();
                        break;

                    case 2:
                        deleteEnd();
                        break;

                    case 3:
                        printf("Enter the Nodevdiue to be deleted: ");
                        scanf("%d",&location);
                        deleteSpecific(location);
                        break;
                    case 4:goto EndSwitch;
                    default: printf("\nPlease select correct Deleting option!!!\n");
                }
                EndSwitch:break;
                case 3: display();
                        break;
                case 4: exit(0);
                        
                default:printf("\nPlease select correct option\n");
            }
        }
    }
}
void insertAtBeginning (int value)
{
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    if (head==NULL)
    {
        newNode->next=head;
        head=newNode;
    }
    else
    {
        struct Node* temp = head;
        while (temp->next!=head)
        {
            temp=temp->next;
        }
        newNode->next=head;
        head=newNode;
        temp->next=newNode;
    }
   printf("\nInsertion success!!");
}
void insertAtEnd(int value)
{
    struct Node * newNode;
    newNode =(struct Node*)malloc(sizeof(struct Node));
    newNode -> data= value;
    if(head == NULL)
    {
        newNode -> next =head;
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while(temp -> next != head)
        {
            temp = temp -> next;
        }
        temp -> next = newNode;
        newNode -> next = head;
    }
    printf("\nInsertion success!!\n");
}
void insertAtAfter(int value,int location)
{
    struct Node * newNode;
    newNode =(struct Node*)malloc(sizeof(struct Node));
    newNode -> data= value;
    if(head == NULL)
    {
        newNode -> next = head;
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while(temp -> data != location)
        {
            if(temp -> next == head)
            {
                printf("Given Node is not Found in the list!!");
                goto EndFunction;
            }
            else
            {
                temp = temp -> next;
            }
            
        }
        newNode->next=temp->next;
        temp->next=newNode;
        printf("\nInsertion success!!");
    }
    EndFunction:
}
void deleteBeginning()
{
    if(head == NULL)
    {
        printf("List is Empty!!! Deletion not possible!!!");
    }
    else
    {
        struct Node *temp = head;
        if(temp -> next == head)
        {
            head = NULL;
            free(temp);
        }
        else
        {
            head = head-> next;
            free(temp);
        }
        printf("\nDeletion success!!");
    }
}
void deleteEnd()
{
    if(head == NULL)
    {
    printf("List is Empty!! Deletion not possible.!");
    }
    else
    {
        struct Node *temp1 = head, *temp2;
        if(temp1 -> next == head)
        {
            head = NULL;
            free(temp1);
        }
        else
        {
            while(temp1 -> next != head)
            {
                temp2 = temp1;
                temp1=temp1->next;
            }
            temp2->next=head;
            free(temp1);
        }
        printf("\nDeletion success!!");
    }
}
void deleteSpecific(int delvalue)
{
    if(head == NULL)
    {
        printf("List is Empty!!! Deletion not possible!!!");
    }
    else
    {
        struct Node *temp1 = head,*temp2;
        while(temp1 -> data != delvalue)
        {
            if(temp1 -> next == head)
            {
                printf("\nGiven node is not found in the list!!");
                goto FunctionEnd;
            }
            else
            {
                temp2=temp1;
                temp1 = temp1 -> next;
            }
        }
        temp2->next=temp1->next;
        free(temp1);
    }
    printf("\nDeletion success!!");
    FunctionEnd:
}
void display()
{
    if(head == NULL)
    {
    printf("\nList is Empty!!!");
    }
    else
    {
        struct Node *temp = head;
        printf("\nList elements are: \n");
        while(temp->next != head)
        {
            printf("<--%d-->",temp->data);
            temp=temp->next;
        }
        printf("<--%d-->",temp->data);
        // struct Node *r = head;
        // while (r->next != head)
        // {
        //     printf("%d",r->data);
        //     r=r->next;
        // }
    }
}