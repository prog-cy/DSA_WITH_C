//reverse a single linkedlist using iteration method
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int  data;
    struct node *link;
};

typedef struct node Node;
Node *create_list(Node *start);
void display(Node *t);
Node *reverse(Node *h);

int main()
{
    Node *head = 0;

    head = create_list(head);
    printf("\nElements before reverse the list\n");
    display(head);

    head = reverse(head);
    printf("\n\nElements after reverse the list\n");
    display(head);
}

Node *create_list(Node * start)
{
        Node *temp, *new;
        int choose;

        printf("Enter the info in the list\n");
        while (1)
        {
            printf("Enter 1 to fill the info in the list: ");
            scanf("%d", &choose);
            if (choose != 1)
                break;

            new = (Node *)malloc(sizeof(Node));
            scanf("%d", &new->data);

            if (start == 0)
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
        }

        return start;
        free(new);
}

void display(Node *t)
{
    while (t!=0)
    {
        printf("%d ", t->data);
        t = t->link;
    }
        
}

Node *reverse(Node *h)
{
        Node *prenode, *newnode, *nextnode;

        prenode = 0;
        newnode = h;
        nextnode = h;
        while (nextnode!=0)
        {
            nextnode = nextnode->link;
            newnode->link = prenode;
            prenode = newnode;
            newnode = nextnode;
        }

        h = prenode;
        return h;
        
}