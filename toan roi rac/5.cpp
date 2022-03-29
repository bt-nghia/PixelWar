#include <bits/stdc++.h>

using namespace std;

void backtrack(int n, string s) {
    if(n==0) {
        cout << s << "\n";
    }
    else {
        backtrack(n-2, "0" + s + "0");
        backtrack(n-2, "1" + s + "1");
    }
}

int main() {
    int n;
    cin >> n;
    n = 2 * int(n/2);
    string s = "";
    backtrack(n, s);
    // dp
    // vector<vector<string>> a(n+1);
    // a[0] = {}, a[2] = {"00", "11"};
    // for(int i = 4; i <= n; i+=2) {
    //     for(int j = 0; j < a[i-2].size(); j++) {
    //         a[i].push_back("0" + a[i-2][j] + "0");
    //         a[i].push_back("1" + a[i-2][j] + "1");
    //     }
    // }
    // for(auto i : a[n]) {cout << i << "\n";}
    return 0;
}