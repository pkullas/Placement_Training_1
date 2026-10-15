#include <stdio.h>

void inputArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void printArray(int arr[], int n)
{
    printf("Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int sumArray(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    inputArray(arr, n);
    printArray(arr, n);

    int total = sumArray(arr, n);
    printf("Sum of array elements = %d\n", total);

    return 0;
}
