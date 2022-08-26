#include <stdlib.h>
#include <stdio.h>
#include "status.h"

struct node;
typedef struct node Node;
//structures for queue and node
//queue has head and tail
struct node
{
	int data;
	Node* next;
};

struct queue
{
	int size;
	Node* head;
	Node* tail;
};
typedef struct queue Queue;

typedef void* QUEUE;

QUEUE queue_init_default(void);

int queue_front(QUEUE hQueue, Status* pStatus);

Boolean queue_is_empty(QUEUE hQueue);

Status queue_enqueue(QUEUE hQueue, int data);

Status queue_service(QUEUE hQueue);

void queue_destroy(QUEUE* head_ref);

void clear_keyboard_buffer(void);