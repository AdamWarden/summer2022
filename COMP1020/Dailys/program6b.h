#include <stdio.h>
#include <stdlib.h>
#include "status.h"

//define node structure
struct node;
typedef struct node Node;

struct node
{
	int data;
	Node* next;
};

Node* reverse_list(Node** head_ref);

void print_list(Node* head);

void head_insert(Node** head_ref, int data);

Node* list_sum(Node* head_ref, Node* head_ref2);

void destroy_list(Node* head);
