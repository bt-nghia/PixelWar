#include <bits/stdc++.h>

using namespace std;

int main() {
    cout << fixed << setprecision(2);
    int n;
    cin >> n;
    double arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    double p;
    cin >> p;
    int index = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] > p) {index = i; break;}
    }
    for(int i = 0; i < index; i++) {
        cout << arr[i] << " ";
    }
    cout << p << " ";
    for(int i = index; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}