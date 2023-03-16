#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 50
int stack[MAX_SIZE];
int top = -1;

void push(int item) {
    stack[++top] = item;
}

int pop() {
    return stack[top--];
}

int evaluate(int operand1, int operand2, char operator) {
    switch (operator) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
    }
    return 0;
}

int evaluatePrefixExpression(char prefixExpression[]) {
    int i, operand1, operand2;
    for (i = strlen(prefixExpression) - 1; i >= 0; i--) {
        if (isdigit(prefixExpression[i])) {
            push(prefixExpression[i] - '0');
        } else {
            operand2 = pop();
            operand1 = pop();
            push(evaluate(operand1, operand2, prefixExpression[i]));
        }
    }
    return stack[top];
}

int main() {
    char prefixExpression[MAX_SIZE];
    printf("Enter a valid prefix expression: ");
    scanf("%s", prefixExpression);
    printf("Evaluated result: %d\n", evaluatePrefixExpression(prefixExpression));
    return 0;
}

