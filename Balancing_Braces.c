#include<stdio.h>
#include<string.h>
#define MAX 100
char stack[MAX];
int top = -1;

void push(char ch)
{
    top = top + 1;
    stack[top] = ch;
}

char pop()
{
    char ch;
    if (top == -1)
        return -1;
    else
    {
        ch = stack[top];
        top = top - 1;
        return ch;
    }
}

int is_match(char a, char b)
{
    if (a == '(' && b == ')')
        return 1;
    else if (a == '{' && b == '}')
        return 1;
    else if (a == '[' && b == ']')
        return 1;
    else
        return 0;
}

int check_braces(char exp[])
{
    int i;
    char temp;
    for (i = 0; i < strlen(exp); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            temp = pop();
            if (!is_match(temp, exp[i]))
                return 0;
        }
    }
    if (top == -1)
        return 1;
    else
        return 0;
}

int main()
{
    char exp[100];
    printf("Enter an expression: ");
    scanf("%s", exp);
    if (check_braces(exp))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");
    return 0;
}

