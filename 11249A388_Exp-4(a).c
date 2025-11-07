
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char c) {
    if (top == MAX - 1)
        printf("Stack overflow\n");
    else
        stack[++top] = c;
}
char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}
int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}
void infixToPostfix(char infix[]) {
    char postfix[MAX];
    int i, j = 0;
    char ch;
    for (i = 0; i < strlen(infix); i++) {
        ch = infix[i];
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while ((stack[top] != '(') && (top != -1))
                postfix[j++] = pop();
            pop(); // remove '(' from stack
        }
        else {
            while (precedence(stack[top]) >= precedence(ch))
                postfix[j++] = pop();
            push(ch);
        }
    }
    while (top != -1)
        postfix[j++] = pop();
    postfix[j] = '\0';
    printf("\nPostfix Expression: %s\n", postfix);
}
int main() {
    char infix[MAX];
    printf("Enter Infix Expression: ");
    gets(infix);
    infixToPostfix(infix);
    return 0;
}
