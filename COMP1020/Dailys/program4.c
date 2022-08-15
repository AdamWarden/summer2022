#include <stdio.h>

void set_flag(unsigned int* flag_holder, int flag_position);
void unset_flag(unsigned int * flag_holder, int flag_position);
int check_flag(unsigned int flag_holder, int flag_position);
void display_32_flags(unsigned int flag_holder);

int main(int argc, char* argv[])
{
    unsigned int flag_holder = 0;
    set_flag(&flag_holder, 3);
    set_flag(&flag_holder, 16);
    set_flag(&flag_holder, 31);
    display_32_flags(flag_holder);
    unset_flag(&flag_holder, 31);
    unset_flag(&flag_holder, 3);
    set_flag(&flag_holder, 9);
    display_32_flags(flag_holder);

    return 0;
}

void set_flag(unsigned int* flag_holder, int flag_position)
{
    *flag_holder = *flag_holder | (1 << flag_position);
}

int check_flag(unsigned int flag_holder, int flag_position)

{
    return (flag_holder >> (flag_position) & 1);
}

void unset_flag(unsigned int* flag_holder, int flag_position)
{
    *flag_holder &= ~(1 << flag_position); 
    //&= returns 1 if both operands are 1 and 0 if either operand is 0
    //~ returns 1 if operand is 0 and 0 if operand is 1
    /*
    1000 0000 0000 0001 0000 0000 0000 1000 : set_flag @ flag_position = 31
    1 << 31 
    1000 0000 0000 0000 0000 0000 0000 0000 : unset_flag @ flag_position = 31
    1 = 1 so result is 0

    1000 0000 0000 0001 0000 0000 0000 1000 : set_flag @ flag_position = 3
    1 << 3
    1000 : unset_flag @ flag_position = 3
    1 = 1 so result is 0

    1000 0000 0000 0001 0000 0000 0000 1000 : set_flag @ flag_position = 9
    1 << 9
    10 0000 0000 : unset_flag @ flag_position = 9
    0 != 1 so result is 1

    final display: 0000 0000 0000 0001 0000 0010 0000 0000 

    */
}

void display_32_flags(unsigned int flag_holder)
{
    for(int i=31; i>=0; i--) //number of bits
    {
        printf("%d", check_flag(flag_holder, i)); //print to screen flag_holder values
        if(i%4 == 0) //seperate bits
        {
            printf(" ");
        }
    }
    printf("\n");
}