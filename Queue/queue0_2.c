//implementing queue using singly link list
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
}*front = 0, *rear = 0;

typedef struct node Node;
void enqueue(int x);
void dequeue();
void peek();
void display();

int main(void)
{
	int choice, x;
	
	do
	{
		printf("1: Insert into queue\n");
		printf("2: Delete from the queue\n");
		printf("3: Peek value\n");
		printf("4: Display\n");
		printf("5: Exit\n");
		
		printf("Enter choice: ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter data\n");
				scanf("%d", &x);
				enqueue(x);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				peek();
				break;
			case 4:
				display();
				break;
			default:
				break;
		}
		printf("\n");
	}while(choice!=5);
} 

//function to insert value in the queue
void enqueue(int x)
{
	Node *new;
	
	new = (Node *)malloc(sizeof(Node));
	new->data = x;
	
	if(front == 0)
	{
		front = new;
		rear = new;
	}
	
	else
	{
		rear->link = new;
		rear = new;
	}
	new->link = 0;
}

//function to delete value from the queue
void dequeue()
{
	Node *firstnode;
	
	if(front == 0)
		printf("Queue is empty\n");
	else
	{
		firstnode = front;
		printf("Deleted value is: %d", firstnode->data);
		front = front->link;
	}
	free(firstnode);
}

//function to find peek value from the queue
void peek()
{
	if(front == 0)
		printf("Queue is empty\n");
	else
		printf("Peek value in the queue: %d\n", front->data);
	
}

//function to display the value of the queue
void display()
{
	Node *p;
	if(front == 0)
		printf("Queue is empty\n");
	else
	{
		p = front;
		while(p!=0)
		{
			printf("| %d |\n", p->data);
			p = p->link;
		}
		
	}
}