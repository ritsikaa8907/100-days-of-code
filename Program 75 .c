//Problem Statement: Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    int value;
    struct Node* next;
};

#define SIZE 1000

int hash(int key) {
    return abs(key) % SIZE;
}

void insert(struct Node* hashMap[], int key, int value) {
    int index = hash(key);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = hashMap[index];
    hashMap[index] = newNode;
}

// Search in hashmap
int search(struct Node* hashMap[], int key) {
    int index = hash(key);
    struct Node* temp = hashMap[index];
    
    while (temp != NULL) {
        if (temp->key == key)
            return temp->value;
        temp = temp->next;
    }
    return -1;
}

int maxLenZeroSum(int arr[], int n) {
    struct Node* hashMap[SIZE] = {NULL};
    
    int sum = 0, maxLen = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0)
            maxLen = i + 1;

        int prevIndex = search(hashMap, sum);
        if (prevIndex != -1) {
            int length = i - prevIndex;
            if (length > maxLen)
                maxLen = length;
        } else {
            insert(hashMap, sum, i);
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Length of longest subarray with sum 0: %d\n", maxLenZeroSum(arr, n));

    return 0;
}
