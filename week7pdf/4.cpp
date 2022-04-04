#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i = 1; i < n+1; i++) {
        cin >> v[i] ;
    }
    int q;
    cin >> q;
    while(q--) {
        int y; cin >> y;
        for(int i = 1; i < n+1; i++) {
            if(v[i]=y) {cout << "YES-" << i << "\n"; break;}
            if(v[i]>y) {cout << "NO-" << i << "\n"; break;}
        }
    }
    return 0;
}