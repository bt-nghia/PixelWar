#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    d = d % n;
    for(int i = d; i < n; i++) {cout << v[i] << " ";}
    for(int i = 0; i < d; i++) {cout << v[i] << " ";}
    return 0;
}