#include<stdio.h>
void insertionSort(int arr[],int n)
{
    int i,j,Key;
    for (int i = 1; i < n; i++)
    {
        Key=arr[i];
        j=i-1;
        while (j>=0&&arr[j]>Key)
        {
            arr[j]=arr[j+1];//Shifting position to create space for the sorted element which is key.
            j=j-1;
        }
        arr[j+1]=Key;
    }
    
}
void printArray(int arr[],int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d ",arr[i]);
    }
    printf("\n");
}
int main()
{
    int arr[]={12,11,13,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("Original Array:\n");
    printArray(arr,n);
    insertionSort(arr,n);
    printf("Sorted Array:\n");
    printArray(arr,n);
    return 0;
}