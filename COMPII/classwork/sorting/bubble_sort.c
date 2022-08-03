#include <stdio.h>
#include <stdlib.h>
#define SIZE 100000

//what is bubble sort?
//bubble sort: compare two adjacent elements and swap them if they are in the wrong order

void print_array(int arr[], int size);
void bubble_sort(int arr[], int size);

int main(int argc, char *argv[])
{
    int numbers[10000];
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
    printf("FINISHED\n");
    bubble_sort(pNumbers, SIZE);
    print_array(pNumbers, SIZE);

    return 0;
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

void bubble_sort(int arr[], int size)
{
    int i, j;
    int temp;
    for(i=0; i<size; i++) 
    {
        for(j=0; j<size-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}