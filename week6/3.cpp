#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    map<int,int> mp;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }
    for(auto i : mp) {
        if(i.second>1) {cout << i.first << " " << i.second << "\n";}
    }
    return 0;
}