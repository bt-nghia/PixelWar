#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 7; i <= n; i+=7) {
        cout << i << " ";
    }
    return 0;
}