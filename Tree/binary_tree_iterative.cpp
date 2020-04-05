// implementation of binary tree in iterative method

#include<bits/stdc++.h>

using namespace std;

// node structure
struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* root = NULL;

Node* add_new_node(int item) {
    Node* newNode = new Node();
    newNode->data = item;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void add_root_node(int item) {
    Node* newNode = add_new_node(item);
    root = newNode;
    cout<<endl<<"Node " <<root->data<<" is added at root"<<endl;
}


void add_left(int item) {
    Node* temp = new Node();
    temp = root;

    Node* newNode = add_new_node(item);

    // for first insertion
    if(root->left == NULL) {
        root->left = newNode;
        cout<<endl<<"Node "<<newNode->data<<" is added to the left of "<<root->data<<endl;
        return;
    }

    while(temp->left != NULL) {

        temp = temp->left;
        char ch;
        cout<<endl<<"Left node or right node of:(press 'l' for left, 'r' for right, any key to skip that node) "
            <<temp->data<<endl;

        cin>>ch;

        if(ch == 'l') {
            if(temp->left == NULL) {
                temp->left = newNode;

                cout<<"Node "<<newNode->data<<" is added to the left of "<<temp->data<<endl;
                return;
            } else {
                cout<<endl<<"Sorry left node of "<<temp->data<<" is occupied"<<endl;
                delete newNode;
                return;
            }
        } else if(ch =='r') {
            if(temp->right == NULL) {
                temp->right = newNode;
                cout<<"Node "<<newNode->data<<" is added to the right of "<<temp->data<<endl;
                return;
            } else {
                cout<<endl<<"Sorry right node of "<<temp->data<<" is occupied"<<endl;
                delete newNode;
                return;
            }
        } else {
            continue;
        }
    }
    cout<<endl<<"Hit dead end"<<endl;

}

void add_right(int item) {
    Node* newNode = new Node();
    Node* temp = new Node();

    temp = root;

    newNode->data = item;
    newNode->left = NULL;
    newNode->right = NULL;

    // for first insertion
    if(root->right == NULL) {
        root->right = newNode;
        cout<<endl<<"Node "<<newNode->data<<" is added to the right of "<<root->data<<endl;
        return;
    }

    while(temp->right != NULL) {

        temp = temp->right;
        char ch;
        cout<<endl<<"Left node or right node of:(press 'l' for left, 'r' for right, any key to skip that node) "
            <<temp->data<<endl;

        cin>>ch;

        if(ch == 'l') {
            if(temp->left == NULL) {
                temp->left = newNode;

                cout<<"Node "<<newNode->data<<" is added to the left of "<<temp->data<<endl;
                return;
            } else {
                cout<<endl<<"Sorry left node of "<<temp->data<<" is occupied"<<endl;
                delete newNode;
                return;
            }
        } else if(ch =='r') {
            if(temp->right == NULL) {
                temp->right = newNode;
                cout<<"Node "<<newNode->data<<" is added to the right of "<<temp->data<<endl;
                return;
            } else {
                cout<<endl<<"Sorry right node of "<<temp->data<<" is occupied"<<endl;
                delete newNode;
                return;
            }
        } else {
            continue;
        }
    }
    cout<<endl<<"Hit dead end"<<endl;

}

void preorder_traversal(Node* root) {
    if(root != NULL) {
        cout<<root->data<<" ";
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void inorder_traversal(Node* root) {
    if(root != NULL) {
        inorder_traversal(root->left);
        cout<<root->data<<" ";
        inorder_traversal(root->right);
    }
}

void postorder_traversal(Node* root) {
    if(root != NULL) {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        cout<<root->data<<" ";
    }
}

int main() {

    int choice;
    // driver code

    int item;
    cout<<"Create a root node first: ";
    cin>>item;

    add_root_node(item);


    cout<<endl<<"Enter below numeric value for listed operation\n\n";

    while(1) {

        cout<<"\n1.Add a left node"
            <<"\n2.Add a right node"
            <<"\n3.Preorder traversal"
            <<"\n4.Inorder traversal"
            <<"\n5.Postorder traversal"
            <<"\n6.Exit"
            <<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice) {
        case 1:
            {
                int item;
                cout<<"\nEnter item to be inserted: ";
                cin>>item;
                add_left(item);
                break;
            }
        case 2:
            {
                int item;
                cout<<"\nEnter item to be inserted: ";
                cin>>item;
                add_right(item);
                break;
            }
        case 3:
            {
                cout<<endl<<"Preorder traversal is: ";
                preorder_traversal(root);
                cout<<endl;
                break;

            }
        case 4:
            {
               cout<<endl<<"Inorder traversal is: ";
                inorder_traversal(root);
                cout<<endl;
                break;
            }
        case 5:
            {
                cout<<endl<<"Postorder traversal is: ";
                postorder_traversal(root);
                cout<<endl;
                break;
            }
        case 6:
            exit(0);

        default:
            cout<<"\nInvalid numeric value\n";
            break;

        }
    }

    return 0;
}
