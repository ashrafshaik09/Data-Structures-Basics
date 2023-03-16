#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
void push(int);
void pop(void);
void peek(void);
void display(void);
struct stack{
	int stk[SIZE];
	int top;
}s;
main(){
	int option,val;
	s.top=-1;
	while(1){
		printf("1.push\t2.pop\t3.peek\t4.display\tothers exit\n");
		scanf("%d",&option);
		switch(option){
			case 1:
				scanf("%d",&val);
				push(val);
				break;
			case 2:
				pop();
				break;
			case 3:
				peek();
				break;
			case 4:
				display();
				break;
			default:
				exit(0);
		}
	}
	return 0;
}
void push(int val){
	if(s.top==SIZE-1)
	 printf("Stack is overflow\n");
	else{
		s.top++;
		s.stk[s.top]=val;
		//s.stk[++s.top]=val;
	}
}
void pop(){
	if(s.top==-1)
	 printf("Stack is underflow\n");
	else
	 printf("Pop Val=%d\n",s.stk[s.top--]);
}
void peek(){
	if(s.top==-1)
	 printf("Stack is empty\n");
	else 
	 printf("peek val=%d\n",s.stk[s.top]);
}
void display(){
	int i;
	if(s.top==-1)
	 printf("Stack is empty\n");
	else{
	  for(i=0;i<=s.top;i++)
	   printf("%d\n",s.stk[i]);	
	}
}

