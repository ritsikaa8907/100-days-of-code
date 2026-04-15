//Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.
 #include <stdio.h>

char firstNonRepeating(char *s) {
    int freq[26] = {0};

    for (int i = 0; s[i] != '\0'; i++)
        freq[s[i] - 'a']++;

    for (int i = 0; s[i] != '\0'; i++) {
        if (freq[s[i] - 'a'] == 1)
            return s[i];
    }

    return '$';
}

int main() {
    char s[] = "aabbcde";
    printf("%c\n", firstNonRepeating(s));
    return 0;
}
