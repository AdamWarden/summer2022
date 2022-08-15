#include <stdio.h>
#include <stdlib.h>
#include "BIT_FLAGS_1.h"
#include "status.h"

void clear_keyboard_buffer();

int main(int argc, char* argv[])
{
    int temp, index = 0;

    BIT_FLAGS bit_flags = bit_flags_init_number_of_bits(2000000000); //initialize bit flags with a number of bits of 2,000,000,000
    int bit_flags_size = bit_flags_get_size(bit_flags); //get the size of the bit flags

    printf("Enter a non-negative list of numbers, using -1 to exit: \n");
    
    while(temp != -1) //while the user does not enter -1
    {
        scanf("%d", &temp); //get the number from the user
        clear_keyboard_buffer();
        if(temp < bit_flags_size && temp > -1) //if the number is within bounds 
        {
            bit_flags_set_flag(bit_flags, temp); //set the flag at the given index
        }
    }
    while(index < bit_flags_size) //while index is in bounds
    {
        if(bit_flags_check_flag(bit_flags, index)) //if the flag is set (removes duplicates by not considering them)
        {
            printf("%d\n", index); //print the index
        }
        index++; //increment index
    }
    bit_flags_destroy(bit_flags);
    return 0;
}

void clear_keyboard_buffer()
{
    char c;
    int noc;
    noc = scanf("%c", &c);
    while(noc != EOF && c != '\n')
    {
        noc = scanf("%c", &c);
    }
}