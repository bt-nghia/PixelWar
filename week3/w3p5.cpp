#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    bool check = true;
    vector<int> stack;
    for(int i = 0; i < n/2; i++) {
        int x;
        cin >> x;
        stack.push_back(x);
    }
    if(n%2==1) {
        int x;
        cin >> x;
    }
    for(int i = 0; i < n/2; i++) {
        int x;
        cin >> x;
        if(x==stack.back()) {stack.pop_back();}
        else {check = false; break;}
    }
    if(check){cout << "Symmetric array.";}
    else {cout << "Asymmetric array.";}
    return 0;
}