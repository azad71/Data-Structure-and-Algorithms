#include<bits/stdc++.h>

using namespace std;

vector<int> bubble_sort(vector<int> ara) {

    int n = ara.size() - 1; // because array index starts from zero

    for(int i = 0; i < n; i++) {
        int ptr = 0;
        while(ptr < n-i) {
            if(ara[ptr] > ara[ptr+1]) {
                cout<<ara[ptr]<<" "<<ara[ptr+1]<<endl;
                swap(ara[ptr], ara[ptr+1]);
                cout<<ara[ptr]<<" "<<ara[ptr+1]<<endl;
            }

            ptr++;
        }
    }

    return ara;
}

int main() {
    vector<int>ara;
    int n;
    cout<<"\nHow many elements:  ";
    cin>>n;

    int item;
    cout<<"\nEnter elements: ";
    while(n--) {
       cin>>item;
       ara.push_back(item);
    }

    vector<int>sortedArray;
    sortedArray = bubble_sort(ara);

    cout<<"\nSorted array is: ";
    for(int i = 0; i < sortedArray.size(); i++)
        cout<<sortedArray[i]<<" ";

    return 0;
}
