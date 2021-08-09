//implemetation of circular queue using Arrays
#include<stdio.h>
#define size 5

int front = -1;
int rear = -1;
int queue[size];

void enqueue(int a);
void dequeue();
void peek();
void display();
int isFull();
int isEmpty();

int main(void)
{
	int choice, x;
	do
	{
		printf("1: Enqueue\n");
		printf("2: Dequeue\n");
		printf("3: peek\n");
		printf("4: Display\n");
		printf("5: Check queue is full or not\n");
		printf("6: Check queue is empty or not\n");
		printf("7: Exit\n");
		
		printf("Enter choice: ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter data which you want to insert in the queue\n");
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
			case 5:
				isFull();
				break;
			case 6:
				isEmpty();
				break;
			default:
				break;
				
		}
	}while(choice!=7);
}

//function to insert in the queue
void enqueue(int a)
{
	if(rear == size-1)
		printf("overflow\n");
	else if(front == -1&& rear == -1)
	{
		front = rear = 0;
	}
	else
	{
		rear++;	
	}
	queue[rear] = a;
}

//function to delete from the queue
void dequeue()
{
	if(isEmpty())
		printf("Under flow\n");
	else if(front == rear)
		front = rear  = -1;
	else
	{
		printf("Deleted value is: %d\n",queue[front]);
		front++;
	}
	
}

//function to find the peek value
void peek()
{
	if(isEmpty())
		printf("Queue is empty\n");
	else
		printf("Peek value in the queue is: %d\n", queue[front]);

}

//function to display the value of the queue
void display()
{
	if(isEmpty())
		printf("Queue is empty\n");
	else
	{
		printf("\n");
		for(int i = front; i<=rear; i++)
			printf("| %d |\n", queue[i]);
		printf("\n");
		
	}
}

//function to check that queue is full or not
int isFull()
{
	if(rear == size-1)
		return 1;
	else 
		return 0;
}

//function to check that queue is empty or not
int isEmpty()
{
	if(front == -1 && rear == -1)
		return 1;
	else
		return 0;
}
