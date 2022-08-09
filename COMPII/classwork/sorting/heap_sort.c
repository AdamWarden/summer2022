#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void heap_sort(int numbers[], int size); //heapify the array, remove the max n-1 times
void heapify(int numbers[], int size, int index); //fix the heap property
void print_array(int arr[], int size);

int main(int argc, char* argv[])
{
    int numbers[100];
    int *pNumbers;
    int i;
    
    pNumbers = (int*)malloc(sizeof(int)*SIZE);
    if(pNumbers == NULL)
    {
        printf("Error allocating memory");
        exit(1);
    }
    
    for(i=0; i<SIZE; i++)
    {
        pNumbers[i] = rand() % 100;
        //printf("%d ", pNumbers[i]);
    }
    heap_sort(pNumbers, SIZE);
    print_array(pNumbers, SIZE);
}

void heapify(int numbers[], int size, int index) //call fix down on all elements in the array starting from the back ignoring leaf nodes and remove the max n-1 times
{
    int i;

    for(i = size-1; i >= 0; i--) 
    {
        int temp = numbers[index];
        numbers[index] = numbers[i];
        numbers[i] = temp;
        index = i;
        if(index*2+1 < size) //if the left child exists
        {
            heapify(numbers, size, index*2+1);
        }
        if(index*2+2 < size) //if the right child exists
        {
            heapify(numbers, size, index*2+2); 
        }
    }

}

void heap_sort(int numbers[], int size)
{
    int i;
    int number_if_times = size-1;
    heapify(numbers, size, i);

    for(i=0; i<number_if_times; i++)
    {
        int temp = numbers[0];
        numbers[0] = numbers[size-1];
        numbers[size-1] = temp;
        heapify(numbers, size-1, 0);
    }
}

void print_array(int arr[], int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}