// implementation of circular queue
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 4 // max capacity 5

int QUEUE[MAX_SIZE];
// initial index of QUEUE
int FRONT = -1, REAR = -1;

/*
    q_insert() working procedure:
    1.Check if queue overflows
    2. Set new value of REAR
        a. Case 1: Set both FRONT & REAR = 0 if inserted for the first time
        b. Case 2: Offset REAR to 0 if REAR reached to MAX_SIZE
        c. Case 3: Else increase REAR by 1
    3. Push item to REAR index of QUEUE
*/
void q_insert(int item) {

    if((FRONT == 0 && REAR == MAX_SIZE) || FRONT == REAR + 1) {
        printf("\nQueue overflow...\n");
    } else {
        if(FRONT == -1)
            FRONT = 0, REAR = 0;
        else if(REAR == MAX_SIZE)
            REAR = 0;
        else
            REAR += 1;
        QUEUE[REAR] = item;
        printf("\n%d is inserted at: %dth position\n", item, REAR);
    }
}

/*
    q_delete() working procedure:
    1. Check if queue underflows
    2. Extract item and position for printing on console(optional)
    3. Set new value of FRONT
        a. Case 1: Offset both FRONT & REAR to negative index if there is only one item
        b. Case 2: Offset FRONT to 0 if FRONT reached to MAX_SIZE
        c. Case 3: Else increase FRONT by 1
*/

void q_delete() {
    if(FRONT == -1)
        printf("\nQueue underflow...\n");
    else {
        int item = QUEUE[FRONT], pos = FRONT;
        if (FRONT == REAR)
            FRONT = -1, REAR = -1;
        else if(FRONT == MAX_SIZE)
            FRONT = 0;
        else
            FRONT += 1;
        printf("\n%d is deleted from %dth position\n", item, pos);
    }
}

/*
    print_queue() working procedure:
    1. Check if queue is empty
    2. Loop through the queue
        a. Case 1: if FRONt <= REAR -> do normal linear looping
        b. Case 2: if FRONT > REAR ->
            i. Loop from FRONT to MAX_SIZE
            ii. Then loop from 0 to REAR
*/
void print_queue() {
    if(FRONT == -1 || REAR == -1 ||(FRONT == -1 && REAR == -1)) {
        printf("\nQueue is empty\n");
    } else if (FRONT <= REAR) {
        // Case 1
        printf("\nQueue items are: ");
        for(int i = FRONT; i <= REAR; i++)
            printf("%5d", QUEUE[i]);
    } else {
         // Case 2
        printf("\nQueue items are: ");
        for(int i = FRONT; i <= MAX_SIZE; i++)
            printf("%5d", QUEUE[i]);
        for(int i = 0; i <= REAR; i++)
            printf("%5d", QUEUE[i]);
    }
}

int main()
{
    // driver code
    int choice;
    printf("Enter below numeric value for listed queue operations\n\n");

    while(1) {

        printf("\n1.Insert\n2.Delete\n3.Print the queue\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
        case 1:
            int item;
            printf("\nEnter item to be queued: ");
            scanf("%d", &item);
            q_insert(item);
            break;

        case 2:
            q_delete();
            break;

        case 3:
            print_queue();
            printf("\n");
            break;

        case 4:
            exit(0);

        default:
            printf("\nInvalid numeric value\n");
            break;

        }
    }
    return 0;
}
