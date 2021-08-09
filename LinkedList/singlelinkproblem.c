//insert odd number at the first five node and then insert even
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};

typedef struct node Node;

Node *create_list(Node *);
void printlist(Node *);

int main()
{
	Node *head = 0;
	
	int choice;
	
	while(1)
	{
		printf("1: Create list\n");
		printf("2: Display list\n");
		printf("3: Exit\n");
		
		printf("Enter choice\n");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				head = create_list(head);
				break;
			case 2:
				printlist(head);
				break;
			case 3:
				exit(1);
			default :
				printf("Wrong choice\n");
		}
		
		printf("\n");
		
		
	}
	
}

Node *create_list(Node *start)
{
	Node *temp, *new;
	int odd = 1, even = 2, cnt = 0;
	int choice;
	
	while(1)
	{
		printf("Enter 1 to fill the data in the list\n");
		scanf("%d", &choice);
		if(choice!=1)
			break;
		
		new = (Node*)malloc(sizeof(Node));
		if(cnt<5)
		{
			new->info = odd;
			odd+=2;
		}
		else
		{
			new->info = even;
			even+=2;
		}
		
		if(start==0)
		{
			start = new;
			temp = start;
		}
		else
		{
			temp->link = new;
			temp = temp->link;
			
		}
		new->link = 0;
		cnt++;	
	}
	
	return start;
	free(new);
}

void printlist(Node *t)
{
	Node *p;
	
	if(t==0)
		printf("Empty list\n");
	else
	{
		printf("Elements in the list\n");
		p = t;
		while(p!=0)
		{
			printf("%d ", p->info);
			p = p->link;
		}
	}
}