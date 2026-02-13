//Given an m x n matrix, return all elements of the matrix in spiral order.
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int rows = matrixSize;
    int cols = matrixColSize[0];
    int total = rows * cols;

    int* result = (int*)malloc(total * sizeof(int));
    *returnSize = total;

    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;
    int k = 0;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++)
            result[k++] = matrix[top][i];
        top++;

        for (int i = top; i <= bottom; i++)
            result[k++] = matrix[i][right];
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                result[k++] = matrix[bottom][i];
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                result[k++] = matrix[i][left];
            left++;
        }
    }

    return result;
}
