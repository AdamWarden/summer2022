#include <stdio.h>

void set_flag(int* pFlag_holder, int flag_position);
int check_flag(int flag_holder, int flag_position);

int main(int argc, char* argv[])
{
    int flag_holder = 0;
    int i;

    //changes values to 1
    set_flag(&flag_holder, 3);
    set_flag(&flag_holder, 16);
    set_flag(&flag_holder, 31);

    for(i=31; i>=0; i--)
    {
        printf("%d", check_flag(flag_holder, i));
        if(i%4 == 0)
        {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}

void set_flag(int* pFlag_holder, int flag_position) //change to 1 without changing other bits
{
    *pFlag_holder += (1 << flag_position); //flag holder is updated with 1 left shifted by flag_position
    //ie. flag_position = 3
    //1<<3 = 8
}

int check_flag(int flag_holder, int flag_position)

{
    return (flag_holder >> (flag_position) & 1); //right shift flag_holder by flag_position # of bits and returns a 1 in flag_position if updated flag_holder and flag_position are 1
    //8 >> 3 = 1
    //1 & 1 = 1
    //returns 1 @ flag_position
}