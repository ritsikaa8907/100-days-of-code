//Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.
#include <stdio.h>
#include <stdlib.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    
    int* answer = (int*)calloc(temperaturesSize, sizeof(int));
    int* stack = (int*)malloc(sizeof(int) * temperaturesSize);
    
    int top = -1;
    *returnSize = temperaturesSize;

    for(int i = 0; i < temperaturesSize; i++) {
        
        while(top >= 0 && temperatures[i] > temperatures[stack[top]]) {
            int prev = stack[top--];
            answer[prev] = i - prev;
        }

        stack[++top] = i;
    }

    free(stack);
    return answer;
}
 
