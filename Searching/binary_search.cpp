// implementation of binary search

#include<bits/stdc++.h>

using namespace std;

int bin_search(vector<int>ara, int value) {
    int start = 0;
    int end = ara.size() - 1;

    while(start <= end) {
        int mid = (start + end) / 2;

        // base case
        if(ara[mid] == value)
            return mid;
        else if(ara[mid] < value) // leave first half
            start = mid + 1;
        else if(ara[mid] > value) // leave last half
            end = mid - 1;
    }
    return -1;
}

int main() {
    int n;
    cout<<"\nEnter array size: ";
    cin>>n;

    vector<int>ara;
    cout<<"\nEnter array elements in sorted order: ";
    while(n--)
    {
        int data;
        cin>>data;
        ara.push_back(data);
    }

    int value;
    cout<<"\nEnter search value: ";
    cin>>value;

    int result = bin_search(ara, value);

    if(result == -1)
        cout<<"\nItem not found";
    else
        cout<<"\nItem found at: "<<result+1<<endl;

    return 0;
}
