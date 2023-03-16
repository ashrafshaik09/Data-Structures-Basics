#include<stdio.h>
#include<stdlib.h>
void create(int);
void display(void);
void insertfirst(int);
void insertmiddle();
void deletefirst(void);
void deletelast(void);
void deletemiddle(int);
struct node{
	int data;
	struct node *next;
}*head=NULL;
main()
{
	int option,val,pos;
	while(1)
	{
		printf("1.display\t2.create\t3.insertfirst\t4.insertmiddle\t5.delete first\t6.delete last\t7.delete middle\tothers exit\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				display();
				break;
			case 2:
			    scanf("%d",&val);
			    create(val);
				break;
			case 3:
				scanf("%d",&val);
				insertfirst(val);
				break;
			case 4:
			    scanf("%d",&val);
				scanf("%d",&pos);
				insertmiddle(val,pos);
				break;
			case 5: deletefirst();
			        break;
			case 6: deletelast();
			        break;
			case 7: scanf("%d",&pos);
			        deletemiddle(pos);
			        break;					
			default :
			        exit(0);		
			   		
		}
	}
	return 0;
}
void create(int val)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=NULL;
	if(head==NULL)
	  head=newnode;
	else 
	{
		struct node *t=head;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		
			t->next=newnode;
	}  
}
void display(void)
{
	if(head==NULL)
	printf("linked list is empty\n");
	else {
		struct node *t=head;
		while(t!=NULL)
		{
			printf("%d-->",t->data);
			t=t->next;
		}
		printf("NULL\n");
	}
}
void insertfirst(int val)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		newnode->next=head;
		head=newnode;
	}
}
void insertmiddle(int val, int pos)
{
    struct node *newnode, *p = head, *f = NULL;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    int i;

    if (pos == 1) {
        newnode->next = head;
        head = newnode;
        return;
    }

    for(i = 1; i < pos && p != NULL; i++)
    {
        f = p;
        p = p->next;
    }

    if (p == NULL && i < pos) {
        printf("Position out of range\n");
        free(newnode);
        return;
    }

    f->next = newnode;
    newnode->next = p;
}

void deletefirst(void)
{
	if(head==NULL)
	printf("list is empty\n");
	else {
		struct node *t=head;
		head=head->next;
		free(t);
	}
}
void deletelast(void)
{
	if(head==NULL)
	printf("list is empty\n");
	else 
	{
		struct node *t=head,*f;
		if(head->next==NULL)
		head=head->next;
		else 
		{
			while(t->next!=NULL)
			{
				f=t;
				t=t->next;
			}
			f->next=NULL;
		}
		free(t);				
	}
}
void deletemiddle(int pos)
{
	struct  node *p=head,*f;
	int i;
	for(i=1;i<pos;i++)
	{
		f=p;
		p=p->next;
	}
	f->next=p->next;
	free(p);
}
