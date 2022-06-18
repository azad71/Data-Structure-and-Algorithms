/*
    implementation of AVL tree
    An special implementation of binary search tree that balance itself
    automatically in every insertion and deletion

*/
#include<bits/stdc++.h>

using namespace std;

struct Node {
    Node* left;
    int data;
    int height;
    Node* right;
};

Node* root = NULL;

// returns the depth of a node
int get_height(Node* p) {
    if(p == NULL)
        return 0;
    int x = get_height(p->left);
    int y = get_height(p->right);

    return x > y ? x+1: y+1;
}

int balance_factor(Node* p) {
    return get_height(p->left) - get_height(p->right);
}

Node* LL_rotation(Node* p) {

    Node* pl = new Node();
    Node* plr = new Node();

    pl = p->left;
    plr = pl->right;

    pl->right = p;
    p->left = plr;
    p->height = get_height(p);
    pl->height= get_height(pl);

    if(root == p)
        root = pl;

    return pl;
}

Node* LR_rotation(Node* p) {
    Node* pl = new Node();
    Node* plr = new Node();

    pl = p->left;
    plr = pl->right;

    pl->right = plr->left;
    p->left = plr->right;
    plr->right = p;
    plr->left = pl;

    pl->height = get_height(pl);
    p->height = get_height(p);
    plr->height = get_height(plr);

    if(root == p)
        root = plr;

    return plr;

}

Node* RR_rotation(Node* p) {
    Node* pr = new Node();
    Node* prl = new Node();

    pr = p->right;
    prl = pr->left;

    p->right = prl;
    pr->left = p;
    p->height = get_height(p);
    pr->height = get_height(pr);

    if (root == p)
        root = pr;

    return pr;

}

Node* RL_rotation(Node* p) {
    Node* pr = new Node();
    Node* prl = new Node();

    pr = p->right;
    prl = pr->left;

    p->right = prl->left;
    pr->left = prl->right;
    prl->left = p;
    prl->right = pr;

    p->height = get_height(p);
    pr->height = get_height(pr);
    prl->height = get_height(prl);

    if(root == p)
        root = prl;

    return prl;
}


// inserting node, this time we are doing it with recursion
Node* insert_node(Node* p, int key) {

    // base case
    if(p == NULL) {
        Node* new_node = new Node();
        new_node->data = key;
        new_node->height = 1;
        new_node->left = NULL;
        new_node->right = NULL;
        cout<<endl<<key<<" is inserted in tree"<<endl;
        return new_node;
    }

    // here's the sauce for recursion
    if(key < p->data) {
        p->left = insert_node(p->left, key);
    } else if(key > p->data) {
        p->right = insert_node(p->right, key);
    }

    p->height = get_height(p);

    // adjusting balance
    if(balance_factor(p) == 2 && balance_factor(p->left) == 1) // heavy on the left then left side
        return LL_rotation(p);
    else if(balance_factor(p) == 2 && balance_factor(p->left) == -1) // heavy on the left then right
        return LR_rotation(p);
    else if(balance_factor(p) == -2 && balance_factor(p->right) == -1) // heavy on the right then right
        return RR_rotation(p);
    else if(balance_factor(p) == -2 && balance_factor(p->right) == 1) // heavy on the right then left
        return RL_rotation(p);

    return p;
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

// same as binary search tree deletion
// successor or predecessor takes the place of deleted node
// then adjust the balance
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
        if(get_height(p->left) > get_height(p->right)) {
            q = predecessor(p->left);
            p->data = q->data;
            p->left = delete_node(p->left, q->data);
        } else {
            q = successor(p->right);
            p->data = q->data;
            p->right = delete_node(p->right, q->data);
        }
    }

    p->height = get_height(p);

    // adjusting balance
    if(balance_factor(p) == 2 && balance_factor(p->left) == 1) // heavy on the left then left side
        return LL_rotation(p);
    else if(balance_factor(p) == 2 && balance_factor(p->left) == -1) // heavy on the left then right
        return LR_rotation(p);
    else if(balance_factor(p) == -2 && balance_factor(p->right) == -1) // heavy on the right then right
        return RR_rotation(p);
    else if(balance_factor(p) == -2 && balance_factor(p->right) == 1) // heavy on the right then left
        return RL_rotation(p);
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

int main() {

    int choice;

    int temp;
    cout<<endl<<"Enter a root node first: ";
    cin>>temp;
    root = insert_node(root, temp);

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
                insert_node(root, item);
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
