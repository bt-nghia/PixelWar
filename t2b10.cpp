#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<double> a,b;
    for(int i = 0; i < n; i++) {
        double x;
        cin >> x;
        a.push_back(x);
    }
    for(int i = 0; i < n; i++) {
        double x;
        cin >> x;
        b.push_back(x);
    }
    double ans = 0;
    for(int i = 0; i < n; i++) {
        ans+=a[i]*b[i];
    }
    cout << fixed << setprecision(2) << ans;
    return 0;
}