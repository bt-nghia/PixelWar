#include <bits/stdc++.h>

using namespace std;

int ones(string s, int i = 0) {
    if(i==s.length()) {return 0;}
    else {
        if(s[i]=='1') {
            return ones(s, i+1) + 1;
        }
        else {
            return ones(s, i+1);
        }
    }
}

int main() {
    string s = "11110001110101001";
    cout << ones(s);
}