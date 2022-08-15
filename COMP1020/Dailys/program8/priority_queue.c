
#include <stdlib.h>
#include <stdio.h>
#include "priority_queue.h"

//make priority_queue structure using linked list
//remove linked list format

struct heap //heap data structure
{
    int priority;
    int value;
};
typedef struct heap Heap;

struct queue //priority_queue data structure
{
    Heap* data;
    int size;
    int capacity;
};
typedef struct queue Queue;

void fix_down(Queue *hQueue, int index);
void fix_up(Queue *hQueue, int index);

PRIORITY_QUEUE priority_queue_init_default(void) //initialize priority queue
{
    Queue* pQueue = (Queue*)malloc(sizeof(Queue));
    if (pQueue != NULL)
    {
        pQueue->size = 0;
        pQueue->capacity = 10;
        pQueue->data = (Heap*)malloc(pQueue->capacity * sizeof(Heap));
        if (pQueue->data == NULL)
        {
            printf("Could not allocate memory for heap\n");
            free(pQueue->data);
            free(pQueue);
            pQueue = NULL;//In case of failure return NULL
            return NULL;
        }
    }
    else
    {
        pQueue = NULL;//In case of failure return NULL
    }
    return pQueue;
}

//insert data into priority queue 
Status priority_queue_insert(PRIORITY_QUEUE hQueue, int priority_level, int data_item)
{
    Queue* pQueue = (Queue*)hQueue;
    Heap* temp;
    int i;
    if (pQueue != NULL) //if the queue is not empty
    {
        if (pQueue->size == pQueue->capacity) //if the queue is full
        {
            temp = (Heap*)malloc(pQueue->capacity * sizeof(Heap)); //allocate memory for the new queue
            if (temp != NULL) 
            {
                for (i = 0; i < pQueue->size; i++) //copy the data from the old queue to the new queue
                {
                    temp[i] = pQueue->data[i]; 
                }
                free(pQueue->data);
                pQueue->data = temp;
                pQueue->capacity *= 2; //double the capacity of the queue
            }
            else
            {
                printf("Could not allocate memory for heap\n");
                return FALSE;
            }
        }
        pQueue->data[pQueue->size].priority = priority_level; //insert the priority level into the queue
        pQueue->data[pQueue->size].value = data_item; //insert the value into the queue
        pQueue->size++; //increment the size of the queue
        fix_down(pQueue, 0); //order the queue from highest priority to lowest priority
    }
    else
    {
        printf("Priority queue is NULL\n");
        return FALSE;
    }
    return TRUE;
}

Status priority_queue_service(PRIORITY_QUEUE hQueue) //remove data from priority queue
{
    Queue* pQueue = (Queue*)hQueue;
    if (pQueue != NULL)
    {
        if (pQueue->size > 0) //if the queue is not empty
        {
            pQueue->data[0] = pQueue->data[pQueue->size - 1]; //copy the last item in the queue to the first item in the queue
            pQueue->size--; //decrement the size of the queue
            fix_down(pQueue, 0); //order the queue from highest priority to lowest priority
        }
        else
        {
            printf("Priority queue is empty\n");
            return FALSE;
        }
    }
    else
    {
        printf("Priority queue is NULL\n");
        return FALSE;
    }
    return TRUE;
}

int priority_queue_front(PRIORITY_QUEUE hQueue, Status* pStatus) //return the data of the node at the front of the queue
{
    Queue* pQueue = (Queue*)hQueue;
    if(pQueue->size <= 0) //if the queue is empty
    {
        if(pStatus != NULL)
        {
            *pStatus = FAILURE;
        }
        return -9;
    }
    if(pStatus != NULL) //means the queue is not empty
    {
        *pStatus = SUCCESS;
    }
    return pQueue->data[0].value; //return the value of the node at the front of the queue
}

Boolean priority_queue_is_empty(PRIORITY_QUEUE hQueue)
{
    Queue* pQueue = (Queue*)hQueue;
    if (pQueue != NULL)
    {
        if (pQueue->size == 0)
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
        return FALSE;
    }
}

void priority_queue_destroy(PRIORITY_QUEUE* phQueue)
{
    Queue* pQueue = (Queue*)*phQueue;
    if (pQueue != NULL)
    {
        free(pQueue->data);
        free(pQueue);
        *phQueue = NULL;
    }
}

void fix_down(Queue *hQueue, int index) //all children are smaller than parent key
{
    Queue* pQueue = (Queue*)hQueue;
    int left_child = 2 * index + 1;
    int right_child = 2 * index + 2;
    int largest_child;

    Heap temp; //temporary variable to hold the data of the parent node

    if(left_child < pQueue->size) //if the left child is not out of bounds
    {
        if(right_child < pQueue->size) //if the right child is not out of bounds
        {
            largest_child = left_child; //set the largest child to the left child
        }
        else
        {
            if(pQueue->data[left_child].priority > (pQueue->data[right_child].priority)) //if left is bigger than right
            {
                largest_child = left_child;
            }
            else
            {
                largest_child = right_child;
            }
        }
        if(pQueue->data[index].priority < pQueue->data[largest_child].priority) //if the parent is smaller than the largest child
        {
            //swap the parent and the largest child
            temp = pQueue->data[index];
            pQueue->data[index] = pQueue->data[largest_child];
            pQueue->data[largest_child] = temp;
            fix_down(pQueue, largest_child);
        }
    }
}

void fix_up(Queue *hQueue, int index) 
{
    Queue* pQueue = (Queue*)hQueue;
    int parent = (index - 1) / 2;
    Heap temp; //temporary variable to hold the data of the parent node
    if(index > 0) 
    {
        if(pQueue->data[index].priority > pQueue->data[parent].priority) //if the parent is smaller than the child
        {
            //swap the parent and child
            temp = pQueue->data[index];
            pQueue->data[index] = pQueue->data[parent];
            pQueue->data[parent] = temp;
            fix_up(pQueue, parent);
        }
    }
}