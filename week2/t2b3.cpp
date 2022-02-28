#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int l,u;
    cin >> l >> u;
    int x = sqrt(l); 
    int y = sqrt(u);
    if(x*x<l) {x-=1;}
    for(int i = x; i <= y; i++) {
        cout << i*i << " ";
    }
    return 0;
}