// You are given an array arr[] of size n - 1 that contains distinct integers in the range from 1 to n (inclusive). This array represents a permutation of the integers from 1 to n with one element missing. Your task is to identify and return the missing element.

int missingNumber(int* arr, int arrSize) {
    int n = arrSize + 1;
    int xor = 0;

    for (int i = 1; i <= n; i++)
        xor ^= i;

    for (int i = 0; i < arrSize; i++)
        xor ^= arr[i];

    return xor;
}
