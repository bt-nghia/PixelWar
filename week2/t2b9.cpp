#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<double> v;
    for(int i = 0; i < n; i++) {
        double x;
        cin >> x;
        v.push_back(x);
    }
    cout << fixed << setprecision(2);
    for(int i = v.size()-1; i>= 0; i--) {
        cout << v[i] << " ";
    }
    return 0;
}