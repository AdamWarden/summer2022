#include <stdlib.h>
#include<stdio.h>
#include "program6b.h"

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
print_list(reverse_list(head1));
//create a list for the number 11
head_insert(&head2, 1);
head_insert(&head2, 1);
print_list(head2);



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
/*
destroy_list(head1); head1 = NULL;
destroy_list(head2); head2 = NULL;
destroy_list(head_sum); head_sum = NULL;
return 0;
*/
}

Node* reverse_list(Node* head_ref)
{
    if(head_ref == NULL || head_ref->next == NULL)
    {
        return head_ref;
    }
    Node* result_head = reverse_list(head_ref->next);
    head_ref->next->next = head_ref;
    head_ref->next = NULL;
    return result_head;
}

Node* newNode(int data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;  
    new_node->next = NULL;
    return new_node;
}

void head_insert(Node** head_ref, int new_data)
{
    Node* new_node = newNode(new_data); 
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

Node* list_sum(Node* head_ref, Node* head_ref2)
{
    reverse_list(head_ref);
    reverse_list(head_ref2);

    Node* result_head = NULL;
    Node *temp = NULL;
    Node *prev = NULL;
    int carry = 0;
    int sum;

    while(head_ref != NULL || head_ref2 != NULL)
    {
        sum = carry + (head_ref ? head_ref->data : 0) + (head_ref2 ? head_ref2->data : 0);
        carry = (sum >= 10) ? 1: 0;
        sum = sum % 10;

        temp = newNode(sum);

        if(result_head == NULL)
            result_head = temp;
        
        else
            prev->next = temp;
        
        prev = temp;
        if(head_ref)
            head_ref = head_ref->next;

        if(head_ref2)
            head_ref2 = head_ref2->next;
        
    }
    if(carry > 0)
        temp->next = newNode(carry);

    reverse_list(result_head);

    return result_head;
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
/*
void destroy_list(Node** head_ref)
{
    Node* current = *head_ref;
    Node* next;
    while(current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *head_ref = NULL;
}
*/