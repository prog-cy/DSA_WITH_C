//creating circular link list using tail and performing all operation
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

typedef struct node Node;
Node *create_list(Node *last);
void display(Node *t);
int len(Node *tail);
Node *insert_at_beg(Node *tail, int value);
Node *insert_at_end(Node *tail, int value);
Node *insert_at_pos(Node *tail, int value, int pos);
Node *insert_after_pos(Node *tail, int value, int pos);
Node *del_from_beg(Node *tail);
Node *del_from_end(Node *tail);
Node *del_from_pos(Node *tail, int pos);
Node *reverse(Node *tail);

int main(void)
{
    Node *tail = 0;
    int choice, value, item, pos;

    while (1)
    {
        printf("1: Create a list\n");
        printf("2: Display list\n");
        printf("3: Length of list\n");
        printf("4: Add element at begin\n");
        printf("5: Add element at end\n");
        printf("6: Add element at specific position\n");
        printf("7 Add element after specific position\n");
        printf("8: Delete data from begining\n");
        printf("9: Delete from end\n");
        printf("10: Delete from a specific position\n");
        printf("11: Reverse list\n");
        printf("12: Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            tail = create_list(tail);
            break;
        case 2:
            display(tail);
            break;
        case 3:
            printf("Length of list: %d", len(tail));
            break;
        case 4:
            printf("Enter value\n");
            scanf("%d", &value);
            tail = insert_at_beg(tail, value);
            break;
        case 5:
            printf("Enter value\n");
            scanf("%d", &value);
            tail = insert_at_end(tail, value);
            break;
        case 6:
            printf("Enter position at which you want to enter the element\n");
            scanf("%d", &pos);
            printf("Enter value\n");
            scanf("%d", &value);
            tail = insert_at_pos(tail, value, pos);
            break;
        case 7:
            printf("Enter position after that you want to enter the element\n");
            scanf("%d", &pos);
            printf("Enter the value\n");
            scanf("%d", &value);
            tail = insert_after_pos(tail, value, pos);
            break;
        case 8:
            tail = del_from_beg(tail);
            break;
        case 9:
            tail = del_from_end(tail);
            break;
        case 10:
            printf("Enter position from where you want to delete\n");
            scanf("%d", &pos);
            tail = del_from_pos(tail, pos);
            break;
        case 11:
            tail = reverse(tail);
            break;
        case 12:
            exit(1);
        default:
            printf("Wrong choice\n");
        }

        printf("\n");
    }
}

//function to create a list
Node *create_list(Node *last)
{
    Node *new;
    int choice;

    while (1)
    {
        printf("Enter 1 to create a node: ");
        scanf("%d", &choice);
        if (choice != 1)
            break;

        new = (Node *)malloc(sizeof(Node));
        scanf("%d", &new->data);

        if (last == 0)
        {
            last = new;
            last->link = last;
        }
        else
        {
            new->link = last->link;
            last->link = new;
            last = last->link;
        }

    }

    return last;
    free(new);
}

//function to display the list
void display(Node *t)
{
    Node *p;

    if (t == 0)
        printf("list is empty\n");

    else
    {
        printf("list element\n");
        p = t->link;

        do
        {
            printf("%d ", p->data);
            p = p->link;

        } while (p != t->link);

        if (p->data == t->link->data)
            printf("\nlist is Circular");
    }
}

//function to find length of the list
int  len(Node *tail)
{
    Node *temp;
    int cnt = 0;

    if(tail == 0)
        printf("no elements in the list\n");
    else
    {
        temp = tail->link;
        do
        {
            cnt++;
            temp = temp->link;
            
        } while (temp!=tail->link);
        
    }
    
    return cnt;
}

//function to insert at begining
Node *insert_at_beg(Node *tail, int value)
{
    Node *newnode;

    newnode = (Node*)malloc(sizeof(Node));
    newnode->data = value;

    if(tail == 0)
    {
        tail = newnode;
        tail->link = tail;
    }

    else
    {
        newnode->link = tail->link;
        tail->link = newnode;

    }

    return tail;


}

//function to insert at end of a circular link list
Node *insert_at_end(Node *tail, int value)
{
    Node *newnode;

    if(tail == 0)
        printf("list is empty\n");

    else
    {
        newnode = (Node*)malloc(sizeof(Node));

        newnode->data = value;

        newnode->link = tail->link;
        tail->link = newnode;
        tail = tail->link;
    }

    return tail;
    
} 

//function to insert data at specific position
Node *insert_at_pos(Node *tail, int value, int pos)
{
    Node *newnode, *temp;
    int i = 1;

    if(tail == 0)
        printf("list is empty\n");
    else
    {
        temp = tail->link;
        newnode = (Node*)malloc(sizeof(Node));

        newnode->data = value;

        if(pos == 1)
             insert_at_beg(tail, value);

        while (i<pos-1)
        {
            temp = temp->link;
            i++;
        }

        newnode->link = temp->link;
        temp->link = newnode;
        
    }

    return tail;
    
}

//function to add element after position
Node *insert_after_pos(Node *tail, int value, int pos)
{
    Node *newnode, *temp;
    int i = 1;

    if (tail == 0)
        printf("list is empty\n");
    else
    {
        temp = tail->link;
        newnode = (Node *)malloc(sizeof(Node));

        newnode->data = value;

        while (i < pos)
        {
            temp = temp->link;
            i++;
        }

        newnode->link = temp->link;
        temp->link = newnode;
    }

    return tail;
}

//function to delete data from begining
Node *del_from_beg(Node *tail)
{
    Node *firstnode;

    if(tail == 0)
        printf("list is empty\n");
    else if(tail == tail->link)
    {
        firstnode = tail;
        tail = 0;
    }
    else
    {
        firstnode = tail->link;
        tail->link = firstnode->link;
    }
    
    free(firstnode);
    return tail;
}

//function to delete from end
Node *del_from_end(Node *tail)
{
    Node *lastnode, *temp;

    if(tail == 0)
        printf("list is empty\n");
    else if (tail == tail->link)
    {
        lastnode = tail;
        tail = 0;
    }
    else
    {
        lastnode = tail;

        temp = tail->link;

        while (temp->link->link!=tail->link)
        {
            temp = temp->link;
        }

        temp->link = tail->link;
        tail = temp;
        
    }

    free(lastnode);
    return tail;
    
}

//function to delete from specific position
Node *del_from_pos(Node *tail, int pos)
{
    Node *prenode, *posnode;
    int i = 1;

    if(tail == 0)
        printf("list is empty\n");
    else if(pos == 1)
        del_from_beg(tail);
    else
    {
        posnode = tail->link;

        while (i<pos)
        {
            prenode = posnode;
            posnode = posnode->link;
            i++;
        }
        if(posnode == tail)
            del_from_end(tail);
        else
        {
            prenode->link = posnode->link;
        }
        free(posnode);
        

    }
    
    return tail;
    
}

//function to reverse a cicrcular link list
Node *reverse(Node *tail)
{
    Node *prenode, *current, *next;

    if(tail == 0)
        printf("list is empty\n");
    else
    {
        current = tail->link;
        next = current->link;

        do
        {
            prenode = current;
            current = next;
            next = current->link;
            current->link = prenode;
        } while (current!=tail);

        next->link = tail;
        tail = next;
        
    }

    return tail;
    
}