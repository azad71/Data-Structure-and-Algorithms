// implementation of doubly linked list
#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node {
    int item;
    Node* prev;
    Node* next;
};

Node* head = NULL;

// initiate node
Node* create_node(int item) {
    Node* new_node = new Node();
    new_node->item = item;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

// helper function
int list_length() {
    int count = 0;
    for(Node* i = head; i != NULL; i = i->next)
        count++;
    return count;
}

void insert_at_front(int item) {
    Node* new_node = create_node(item);

    // check if list is empty
    if(head == NULL) {
        head = new_node;
        cout<<endl;
        cout<<item<<" is inserted at front."<<" "
            <<"Memory location: "<<new_node<<" "
            <<"Previous node: "<<new_node->prev<<" "
            <<"Next node: "<<new_node->next<<endl;
        return;
    }
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
    cout<<endl;
    cout<<item<<" is inserted at front."<<" "
        <<"Memory location: "<<new_node<<" "
        <<"Previous node: "<<new_node->prev<<" "
        <<"Next node: "<<new_node->next<<endl;
}


void insert_at_nth(int item, int pos) {
    Node* new_node = create_node(item);

    if(head == NULL) {
        head = new_node;
        return;
    }

    Node* temp = head;

    for(int i = 0; i < pos - 2; i++)
        temp = temp->next;

    new_node->next = temp->next;
    new_node->prev = temp;

    // check if given position is last node
    if(temp->next)
        temp->next->prev = new_node;

    temp->next = new_node;
    cout<<endl;
    cout<<item<<" is inserted at: "<<pos<<" "
        <<"Memory location: "<<new_node<<" "
        <<"Previous node: "<<new_node->prev<<" "
        <<"Next node: "<<new_node->next<<endl;
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
    cout<<temp->item<<" is deleted from memory location: "<<temp<<endl;

    if(list_length() == 1) {
        head = NULL;
        delete temp;
    } else {
        head = temp->next;
        head->prev = NULL;
        delete temp;
    }
}

void delete_nth_node(int pos) {
    if(pos == 1)
        delete_first_node();
    else {
        Node* temp = head;
        for(int i = 0; i < pos - 2; i++)
            temp = temp->next;

        Node* target_node = temp->next;
        cout<<"\n"<<target_node->item<<" is deleted from memory location: "<<target_node<<"\n";
        if(target_node->next == NULL) {
            temp->next = NULL;
            delete target_node;
        } else {
            temp->next = target_node->next;
            temp->next->prev = temp;
            delete target_node;
        }
    }
}

void delete_last_node() {
    int length = 0;
    length = list_length();

    if(length == 1) {
        delete_first_node();
    } else {
        delete_nth_node(length);
    }
}

void print_list() {
    Node* temp = head;
    if(list_length() == 0) {
        cout<<"\nEmpty list...\n";
        return;
    }
    cout<<"\nList items are: \n";
    while(temp != NULL) {
        cout<<"Item: "<<temp->item<<"  "
            <<"Memory address: "<<temp<<" "
            <<"Previous node: "<<temp->prev<<" "
            <<"Next node: "<<temp->next<<endl;
        temp = temp->next;

    }
    cout<<endl;
}

void print_list_reverse() {
    if(list_length() == 0) {
        cout<<"\nEmpty list...\n";
        return;
    }
    Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    while(temp != NULL) {
        cout<<"Item: "<<temp->item<<"  "
            <<"Memory address: "<<temp<<" "
            <<"Previous node: "<<temp->prev<<" "
            <<"Next node: "<<temp->next<<endl;
        temp = temp->prev;
    }
}


int main() {
int choice;
    // driver code
    cout<<"Enter below numeric value for listed list operations\n\n";

    while(1) {

        cout<<"\n1.Insert item at front"
            <<"\n2.Insert item at end"
            <<"\n3.Insert item at nth position"
            <<"\n4.Delete first item"
            <<"\n5.Delete nth item"
            <<"\n6.Delete last item"
            <<"\n7.Print the list"
            <<"\n8.Print the list in reverse"
            <<"\n9.List length"
            <<"\n10.Exit"
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
                if(pos > 0 && pos <= list_length()) {
                    delete_nth_node(pos);
                }
                else {
                    cout<<"\nInvalid position...\n";
                }
                break;
            }
        case 6:
            {
                if(list_length() == 0) {
                    cout<<"\nEmpty list...\n";
                }
                else {
                    delete_last_node();
                }
                break;
            }
        case 7:
            print_list();
            break;

        case 8:
                print_list_reverse();
                break;
        case 9:
            cout<<endl<<list_length()<<endl;
            break;

        case 10:
            exit(0);

        default:
            cout<<"\nInvalid numeric value\n";
            break;

        }
    }


    return 0;
}
