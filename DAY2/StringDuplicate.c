#include<stdio.h>
int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    char arr[n];
    for(int i=0;i<n;i++)
    {
        scanf(" %c",&arr[i]); 
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j])
            {
                printf("Duplicate element is %c\n",arr[i]);
                break;
            }
        }
    }
    
} 