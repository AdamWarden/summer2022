#include <stdio.h>

void set_flag(unsigned int flag_holder[], int flag_position);
void unset_flag(unsigned int flag_holder[], int flag_position);
int check_flag(unsigned int flag_holder[], int flag_position);
void display_flags_as_array(unsigned int flag_holder);
void display_flags(unsigned int flag_holder[], int size);

int main(int argc, char* argv[])
{
    unsigned int flag_holder[5] = { 0 }; //Set the first integer to zero and all others to zero by default.
    set_flag(flag_holder, 3);
    set_flag(flag_holder, 16);
    set_flag(flag_holder, 31);
    set_flag(flag_holder, 87);
    display_flags(flag_holder, 5);
    printf("\n\n");
    unset_flag(flag_holder, 31);
    unset_flag(flag_holder, 3);
    set_flag(flag_holder, 99);
    set_flag(flag_holder, 100);
    display_flags(flag_holder, 5);

    return 0;
}

void set_flag(unsigned int flag_holder[], int flag_position)
{
    int index = flag_position/32; //index variable to reference flag_position in array out of 32 bits
    flag_holder[index] = flag_holder[index] | (1 << flag_position); //changed to reference array
}

int check_flag(unsigned int flag_holder[], int flag_position)

{
    int index = flag_position/32;
    return (flag_holder[index] >> (flag_position) & 1);
}

void unset_flag(unsigned int flag_holder[], int flag_position)
{
   int index = flag_position/32;
   flag_holder[index] ^= (1 << flag_position);
}

void display_flags_as_array(unsigned int flag_holder)
{
    for(int i=1; i<=32; i++) //prints starting from bit [0] to bit [31]
    {
        printf("%d", check_flag(&flag_holder, i-1));
        if(i%4 == 0)
        {
            printf(" "); //seperator
        }
    }
    printf("\n");
}

void display_flags(unsigned int flag_holder[], int size)
{
    for(int i=0; i<size; i++) //display number of lines of bits
    {
        display_flags_as_array(flag_holder[i]); //print to screen
    }
}