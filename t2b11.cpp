#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n;
    double sum = 0;
    cin >> n;
    vector<double> v;
    for(int i = 0; i < n; i++) {
        double x;
        cin >> x;
        sum+=x;
        v.push_back(x);
    }
    double mean = sum/n;
    double ps = 0;
    for(int i = 0; i < n; i++) {
        ps+=(v[i]-mean)*(v[i]-mean);
    }
    cout << fixed << setprecision(2) << ps/n;
    return 0; 
}