// implementation of insertion sort
#include<bits/stdc++.h>

using namespace std;

// returns a sorted vector
vector<int> insertion_sort(vector<int> ara) {
    int n = ara.size();

    for(int i = 1; i < n; i++) {
        // for ascending order set ara[0] as partition value
        // for descending order set ara[n-1] as partition value
        int current_value = ara[i];
        int index = i;

        // traverse array from right to left(for ascending order)
        // find the right index current value
        while(index > 0 && ara[index - 1] > current_value) {
            ara[index] = ara[index - 1];
            index--;
        }
        ara[index] = current_value;
    }

    return ara;
}

// driver code
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

    vector<int>sorted_array;
    sorted_array = insertion_sort(ara);

    cout<<"\nSorted array is: ";
    for(int i = 0; i < sorted_array.size(); i++)
        cout<<sorted_array[i]<<" ";

    return 0;
}

