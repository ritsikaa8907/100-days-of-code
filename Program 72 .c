//Given a string s consisting of lowercase letters, find the first repeated character in the string. A character is considered repeated if it appears more than once, and among all such characters, the one whose second occurrence has the smallest index should be returned.
#include <stdio.h>

char firstRepeated(char *s) {
    int seen[26] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        int idx = s[i] - 'a';

        if (seen[idx] == 1)
            return s[i];

        seen[idx] = 1;
    }

    return '#';
}

int main() {
    char s[] = "abccbaacz";
    printf("%c\n", firstRepeated(s));
    return 0;
}
