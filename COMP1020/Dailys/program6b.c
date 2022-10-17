/*
Program: Daily 6b
Author: Adam Warden
Date: 17 Oct 2022
Time Spent: 3 days
Purpose: This program takes two seperate linked lists and adds their values together in a new list
*/

#include <stdio.h>
#include <stdlib.h>
#include "program6b.h"

int main(int argc, char* argv[])
{
    Node* head1 = NULL;
    Node* head2 = NULL;
    Node* head_sum = NULL;

    head_insert(&head1, 9);
    head_insert(&head1, 8);
    head_insert(&head1, 1);

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

    destroy_list(head1); head1 = NULL;
    destroy_list(head2); head2 = NULL;
    destroy_list(head_sum); head_sum = NULL;
    return 0;
}

Node* reverse_list(Node** head_ref)
{
    Node* prev = NULL;
    Node* curr = *head_ref;
    Node* next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *head_ref = prev;
    return *head_ref;
}

void print_list(Node* head)
{
    Node* curr = head;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

void head_insert(Node** head_ref, int data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

Node* list_sum(Node* head_ref, Node* head_ref2) 
{
    Node* head_sum = NULL; //head of the sum list
    Node* curr = head_ref; //current node in the first list
    Node* curr2 = head_ref2; //current node in the second list
    
    curr = reverse_list(&head_ref); //reverse the first list to match digits
    curr2 = reverse_list(&head_ref2); //reverse the second list to match digits
    
    int carry = 0; //carry for the sum of the two lists
    int sum = 0; //sum of the two lists
    int data = 0; //data for the new node in the sum list
    
    while (curr != NULL || curr2 != NULL) //while at least one list is not empty
    {
        if (curr != NULL) //if the first list is not empty
        {
            sum = curr->data + carry; //add the carry to the first list's data
            curr = curr->next; //move on to the next node in the first list
        }
        else //if the first list is empty
        {
            sum = carry; //add the carry to the first list's data
        }
        if (curr2 != NULL) //if the second list is not empty
        {
            sum += curr2->data; //add the second list's data to the sum
            curr2 = curr2->next; //move on to the next node in the second list
        }
        data = sum % 10; //get the last digit of the sum
        carry = sum / 10; //get the carry for the next iteration
        head_insert(&head_sum, data); //insert the last digit of the sum into the sum list
    }
    if (carry > 0) //if there is a carry left over
    {
        head_insert(&head_sum, carry); //insert the carry into the sum list
    }

    reverse_list(&head_ref); //reverse the first list back to the original order
    reverse_list(&head_ref2); //reverse the second list back to the original order

    return head_sum; //return the head of the sum list
}

void destroy_list(Node* head)
{
    Node* curr = head;
    Node* next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        free(curr);
        curr = next;
    }
}
