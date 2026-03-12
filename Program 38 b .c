//Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    int* freq = (int*)calloc(20001, sizeof(int));
    
    for (int i = 0; i < numsSize; i++)
        freq[nums[i] + 10000]++;

    int* result = (int*)malloc(sizeof(int) * k);

    for (int i = 0; i < k; i++) {
        int max = 0, index = -1;

        for (int j = 0; j < 20001; j++) {
            if (freq[j] > max) {
                max = freq[j];
                index = j;
            }
        }

        result[i] = index - 10000;
        freq[index] = 0;
    }

    *returnSize = k;
    return result;
}
