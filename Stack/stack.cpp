// Simple implementation of STACK for fixed size array

#include<stdio.h>
#include<stdlib.h> // for exit(0)
#define STACK_SIZE 9 // max stack capacity is 10

// declared globally for being accessed by all functions

int TOP = -1; // current position of stack
int STACK[STACK_SIZE]; // stack initialized with 10 capacity

/*
    push function working procedure:
    1. Check if current size exceeds max capacity
    2. increase TOP by 1
    3. Set stack index TOP
    4. Push item into current index
*/

void push(int item) {
    // checking if stack overflows
    if(TOP < STACK_SIZE) {
        // increasing TOP
        TOP = TOP + 1;

        // setting index and pushing item to it
        STACK[TOP] = item;
        printf("\n%d is inserted at: %dth position\n", item, TOP);
    } else {
        printf("\nCurrent stack size exceeds max size, can't insert new item\n");
    }
}

/*
    pop function working procedure:
    1. Check if current stack size underflows
    2. Extract item from current stack index for printing(optional)
    3. Decrease TOP by 1

*/

void pop() {
    int item;
    // checking if stack size underflows
    if(TOP == -1) {
        printf("\nCurrent stack is empty. Can't pop item\n");
    } else {

        // extracting item from current index
        item = STACK[TOP];
        printf("\n%d is popped from: %dth position\n", item, TOP);

        // decreasing index by 1
        TOP--;
    }
}

/*
    print_stack() working procedure
    1. Check if stack size underflows
    * Current stack size is determined by TOP.
    2. Loop till counter variable reached to zero
    3. Access and print stack by counter variable

*/

void print_stack() {
    // check if stack is empty
    if(TOP == -1) {
        printf("\nCurrent stack is empty\n");
    } else {
         printf("\nItems in current stack:\n");
         // iterating
        for(int i = TOP; i >= 0; i--) {
           printf("%d\n", STACK[i]);
        }
    }
}

/*
    whats_on_the_top() working procedure
    1. Check if current stack size underflows
    2. Access most recent item by TOP and print it

*/

void whats_on_the_top() {
    if(TOP == -1) {
        printf("\nCurrent Stack is empty\n");
    } else {
        printf("\nItem on top of stack: %d\n", STACK[TOP]);
    }
}

int main() {
    int choice;
    // driver code
    printf("Enter below numeric value for listed stack operation\n\n");

    while(1) {

        printf("\n1.Push\n2.Pop\n3.Print the stack\n4.See what's on the top\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
        case 1:
            int item;
            printf("\nEnter item to be pushed: ");
            scanf("%d", &item);
            push(item);
            break;

        case 2:
            pop();
            break;

        case 3:
            print_stack();
            printf("\n");
            break;

        case 4:
            whats_on_the_top();
            break;

        case 5:
            exit(0);

        default:
            printf("\nInvalid numeric value\n");
            break;

        }
    }

    return 0;
}
