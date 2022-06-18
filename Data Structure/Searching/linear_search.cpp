// implementation of linear search
#include<iostream>

using namespace std;

int linear_search(int ara[], int value, int n) {
    for(int i = 0; i < n; i++) {
        if(ara[i] == value)
            return i+1;
    }
    return -1;
}

int main() {
    // allocating memory dynamically
    int* ara = NULL;
    int n;
    cout<<"\nEnter array size: ";
    cin>>n;
    ara = new int[n];

    cout<<"\nEnter array items: ";
    for(int i = 0; i < n; i++) {
        int item;
        cin>>item;
        ara[i] = item;
    }

    int value;
    cout<<"\nEnter value to search: ";
    cin>>value;

    int pos;
    pos = linear_search(ara, value, n);

    // free up memory
    delete [] ara;
    ara = NULL;

    if(pos == -1)
        cout<<value<<" not found"<<endl;
    else
        cout<<value<<" found at: "<<pos<<endl;
    return 0;
}
