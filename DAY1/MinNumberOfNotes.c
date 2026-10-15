#include<stdio.h>
int main()
{
    int amount, notes;
    printf("Enter the amount: ");
    scanf("%d", &amount);
    int changes[] = {100, 50, 20, 10, 5, 2, 1};
    notes = 0;
    for(int i=0;i<7;i++){
        notes += amount / changes[i];
        amount %= changes[i];
    }
    printf("Minimum number of notes required: %d\n", notes);
    return 0;
}