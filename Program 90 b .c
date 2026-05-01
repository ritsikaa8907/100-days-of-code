//Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.cReturn the minimized largest sum of the split.
int canSplit(int* nums, int n, int k, int maxSum) {
    int count = 1;
    int curr = 0;

    for (int i = 0; i < n; i++) {
        if (curr + nums[i] <= maxSum) {
            curr += nums[i];
        } else {
            count++;
            curr = nums[i];
            if (count > k) return 0;
        }
    }
    return 1;
}

int splitArray(int* nums, int numsSize, int k) {
    int low = 0, high = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > low)
            low = nums[i];
        high += nums[i];
    }

    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canSplit(nums, numsSize, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}
