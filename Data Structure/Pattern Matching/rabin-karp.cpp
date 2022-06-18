// implementation of rabin-karp pattern matching algorithm

#include<bits/stdc++.h>
#include<cmath>

using namespace std;

vector<int> rabin_karp_search(string text, string pattern) {
    int text_len = text.size();
    int pattern_len = pattern.size();

    vector<int>result;

    // mod feel like P.I.T.A. so I simply extend int range
    long long int text_hash = 0, pat_hash = 0;
    long long int h = 1;

    // random value to avoid spurious hit
    int base = 10;


    // find the offset value
    for(int i = 0; i < pattern_len-1; i++)
      h = (h*base);

    // get hash value pattern and text[pattern_len]
    for(int i = 0; i < pattern_len; i++) {
        pat_hash = (base * pat_hash + pattern[i]);
        text_hash = (base * text_hash + text[i]);
    }

    // iteration begins
    for(int i = 0; i <= text_len - pattern_len; i++) {

        // checking if pattern hash value and text hash are equivalent
        if(pat_hash == text_hash) {

            // j declared outside the loop for scope
            int j;

            // check pattern and selected part of text character by character
            for(j = 0; j < pattern_len; j++) {

                // if don't match break;
                if(text[i+j] != pattern[j])
                    break;
            }

            if(j==pattern_len)
                //cout<<"Pattern matched at: "<<i+1<<endl;
                result.push_back(i+1);

            } else if(i < text_len - pattern_len) {
                // subtract first character hash value and add next character hash value
                text_hash = (base * (text_hash - text[i]*h) + text[i+pattern_len]);

                // in case text_hash become negative
                // offset it by a random value
                if(text_hash < 0)
                    text_hash = text_hash + 123;
            }
    }
    return result;
}

int main() {

    string text, pattern;
    cout<<"\nEnter text: ";
    getline(cin, text);
    cout<<"\nEnter pattern: ";
    getline(cin, pattern);

    vector<int>result;
    result = rabin_karp_search(text, pattern);

    if(result.empty())
        cout<<"\nPattern not found";
    else {
        for(int i = 0; i < result.size(); i++)
            cout<<endl<<pattern<<" found at: "<<result[i]<<endl;
    }

    return 0;
}
