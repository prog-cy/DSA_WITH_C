//implementing stack using array
#include<stdio.h>
#include<stdlib.h>
#define size 7

int stack[size];
int top = -1;

void push();
void pop();
void peek();
int isfull();
int isEmpty();
void display();

int main(void)
{
    int choice;

    while (1)
    {
        printf("1: push element\n");
        printf("2: pop element\n");
        printf("3: peek element\n");
        printf("4: check stack is full\n");
        printf("5: check stack is empty\n");
        printf("6: Display\n");
        printf("7: Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            if(isfull())
                printf("Stack is full\n");
            else
            {
                printf("Stack is not full\n");
            }
            break;
        case 5:
            if(isEmpty())
                printf("Stack is empty\n");
            else
            {
                
                printf("Stack is not empty\n");
            }
            break;
        case 6:
            display();
            break;
        case 7:
            exit(1);
        default:
            printf("Wrong choice\n");
        }

        printf("\n");
    }
    
}

//function to push element in the stack
void push()
{
    int data;
    printf("Enter data: ");
    scanf("%d", &data);

    if(isfull())
        printf("Overflow\n");
    else
    {
        top++;
        stack[top] = data;
    }
    
}

//function to pop element from the stack
void pop()
{
    int item;

    if(isEmpty())
        printf("Under flow\n");
    else
    {
        item = stack[top];
        printf("Deleted item is: %d", item);
        top--;
    }
    
}

//function to find top element in the stack
void peek()
{
    if(isfull())
        printf("Over flow\n");
    else if(isEmpty())
        printf("Under flow\n");
    else
    {
        printf("peek element: %d", stack[top]);
    }
    
    
}

//function to check overflow in stack
int isfull()
{
    if(top == size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

//function to check under flow 
int isEmpty()
{
    if(top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//function to display stack element
void display()
{
    if(isEmpty())
        printf("Stack is empty\n");
    else
    {
        printf("values in stack\n");
        for(int i=top; i>=0; i--)
            printf("%d\n", stack[i]);
    }
    
}