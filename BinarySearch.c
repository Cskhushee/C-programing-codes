#include <stdio.h>
#include <conio.h>
void main()
{
    int c, first, last, middle, n, search, array[100];
    // clrscr();
    printf("\n\n****BINARY SEARCH****\n");
    // printf("\n**Make sure not to enter more than 100**\n");
    // printf("\n**Make sure enter elements in ASCENDING ORDER or DESCENDING ORDER**\n");
    // printf("\n**Because Binary Search ONLY works on SORTED ARRAY OR LIST**\n\n");
    printf("\nEnter number of elements(*Make sure not to enter more than 100*):\n");
    scanf("%d", &n);
    printf("\nEnter %d integers\n", n);
    for (c = 0; c < n; c++)
    {
        scanf("%d", &array[c]);
    }
    // printf("\nEnter value to find\n");
    // scanf("%d", &search);
    // first = 0;
    // last = n - 1;
    // middle = (first + last) / 2;
    while (1)
    {
        int choice;
        printf("\nSelect from the following:\n1. Search(BINARY).\n2. Exit.\n\nEnter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter value to find\n");
            scanf("%d", &search);
            first = 0;
            last = n - 1;
            middle = (first + last) / 2;
            while (first <= last)
            {
                if (array[middle] == search)
                {
                    printf("\n%d found at location %d.\n", search, middle + 1);
                    break;
                }
                else if (array[middle] < search)
                {
                    first = middle + 1;
                }
                else
                {
                    last = middle - 1;
                }
                middle = (first + last) / 2;
            }
            if (first > last)
            {
                printf("\n\n!!NOT FOUND!!\n%d - is not present in the List\n", search);
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
    printf("\n!!Exit!!\n");
    getch();
}
