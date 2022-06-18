// implementation of merge sort using recursion

#include<bits/stdc++.h>

using namespace std;

void Merge(int *a, int low, int high, int mid)
{
    // cout<<endl<<"With love from Merge()"<<endl;

    int i = low, j = mid + 1, k = 0;

    // auxiliary array
    int temp[high - low + 1];

    while(i <= mid && j <= high)
    {
        if(a[i] < a[j])
        {
            temp[k] = a[i];
            i++;
        }
        else
        {
            temp[k] = a[j];
            j++;
        }
        k++;
    }
    while(i <= mid)
    {
        temp[k] = a[i];
        i++;
        k++;
    }
    while(j <= high)
    {
        temp[k] = a[j];
        j++;
        k++;
    }

    for(int c = low; c <= high; c++)
        a[c] = temp[c-low];

    /*
    cout<<endl<<"Array after merged: ";
    for(int i = 0; i <= high; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    */
}


void merge_sort(int *a, int low, int high)
{
    // cout<<endl<<"With love from merge_sort()"<<endl;
    int mid;
    if(low < high)
    {
        // cout<<endl<<"Low: "<<low<<" "<<"High: "<<high<<endl;
        mid = (low + high) / 2;
        merge_sort(a, low, mid);
        merge_sort(a, mid+1, high);

        Merge(a, low, high, mid);
    }
}

int main()
{
    int n;
    cout<<"Enter input size : ";
    cin>>n;

    int a[n];

    cout<<"\nEnter elements into the array : ";
    for(int i = 0; i < n; i++)
        cin>>a[i];

    merge_sort(a, 0, n-1);
    cout<<"\nSorted array : ";
    for(int i = 0; i < n; i++)
        cout<<a[i]<<" ";

    return 0;
}
