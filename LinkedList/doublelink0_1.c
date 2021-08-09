//creating a double linked list and performing all operation 
#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *pre;
    int data;
    struct node *next;
   
    
};

typedef struct node Node;
Node *create_list(Node *start);
void display(Node *t);
int len(Node *head);
void reverse_ele(Node *head);
Node *insert_at_beg(Node *head, int value);
Node *insert_at_end(Node *head, int value);
Node *insert_at_pos(Node *head, int value, int pos);
Node *insert_after_node(Node *head, int value, int item);
Node *del_from_beg(Node *head);
Node *del_from_end(Node *head);
Node *del_from_pos(Node *head, int pos);
Node *reverse_list(Node *head);
void search(Node *head, int item) ;


int main(void)
{
    Node *head = 0;
    int choice, value, i, pos, item;

    while(1)
    {
        printf("1: Create a double link list\n");
        printf("2: Display list\n");
        printf("3: Length of list\n");
        printf("4: Display list element in reverse order \n");
        printf("5: Add data at begin\n");
        printf("6: Add element at the end\n");
        printf("7: Add element at specific position\n");
        printf("8: Add after a given element\n");
        printf("9: Delete from begining\n");
        printf("10: Delete from end\n");
        printf("11: Delete from specific position\n");
        printf("12: Reverse list\n");
        printf("13: Search element in the list\n");
        printf("14: Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            head = create_list(head);
            break;
        case 2:
            display(head);
            break;
        case 3:
            printf("length is: %d", len(head));
            break; 
        case 4:
            reverse_ele(head);
            break;
        case 5:
            printf("Enter value \n");
            scanf("%d", &value);
            head = insert_at_beg(head, value);
            break;
        case 6:
            printf("Enter value\n");
            scanf("%d", &value);
            head = insert_at_end(head, value);
            break; 
        case 7:
            printf("Enter position\n");
            scanf("%d", &pos);
            printf("Enter value\n");
            scanf("%d", &value);
            head = insert_at_pos(head, value, pos);
            break;
        case 8:
            printf("Enter value\n");
            scanf("%d", &value);
            printf("Enter item\n");
            scanf("%d", &item);
            head = insert_after_node(head, value, item);
            break;
        case 9:
            head = del_from_beg(head);
            break;
        case 10:
            head = del_from_end(head);
            break;
        case 11:
            printf("Enter position\n");
            scanf("%d", &pos);
            head = del_from_pos(head, pos);
            break;
        case 12:
            head = reverse_list(head);
            break;
        case 13:
            printf("Enter the item that you want to search in the list\n");
            scanf("%d", &item);
            search(head, item);
            break;
        case 14:
            exit(1);
        
        default:
            printf("Wrong choice\n");
        }

        printf("\n");
    }
}

//function to create a double linked list
Node *create_list(Node *start)
{
    Node *temp, *new;
    int choice;

    while (1)
    {
        printf("Enter 1 to fill the data in the list: ");
        scanf("%d", &choice);
        if(choice!=1)
            break;
        
        new = (Node*)malloc(sizeof(Node));
        scanf("%d", &new->data);
        new->pre = 0;

        if(start == 0)
        {
            start = new;
            temp = start;
        }

        else
        {
            temp->next = new;
            new->pre = temp;
            temp = temp->next;  
        }
        new->next = 0;

    }
    
    return start;
    free(new);
}

//function to display the list
void display(Node *t)
{
    if(t==0)
        printf("Empty list\n");
    
    Node *p;

    p = t;
    while (p!=0)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    
}

//function to find the len of the list
int len(Node *head)
{
    Node *temp;
    int cnt = 0;
    if(head == 0)
        return cnt;
    
    else
    {
        temp = head;
        while(temp!=0)
        {
            cnt++;
            temp = temp->next;
        }
    }

    return cnt;
    
}

//function to reverse list the element
void reverse_ele(Node *head)
{
    Node *temp, *prev;

    temp = head;
    while (temp->next!=0)
    {
        temp = temp->next;
    }

    prev = temp;

   printf("Elements in reverse order\n");
    while (prev!=0)
    {
        printf("%d ", prev->data);
        prev = prev->pre;
    }
    
}

