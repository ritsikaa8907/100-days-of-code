//Problem Statement: Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.
#include <stdio.h>

int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pages = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages)
            return 0;

        if (pages + arr[i] <= maxPages) {
            pages += arr[i];
        } else {
            students++;
            pages = arr[i];

            if (students > m)
                return 0;
        }
    }

    return 1;
}

int findMinPages(int arr[], int n, int m) {
    if (m > n) return -1;

    int low = arr[0], high = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > low)
            low = arr[i];
        high += arr[i];
    }

    int result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, n, m, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    int arr[] = {12, 34, 67, 90};
    int n = 4;
    int m = 2;

    printf("Minimum pages: %d\n", findMinPages(arr, n, m));

    return 0;
}
