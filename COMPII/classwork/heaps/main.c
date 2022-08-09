#include <stdio.h>
#include <stdlib.h>

//what is the heap property?
//heap property: the parent is always smaller than the children

//what is the difference between fix_up and fix_down?
//fix_up: if the parent is bigger than the child, swap them
//fix_down: if the child is bigger than the parent, swap them

//what is heapify?
//heapify: calling fix_down on all the nodes except leaf nodes

void heap_insert(int heap[], int *size, int value);
void fix_up(int heap[], int index);
void heap_remove_max(int heap[], int *size);
void fix_down(int heap[], int index, int size);

#define SIZE 50
int main(int argc, char *argv[])
{
    int heap[SIZE];
    int size = 0;

    heap_insert(heap, &size, 99);
    heap_insert(heap, &size, 10);
    heap_insert(heap, &size, 25);
    heap_insert(heap, &size, 75);
    heap_insert(heap, &size, 31);
    heap_insert(heap, &size, 41);
    heap_insert(heap, &size, 2);
    heap_insert(heap, &size, 5);
    heap_insert(heap, &size, 0);
    heap_insert(heap, &size, 100);
    heap_insert(heap, &size, 98);

    for(int i = 0; i < size; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");

    while(size > 0)
    {
        heap_remove_max(heap, &size);
        for(int i = 0; i < size; i++)
        {
            printf("%d ", heap[i]);
        }
        printf("\n");
    }

    return 0;
}

void heap_insert(int heap[], int *size, int value)
{
    heap[*size] = value; // insert value into heap
    (*size)++; // increment size
    fix_up(heap, *size - 1); // fix heap property
    

}

void fix_up(int heap[], int index) //recursive
{
    if(index > 0)
    {
        int parent = (index - 1) / 2;
        if(heap[index] > heap[parent])
        {
            int temp = heap[index];
            heap[index] = heap[parent];
            heap[parent] = temp;
            fix_up(heap, parent);
        }
    }
}

//iterative fix_up

void heap_remove_max(int heap[], int *size)
{
    int temp = heap[0];
    heap[0] = heap[*size - 1];
    heap[*size - 1] = temp;
    (*size)--;
    fix_down(heap, 0, *size); 
}

void fix_down(int heap[], int index, int size)
{
    int left, right, largest;
    left = 2 * index + 1;
    right = 2 * index + 2;

    //two children
    if(left < size)
    {
        if(right < size)
        {
            if(heap[left] > heap[right])
            {
                largest = left;
            }
            else
            {
                largest = right;
            }
        }
        else if(left < size)
        {
            largest = left;
        }
        if(heap[index] < heap[largest])
        {
            int temp = heap[index];
            heap[index] = heap[largest];
            heap[largest] = temp;
            fix_down(heap, largest, size);
        }
    }
}