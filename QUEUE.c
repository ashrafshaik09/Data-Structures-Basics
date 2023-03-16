#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
void enqueue(int);
void dequeue(void);
void display(void);
struct queue{
	int que[SIZE];
	int front,rear;
}q;
main(){
	int option,val;
	q.front=-1;
	q.rear=-1;
	while(1){
		printf("1.enqueue\t2.dequeue\t3.display\tothers exit\n");
		scanf("%d",&option);
		switch(option){
			case 1:
				scanf("%d",&val);
				enqueue(val);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			default:
				exit(0);
		}
	}
	return 0;
}
void enqueue(int val){
	if(q.rear==SIZE-1)
	 printf("queue is overflow\n");
	else
	{
		if(q.front==-1)
		 q.front++;
		q.que[++q.rear]=val;
	}
}
void dequeue(){
	if(q.front==-1||q.front>q.rear)
	 printf("queue is underflow\n");
	else
	 printf("dequeued val=%d\n",q.que[q.front++]);
}
void display(){
	int i;
	if(q.front==-1||q.front>q.rear)
	 printf("queue is empty\n");
	else
	 {
	 	for(i=q.front;i<=q.rear;i++)
	 	 printf("%d ",q.que[i]);
	 	printf("\n");
	 }
}

