#include<stdio.h>
#include<string.h>
#include<ctype.h>

int stack[20];
int top=-1;

void push(int val)
{
	stack[++top]=val;
}

int pop()
{
	return (stack[top--]);
}

int main()
{
	int op1,op2,result,i,n;
	char postfix[30],op;
	printf("\nEnter the Postfix Expression : ");
	gets(postfix);
	n = strlen(postfix);
	for(i=0;i<n;i++)
	{
		if(isdigit(postfix[i]))
			push(postfix[i]-'0');
		else
		{
			op=postfix[i];
			op2=pop();
			op1=pop();
			switch(op)
			{
				case '+': push(op1+op2);
						  break;
				case '-': push(op1-op2);
						  break;
				case '*': push(op1*op2);
						  break;
				case '/': push(op1/op2);
						  break;
				case '%': push(op1%op2);
						  break;
			}
		}
	}
	result=pop();
	printf("The Evaluated Value is : %d\n",result);
	return 0;
}
