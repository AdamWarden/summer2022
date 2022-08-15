#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

QUEUE queue_init_default(void)
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL)
    {
        free(queue);
        return NULL;
    }
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

int queue_front(QUEUE hQueue)
{
    Queue* queue = (Queue*)hQueue;
    if (queue->head == NULL)
    {
        return 0;
    }
    return queue->head->data;
}

Boolean queue_is_empty(QUEUE hQueue)
{
    Queue* queue = (Queue*)hQueue;
    if (queue->head == NULL)
    {
        return TRUE;
    }
    return FALSE;
}

Status queue_enqueue(QUEUE hQueue, int data)
{
    Queue* queue = (Queue*)hQueue;
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        free(new_node);
        return FAILURE;
    }
    new_node->data = data;
    new_node->next = NULL;
    if (queue->head == NULL)
    {
        queue->head = new_node;
        queue->tail = new_node;
    }
    else
    {
        queue->tail->next = new_node;
        queue->tail = new_node;
    }
    return SUCCESS;
}

Status queue_service(QUEUE hQueue)
{
    Queue* queue = (Queue*)hQueue;
    if (queue->head == NULL)
    {
        return FAILURE;
    }
    Node* temp = queue->head;
    queue->head = queue->head->next;
    free(temp);
    return SUCCESS;
}

void queue_destroy(QUEUE* head_ref)
{
    Queue* queue = (Queue*)*head_ref;
    Node* temp = queue->head;
    while (temp != NULL)
    {
        temp = queue->head->next;
        free(queue->head);
        queue->head = temp;
    }
    free(queue);
    *head_ref = NULL;
}