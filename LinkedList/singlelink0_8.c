//insert at any position in the list
#include<stdio.h>
#include<stdlib.h>

int count = 0;
struct node
{
    int data;
    struct node *link;
};

typedef struct node Node;
void printlist(Node *n);
Node *create_list(Node *start);
Node *insert_at_pos(Node *n, int value, int pos);

int main()
{
    Node *start = NULL;

    int value, pos;
    printf("\nEnter position after which you want to enter the node: ");
    scanf("%d",&pos);
    printf("\nEnter the value in the node: ");
    scanf("%d", &value);

    start = create_list(start);
    printf("\nElements in the list\n");
    printlist(start);

    printf("\nElements in the list after insertion\n");
    start = insert_at_pos(start, value, pos);
    printlist(start);

}

Node* create_list(Node *start)
{
    Node  *temp, *n;

    printf("Enter info in the list\n");
    while (1)
    {
        n = (Node*)malloc(sizeof(Node));
        scanf("%d",&n->data);

        if(start==NULL)
        {
            start = n;
            temp = start;
            n->link = 0;
        }
        else
        {
            temp->link = n;
            temp = temp->link;
            n->link = 0;
        }
        ++count;

        if(count==5)
            break;
    }
    return start;
    free(n);
}

void printlist(Node *n)
{
    while (n!=0)
    {
        printf("%d ",n->data);
        n = n->link;
    }
    
}

Node *insert_at_pos(Node *n, int value, int pos)
{
    int i = 1;
    Node *randnode, *temp;

    if(pos>count){
        printf("Invalid position\n");
        return NULL;
    }

    else{

    randnode = (Node *)malloc(sizeof(Node));

    randnode->data = value;

    temp = n;
    while (i<pos)
    {
        temp = temp->link;
        i++;
        
    }

    randnode->link = temp->link;
    temp->link = randnode;
    return n;

    free(randnode);
    }

    
    
}
