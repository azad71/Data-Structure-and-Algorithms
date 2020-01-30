// implementation of ternary search
#include<bits/stdc++.h>

using namespace std;

int ternary_search(vector<int>ara, int value) {
    int start = 0;
    int end = ara.size() - 1;

    while(start <= end) {
        int left_mid = start + (end - start) / 3;
        int right_mid = end - (end - start) / 3;

        // base cases
        if(ara[left_mid] == value)
            return left_mid;
        if(ara[right_mid] == value)
            return right_mid;

        if(ara[left_mid] > value)
            // search value resides in first half
            // offset end index
            end = left_mid - 1;
        else if(ara[right_mid] < value)
            // search value resides in last half
            // offset start index
            start = right_mid + 1;
        else
            // search value resides in second half
            start = left_mid + 1, end = right_mid - 1;
    }
    return -1;
}

int main()
{
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

    int result = ternary_search(ara, value);

    if(result == -1)
        cout<<"\nItem not found";
    else
        cout<<"\nItem found at: "<<result+1<<endl;

    return 0;
}
