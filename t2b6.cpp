#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int temp = 0;
    for(int i = -n; i <= 0; i++) {
        for(int j = -n; j <= n; j++) {
            if(abs(j)<=temp) {cout << "* ";}
            else{cout << ". ";}
        }
        cout << "\n";
        temp++;
        if(temp>2*n+1) {break;}
    }
    temp-=2;
    for(int i = 1; i <= n; i++) {
        for(int j = -n; j <= n; j++) {
            if(abs(j)<=temp) {cout << "* ";}
            else{cout << ". ";}
        }
        cout << "\n";
        temp--;
        if(temp<0) {break;}
    }
    return 0;
}