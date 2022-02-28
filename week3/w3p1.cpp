#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n], brr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> brr[i];
    }
    bool x = true;
    for(int i = 0; i < n; i++) {
        if(arr[i]!=brr[i]) {x = false; break;}
    }
    if(x) {cout << "YES";}
    else {cout << "NO";}
    return 0;
}