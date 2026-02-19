//Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.
int maxSubarraySumCircular(int* nums, int numsSize) {
    int totalSum = 0;
    int currMax = nums[0], maxSum = nums[0];
    int currMin = nums[0], minSum = nums[0];

    for (int i = 0; i < numsSize; i++) {
        totalSum += nums[i];

        if (i > 0) {
            currMax = (currMax > 0) ? currMax + nums[i] : nums[i];
            if (currMax > maxSum)
                maxSum = currMax;

            currMin = (currMin < 0) ? currMin + nums[i] : nums[i];
            if (currMin < minSum)
                minSum = currMin;
        }
    }

    if (maxSum < 0)
        return maxSum;

    int circularSum = totalSum - minSum;
    return (maxSum > circularSum) ? maxSum : circularSum;
}
