//creating doubly circular linked list and display the list also performing all operation
#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *link;
    
};

typedef struct node Node;

Node *head = 0, *tail = 0;

void create_list();
void display();
int len();
void insert_at_beg();
void insert_at_end();
void insert_at_pos();
void del_from_beg();
void del_from_end();
void del_from_pos();
void reverse();

int main(void)
{
    int choice;

    while (1)
    {
        printf("1: Create a doubly circular link list\n");
        printf("2: Display the list\n");
        printf("3: Find length of list\n");
        printf("4: Add element at begin\n");
        printf("5: Add element at end\n");
        printf("6: Add at specific position\n");
        printf("7: Delete from begining\n");
        printf("8: Delete from end\n");
        printf("9: Delete from specific position\n");
        printf("10: Reverse a list\n");
        printf("11: Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            create_list();
            break;
        case 2:
            display();
            break;
        case 3:
            printf("Length is: %d", len());
            break;
        case 4:
            insert_at_beg();
            break;
        case 5:
            insert_at_end();
            break;
        case 6:
            insert_at_pos();
            break;
        case 7:
            del_from_beg();
            break;
        case 8:
            del_from_end();
            break;
        case 9:
            del_from_pos();
            break;
        case 10:
            reverse();
            break;
        case 11:
            exit(1);
        default:
            printf("Enter wrong choice\n");
        }

        printf("\n");
    }
    
}

//function to create a doubly circular link list
void create_list()
{
    Node *new;
    int choice;

    while (1)
    {
        printf("Enter 1 to create a node: ");
        scanf("%d", &choice);
        if(choice!=1)
            break;
        new = (Node*)malloc(sizeof(Node));
        scanf("%d", &new->data);

        if(head==0)
        {
            head = new;
            new->prev = head;
            new->link = head;
            tail = head;
        }

        else
        {
            new->prev = tail;
            tail->link = new;
            new->link = head;
            head->prev = new;
            tail = new;
        }
        
    }
    
}

//function to display length of list
int len()
{
    Node *temp;
    int cnt = 1;

    temp = head;

    if (head == 0)
        return 0;
    else
    {
        while (temp != tail)
        {
            temp = temp->link;
            cnt++;
        }
    }

    return cnt;
}

//function to diplay a linked list
void display()
{
    Node *temp;

    if(head == 0) 
        printf("list is empty\n");
    else
    {
        printf("List is\n");
        temp = head;
        
        do
        {
            printf("%d ", temp->data);
            temp = temp->link;
        } while (temp != tail->link);

    }
    
}

//function to insert at begining
void insert_at_beg()
{
    Node *newnode;

    newnode = (Node *)malloc(sizeof(Node));
    printf("Enter element\n");
    scanf("%d", &newnode->data);

    if(head == 0)
    {
        head = newnode;
        newnode->link = head;
        newnode->prev = head;
        tail = head;
    }
    else
    {
        newnode->link = head;
        newnode->prev = tail;
        head->prev = newnode;
        tail->link = newnode;
        head = newnode;
    }
    
}

//function to insert at end
void insert_at_end()
{
    Node *newnode;

    newnode = (Node*)malloc(sizeof(Node));
    printf("Enter element\n");
    scanf("%d", &newnode->data);

    if (head == 0)
    {
        head = newnode;
        newnode->link = head;
        newnode->prev = head;
        tail = head;
    }
    else
    {
        newnode->link = head;
        newnode->prev = tail;
        tail->link = newnode;
        tail = newnode;
        head->prev = newnode;
    }
    
}

//function to insert at specific position
void insert_at_pos()
{
    Node *temp, *newnode;
    int i = 1, pos;
    printf("Enter position where you want to add: ");
    scanf("%d", &pos);

    if(head == 0)
        insert_at_beg();
    else if(pos>len())
        printf("Invalid position\n");
    else
    {
        temp = head;
        while (i<pos-1)
        {
            temp = temp->link;
            i++;
        }

        if(temp == tail)
            insert_at_end();
        else
        {
            newnode = (Node*)malloc(sizeof(Node));
            printf("Enter element\n");
            scanf("%d", &newnode->data);
            newnode->prev = temp;
            newnode->link = temp->link;
            temp->link->prev = newnode;
            temp->link = newnode;
        }
        
        
    }
    
    
}

//function to delete element from the begining
void del_from_beg()
{
    Node *firstnode;
    if(head == 0)
        printf("list is empty\n");
    
    else if(head == head->link)
    {
        firstnode = head;
        head = 0;
        tail = 0;
    }
    else
    {
        firstnode = head;
        tail->link = head->link;
        head->link->prev = tail;
        head = head->link;
    }
    
    free(firstnode);
}

//function to delete from end
void del_from_end()
{
    Node *lastnode;

    if(head == 0)
        printf("list is empty\n");
    else if(tail == tail->link)
    {
        lastnode = tail;
        tail = 0;
        head = 0;
    }
    else
    {
        lastnode = tail;
        head->prev = tail->prev;
        tail->prev->link = head;
        tail = tail->prev;
    }
    
    free(lastnode);
}

//function to delete from specific position
void del_from_pos()
{
    Node *temp;
    int pos, i = 1;

    printf("Enter position from where you want to delete: ");
    scanf("%d", &pos);

    if(head == 0)
        printf("list is empty\n");
    else if(head == head->link)
        del_from_beg();
    else
    {
        temp = head;
        while (i<pos)
        {
            temp = temp->link;
            i++;
        }

        if(temp == tail)
            del_from_end();
        else
        {
            temp->prev->link = temp->link;
            temp->link->prev = temp->prev;
        }
        
        
    }
    
    free(temp);
}

//function to reverse circular doubly link list
void reverse()
{
    Node *pre, *current, *next;

    if(head == 0)
        printf("list is empty\n");
    else
    {
        current = head;
        next = current->link;

        do{
            pre = current;
            current = next;
            next = next->link;
            current->link = pre;
            current->prev = next;
        }while(current!=tail);

        head->prev = head->link;
        head->link = tail;
        tail = next;
        head = current;
    }
    
}
