#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "status.h"

int main(int argc, char* argv[])
{
    STACK hStack;
    char string;

	hStack = stack_init_default();
	//initilize the stack
	if (hStack == NULL)
	{
		printf("Failed to allocate space for stack object.\n");
		exit(1);
	}

    printf("Enter string: ");
    scanf("%s\n", &string);

    return string;
    
}