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
//create a list for the number 11
head_insert(&head2, 1);
head_insert(&head2, 1);

head_sum = list_sum(head1, head2);

printf("The sum of ");
print_list(head1); //prints wrong number
printf(" + ");
print_list(head2); //prints wrong number
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
     
    Node* result_head = NULL;
    Node *temp = NULL;
    Node *prev = NULL;
    int carry = 0;
    int sum;

    Node* new_head_ref = reverse_list(head_ref);
    Node* new_head_ref2 = reverse_list(head_ref2);

    while(head_ref != NULL || head_ref2 != NULL)
    {
        if(head_ref == NULL) //if first list is empty
        {
            sum = carry +  head_ref2->data; //sum = carry + second list's data
            if(sum >= 10)
            {
                carry = 1; //remainder is 1
                sum = sum % 10;
            }
            else
            {
                carry = 0; //otherwise, remainder is 0
            }
            sum = sum % 10;
        }
        else if(head_ref2 == NULL) //if second list is empty
        {
            sum = carry + head_ref->data; //sum = carry + first list's data
            if(sum >= 10)
            {
                carry = 1; //remainder is 1
                sum = sum % 10;
            }
            else
            {
                carry = 0; //otherwise, remainder is 0
            }
            sum = sum % 10;
        }
        else
        {
            if(new_head_ref->data >= 10) //if first list's data exceeds two digits
            {
                sum = head_ref->data % 10 + head_ref2->data + carry; //sum = first list's data mod 10 + second list's data + carry
                carry = 1; //remainder from overflow of digits in first list is 1
            }
            else
            {
                sum = head_ref->data + head_ref2->data + carry; //sum = first list's data + second list's data + carry
                carry = 0; //first list's data is less than 10, so remainder is 0
            }
            if(sum >= 10) //if sum exceeds two digits
            {
                carry = 1; //remainder is 1
                sum = sum % 10;
            }
            else
            {
                carry = 0; //otherwise, remainder is 0
            }
            sum = sum % 10; 
        }
        
        sum = sum % 10;

        temp = newNode(sum); //create a new node with the sum

        if(result_head == NULL) //if result list is empty
        {
            result_head = temp; //set result list to the new node
        }
        else
        {
            prev->next = temp; //set the previous node's next to the new node
        }
        
        prev = temp; //set the previous node to the new node

        if(new_head_ref) //if first list is not empty
        {
            head_ref = head_ref->next; //move first list to the next node
        }

        if(new_head_ref2) //if second list is not empty
        {
            head_ref2 = head_ref2->next; //move second list to the next node
        }
    }
    if(carry > 0)
    {
        temp->next = newNode(carry); //if carry is 1, add a new node with the carry
    }

    reverse_list(new_head_ref); //reverse the first list back to normal
    reverse_list(new_head_ref2); //reverse the second list back to normal

    result_head = reverse_list(result_head); //reverse the result list back to normal
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

void destroy_list(Node* head_ref)
{
    Node* current = head_ref;
    Node* next;
    while(current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    head_ref = NULL;
}
