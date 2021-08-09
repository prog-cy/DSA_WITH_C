//queue implementation using stack
#include<stdio.h>
#define size 10

int count = 0;
int top1 = -1, top2 = -1;
int s1[size], s2[size];

void push1(int data);
void enqueue(int data);
int pop1();
void push2(int val);
int pop2();
void dequeue();
void display();
void peek();

int main(void)
{
	int choice ,data;
	do
	{
		printf("1: Insert element in the queue\n");
		printf("2: Delete element form  the queue\n");
		printf("3: Display queue element\n");
		printf("4: peek element in queue\n");
		printf("5: Quit\n");
		
		printf("Enter the choice: ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter data\n");
				scanf("%d", &data);
				enqueue(data);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				peek();
			default:
				break;
				
		}
		printf("\n");
	}while(choice!=5);
}

//function to push data in the stack1
void push1(int data)
{
	if (top1 == size-1)
		printf("Overflow\n");
	else
	{
		top1++;
		s1[top1] = data;
	}
}

//function to insert data in the queue
void enqueue(int data)
{
	push1(data);
	count++;
}

//function to pop data from the stack 1
int pop1()
{
	if(top1 == -1)
		return 0;
	else
		return s1[top1--];
}

//function to push data in stack 2
void push2(int val)
{
	top2++;
	s2[top2] = val;
}

//function to pop data from the stack2
int pop2()
{
	if(top2== -1)
		return 0;
	else
		return s2[top2--];
		
}

//function to delete data from the queue
void dequeue()
{
	int  a, b;
	for (int i = 0; i<count; i++)
	{
		a = pop1();
		push2(a);
	}
	if(top2 == -1)
		printf("Underflow\n");
	else
		printf("Deleted data from the queue: %d", pop2());
	count--;
	for(int i =0; i<count;i++)
	{
		b = pop2();
		push1(b);
	}
		
} 

//display data from the queue
void display()
{
	if(top1 == -1)
		printf("Queue is empty\n");
	else
	{
		printf("Eleemnts in the queue\n");
		for(int i = 0;i<count;i++)
			printf("|%d|\n", s1[i]);
	}
}

//display peek element from the queue
void peek()
{
	if(top1 == -1)
		printf("Queue is empty\n");
	else
	{
		printf("Peek value in the queue: %d", s1[0]);
	}
}
