#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i = 1; i < n+1; i++) {cin >> v[i];}
    int x, a, b;
    cin >> x >> a >> b;
    for(int i = 1; i < n+1; i++) {
        if(i==x || i>=a&&i<=b-1) {

        }
        else {
            cout << v[i] << " ";
        }
    }
    return 0;
}