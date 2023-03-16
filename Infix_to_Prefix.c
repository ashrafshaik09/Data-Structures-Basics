#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char c)
{
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void reverse(char *str)
{
    int len = strlen(str);
    int i, j;
    char temp;
    for(i = 0, j = len-1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void infixToPrefix(char *infix, char *prefix)
{
    int i, j = 0;
    int len = strlen(infix);
    reverse(infix);
    for(i = 0; i < len; i++)
    {
        if(isalpha(infix[i]) || isdigit(infix[i]))
            prefix[j++] = infix[i];
        else if(infix[i] == ')')
            push(infix[i]);
        else if(infix[i] == '(')
        {
            while(stack[top] != ')')
                prefix[j++] = pop();
            pop();
        }
        else
        {
            while(priority(stack[top]) >= priority(infix[i]))
                prefix[j++] = pop();
            push(infix[i]);
        }
    }
    while(top != -1)
        prefix[j++] = pop();
    prefix[j] = '\0';
    reverse(prefix);
}

int main()
{
    char infix[MAX];
    char prefix[MAX];
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    infixToPrefix(infix, prefix);
    printf("The prefix expression is: %s", prefix);
    return 0;
}

