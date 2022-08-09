//select pivot
//partition the numbers such that all items greater than the pivot are on the right and all items less are on the left
//partition is done by scanning from the right to find an element that does not belong on the right side of the pivot
//and scanning from the left until we find an item that does not belong on the left
//swap these items if they are found and keep scanning
//if the scanners meet swap the pivot into that spot
//quick sort the halves

#include <stdlib.h>
#include <stdio.h>
#define SIZE 10

void quick_sort(int numbers[], int size);
void print_array(int arr[], int size);

int main(int argc, char* argv[])
{
    int numbers[10];
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
        pNumbers[i] = rand() % 10;
        pNumbers_original[i] = pNumbers[i];
        //printf("%d ", pNumbers[i]);
    }
    quick_sort(pNumbers, SIZE);
    print_array(pNumbers, SIZE);
}

void quick_sort(int numbers[], int size) 
{   
    //select pivot randomly
    int temp;
    int random_index;
    int* left;
    int* right;

    if(size > 1)
    {
        random_index = ((rand() << 15) + rand())%size;
        temp = numbers[0];
        numbers[0] = numbers[random_index];
        numbers[random_index] = temp;

        right = numbers + size -1;
        left = numbers;

        while(left < right && *right >= numbers[0]) //as long as scanners have not met
        {
            //scan from the right
            right --;
        }
        while(left < right && *left <= numbers[0]) //as long as scanners have not met
        {
            //scan from the left
            left ++;
        }
        if(left < right)
        {
            temp = *left;
            *left = *right;
            *right = temp;
        } 
    }
    temp = numbers[0];
    numbers[0] = *left;
    *left = temp;

    //quick sort the halves
    quick_sort(numbers, left - numbers);
    quick_sort(left + 1, right - left);
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