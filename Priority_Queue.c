#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	int priority;
	struct node *next;
	
}*front=NULL;

// insertion

void Enqueue()
{
	struct node *n;
	n=(struct node *)malloc(sizeof(struct node));
	int x,pr;
	printf("Enter data and priority to insert in a queue\n");
	scanf("%d%d",&x,&pr);
	n->data=x;
	n->priority=pr;
	if(front==NULL || pr<front->priority)
	{
		n->next=front;
		front=n;
	}
	else
	{
		struct node *temp=front;
		while(temp->next!=NULL && temp->next->priority<=pr)
		{
			temp=temp->next;
		}
		n->next=temp->next;
		temp->next=n;
	}
}

// deletion

void Dequeue()
{
	struct node *temp;
	if(front==NULL)
		printf("Queue Underflow\n");
	else
	{
		temp=front;
		printf("Deleted item is %d\n",temp->data);
		front=front->next;
		free(temp);
	}
}

//displaying

void display()
{
	struct node *p;
	p=front;
	if(front==NULL)
		printf("Queue is Empty\n");
	else
	{
		printf("Queue is :\n");
		printf("Priority     data\n");
		while(p!=NULL)
		{
			printf("%5d     %5d\n",p->priority,p->data);
			p=p->next;
		}
	}
}
int main()
{
	int choice;
	do
	{
		printf("1.Enqueue\t2.Dequeue\t3.Display\t4.Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: Enqueue();
					break;
			case 2: Dequeue();
					break;
			case 3: display();
					break;
			case 4:
					break;
			default:
					printf("Wrong Choice\n");
		}
	}while(choice!=4);
	return 0;
}