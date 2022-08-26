//priority_queue implementation using a heap
#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

void heap_insert(PRIORITY_QUEUE hQueue, int data_item, int priority_level);
void fix_down(PRIORITY_QUEUE hQueue, int index, int size);
int priority_queue_size(PRIORITY_QUEUE hQueue);

struct queue
{
    int data;
    int priority;
    struct queue *next;
};
typedef struct queue Queue;

PRIORITY_QUEUE priority_queue_init_default(void)
{
    Queue* pQueue = (Queue*)malloc(sizeof(Queue));
    if(pQueue != NULL)
    {
        pQueue->data = (Queue*)malloc(sizeof(Queue));
        pQueue->priority = 0;
        pQueue->next = NULL;
        if(pQueue->data == NULL)
        {
            printf("pQueue->data is NULL\n");
            return NULL;
        }
    }
    else if(pQueue == NULL)
    {
        printf("pQueue is NULL\n");
        free(pQueue);
        return NULL;
    }
    return pQueue;
}

Status priority_queue_insert(PRIORITY_QUEUE hQueue, int priority_level, int data_item)
{
    //use a heap to insert into the queue based on priority
    Queue* pQueue = (Queue*)hQueue;
    if(hQueue == NULL)
    {
        printf("hQueue is NULL\n");
        return FAILURE;
    }
    heap_insert(hQueue, data_item, priority_level);
    return SUCCESS;
}

Status priority_queue_service(PRIORITY_QUEUE hQueue)
{
    Queue* pQueue = (Queue*)hQueue;
    if(pQueue != NULL)
    {
        if(pQueue->next != NULL)
        {
            Queue* pTemp = pQueue->next;
            pQueue->next = pTemp->next;
            free(pTemp);
            return SUCCESS;
        }
        else if(pQueue->next == NULL)
        {
            printf("pQueue->next is NULL\n");
            return FAILURE;
        }
    }
    else if(pQueue == NULL)
    {
        printf("pQueue is NULL\n");
        return FAILURE;
    }
    return FAILURE;
}

int priority_queue_front(PRIORITY_QUEUE hQueue, Status* pStatus)
{
    Queue* pQueue = (Queue*)hQueue;
    if(pQueue != NULL)
    {
        if(pQueue->next != NULL)
        {
            return pQueue->next->data;
        }
        else if(pQueue->next == NULL)
        {
            printf("pQueue->next is NULL\n");
            return 0;
        }
    }
    else if(pQueue == NULL)
    {
        printf("pQueue is NULL\n");
        return 0;
    }
    return 0;
}

Boolean priority_queue_is_empty(PRIORITY_QUEUE hQueue)
{
    Queue* pQueue = (Queue*)hQueue;
    if(pQueue != NULL)
    {
        if(pQueue->next != NULL)
        {
            return FALSE;
        }
        else if(pQueue->next == NULL)
        {
            return TRUE;
        }
    }
    else if(pQueue == NULL)
    {
        return TRUE;
    }
    return TRUE;
}

void priority_queue_destroy(PRIORITY_QUEUE* phQueue)
{
    Queue* pQueue = (Queue*)*phQueue;
    if(pQueue != NULL)
    {
        if(pQueue->next != NULL)
        {
            Queue* pTemp = pQueue->next;
            while(pTemp->next != NULL)
            {
                pQueue->next = pTemp->next;
                free(pTemp);
                pTemp = pQueue->next;
            }
            free(pTemp);
        }
        else if(pQueue->next == NULL)
        {
            free(pQueue);
        }
    }
    else if(pQueue == NULL)
    {
        printf("pQueue is NULL\n");
    }
}

void heap_insert(PRIORITY_QUEUE hQueue, int data_item, int priority_level) //use a heap to insert into the queue based on priority
{
   //insert into the priority queue by organizing the queue based on highest priority
    Queue* pQueue = (Queue*)hQueue;
    if(hQueue == NULL)
    {
        printf("hQueue is NULL\n");
        return;
    }
    Queue* pTemp = (Queue*)malloc(sizeof(Queue));
    if(pTemp != NULL)
    {
        pTemp->data = data_item;
        pTemp->priority = priority_level;
        pTemp->next = NULL;
        if(pQueue->next == NULL)
        {
            pQueue->next = pTemp;
        }
        else if(pQueue->next != NULL)
        {
            Queue* pTemp2 = pQueue->next;
            while(pTemp2->next != NULL)
            {
                pTemp2 = pTemp2->next;
            }
            pTemp2->next = pTemp;
        }
        else if(pQueue->next == NULL)
        {
            printf("pQueue->next is NULL\n");
            return;
        }
    }
    else if(pTemp == NULL)
    {
        printf("pTemp is NULL\n");
        return;
    }
    fix_down(hQueue, 0, priority_queue_size(hQueue));
}

void fix_down(PRIORITY_QUEUE hQueue, int index, int size) //order the heap from largest to smallest
{
    Queue* pQueue = (Queue*)hQueue;
    if(hQueue == NULL)
    {
        printf("hQueue is NULL\n");
        return;
    }
    if(index < size)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;
        if(left < size && pQueue->next->data < pQueue->next->next->data)
        {
            largest = left;
        }
        if(right < size && pQueue->next->data < pQueue->next->next->next->data)
        {
            largest = right;
        }
        if(largest != index)
        {
            Queue* pTemp = pQueue->next;
            pQueue->next = pTemp->next;
            pTemp->next = pQueue->next->next;
            pQueue->next->next = pTemp;
            fix_down(hQueue, largest, size);
        }
    }
}

int priority_queue_size(PRIORITY_QUEUE hQueue)
{
    Queue* pQueue = (Queue*)hQueue;
    if(hQueue == NULL)
    {
        printf("hQueue is NULL\n");
        return 0;
    }
    int size = 0;
    if(pQueue->next != NULL)
    {
        Queue* pTemp = pQueue->next;
        while(pTemp->next != NULL)
        {
            size++;
            pTemp = pTemp->next;
        }
        size++;
    }
    else if(pQueue->next == NULL)
    {
        printf("pQueue->next is NULL\n");
        return 0;
    }
    return size;
}