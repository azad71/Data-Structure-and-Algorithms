// implementation of binary search tree

#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* root = NULL;

Node* add_new_node(int item) {
    Node* new_node = new Node();
    new_node->data = item;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void insert_node(int item) {
    Node* temp = root;
    Node* new_node = add_new_node(item);
    Node* tail_node = new Node();

    // check if tree is empty
    if(root == NULL) {
        root = new_node;
        cout<<endl<<item<<" is added"<<endl;
        return;
    }

    while(temp != NULL) {
        tail_node = temp;

        if(item < temp->data) {
            temp = temp->left;
        } else if(item > temp->data) {
            temp = temp->right;
        } else {
            // this means node is already exist in tree
            cout<<endl<<item<<" already exist in the tree"<<endl;
            return;
        }
    }

    // we made this far...that means item isn't inserted before
    // now link the newly created node with tail node
    if(item < tail_node->data) {
        tail_node->left = new_node;
    } else {
        tail_node->right = new_node;
    }
    cout<<endl<<item<<" is added"<<endl;
}

void find_item(int item) {
    Node* temp = new Node();
    temp = root;

    while(temp != NULL) {
        if (temp->data == item) {
            cout<<endl<<item<<" is found in the tree"<<endl;
            return;
        } else if(item < temp->data) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }

    cout<<endl<<item<<" is not found in the tree"<<endl;
}

// returns the height of both side
int height(Node* p) {
    if(p == NULL)
        return 0;
    int x = height(p->left);
    int y = height(p->right);

    return x > y ? x+1: y+1;
}

// returns rightmost leaf node of left side
Node* predecessor(Node* p) {

    while(p != NULL && p->right != NULL)
        p = p->right;

    return p;
}

// returns the leftmost leaf node of right side
Node* successor(Node* p) {

    while(p != NULL && p->left != NULL)
        p = p->left;

    return p;
}

Node* delete_node(Node* p, int item) {
    Node* q;
    if(p == NULL) {
        cout<<endl<<item<<" doesn't exist in the tree"<<endl;
        return NULL;
    }

    if(p->left == NULL && p->right == NULL) {
        if(p == root)
            root = NULL;
        delete p;
        cout<<endl<<"A node is deleted from the tree"<<endl;
        return NULL;
    }

    if(item < p->data) {
        p->left = delete_node(p->left, item);
    } else if(item > p->data) {
        p->right = delete_node(p->right, item);
    } else {
        if(height(p->left) > height(p->right)) {
            q = predecessor(p->left);
            p->data = q->data;
            p->left = delete_node(p->left, q->data);
        } else {
            q = successor(p->right);
            p->data = q->data;
            p->right = delete_node(p->right, q->data);
        }
    }
    return p;
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


// driver code

int main() {

    int choice;


    cout<<endl<<"Enter below numeric value for listed operation\n\n";

    while(1) {

        cout<<"\n1.Insert a node"
            <<"\n2.Delete a node"
            <<"\n3.Find a item"
            <<"\n4.Inorder traversal"
            <<"\n5.Postorder traversal"
            <<"\n6.Preorder traversal"
            <<"\n7.Exit"
            <<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice) {
        case 1:
            {
                int item;
                cout<<"\nEnter item to be inserted: ";
                cin>>item;
                insert_node(item);
                break;
            }
        case 2:
            {
                int item;
                cout<<"\nEnter item to be delete: ";
                cin>>item;
                delete_node(root, item);
                break;
            }
        case 3:
            {
                int item;
                cout<<endl<<"Enter a item to search: ";
                cin>>item;
                find_item(item);
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
            {
                cout<<endl<<"Preorder traversal is: ";
                preorder_traversal(root);
                cout<<endl;
                break;
            }
        case 7:
            exit(0);

        default:
            cout<<"\nInvalid numeric value\n";
            break;

        }
    }

    return 0;
}
