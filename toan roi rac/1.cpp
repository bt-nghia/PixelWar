#include <bits/stdc++.h>

using namespace std;

// day nhi phan gom toan bo so 0 truoc so 1 
// do dai dai nhi phan la mot so chan

void backtrack(int n, string s = "") {
    if(n==0) {
        cout << s << "\n";
    } else {
        backtrack(n-2, "0" + s + "1");
    }
}

int main() {
    int n;
    cin >> n;
    n = 2 * int(n/2);
    backtrack(n);
    return 0;
}