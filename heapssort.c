#include <stdio.h>
void swap(int *a, int *b) {
int temp = *a;
*a = *b;
*b = temp; }
void maxHeapify(int arr[], int n, int i) {
int largest = i;
int left = 2 * i + 1;
int right = 2 * i + 2;
if (left < n && arr[left] > arr[largest])
largest = left;


if (right < n && arr[right] > arr[largest])
largest = right;

printArray(arr,n);
if (largest != i)
{
swap(&arr[i], &arr[largest]);
maxHeapify(arr, n, largest);
} }
void buildMaxHeap(int arr[], int n) {
for (int i = n / 2 - 1; i >= 0; i--)
{
maxHeapify(arr, n, i);
} }


void heapSort(int arr[], int n) {
buildMaxHeap(arr, n);
for (int i = n - 1; i > 0; i--)
{
swap(&arr[0], &arr[i]);
printArray(arr,n);
maxHeapify(arr, i, 0);
} }
void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
    printf("\n"); 
}
void printFinnalArray(int arr[] , int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main() {
int arr[] = {9,4,7,1,-2,6};
int n = sizeof(arr) / sizeof(arr[0]);
printf("Original array: \n");
printArray(arr, n);
printf("\nNow!!\n\nDisplaying the step by step changes in the array:\n\n");
heapSort(arr, n);
printf("Sorted array in descending order: \n");
printFinnalArray(arr,n);
return 0; }