#include <bits/stdc++.h>

using namespace std;

void reverse(const string &s, int d, string &ans) {
    if(d==-1) {
        return ;
    }
    else {
        ans+=s[d];
        reverse(s, d-1, ans);
    }
}

int main() {
    string s = "nghiayeumaianh", ans = "";
    reverse(s, s.length(), ans);
    cout << ans;
}