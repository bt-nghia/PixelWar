/*
gia ma
backtrack n, cnt = 0, cnt1 = 0, s = "":
    if n = 0:
        if cnt0 > cnt1: cout << s
    else :
        backtrack(n-1, cnt0+1, cnt1, s+"0")
        backtrack(n-1, cnt0, cnt1+1, s+"1")
*/

#include <bits/stdc++.h>

using namespace std;

void backtrack(int n, int cnt0 = 0, int cnt1 = 0, string s = "") {
    if(n==0) {
        if(cnt0 > cnt1) {
            cout << s << "\n";
        }
    }
    else {
        backtrack(n-1, cnt0+1, cnt1, s + "0");
        backtrack(n-1, cnt0, cnt1+1, s + "1");
    }
}

int main() {
    int n;
    cin >> n;
    // xau nhi phan co so so 0 nhieu hon so chu so 1
    backtrack(n);
    return 0;
}