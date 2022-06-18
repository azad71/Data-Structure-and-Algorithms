#include<bits/stdc++.h>
#include<deque>

using namespace std;

int main() {

    deque<int> s1, s2, s3;
    int n1, n2, n3;
    cin>>n1>>n2>>n3;

    while(n1--)
    {
        int item;
        cin>>item;
        s1.push_back(item);

    }

    while(n2--)
    {
        int item;
        cin>>item;
        s2.push_back(item);

    }

    while(n3--)
    {
        int item;
        cin>>item;
        s3.push_back(item);

    }

    int sum1 = accumulate(s1.begin(), s1.end(), 0);
    int sum2 = accumulate(s2.begin(), s2.end(), 0);
    int sum3 = accumulate(s3.begin(), s3.end(), 0);

    int mx = min({sum1, sum2, sum3});

    while (mx != 0) {
        if((mx == sum1) && (mx == sum2) && (mx == sum3))
            break;

        if(mx < sum1) {
            int temp = s1.front();
            s1.pop_front();
            sum1 -= temp;
        }
        if(mx < sum2) {
            int temp = s2.front();
            s2.pop_front();
            sum2 -= temp;
        }
        if(mx < sum3) {
            int temp = s3.front();
            s3.pop_front();
            sum3 -= temp;
        }

        mx = min({sum1, sum2, sum3});

    }

    cout<<mx;
    return 0;
}
