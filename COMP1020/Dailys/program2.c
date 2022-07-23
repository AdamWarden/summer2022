#include <stdio.h>

int main(int argc, char* argv[])
{
    unsigned int x = 1;

    for(int i=0; i<32; i++) //32 bit integers
    {
        printf("%d: %u\n", i, x);
        x = x << 1; //left shift x by 1
    } 
}