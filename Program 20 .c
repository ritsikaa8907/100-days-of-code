//Given an array of integers, count the number of subarrays whose sum is equal to zero.
#include <stdio.h>

int countZeroSumSubarrays(int arr[], int n) {
    int sum = 0, count = 0;
    
    int freq[1000] = {0};
    
    freq[0] = 1; 
    
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        
        if(freq[sum] != 0) {
            count += freq[sum];
        }
        
        freq[sum]++;
    }
    
    return count;
}

int main() {
    int arr[] = {6, -1, -3, 4, -2, 2, 4, 6, -12, -7};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Count = %d", countZeroSumSubarrays(arr, n));
    
    return 0;
}
