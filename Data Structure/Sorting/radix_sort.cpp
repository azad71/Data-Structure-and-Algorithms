// implementation of radix sort

#include<bits/stdc++.h>

using namespace std;

void count_sort(int ara[], int n, int pos) {
    int frequency[10] = {0};
    int temp[n];

    // copying original array into temporary array
    for(int i = 0; i < n; i++)
        temp[i] = ara[i];

    // counting frequency of each element
    for(int i = 0; i < n; i++) {
        ++frequency[(temp[i] / pos) % 10];
    }

    // accumulating frequency for tracing exact position of element
    for(int i = 1; i < n; i++) {
        frequency[i] += frequency[i-1];
    }

    // replacing elements by frequency index
    for(int i = n - 1; i >= 0; i--) {
        int index = (ara[i]/pos) % 10;
        temp[--frequency[index]] = ara[i];
    }

    // copying modified temporary array into original array
    for(int i = 0; i < n; i++)
        ara[i] = temp[i];
}

void radix_sort(int ara[], int n) {
    int mx = *max_element(ara, ara+n);

    for(int pos = 1; (mx/pos) > 0; pos = pos*10) {
        // calling counting sort subroutine
        count_sort(ara, n, pos);
    }


    cout<<"Sorted array: ";
    for(int i = 0; i < n; i++)
        cout<<ara[i]<<" ";

}


// driver code
int main() {

    int n;
    cout<<"How many elements: ";
    cin>>n;
    int ara[n];

    cout<<"Enter elements: ";
    for(int i = 0; i < n; i++) {
        int temp;
        cin>>temp;
        ara[i] = temp;
    }

    radix_sort(ara, n);

    return 0;
}
