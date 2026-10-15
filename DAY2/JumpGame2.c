#include<stdio.h>
int main()
{
    int max=0,n,count=0;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]); 
    }
    for(int i=0;i<n;i+=arr[i])
    {
        printf("%d ",arr[i]+i);
        if(arr[i]==0)
        {
            printf("\nCannot jump further from index %d\n",i);
            printf("False\n");
            break;
        }
        printf("True\n");
        count++;
        printf("Number of count is %d",count);

    }
    return 0;
}