#include <stdio.h>
#include <stdlib.h>
#include "status.h"
#include "stack.h"

int main(int argc, char* argv[])
{
    int count;
    int i;

    printf("How many expressions do you want to test?\n");
    scanf("%d", &count);
    printf("Enter an expression:\n");
    for(i = 0; i < count; i++)
    {
        char* expression = (char*)malloc(sizeof(char) * 100);
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
    /*
    char* expression = "((()))";
    printf("%d\n", stack_balanced(expression));
    */
    return 0;
}