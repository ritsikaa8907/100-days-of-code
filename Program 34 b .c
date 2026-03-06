//Given a string s which represents an expression, evaluate this expression and return its value. 
int calculate(char *s) {
    long num = 0, last = 0, result = 0;
    char op = '+';

    for (int i = 0; s[i]; i++) {
        if (s[i] >= '0' && s[i] <= '9')
            num = num * 10 + (s[i] - '0');

        if ((s[i] < '0' || s[i] > '9') && s[i] != ' ' || s[i+1] == '\0') {

            if (op == '+') {
                result += last;
                last = num;
            }
            else if (op == '-') {
                result += last;
                last = -num;
            }
            else if (op == '*') {
                last = last * num;
            }
            else if (op == '/') {
                last = last / num;
            }

            op = s[i];
            num = 0;
        }
    }

    result += last;
    return result;
}
