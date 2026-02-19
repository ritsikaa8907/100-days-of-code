//Given an array of integers, find two elements whose sum is closest to zero.
#include <stdlib.h>
#include <math.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* twoSumClosestToZero(int* nums, int numsSize, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), compare);

    int left = 0;
    int right = numsSize - 1;

    int minSum = nums[left] + nums[right];
    int* result = (int*)malloc(2 * sizeof(int));

    result[0] = nums[left];
    result[1] = nums[right];

    while (left < right) {
        int sum = nums[left] + nums[right];

        if (abs(sum) < abs(minSum)) {
            minSum = sum;
            result[0] = nums[left];
            result[1] = nums[right];
        }

        if (sum < 0)
            left++;
        else
            right--;
    }

    *returnSize = 2;
    return result;
}
