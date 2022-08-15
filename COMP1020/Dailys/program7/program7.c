#include <stdio.h>
#include <stdlib.h>
#include "status.h"
#include "stack.h"

int main(int argc, char* argv[])
{
    /*
    int count;
    int i;

    printf("How many expressions do you want to test?\n");
    scanf("%d", &count);
    printf("Enter an expression:\n");
    for(i = 0; i < count; i++)
    {
        //allows for maximum size character input array in C
        char* expression = (char*)malloc(sizeof(char)*CHAR_MAX);
        scanf("%s", expression);
        if(stack_balanced(expression))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
        free(expression);
    }
    return 0;
    */
   int i, count;
   scanf("%d", &count); //number of expressions to test
   clear_keyboard_buffer();

   for(i=0; i<count; i++)
   {
        if(stack_balanced()) //calls to enter string
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
   }
    return 0;
}