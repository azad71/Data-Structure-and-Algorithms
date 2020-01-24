// implementation of singly linked list

#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node {
    int item;
    Node* next;
};

Node* head = NULL;

int list_length() {
    int count = 0;
    for(Node* i = head; i != NULL; i = i->next)
        count++;
    return count;
}

void insert_at_front(int item) {
    Node* new_node = new Node();
    new_node->item = item;
    new_node->next = head;
    head = new_node;
    cout<<endl;
    cout<<item<<" is inserted at memory location: "<<head<<endl;
}

void insert_at_nth(int item, int pos) {
    Node* new_node = new Node();
    new_node->item = item;
    new_node->next = NULL;

    // if inserted at start
    if(pos == 1) {
        new_node->next = head;
        head = new_node;
        cout<<endl;
        cout<<item<<" is inserted at memory location: "<<head<<endl;
        return;
    }
    Node* temp = head;
    for(int i = 0; i < pos-2; i++) {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;

    cout<<endl;
    cout<<item<<" is inserted at memory location: "<<temp->next<<endl;
}


void insert_at_end(int item) {
    int length = 0;
    length = list_length();

    if(length == 0) {
        insert_at_front(item);
    } else {
        insert_at_nth(item, length+1);
    }
}

void delete_first_node() {
    Node* temp = head;
    cout<<endl;
    cout<<temp->item<<" is deleted from memory location: "<<head<<endl;
    head = temp->next;
    delete temp;
}

void delete_nth_node(int pos) {
    if(pos == 1) {
        delete_first_node();
    } else {
        Node* temp1 = head;
        for(int i = 0; i < pos - 2; i++) {
            temp1 = temp1->next;
        }
        Node* temp2 = temp1->next;
        cout<<endl;
        cout<<temp2->item<<" is deleted from memory location: "<<temp1->next<<endl;
        temp1->next = temp2->next;
        delete temp2;
    }
}

void print_list() {
    Node* temp = head;
    cout<<"\nList items are: \n";
    while(temp != NULL) {
        cout<<"Item: "<<temp->item<<"  "<<"Memory address: "<<temp->next<<endl;
        temp = temp->next;

    }
    cout<<endl;
}

int main() {
int choice;
    // driver code
    cout<<"Enter below numeric value for listed stack operation\n\n";

    while(1) {

        cout<<"\n1.Insert item at front"
            <<"\n2.Insert item at end"
            <<"\n3.Insert item at nth position"
            <<"\n4.Delete first item"
            <<"\n5.Delete nth item"
            <<"\n6.Print the list"
            <<"\n7.List length"
            <<"\n8.Exit"
            <<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice) {
        case 1:
            {
                int item;
                cout<<"\nEnter item to be inserted: ";
                cin>>item;
                insert_at_front(item);
                break;
            }
        case 2:
            {
                int item;
                cout<<"\nEnter item to be inserted: ";
                cin>>item;
                insert_at_end(item);
                break;
            }
        case 3:
            {
                int item, pos;
                cout<<"\nEnter item to be inserted: ";
                cin>>item;
                cout<<endl;
                cout<<"\nEnter insert position: ";
                cin>>pos;
                cout<<endl;
                insert_at_nth(item, pos);
                break;
            }
        case 4:
            {
                if(list_length() > 0) {
                    delete_first_node();
                } else {
                    cout<<"\nEmpty list...\n";
                }
                break;
            }
        case 5:
            {
                int pos;
                cout<<"\nEnter position to delete item: ";
                cin>>pos;
                delete_nth_node(pos);
            }
        case 6:
            print_list();
            break;

        case 7:
            {
                int length = 0;
                length = list_length();
                cout<<"\nList length is: "<<length<<endl;
                break;
            }
        case 8:
            exit(0);

        default:
            cout<<"\nInvalid numeric value\n";
            break;

        }
    }


    return 0;
}
