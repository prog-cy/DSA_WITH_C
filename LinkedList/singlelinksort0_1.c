//sorting a single link list
#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *link;
};

typedef struct node Node;
Node *head = 0, *tail = 0;

void create_list(Node *start);
void display(Node *head);
void sort(Node *head);
void max();
void min();

int main(void)
{	
	int choice;
	
	while(1)
	{
		printf("1: Creating a list\n");
		printf("2: display\n");
		printf("3: sort a list\n");
		printf("4: max value in the list\n");
		printf("5: min value in the list\n");
		printf("6: Exit\n");
		
		printf("Enter choice: ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				create_list(head);
				break;
			case 2:
				display(head);
				break;
			case 3:
				sort(head);
				break;
			case 4:
				max();
				break;
			case 5:
				min();
				break;
			case 6:
				exit(1);
			default:
				printf("Invalid position\n");
				
		}
		printf("\n");
	}
}

//function for creating a single link list
void create_list(Node *start)
{
	Node *new, *temp;
	int choice;
	
	while(1)
	{
		printf("Enter 1 to create new node and  0 to quit: ");
		scanf("%d", &choice);
		if(choice !=1)
			break;
		new = (Node *)malloc(sizeof(Node));
		scanf("%d", &new->data);
		
		if(start == 0)
		{
			start = new;
			temp = start;
		}
		
		else
		{
			temp->link = new;
			temp = new;
		}
		new->link = 0;
		
	}
	head = start;
	tail = temp;
}

//function to display a list
void display(Node *head)
{
	Node *p;
	
	if(head == 0)
		printf("List is empty\n");
	else
	{
		p = head;
		
		while(p!=0)
		{
			printf("%d ", p->data);
			p = p->link;
		}
	}
}

//function to sort list in ascending order using selection sort
void sort(Node *head)
{
	Node *current , *next;
	int val;
	
	if(head == 0)
		printf("List is empty\n");
	else
	{
		current = head;
		next = current->link;
		while(current->link!=0)
		{
			while(next!=0)
			{
				if(current->data>next->data)
				{
					val = current->data;
					current->data = next->data;
					next->data = val;
				}
				next = next->link;
			}
			
			current = current->link;
			next = current->link;
		}
	}
}

//function to find max in a single sorted link list
void max()
{
	if(head == 0)
		printf("List is empty");
	printf("Max value in the list is: %d\n", tail->data);
}

//function to find min value in a single sorted link list
void min()
{
	if(head == 0)
		printf("List is empty");
	printf("Min value in the list is: %d\n", head->data);
}