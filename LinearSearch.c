#include <stdio.h>
#include <conio.h>
void main()
{
    int array[100], search, C, n;
    printf("\n****LINEAR SEARCH****\n");
    printf("\nEnter number of elements in array\n");
    scanf("%d", &n);
    printf("\nEnter %d integer(s)\n", n);
    for (C = 0; C < n; C++)
    {
        scanf("%d", &array[C]);
    }
    while (1)
    {
        int choice;
        printf("\nSelect from the following:\n1. Search(LINEAR).\n2. Exit.\n\nEnter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter a number to search\n");
            scanf("%d", &search);
            for (C = 0; C < n; C++)
            {
                if (array[C] == search)
                {
                    printf("\n%d is present at location %d.\n", search, C + 1);
                    break;
                }
            }
            if (C == n)
            {
                printf("\n%d - is not present in the array\n",search);
                break;
            }
            break;
        case 2:
            goto EndFunction;
            break;
        default:
            printf("\n\nKindly enter your choice carefully\n");
        }
    }
    EndFunction:
    getch();
}
