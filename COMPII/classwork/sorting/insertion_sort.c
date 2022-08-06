#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000

void vanilla_insertion_sort(int numbers[], int size);
void insertion_sort_with_shifting(int numbers[], int size);
void insertion_sort(int numbers[], int size);
void print_array(int arr[], int size);

int main(int argc, char *argv[])
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
        pNumbers[i] = rand() % 1000;
        //printf("%d ", pNumbers[i]);
    }
    vanilla_insertion_sort(pNumbers, SIZE);
    print_array(pNumbers, SIZE);
    printf("\n");
    insertion_sort_with_shifting(pNumbers, SIZE);
    print_array(pNumbers, SIZE);
    printf("\n");
    insertion_sort(pNumbers, SIZE);
    print_array(pNumbers, SIZE);
    return 0;
}

void vanilla_insertion_sort(int numbers[], int size)
{
    int i;
    for(i=1; i<size; i++)
    {
        int j = i;
        while(j>0 && numbers[j] < numbers[j-1]) //while the current number is less than the number before it, swap them
        {
            int temp = numbers[j];
            numbers[j] = numbers[j-1];
            numbers[j-1] = temp;
            j--;
        }
    }
}

void insertion_sort_with_shifting(int numbers[], int size)
{
    int j = 1;
    int temp = numbers[j];
    while(j>0 && temp < numbers[j-1]) 
    {
        numbers[j] = numbers[j-1];
        j--;
    }
    numbers[j] = temp;
}

void insertion_sort(int numbers[], int size) //sentinel version
{
    int i;
    int j;
    int temp;
    for(i=1; i<size; i++)
    {
        temp = numbers[i];
        for(j=i; j>0 && temp < numbers[j-1]; j--)
        {
            numbers[j] = numbers[j-1];
        }
        numbers[j] = temp;
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