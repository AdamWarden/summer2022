#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

//what is shell sort?
//shell sort is a sorting algorithm that works by successively inserting elements into the array.

void shell_sort(int numbers[], int size);
void print_array(int arr[], int size);

int main(int argc, char *argv[])
{
    int numbers[100];
    int *pNumbers;
    int *pNumbers_original;
    int i;
    
    pNumbers = (int*)malloc(sizeof(int)*SIZE);
    if(pNumbers == NULL)
    {
        printf("Error allocating memory");
        exit(1);
    }
    pNumbers_original = (int*)malloc(sizeof(int)*SIZE);
    if(pNumbers_original == NULL)
    {
        printf("Error allocating memory");
        exit(1);
    }

    for(i=0; i<SIZE; i++)
    {
        pNumbers[i] = rand() % 100;
        pNumbers_original[i] = pNumbers[i];
        //printf("%d ", pNumbers[i]);
    }
    shell_sort(pNumbers, SIZE);
    print_array(pNumbers, SIZE);
}

void shell_sort(int numbers[], int size)
{
    int i;
    int j;
    int h;
    int temp;
    while(h > 0)
    {
        for(i=h; i<size; i++)
        {
            j = 1;
            temp = numbers[j];
            while(j >= h && temp < numbers[j-h])
            {
                numbers[j] = numbers[j-h];
                j -= h;
            }
            numbers[j] = temp;
        }
        h /= 2;
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