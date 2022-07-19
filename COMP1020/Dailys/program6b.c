#include <stdlib.h>
#include<stdio.h>
#include "program6b.h"

struct node
{
    struct Node* next;
    int* data;
};
typedef struct node Node;

int main(int argc, char* argv[])
{
//add up 189 + 11
Node* head1 = NULL;
Node* head2 = NULL;
Node* head_sum = NULL;
//create a list for the number 189
head_insert(&head1, 9);
head_insert(&head1, 8);
head_insert(&head1, 1);
//create a list for the number 11
head_insert(&head2, 1);
head_insert(&head2, 1);
head_sum = list_sum(head1, head2);
printf("The sum of ");
print_list(head1);
printf(" + ");
print_list(head2);
printf("\n");
printf(" = ");
print_list(head_sum);
printf("\n");
//clean up three lists
destroy_list(head1); head1 = NULL;
destroy_list(head2); head2 = NULL;
destroy_list(head_sum); head_sum = NULL;
return 0;
}

void reverse_list(Node** head_ref)
{
    Node* previous = NULL;
    Node* current = *head_ref; 
    Node* next = NULL;
    
    while(current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    *head_ref = previous;
}

void head_insert(Node** head_ref, int new_data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;    
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

Node* list_sum(Node* head1, Node head2)
{
    Node* new_head = NULL;
    Node* temp = NULL;
    Node* prev = NULL;
    int carry = 0;
    int sum;

    while(head1 != NULL || head2 != NULL)
    {
        sum = carry + head1->data + head2->data;
        if(sum >= 10)
        {
            carry = 1;
            sum = sum % 10;
        }
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->data = data;
        temp->next = NULL;

        if(new_head == NULL)
        {
            new_head = temp;
        }
        else
        {
            prev->next = temp;
        }
        prev = temp;
        if(head1)
        {
            head1 = head1->next;
        }
        if(head2)
        {
            head2 = head2->next;
        }
    }
    if(carry > 0)
    {
        temp->next = (Node*)malloc(sizeof(Node));
        temp->next->data = carry;
        temp->next->next = NULL;
    }
    return new_head;
}

void print_list(Node* node)
{
    while(node != NULL)
    {
        printf("%d", node->data);
        node = node->next;
    }
    printf("\n");
}