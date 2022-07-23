#include <stdio.h>
#include <stdlib.h>
#include "BIT_FLAGS_1.h"
#include "status.h"

struct bit_flags
{
    unsigned int flag_holder;
    int number_of_bits;
    int number_of_bytes;
    int number_of_bits_in_last_byte;
};
typedef struct bit_flags Bit_flags;

BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits)
{
    Bit_flags* bytes = (Bit_flags*)malloc(sizeof(Bit_flags));
    if (bytes == NULL)
    {
        free(bytes);
        return NULL;
    }
    //BIT_FLAGS bit_flags;
    bytes->number_of_bits = number_of_bits;
    bytes->number_of_bytes = (number_of_bits / 8) + 1;
    bytes->number_of_bits_in_last_byte = number_of_bits % 8;
    return bytes;
}

Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position)
{
    Bit_flags* bytes = (Bit_flags*)hBit_flags;
    if (flag_position < 0 || flag_position >= bytes->number_of_bits)
    {
        return FAILURE;
    }
    int byte_position = flag_position / 8;
    int bit_position = flag_position % 8;
    //hBit_flags.bytes[byte_position] |= (1 << bit_position);
    bytes->flag_holder |= (1 << bit_position);
    return SUCCESS;
}

Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position)
{
    Bit_flags* bytes = (Bit_flags*)hBit_flags;
    if (flag_position < 0 || flag_position >= bytes->number_of_bits)
    {
        return FAILURE;
    }
    int byte_position = flag_position / 8;
    int bit_position = flag_position % 8;
    //hBit_flags.bytes[byte_position] &= ~(1 << bit_position);
    bytes->flag_holder &= ~(1 << bit_position);
    return SUCCESS;
}

int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position)
{
    Bit_flags* bytes = (Bit_flags*)hBit_flags;
    if (flag_position < 0 || flag_position >= bytes->number_of_bits)
    {
        return FAILURE;
    }
    int byte_position = flag_position / 8;
    int bit_position = flag_position % 8;
    //return (hBit_flags.bytes[byte_position] >> bit_position) & 1;
    return (bytes->flag_holder >> bit_position) & 1;
}

int bit_flags_get_size(BIT_FLAGS hBit_flags)
{
    Bit_flags* bytes = (Bit_flags*)hBit_flags;
    //return hBit_flags.number_of_bits;
    return bytes->number_of_bits;

}

int bit_flags_get_capacity(BIT_FLAGS hBit_flags)
{
    Bit_flags* bytes = (Bit_flags*)hBit_flags;
    //return hBit_flags.number_of_bytes * 8;
    return bytes->number_of_bytes * 8;
}

void bit_flags_destroy(BIT_FLAGS* phBit_flags)
{
    Bit_flags* bytes = (Bit_flags*)phBit_flags;
    /*
    free((*phBit_flags).bytes);
    (*phBit_flags).bytes = NULL;
    (*phBit_flags).number_of_bits = 0;
    (*phBit_flags).number_of_bytes = 0;
    (*phBit_flags).number_of_bits_in_last_byte = 0;
    */
    free(bytes);
    bytes = NULL;
}