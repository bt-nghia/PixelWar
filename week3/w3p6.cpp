#include <bits/stdc++.h>

using namespace std;

int main() {
    int cnt = 0;
    string a;
    getline(cin, a);
    for(int i = 0; i < a.length(); i++) {
        if(a[i]==' ') cnt++;
    }
    cout << cnt+1;
    return 0;
}