#include<stdio.h>

int main()
{
    int n, i, j, duplicateFound = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                printf("Duplicate element is %d\n", arr[i]);
                duplicateFound = 1;
                break;
            }
        }
        if (duplicateFound)
        {
            break;
        }
    }

    if (!duplicateFound)
    {
        printf("No duplicate elements found.\n");
    }

    return 0;
}