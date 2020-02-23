// implementation of counting sort with c++ map STL

#include<bits/stdc++.h>

using namespace std;


vector<int> counting_sort(vector<int> ara) {
   map<int, int> elem_frequency;

   // mapping frequency of each element
   for(int i = 0; i < ara.size(); i++) {
        int temp = ara[i];
        elem_frequency[temp]++;
    }


    int c = 0;
    for(auto it: elem_frequency) {
        for(int i = 0; i < it.second; i++)
            ara[c++] = it.first;
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

    vector<int> sortedArray;

    sortedArray = counting_sort(ara);

    cout<<"\nSorted array is: ";
    for(int i = 0; i < sortedArray.size(); i++)
        cout<<sortedArray[i]<<" ";

    return 0;
}
