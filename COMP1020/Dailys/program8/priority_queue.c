#include <stdlib.h>
#include <stdio.h>
#include "priority_queue.h"

//make priority_queue structure using linked list
struct queue
{
    int data;
    int priority;
    struct queue *next;
};
typedef struct queue Queue;

void fix_down(Queue *hQueue, int index, int size);

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
        else
        {
            return FAILURE;
        }
    }
    else
    {
        return FAILURE;
    }
}

int priority_queue_front(PRIORITY_QUEUE hQueue, Status* pStatus)
{
    //return the data of the node at the front of the queue
    Queue* pQueue = (Queue*)hQueue;
    if(pQueue != NULL)
    {
        if(pQueue->next != NULL)
        {
            return pQueue->next->data;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
    return 0;
}

Boolean priority_queue_is_empty(PRIORITY_QUEUE hQueue)
{
    Queue* pQueue = (Queue*)hQueue;
    if(pQueue != NULL)
    {
        if(pQueue->next == NULL)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else
    {
        return TRUE;
    }
}

void priority_queue_destroy(PRIORITY_QUEUE* phQueue)
{
    Queue* pQueue = (Queue*)*phQueue;
    if(pQueue != NULL)
    {
        Queue* pTemp = pQueue->next;
        while(pTemp != NULL)
        {
            pQueue->next = pTemp->next;
            free(pTemp);
            pTemp = pQueue->next;
        }
        free(pQueue);
        *phQueue = NULL;
    }
}

void fix_down(Queue *hQueue, int index, int size) //fix_down is used to fix the heap after inserting a new node
{
    Queue* pQueue = (Queue*)hQueue;
    if(pQueue != NULL)
    {
        if(index < size)
        {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            if(left < size)
            {
                if(pQueue->next->priority > pQueue->next->next->priority)
                {
                    Queue* pTemp = pQueue->next;
                    pQueue->next = pTemp->next;
                    pTemp->next = pQueue->next;
                    pQueue->next = pTemp;
                    fix_down(hQueue, left, size);
                }
                else
                {
                    fix_down(hQueue, left, size);
                }
            }
            if(right < size)
            {
                if(pQueue->next->priority > pQueue->next->next->priority)
                {
                    Queue* pTemp = pQueue->next;
                    pQueue->next = pTemp->next;
                    pTemp->next = pQueue->next;
                    pQueue->next = pTemp;
                    fix_down(hQueue, right, size);
                }
                else
                {
                    fix_down(hQueue, right, size);
                }
            }
        }
    }
}