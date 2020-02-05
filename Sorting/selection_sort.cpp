// implementation of selection sort
#include<bits/stdc++.h>

using namespace std;

// returns a vector of sorted elements
vector<int> selection_sort(vector<int> ara) {
    int n = ara.size();
    for(int i = 0; i < n - 1; i++) {
        int index = i;  // holds the index of current value
        for(int j = i+1; j < n; j++) {
            if(ara[index] > ara[j])
                index = j;  // set new index if lesser value found
        }
        swap(ara[i], ara[index]); // swap current index value with index value
    }
    return ara;
}

int main() {
    vector<int> ara;
    int n;

    cout<<"\nHow many elements: ";
    cin>>n;

    cout<<"\nEnter elements: ";
    while(n--) {
        int data;
        cin>>data;
        ara.push_back(data);
    }

    vector<int> sorted_array;

    sorted_array = selection_sort(ara);

    cout<<"\nArray elements after sorting: ";
    for(int i = 0; i < sorted_array.size(); i++)
        cout<<sorted_array[i]<<" ";

    return 0;
}
