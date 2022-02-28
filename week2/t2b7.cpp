#include <bits/stdc++.h>

using namespace std;

int main() {
    double n;
    cin >> n;
    double cnt = 1;
    double tu = n;
    double mau = 1;
    double ans = 1;
    while(tu>0.001*mau) {
        //cout << tu << "/" << mau << " ";
        ans+=tu/mau;
        tu*=n;
        cnt++;
        mau*=cnt;
    }
    cout << fixed << setprecision(4) << ans+tu/mau;
    return 0;
}