
#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize,
                 int* matrixColSize, int* returnSize) {
    int rows = matrixSize;
    int cols = matrixColSize[0];

    int* result = (int*)malloc(rows * cols * sizeof(int));

    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = rows * cols;

    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;
    int k = 0;

    while (top <= bottom && left <= right) {
        // Left to right
        for (int i = left; i <= right; i++) {
            result[k++] = matrix[top][i];
        }
        top++;

        // Top to bottom
        for (int i = top; i <= bottom; i++) {
            result[k++] = matrix[i][right];
        }
        right--;

        // Right to left
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                result[k++] = matrix[bottom][i];
            }
            bottom--;
        }

        // Bottom to top
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result[k++] = matrix[i][left];
            }
            left++;
        }
    }

    return result;
}

int main(void) {
    int row1[] = {1, 2, 3};
    int row2[] = {4, 5, 6};
    int row3[] = {7, 8, 9};

    int* matrix[] = {row1, row2, row3};
    int matrixColSize[] = {3, 3, 3};
    int matrixSize = 3;
    int returnSize = 0;

    int* result = spiralOrder(
        matrix, matrixSize, matrixColSize, &returnSize
    );

    if (result != NULL) {
        printf("Spiral order: ");
        for (int i = 0; i < returnSize; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
        free(result);
    }

    return 0;
}
