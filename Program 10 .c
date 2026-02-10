// Read a string and check if it is a palindrome using two-pointer comparison.

#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int l = 0, r = strlen(s) - 1;
    int flag = 1;

    while (l < r) {
        if (s[l] != s[r]) {
            flag = 0;
            break;
        }
        l++;
        r--;
    }

    if (flag)
        printf("YES");
    else
        printf("NO");

    return 0;
}
