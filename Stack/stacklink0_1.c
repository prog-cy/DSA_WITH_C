//implementation of stack using linked list
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

typedef struct node Node;
Node *top = 0;

void display();
void push(int val);
void pop();
void count_ele();
void search(int val);

int main()
{
    int choice, value;

    do
    {
        printf("1: push element\n");
        printf("2: pop element\n");
        printf("3: Display \n");
        printf("4: count number of elements\n");
        printf("5: Search particular element\n");
        printf("6: Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data\n");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            count_ele();
            break;
        case 5:
            printf("Enter value \n");
            scanf("%d", &value);
            search(value);
            break;
        default:
            break;
        }

        printf("\n");
    } while (choice!=6);
    

}

//function to push element
void push(int val)
{
    Node *new;
    
    new = (Node*)malloc(sizeof(Node));

    new->data = val;
    new->link = top;
    top = new;

}

//function to pop element from the stack
void pop()
{
    Node *del;
    if(top == 0)
        printf("stack is empty\n");
    else
    {
        del = top;
        top = top->link;
        free(del);
    }
    
}

//function to display stack element
void display()
{
    Node *temp;
    if(top == 0)
        printf("stack is empty\n");
    else
    {
        printf("Stack is: \n\n");
        temp = top;
        while (temp != 0)
        {

            printf("|%d|\n", temp->data);
            temp = temp->link;
        }
        printf("|__|");
    }
    
}

//function to count element in the stack
void count_ele()
{
    Node *temp;

    int cnt = 0;

    if(top == 0)
        printf("stack is empty\n");
    else
    {
        temp = top;
        while (temp !=0)
        {
            cnt++;
            temp = temp->link;
        }
        
        printf("Total elements: %d\n", cnt);
    }
    
}

//function to search element in the stack
void search(int val)
{
    Node *temp;
    int pos = 1;

    if(top == 0)
        printf("stack is empty\n");
    else
    {
        temp = top;
        while (temp!=0)
        {
            if(temp->data == val)
            {
                printf("%d is at %d place\n", val, pos);

            }
            pos++;
            temp = temp->link;
        }
        
    }
    
}