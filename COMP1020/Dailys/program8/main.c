#include <stdlib.h>
#include <stdio.h>
#include "priority_queue.h"

int main(int argc, char* argv[])
{
    PRIORITY_QUEUE hQueue = priority_queue_init_default();

    priority_queue_insert(hQueue, 5, 5);
    priority_queue_insert(hQueue, 10, 10);
    priority_queue_insert(hQueue, 15, 15);
    printf("%d\n", priority_queue_front(hQueue, NULL));
    priority_queue_service(hQueue);
    printf("%d\n", priority_queue_front(hQueue, NULL));
    priority_queue_service(hQueue);
    printf("%d\n", priority_queue_front(hQueue, NULL));
    priority_queue_service(hQueue);
    
    return 0;
}