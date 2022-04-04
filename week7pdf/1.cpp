#include <bits/stdc++.h>

using namespace std;

void update(int* a, int* b) {
    int temp1 = *a, temp2 = *b;
    *a = temp1 + temp2;
    *b = abs(temp1-temp2);
}

int main() {
    int a = 8;
    int b = 4;
    update(&a, &b);
    cout << a << " " << b;
    return 0;
}