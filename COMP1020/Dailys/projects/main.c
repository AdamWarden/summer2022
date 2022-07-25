#include <stdio.h>
#include <stdlib.h>
#include "BIT_FLAGS_1.h"

int main(int argc, char* argv[])
{
    BIT_FLAGS bit_flags = bit_flags_init_number_of_bits(8);
    bit_flags_set_flag(bit_flags, 0); //set bit 0
    bit_flags_set_flag(bit_flags, 1); //set bit 1
    bit_flags_set_flag(bit_flags, 2); //set bit 2
    bit_flags_set_flag(bit_flags, 3); //set bit 3
    bit_flags_set_flag(bit_flags, 4); //set bit 4
    bit_flags_set_flag(bit_flags, 5); //set bit 5
    bit_flags_set_flag(bit_flags, 6); //set bit 6
    bit_flags_set_flag(bit_flags, 7); //set bit 7
    printf("%d\n", bit_flags_check_flag(bit_flags, 0)); //check bit 0
    printf("%d\n", bit_flags_check_flag(bit_flags, 1)); //check bit 1
    printf("%d\n", bit_flags_check_flag(bit_flags, 2)); //check bit 2
    printf("%d\n", bit_flags_check_flag(bit_flags, 3)); //check bit 3
    printf("%d\n", bit_flags_check_flag(bit_flags, 4)); //check bit 4
    printf("%d\n", bit_flags_check_flag(bit_flags, 5)); //check bit 5
    printf("%d\n", bit_flags_check_flag(bit_flags, 6)); //check bit 6
    printf("%d\n", bit_flags_check_flag(bit_flags, 7)); //check bit 7
    bit_flags_unset_flag(bit_flags, 0); //unset bit 0
    bit_flags_unset_flag(bit_flags, 1); //unset bit 1
    bit_flags_unset_flag(bit_flags, 2); //unset bit 2
    bit_flags_unset_flag(bit_flags, 3); //unset bit 3
    bit_flags_unset_flag(bit_flags, 4); //unset bit 4
    bit_flags_unset_flag(bit_flags, 5); //unset bit 5
    bit_flags_unset_flag(bit_flags, 6); //unset bit 6
    bit_flags_unset_flag(bit_flags, 7); //unset bit 7
    printf("%d\n", bit_flags_check_flag(bit_flags, 0)); //check bit 0
    printf("%d\n", bit_flags_check_flag(bit_flags, 1)); //check bit 1
    printf("%d\n", bit_flags_check_flag(bit_flags, 2)); //check bit 2
    printf("%d\n", bit_flags_check_flag(bit_flags, 3)); //check bit 3
    printf("%d\n", bit_flags_check_flag(bit_flags, 4)); //check bit 4
    printf("%d\n", bit_flags_check_flag(bit_flags, 5)); //check bit 5
    printf("%d\n", bit_flags_check_flag(bit_flags, 6)); //check bit 6
    printf("%d\n", bit_flags_check_flag(bit_flags, 7)); //check bit 7
    bit_flags_destroy(&bit_flags); //destroy bit_flags
    return 0; //end of program
}