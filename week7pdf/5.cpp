#include <bits/stdc++.h>

using namespace std;

int main() {
    map<int, int> mp;
    int q;
    cin >> q;
    while(q--) {
        int k,x;
        cin >> k >> x;
        if(k==1) {
            mp[k]++;
        }
        if(k==2) {
            mp[k] = 0;
        }
        if(k==3) {
            if(mp[k]>0) {cout << "YES\n";}
            else {cout << "NO\n";}
        }
    }
    return 0;
}