//final program for implementing single linked list operation
#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
    int data;
    struct node *link;
}Node;

Node *create_list(Node *start);
void display(Node *t);
void search(Node *head, int value) ;
int find_len(Node *head);
Node *insert_at_beg(Node *head, int value);
Node *insert_at_end(Node *head, int value);
Node *insert_at_pos(Node *head, int value, int pos);
Node *del_at_beg(Node *head);
Node *del_at_end(Node *head);
Node *del_at_pos(Node *head, int pos);
Node *insert_before_node(Node *head, int value, int item);
Node *reverse(Node *head);

int main()
{
    Node *head = NULL;
    int choice, value, pos, item;

    while(1)
    {
        printf("1: Create a list\n");
        printf("2: Display List\n");
        printf("3: find length of the list\n");
        printf("4: Add info at begining\n");
        printf("5: Add data at end \n");
        printf("6: Add at specific position\n");
        printf("7: Delete data from the begin\n");
        printf("8: Delete data from the end\n");
        printf("9: Delete data from the specific position\n");
        printf("10: Reverse list element\n");
        printf("11: Search element in the list\n");
        printf("12: insert before a node\n");
        printf("13: Exit\n\n");

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
            printf("Length of list: %d",find_len(head));
            break;
        case 4:
            printf("Enter the value\n");
            scanf("%d", &value);
            head = insert_at_beg(head, value);
            break;
        case 5:
            printf("Enter the value\n");
            scanf("%d", &value);
            head = insert_at_end(head, value);
            break;
        case 6:
            printf("Enter the position after that you want to insert\n");
            scanf("%d", &pos);
            printf("Enter the value\n");
            scanf("%d", &value);
            head = insert_at_pos(head, value, pos);
            break;
        case 7:
            head = del_at_beg(head);
            break;
        case 8:
            head = del_at_end(head);
            break;
        case 9:
            printf("Enter position from where you want to delete\n");
            scanf("%d", &pos);
            head = del_at_pos(head, pos);
            break;
        case 10:
            head = reverse(head);
            break;
        case 11:
            printf("Enter the value that you want to search in the list\n");
            scanf("%d", &value);
            search(head, value);
            break;
        case 12:
            printf("Enter item before which you want to enter node\n");
            scanf("%d", &item);
            printf("Enter value that you to fill in the node\n");
            scanf("%d", &value);
            head = insert_before_node(head, value, item);
            break;
        case 13:
            exit(1);
        default:
            printf("wrong choice\n");
        }

        printf("\n");
    }
    
}

//function to create a single linked list
Node *create_list(Node *start)
{
    Node *temp, *new;
    int choose;

    printf("Enter info in the list\n");
    while (1)
    {
        printf("Enter 1 to fill the info in the list: ");
        scanf("%d", &choose);
        if(choose != 1)
            break;
        
        new = (Node*)malloc(sizeof(Node));
        scanf("%d", &new->data);

        if(start == NULL)
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

//function to display linked list
void display(Node *t)
{
    Node *p;

    if(t==NULL)
    {
        printf("Empty list\n");
    }
    else{

        p = t;
        printf("data in list\n");
        while (p != 0){

            printf("%d ", p->data);
            p = p->link;
        }
    }
}

//function to find length of list
int find_len(Node *head)
{
    Node *temp;
    int cnt = 0;

    if(head == NULL)
        return cnt;
    
    else
    {
        temp = head;
        while(temp!=0)
        {
            temp = temp->link;
            cnt++;
        }
    }

    return cnt;   

}

//function to add element in th begining of the list
Node *insert_at_beg(Node *head, int value)
{
    Node *newnode = (Node*)malloc(sizeof(Node));

    if(head == NULL){
        newnode->data = value;
        head = newnode;
        newnode->link = 0;

    }

    else
    {
        newnode->data = value;
        newnode->link = head;
        head = newnode;
    }

    return head;
    free(newnode);   
}

//function to add data in the end of the list
Node *insert_at_end(Node *head, int value)
{
    Node *newnode = (Node*)malloc(sizeof(Node));
    Node *temp;

    if(head == NULL)
        printf("Empty list\n");
    
    else
    {
        newnode->data = value;
        temp = head;
        while(temp->link!=0)
        {
            temp = temp->link;
        }
        temp->link = newnode;
        newnode->link = 0;
    }

    return head;
    free(newnode);    
}

//function to add element at a specific position
Node *insert_at_pos(Node *head, int value, int pos)
{
    Node *newnode = (Node*)malloc(sizeof(Node));
    Node *temp;
    int i = 1;

    if(pos>find_len(head))
        printf("Invalid position\n");

    else
    {
        newnode->data = value;
        temp = head;
        while (i<pos-1)
        {
            temp = temp->link;
            i++;
        }
        
        newnode->link = temp->link;
        temp->link = newnode;
        
    }

    return head;
    free(newnode);    
}

//function to delete data from the begining
Node *del_at_beg(Node *head)
{
    Node *firstnode;

    firstnode = head;
    head = firstnode->link;

    return head;
    free(firstnode);

}

//function to delete info at the end
Node *del_at_end(Node *head)
{
    Node *prenode, *temp;

    if(head==NULL)
        printf("Empty list\n");
    else
    {
        temp = head;

        while (temp->link!=0)
        {
            prenode = temp;
            temp = temp->link;
        }

        prenode->link = 0;
                
    }

    return head;
    free(temp);
}

//function to delete info at specific position
Node *del_at_pos(Node *head, int pos)
{
    Node *prenode, *temp;
    int i = 1;

    if(pos>find_len(head))
        printf("Invalid position");
    
    else
    {
        temp = head;
        while(i<pos)
        {
            prenode = temp;
            temp = temp->link;
            i++;
        }

        prenode->link = temp->link;
    }

    return head;
    free(temp);
}

//function to reverse a list using iteration 
Node *reverse(Node *head)
{
    Node *prenode, *node, *temp;
    if(head==NULL)
        printf("Empty list\n");
        
    else
    {
        prenode = 0;
        temp = head;
        node = temp;

        while(temp!=0)
        {
            temp = temp->link;
            node->link = prenode;
            prenode = node;
            node = temp;
        }

    }

    head = prenode;
    return head;
    
}

//function to search element in the list
void search(Node *head, int value)
{
    Node *t;
    int pos = 1;

    if(head == NULL)
        printf("Empty list\n");
    else
    {
        t = head;

        while (t!=0)
        {
            if(t->data == value)
                printf("%d is at %d position in the list\n", value, pos);
            ++pos;
            t = t->link;
        }   

    }
}

//function to insert data before specific node
Node *insert_before_node(Node *head, int value, int item)
{
    Node *newnode, *temp;

    newnode = (Node*)malloc(sizeof(Node));

    if(head == NULL)
        printf("Empty List\n");

    if(head->data == item)
    {
        newnode->data = value;
        newnode->link = head;
        head = newnode;
        return head;
    }

    else
    {
        temp = head;
        while(temp->link!=0)
        {
            if(temp->link->data == item)
            {
                newnode->data = value;
                newnode->link = temp->link;
                temp->link = newnode;
                return head;
            }

            temp = temp->link;
        }
    }

    printf("%d is not in the list\n", item);
    return head;
    free(newnode);
    
}
