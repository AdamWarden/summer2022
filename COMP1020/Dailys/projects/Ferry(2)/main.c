#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "status.h"

/*
The first line of input contains c, the number of test cases. Each test case begins
with the number l, a space and then the number m. m lines follow describing the cars
that arrive in this order to be transported. Each line gives the length of a car (in
centimeters), and the bank at which the car awaits the ferry ("left" or "right").
For each test case, output one line giving the number of times the ferry has to cross
the river in order to serve all waiting cars.
*/

int main(int argc, char* argv[])
{
    int state = LEFT;
    int result = 0;
    int cases, car_length;
    int l, m;
    char side;

    printf("Please enter the number of test cases: ");
    scanf("%d", &cases);

    QUEUE left_queue = queue_init_default(); //initialize linked list for left bank
    QUEUE right_queue = queue_init_default(); //initialize linked list for right bank

    while(cases != 0)
    {
        cases--;
        printf("Please enter the length of the ferry: ");
        scanf("%d", &l);
        printf("Please enter the number of cars: ");
        scanf("%d", &m);
        
        l *= 100; //unit conversion

        //new function to handle creating and destroying queues for each round
        while(queue_front(left_queue) != NULL) //remove all cars from left list if for some reason its not empty
        {
            queue_service(left_queue);
        }
        while(queue_front(right_queue) != NULL) //remove all cars from right list if for some reason its not empty
        {
            queue_service(right_queue);
        }



        while(m != 0) //adding cars
        {
            printf("Please enter the length of the car: ");
            scanf("%d", &car_length);
            printf("Please enter the bank at which the car awaits the ferry: ");
            scanf(" %c", &side);
            if (side == 'l') //if car is on left bank
            {
                queue_enqueue(left_queue, car_length); //add to queue for left cars
            }
            else if (side == 'r') //if car is on right bank
            {
                queue_enqueue(right_queue, car_length); //add to queue for right cars
            }
            m--;
        }
        car_length = 0; //reset the length of a car
        //use is empty function 
        //incorporate another function to pass left/right queues
        while(!queue_is_empty(left_queue) || !queue_is_empty(right_queue)) //while either list has a car
        {
            result++; //ferry will make at least one trip
            
            if(state == LEFT) //if ferry is on the left bank
            {
                car_length = 0; 
                while(queue_front(left_queue) != NULL) //while there are cars on the left bank
                {
                    if(car_length + queue_front(left_queue) > l) //if the car is too big
                    {
                        break;
                    }
                    car_length += queue_front(left_queue); //add length of car to ferry length
                    queue_service(left_queue); //remove car from list
                }
                state = RIGHT; //change ferry state to right bank
            }
            else
            {
                car_length = 0;
                while(queue_front(right_queue) != NULL)
                {
                    if(car_length + queue_front(right_queue) >  l)
                    {
                        break;
                    }
                    car_length += queue_front(right_queue);
                    queue_service(right_queue);
                }
            }
        }
        printf("%d\n", result);
        queue_destroy(&left_queue);
        queue_destroy(&right_queue);
    }
    return 0;
}

void clear_keyboard_buffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}