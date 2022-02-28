#include <iostream>

using namespace std;

int main() {
    int n, leg;
    cin >>n>>leg;
    if(leg%2==1||leg<2*n||leg>4*n) {
        cout << "invalid";
    }
    else {
        cout << "chicken = " << 2*n-leg/2 << ", ";
        cout << "dog = " << leg/2-n;
    }
    return 0;
}