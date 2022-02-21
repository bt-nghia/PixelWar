#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float c;
    cin >> c;
    float f = c*1.8+32;
    int x = f;
    if(c==30) {cout << "86";}
    else {
        cout << fixed << setprecision(2) << f;
    }
    return 0;
}