//function to add element at begining of the list
Node *insert_at_beg(Node *head, int value)
{
    Node *newnode;

    newnode = (Node *)malloc(sizeof(Node));

    if(head == 0)
    {
        newnode->data = value;
        newnode->pre = 0;
        newnode->next = 0;
        head = newnode;
    }

    else
    {
        newnode->data = value;
        head->pre = newnode;
        newnode->next = head;
        newnode->pre = 0;
        head = newnode;
        
    }
    
    return head;
    free(newnode);
}

//function to add data at the end of the list
Node *insert_at_end(Node *head, int value)
{
    Node *newnode, *tail;

    if(head == 0)
        printf("Empty list\n");
    
    else
    {
        newnode = (Node*)malloc(sizeof(Node));

        newnode->data = value;
        tail = head;

        while(tail->next!=0)
        {
            tail = tail->next;
        }

        tail->next = newnode;
        newnode->pre  = tail;
        newnode->next = 0;
    }
    return head;
    free(newnode);
}

//function to add data at specific position
Node *insert_at_pos(Node *head, int value, int pos)
{
    Node *newnode, *temp;
    int i = 1;

    newnode = (Node*)malloc(sizeof(Node));

    if(head == 0)
        head = insert_at_beg(head, value);
    
    else if(pos>len(head))
        printf("Invalid position\n");

    else
    {
        temp = head;

        newnode->data = value;

        while(i<pos-1)
        {
            temp = temp->next;
            i++;
        }

        newnode->next = temp->next;
        temp->next->pre = newnode;
        newnode->pre = temp;
        temp->next = newnode;
    }

    return head;
    free(newnode);
    
}

//function to add element after a given node
Node *insert_after_node(Node *head, int value, int item)
{
    Node *newnode, *temp;

    if(head == 0)
        printf("Empty list\n");
    
    else
    {
        
        temp = head;

        while(temp!=0)
        {
            if(temp->data == item)
            {
                newnode = (Node*)malloc(sizeof(Node));
                newnode->data = value;
                newnode->next = temp->next;
                temp->next->pre = newnode;
                newnode->pre = temp;
                temp->next = newnode;
                return head;   
            }

            temp = temp->next;
        }

    }

    printf("%d is not in the list\n", item);

}

//function to delete from the begining
Node *del_from_beg(Node *head)
{
    Node *firstnode;
    if(head == 0)
        printf("Empty list\n");
    
    else
    {
        firstnode = head;
        head = head->next;
        head->pre = 0;
        free(firstnode);
    }
    return head;
}

//function to delete element from end of the list
Node *del_from_end(Node *head)
{
    Node *tail;
    if(head == 0)
        printf("Empty list\n");
    else
    {
        tail = head;
        while (tail->next!=0)
        {
            tail = tail->next;
        }

        tail->pre->next = 0;
        free(tail);
        
    }

    return head;
    
}

//function to delete element from a specific position
Node *del_from_pos(Node *head, int pos)
{
    Node *delnode, *temp;
    int i = 1;

    if(head == 0)
        printf("Empty list\n");
    else
    {
        temp = head;
        while(i<pos)
        {
            temp = temp->next;
            i++;
        }

        delnode = temp;
        temp->pre->next = temp->next;
        temp->next->pre = temp->pre;
        free(delnode);
    }

    return head;
    
}

//function to reverse list
Node *reverse_list(Node *head)
{
    Node *temp, *nextnode, *tail;

    temp = head;
    nextnode = temp;
    tail = head;

    if(head == 0)
        printf("Empty list\n");
    else
    {
        while (tail->next != 0)
        {
            tail = tail->next;
        }

        while(temp!=0)
        {
            nextnode = nextnode->next;
            temp->next = temp->pre;
            temp->pre = nextnode;
            temp = temp->pre;
        }

        temp = head;
        head = tail;
        tail = temp;
    }

    return head;
    
}

//function to search elementin the list
void search(Node *head, int item)
{
    Node *temp;
    int pos = 1;


    if(head == 0)
        printf("Empty list\n");
    else
    {
        temp = head;
        while (temp!=0)
        {
            if(temp->data == item)
            {
                printf("%d is in the list at %d place\n",item, pos);
            }
            temp = temp->next;
            pos++;
        }
        
    }
    printf("%d is not in the list", item);
}