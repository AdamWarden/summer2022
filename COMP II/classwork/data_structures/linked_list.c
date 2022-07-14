#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;

struct node
{
    int value;
    Node* next;
};

void print_list(Node* head);
//Node* insert_at_tail(Node* head, int value);
void insert_at_tail(Node** pHead, int value);
Node* recursive_insert_at_Tail(Node* head, int value);
void insert_at_head(Node** pHead, int value);

int main(int argc, char* argv[])
{
    Node* head = NULL;
   
    head = insert_at_tail(&head, 42);
    head = insert_at_tail(&head, 107);
    head = insert_at_tail(&head, 36);
    head = insert_at_tail(&head, 69);

    
    print_list(head);
    printf("******\n");
    print_list(head);
    
    return 0;
}

void print_list(Node* head)
{
    while(head != NULL)
    {
        printf("The value of this node is %d\n", head->value);
        head = head->next; //assign temp the address of the next node
    }
}

/*
Node* insert_at_tail(Node* head, int value)
{
    if(head == NULL)
    {
        head = (Node*)malloc(sizeof(Node));
        head->next = NULL;
        head->value = value;
    }
    else
    {
        Node* temp;
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = (Node*)malloc(sizeof(Node));
        if(temp->next == NULL)
        {
            printf("Failed to allocate space for first node\n");
            exit(1);
        }
        temp->next->value = value;
        temp->next->next = NULL;
    }

    return head;
}
*/

void insert_at_tail(Node** pHead, int value)
{
    *pHead = (Node*)malloc(sizeof(Node));
        if(*pHead == NULL)
        {
            printf("Failed to allocate space for first node\n");
            exit(1);
        }
        (*pHead)->value = value;
        (*pHead)->next = NULL;
        else
        {
            Node* temp;
            Node* temp;
            temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = (Node*)malloc(sizeof(Node));
            if(temp->next == NULL)
            {
                printf("Failed to allocate space for first node\n");
                exit(1);
            }
            temp->next->value = value;
            temp->next->next = NULL;
    }
}

Node* recursive_insert_at_Tail(Node* head, int value)
{
    if(head == NULL)
    {
        head = (Node*)malloc(sizeof(Node));
        head->next = NULL;
        head->value = value;
    }
    else
    {
        head->next = recursive_insert_at_tail(head->next, value);
    }
    return head;
}

void insert_at_head(Node** pHead, int value)
{
    if(*pHead == NULL)
    {
        (*pHead) = (Node*)malloc(sizeof(Node));   
    }
}