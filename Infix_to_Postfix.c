#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/' || c=='%')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char c;
    for (i = 0; infix[i]; i++) {
        c = infix[i];
        if (isalnum(c))
            postfix[j++] = c;
        else if (c == '(')
            push(c);
        else if (c == ')') {
            while ((c = pop()) != '(')
                postfix[j++] = c;
        } else {
            while (priority(stack[top]) >= priority(c))
                postfix[j++] = pop();
            push(c);
        }
    }
    while (top != -1)
        postfix[j++] = pop();
    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}

