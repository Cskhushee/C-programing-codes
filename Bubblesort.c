#include <stdio.h>

void bubblesort(int arr[], int n)
{
    int i , j;
    for (i=0;i<n-1;i++)
    {
        for (int j = 0; j < n-i; j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
            
        }
        
    }
}

int main()
{
    int arr[]={64,25,12,22,11};
    int n=sizeof(arr)/sizeof(arr[0]);
    bubblesort(arr,n);
    printf("Sorted Array:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ",arr[i]);
    }
    return 0;
}