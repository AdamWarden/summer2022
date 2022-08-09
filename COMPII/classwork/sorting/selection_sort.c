#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

void print_array(int arr[], int size);
void selection_sort(int arr[], int size);
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
    selection_sort(pNumbers, SIZE);
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

void selection_sort(int arr[], int size)
{
    int i, j, min;
    for(i=0; i<size-1; i++)
    {
        min = i;
        for(j=i+1; j<size; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        if(min != i)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

//what is bad with selection sort?
//selection sort: it is not efficient for large data sets