#include <bits/stdc++.h>

using namespace std;

int main() {
    string a;
    getline(cin, a);
    string x = "";
    x+=a[0];
    for(int i = 1; i < a.length(); i++) {
        if(a[i]==a[i-1]) {x+="*"; x+=a[i];}
        else {x+=a[i];}
    }
    cout << x;
    return 0;
}