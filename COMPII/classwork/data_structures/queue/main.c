#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "status.h"

int main(int argc, char* argv[])
{
    QUEUE hQ  = queue_init_default();
    int i;
    Status status;

    if(hQ == NULL){
        printf("Failed to allocate space for vector object.\n");
        exit(1);
    }

    for(i=0; i<10; i++)
    {
        if(queue_insert(hQ, i) == FAILURE);
        {
            printf("Failed to insert element %d into queue.\n", i);
            exit(1);
        }
    }

    while(!queue_is_empty(hQ))
    {
        printf("%d\n", queue_front(hQ, &status));
        if(status == SUCCESS)
        {
            printf("SUCCESS\n");
        }
        else
        {
            printf("FAILURE\n");
        }
    }
    if(queue_service(hQ) == FAILURE)
    {
        printf("Failed to remove element from queue.\n");
        exit(1);
    }
    queue_destroy(&hQ);

    return 0;
}