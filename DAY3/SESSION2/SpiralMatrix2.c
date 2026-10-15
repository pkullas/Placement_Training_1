
#include <stdio.h>
#include <stdlib.h>

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    int** matrix = (int**)malloc(n * sizeof(int*));

    *returnSize = n;
    *returnColumnSizes = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
    }

    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    int num = 1;

    while (top <= bottom && left <= right) {
        // Left to right
        for (int i = left; i <= right; i++) {
            matrix[top][i] = num++;
        }
        top++;

        // Top to bottom
        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = num++;
        }
        right--;

        // Right to left
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = num++;
            }
            bottom--;
        }

        // Bottom to top
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = num++;
            }
            left++;
        }
    }

    return matrix;
}

int main(void) {
    int n = 3;
    int returnSize;
    int* returnColumnSizes;

    int** matrix = generateMatrix(
        n, &returnSize, &returnColumnSizes
    );

    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < returnSize; i++) {
        free(matrix[i]);
    }

    free(matrix);
    free(returnColumnSizes);

    return 0;
}
