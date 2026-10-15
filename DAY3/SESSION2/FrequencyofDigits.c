#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;
    int *freq;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        num = -num;
    }

    freq = (int *)calloc(10, sizeof(int));
    if (freq == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    while (num > 0) {
        int digit = num % 10;
        freq[digit]++;
        num /= 10;
    }

    printf("Frequency of each digit:\n");
    for (int i = 0; i < 10; i++) {
        printf("Digit %d: %d\n", i, freq[i]);
    }

    free(freq);
    return 0;
}