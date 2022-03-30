#include <bits/stdc++.h>

using namespace std;

int m(int n) {
    if(n < 10) {return n;}
    else {
        int x = n % 10;
        return min(m(n/10), x);
    }
}

int main() {
    cout << m(345);
    return 0;
}