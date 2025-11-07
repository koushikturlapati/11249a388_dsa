
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int x) {
    stack[++top] = x;
}
int pop() {
    return stack[top--];
}
int evaluatePostfix(char* exp) {
    int i;
    for (i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];
        if (isdigit(ch)) {
            push(ch - '0');
        }
        else {
            int val1 = pop();
            int val2 = pop();
            switch (ch) {
                case '+': push(val2 + val1); break;
                case '-': push(val2 - val1); break;
                case '*': push(val2 * val1); break;
                case '/': push(val2 / val1); break;
            }
        }
    }
    return pop();
}
int main() {
    char exp[100];
    printf("Enter a postfix expression: ");
    scanf("%s", exp);
    printf("Result of postfix evaluation: %d\n", evaluatePostfix(exp));
    return 0;
}
