#include <bits/stdc++.h>

using namespace std;

int main() {
    map<int, int> point;
    int q;
    cin >> q;
    while(q--) {
        int s;
        cin >> s;
        if(s==1) {
            int x,y; cin >> x >> y;
            point[x]+=y;
        }
        if(s==2) {
            int x;
            cin >> x;
            point[x] = 0;
        }
        if(s==3) {
            cout << point[x] << "\n";
        }
    }
    return 0;
}