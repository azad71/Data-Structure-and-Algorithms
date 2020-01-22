#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 9

int QUEUE[MAX_SIZE+1];
int FRONT = -1, REAR = -1;

/*
    q_insert() working procedure:
    1. check if queue already filled
    2. Set new value of REAR
    3. Insert item into REAR index
*/

void q_insert(int item) {
    if(REAR == MAX_SIZE)
        printf("\nQueue overflows...\n");
    else {
        // if queue initialized for the first time
        if(FRONT == -1) FRONT = 0;

        REAR += 1;
        QUEUE[REAR] = item;
        printf("\n%d is inserted at: %dth position\n", item, REAR);

    }
}

/*
    q_delete() working procedure:
    1. Check if queue underflows
    2. Assign current FRONT value to a variable for further use
    3. Set new value of FRONT
        a. If FRONT exceeds REAR, reset FRONT and REAR back to initial state
    4. Access deleted item by temp for printing
*/
void q_delete() {
    if(FRONT == -1)
        printf("\nQueue underflows...\n");
    else {
        int temp = FRONT;
        FRONT += 1;
        if(FRONT > REAR) {
            FRONT = -1, REAR = -1;
        }
        printf("\n%d is deleted from %dth position\n",QUEUE[temp], temp);
    }
}

/*
    print_queue() working procedure:
    1. check if queue is empty
    2. Loop through the queue
*/

void print_queue() {
    if(FRONT == -1 || REAR == -1 || (FRONT == -1 && REAR == -1))
        printf("\nQueue is empty...\n");
    else {
        printf("Items in the queue is: \t");
        for(int i = FRONT; i <= REAR; i++) {
            printf("%5d", QUEUE[i]);
        }
        printf("\n\n");
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
