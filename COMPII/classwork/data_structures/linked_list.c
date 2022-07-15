#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;

struct node
{
	int value;
	Node* next;
};

//11:40

void print_list(Node* head);
//Node* insert_at_tail(Node* head, int value);  //return style
void insert_at_tail(Node** pHead, int value);  //reference style
//Node* recursive_insert_at_tail(Node* head, int value);
void recursive_insert_at_tail(Node** pHead, int value);
void insert_at_head(Node** pHead, int value);

int main(int argc, char* argv[])
{
	Node* head = NULL;


	/*head = insert_at_tail(head, 42);
	head = insert_at_tail(head, 107);
	head = insert_at_tail(head, 36);
	head = insert_at_tail(head, 99);*/
	
	for (int i = 0; i < 10000; i++)
	{
		insert_at_head(&head, i);
	}

	//recursive_insert_at_tail(&head, 42);
	//recursive_insert_at_tail(&head, 107);
	//recursive_insert_at_tail(&head, 36);
	//recursive_insert_at_tail(&head, 99);



	print_list(head);
	printf("****\n");
	print_list(head);
	

	
	return 0;
}

void print_list(Node* head)
{
	while (head != NULL)
	{
		printf("The value of this node is %d\n", head->value);
		head = head->next;
	}
}

//Node* insert_at_tail(Node* head, int value)
//{
//	//Consider 3 cases:
//	//case 1: what if the list is empty?
//	//case 2: What if the list has only one item?
//	//case 3: What if the list has many items(2 or more?)
//
//	if (head == NULL)
//	{
//		head = (Node*)malloc(sizeof(Node));
//		if (head == NULL)
//		{
//			printf("Failed to allocate space for first node.\n");
//			exit(1);
//		}
//		head->next = NULL;
//		head->value = value;
//	}
//	else
//	{		
//		Node* temp;
//		temp = head;
//		while (temp->next != NULL)
//		{
//			temp = temp->next;
//		}
//		temp->next = (Node*)malloc(sizeof(Node));
//		if (temp->next == NULL)
//		{
//			printf("Failed to allocate space for last node.\n");
//			exit(1);
//		}
//		temp->next->value = value;
//		temp->next->next = NULL;		
//	}
//
//	return head;
//}

void insert_at_tail(Node** pHead, int value)
{
	if (*pHead == NULL)
	{
		*pHead = (Node*)malloc(sizeof(Node));
		if (*pHead == NULL)
		{
			printf("Failed to allocate space for first node.\n");
			exit(1);
		}
		(*pHead)->value = value;
		(*pHead)->next = NULL;
	}
	else
	{
		Node* temp;
		temp = (*pHead);
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = (Node*)malloc(sizeof(Node));
		if (temp->next == NULL)
		{
			printf("Failed to allocate space for last node.\n");
			exit(1);
		}
		temp->next->value = value;
		temp->next->next = NULL;
	}
}

//Node* recursive_insert_at_tail(Node* head, int value)
//{
//	if (head == NULL)
//	{
//		head = (Node*)malloc(sizeof(Node));
//		if (head == NULL)
//		{
//			printf("Failed to allocate space for first node.\n");
//			exit(1);
//		}
//		head->next = NULL;
//		head->value = value;
//	}
//	else
//	{
//		head->next = recursive_insert_at_tail(head->next, value);
//	}
//
//	return head;
//}

void recursive_insert_at_tail(Node** pHead, int value)
{
	if ((*pHead) == NULL)
	{
		(*pHead) = (Node*)malloc(sizeof(Node));
		if ((*pHead) == NULL)
		{
			printf("Failed to allocate space for first node.\n");
			exit(1);
		}
		(*pHead)->next = NULL;
		(*pHead)->value = value;
	}
	else
	{
		recursive_insert_at_tail(&((*pHead)->next), value);
	}
}

void insert_at_head(Node** pHead, int value)
{
	Node* temp;

	temp = (Node*)malloc(sizeof(Node));
	if (temp == NULL)
	{
		printf("Failed to allocate space for node.\n");
		exit(1);
	}
	temp->next = *pHead;
	temp->value = value;
	(*pHead) = temp;

}