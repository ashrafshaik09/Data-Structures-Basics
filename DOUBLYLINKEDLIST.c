#include<stdio.h>
#include<stdlib.h>
void display(void);
void insertion_beginning(int);
void insertion_middle(int,int);
void insertion_last(int);
void deletion_beginning(void);
void deletion_last(void);
void deletion_middle(int);
struct dnode{
	int data;
	struct dnode *next;
	struct dnode *prev;
}*head=NULL;
main()
{
	int option,val,pos,item;
	while(1)
	{
		printf("1.display\t2.insertion_beginning\t3.insertion_middle\t4.insertion_last\t5.deletion_beginning\t6.deletion_last\t7.deletion_middle\tothers exit\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				display();
				break;
			case 2:
				scanf("%d",&val);
				insertion_beginning(val);
				break;
			case 3:
			    scanf("%d",&val);
				scanf("%d",&pos);
				insertion_middle(val,pos);
				break;
			case 4:
				scanf("%d",&val);
				insertion_last(val);
				break;
			case 5: deletion_beginning();
			        break;
			case 6: deletion_last();
			        break;
			case 7: scanf("%d",&pos);
			        deletion_middle(pos);
			        break;	
			default :
			        exit(0);		
			   		
		}
	}
	return 0;
}
void display()
{
	struct dnode *p;
	printf("Printing Values...\n");
	p=head;
	while(p!=NULL)
	{
		printf("%d\t",p->data);
		p=p->next;
	}
	printf("\n");
}
void insertion_beginning(int item)
{
	struct dnode *n;
	n=(struct dnode*)malloc(sizeof(struct dnode));
	if(head==NULL)
	{
		n->next=NULL;
		n->prev=NULL;
		n->data=item;
		head=n;
	}
	else
	{
		n->data=item;
		n->prev=NULL;
		n->next=head;
		head->prev=n;
		head=n;
	}
	printf("Node Inserted\n");
}
void insertion_middle(int loc,int item)
{
	struct dnode *n,*temp;
	int i;
	n=(struct dnode*)malloc(sizeof(struct dnode));
	if(n==NULL)
		printf("\nOVERFLOW\n");
	else
	{
		temp=head;
		for(i=1;i<loc-1;i++)
		{
			temp=temp->next;
			if(temp==NULL)
			{
				printf("There are less than %d elements",loc);
				return;
		    }
		}
		n->data=item;
		n->next=temp->next;
		temp->next->prev=n;
		n->prev=temp;
		temp->next=n;
		printf("\n Node Inserted \n");
	}
}
void insertion_last(int item)
{
	struct dnode *n,*temp;
	n=(struct dnode*)malloc(sizeof(struct dnode));
	if(n==NULL)
		printf("\nOVERFLOW\n");
	else
	{
		n->data=item;
		if(head==NULL)
		{
			n->next=NULL;
			n->prev=NULL;
			head=n;
		}
		else
		{
			temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=n;
			n->prev=temp;
			n->next=NULL;
		}
	}
	printf("\n Node Inserted \n");
}
void deletion_beginning()
{
	struct dnode *p;
	if(head==NULL)
		printf("\n UNDERFLOW \n");
	else if(head->next==NULL)
	{
		head=NULL;
		free(head);
		printf("\n Node Deleted \n");
	}
	else
	{
		p=head;
		head=head->next;
		head->prev=NULL;
		free(p);
		printf("\n Node Deleted \n");
	}
}
void deletion_last()
{
	struct dnode *p;
	if(head==NULL)
		printf("\n UNDERFLOW \n");
	else if(head->next==NULL)
	{
		head=NULL;
		free(head);
		printf("\n Node Deleted \n");
	}
	else
	{
		p=head;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->prev->next=NULL;
		free(p);
		printf("\n Node Deleted \n");
	}
}
void deletion_middle(int item)
{
	struct dnode *p,*temp;
	p=head;
	while(p->data!=item)
	{
		p=p->next;
	}
	if(p->next==NULL)
		printf("\n Can't Delete \n");
	else if(p->next->next==NULL)
		p->next=NULL;
	else
	{
		temp=p->next;
		p->next=temp->next;
		temp->next->prev=p;
		free(temp);
		printf("\n Node Deleted \n");
	}
}