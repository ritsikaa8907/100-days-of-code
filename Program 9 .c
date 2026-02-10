// A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.
#include <stdio.h>
#include <string.h>

void reverse(char s[], int l, int r) {
    if (l >= r)
        return;
    char temp = s[l];
    s[l] = s[r];
    s[r] = temp;
    reverse(s, l + 1, r - 1);
}

int main() {
    char s[1000];
    scanf("%s", s);
    reverse(s, 0, strlen(s) - 1);
    printf("%s", s);
    return 0;
}
