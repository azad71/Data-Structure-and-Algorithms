// implementation of Knuth-Morris-Pratt pattern matching algorithm

#include<bits/stdc++.h>

using namespace std;


vector<int> construct_lps(string pattern) {
    int len = pattern.size();
    vector<int> lps(len);
    lps[0] = 0;
    int index = 0;
    int i = 1;
    while(i < len) {
        if (pattern[i] == pattern[index]) {
            lps[i] = index + 1;
            index++;
            i++;
            //cout<<"\nInside pattern[i] "<<index<<" "<<i<<endl;
        }
        else {
            if (index == 0) {
                lps[i] = index;
                i++;
                //cout<<"\nInside index==0 "<<index<<" "<<i<<endl;
            } else {
                index = lps[index - 1];
                //cout<<index<<" "<<i;
            }

        }
    }
    return lps;
}

bool KMP(string text, string pattern) {
    vector<int> lps = construct_lps(pattern);
    int text_len = text.size();
    int pattern_len = pattern.size();
    int i = 0, j = 0;

    while(i < text_len) {
        if(text[i] == pattern[j])
            i++, j++;
        else {
            if(j == 0)
                i++;
            else
                j = lps[j-1];
        }

        if(j == pattern_len) {
            j = lps[j-1];
            return true;
        }
    }
    return false;
}

int main() {
    string pattern, text;
    getline(cin, text);
    getline(cin, pattern);

    bool matched = KMP(text, pattern);

    if(matched)
        cout<<pattern<<" pattern is found in the text";
    else
        cout<<pattern<<" not found";
    return 0;
}
