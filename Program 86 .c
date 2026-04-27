//Problem: Find the integer square root of a given non-negative integer using Binary Search. The integer square root of a number is defined as the greatest integer whose square is less than or equal to the given number.
#include <stdio.h>

int intSqrt(int x) {
    int left = 0, right = x, ans = 0;

    while (left <= right) {
        long mid = left + (right - left) / 2;

        if (mid * mid == x)
            return mid;
        else if (mid * mid < x) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return ans;
}

int main() {
    int x = 17;
    printf("Integer square root: %d\n", intSqrt(x));
    return 0;
}
