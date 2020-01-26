#include<iostream>
#define MAX_SIZE 4

using namespace std;

int DEQUE[MAX_SIZE];
int FRONT = -1, REAR = -1;

// helper methods
// check if full
bool is_full() {
    if((FRONT == 0 && REAR == MAX_SIZE) || FRONT == REAR + 1)
        return true;
    return false;
}

// check if empty
bool isEmpty() {
    if(FRONT == -1)
        return true;
    return false;
}

// insert_front
void push_front(int item) {
    // check if deque is full
    if(is_full()) {
        cout<<"\nDeque Overflows...\n";
        return;
    }

    // find new FRONT index
    if(isEmpty()) // if deque is empty
        FRONT = 0, REAR = 0;
    else if(FRONT == 0) // if FRONT points to first index
        FRONT = MAX_SIZE;
    else
        FRONT -= 1; // if FRONT points to in between first and last index

    // push item to FRONT index
    DEQUE[FRONT] = item;
    cout<<endl<<item<<" is inserted at: "<<FRONT<<endl;
}

void push_back(int item) {
    if(is_full()) {
        cout<<"\nDeque Overflows...\n";
        return;
    }

    // find new REAR index
    if(isEmpty()) // if deque is empty
        FRONT = 0, REAR = 0;
    else if(REAR == MAX_SIZE) // if REAR points to last index
        REAR = 0;
    else // if REAR points to in between first and last index
        REAR += 1;

    // push item to REAR index
    DEQUE[REAR] = item;
    cout<<endl<<item<<" is inserted at: "<<REAR<<endl;
}

void pop_front() {
    // check if empty
    if(isEmpty()) {
        cout<<"\nDeque underflows...\n";
        return;
    }

    // extract item and position for printing on console
    int item = DEQUE[FRONT];
    int pos = FRONT;

    // find new FRONT index
    if(FRONT == REAR) // if deque has only one element
        FRONT = -1, REAR = -1;
    else if(FRONT == MAX_SIZE) // if FRONT points to last index
        FRONT = 0;
    else
        FRONT += 1;

    cout<<endl<<item<<" is deleted from: "<<pos<<endl;
}

void pop_back() {
    // check if empty
    if(isEmpty()) {
        cout<<"\nDeque underflows...\n";
        return;
    }

    // extract item and position for printing on console
    int item = DEQUE[REAR];
    int pos = REAR;

    // find new REAR index
    if(FRONT == REAR) // if deque has only one element
        FRONT = -1, REAR = -1;
    else if(REAR == 0) // if REAR points to first index
        REAR = MAX_SIZE;
    else // if REAR points in between first and last index
        REAR -= 1;

    cout<<endl<<item<<" is deleted from: "<<pos<<endl;
}

void print_deqeue() {
    // check if empty
    if(isEmpty()) {
        cout<<"\nEmpty deque\n";
        return;
    }

    if (FRONT <= REAR) {
        // Case 1
        printf("\nDeque items are: ");
        for(int i = FRONT; i <= REAR; i++)
            cout<<DEQUE[i]<<" ";
    } else {
         // Case 2
        printf("\nDeque items are: ");
        for(int i = FRONT; i <= MAX_SIZE; i++)
            cout<<DEQUE[i]<<" ";
        for(int i = 0; i <= REAR; i++)
            cout<<DEQUE[i]<<" ";
    }
}

int main()
{
    // driver code
    int choice;
    cout<<"Enter below numeric value for listed deque operations\n\n";

    while(1) {

        cout<<"\n1.Push item at front"
            <<"\n2.Push item at end"
            <<"\n3.Delete from front"
            <<"\n4.Delete from end"
            <<"\n5.Print Deque"
            <<"\n6.Exit"
            <<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice) {
        case 1:
            {
                int item;
                printf("\nEnter item to be pushed at front: ");
                scanf("%d", &item);
                push_front(item);
                break;
            }
        case 2:
            {
                int item;
                printf("\nEnter item to be pushed at end: ");
                scanf("%d", &item);
                push_back(item);
                break;
            }

        case 3:
            pop_front();
            break;

        case 4:
            pop_back();
            break;

        case 5:
            print_deqeue();
            cout<<endl;
            break;

        case 6:
            exit(0);

        default:
            printf("\nInvalid numeric value\n");
            break;

        }
    }
    return 0;
}












