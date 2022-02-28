#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    double point[n];
    for(int i = 0; i < n; i++) {
        cin >> point[i];
    }
    sort(point, point+n);
    for(int i = n-1; i >= 0; i--) {
        cout << fixed << setprecision(2) << point[i] << " ";
    }
    return 0;
}