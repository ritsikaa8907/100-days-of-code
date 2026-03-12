//You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

#include <stdio.h>

void slidingWindowMax(int nums[], int n, int k)
{
    int dq[n]; 
    int front = 0, rear = -1;

    for(int i = 0; i < n; i++)
    {
        if(front <= rear && dq[front] <= i - k)
            front++;

        while(front <= rear && nums[dq[rear]] < nums[i])
            rear--;

        dq[++rear] = i;

        if(i >= k - 1)
            printf("%d ", nums[dq[front]]);
    }
}

int main()
{
    int nums[] = {1,3,-1,-3,5,3,6,7};
    int n = 8;
    int k = 3;

    slidingWindowMax(nums, n, k);

    return 0;
}
