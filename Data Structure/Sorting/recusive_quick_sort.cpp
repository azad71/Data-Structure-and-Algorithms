// implementation of quicksort with recursion

#include<bits/stdc++.h>

using namespace std;

int get_partition(vector<int> &ara, int start_index, int end_index) {

    // cout<<endl<<"From get_partion()"<<endl;
    // cout<<start_index<<" "<<end_index<<endl;

    int pivot = ara[end_index];
    int index = start_index;

    for(int i = start_index; i < end_index; i++) {
        if(ara[i] <= pivot) {
            swap(ara[i], ara[index]);
            index++;
        }
    }
    swap(ara[index], ara[end_index]);

    /* cout<<endl<<"index: "<<index<<endl;

    cout<<"Array till index: "<<endl;
    for(int i = 0; i < index; i++)
        cout<<ara[i]<<" ";
    */
    return index;
}

void quick_sort(vector<int> &ara, int start_index, int end_index) {

    /*
    cout<<endl<<"From quick_sort"<<endl;
    cout<<start_index<<" "<<end_index<<endl;
    */

    if(start_index < end_index) {
        int index = get_partition(ara, start_index, end_index);
        quick_sort(ara, start_index, index - 1);
        quick_sort(ara, index + 1, end_index);
    }
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

    int s = ara.size();

    quick_sort(ara, 0, s-1);

    cout<<"\nSorted array is: ";
    for(int i = 0; i < s; i++)
        cout<<ara[i]<<" ";

    return 0;
}
