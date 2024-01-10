#include<stdio.h>
int main()
{
    int a, var, sum=0;
    do
    {
        printf("Enter the number : ");
        scanf("%d",& a);
        sum = sum+ a;
        printf("\nDo you want to continue ? if yes then enter 0. ");
        scanf("%d",& var);
    } while (var==0);
    printf("The result is %d ",sum);
    return 0;
}