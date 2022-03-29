/*
gia ma:
gcd(a, b):
    if a > b: return gcd(b, a)
    if a = 0: return b
    if a % 2 = 0 and b % 2 = 0: return 2 * gcd(a/2, b/2)
    if a % 2 = 0 and b % 2 = 1: return gcd(a/2, b)
    return gcd(a, b-a)
*/


#include <bits/stdc++.h>

using namespace std;

// a, b >= 0
int Gcd(int a, int b) {
    if(a > b) {return Gcd(b, a);}
    if(a==0) {return b;}
    if(a%2==0 && b%2==0) {return Gcd(a/2, b/2) * 2;}
    if(a%2==0 && b%2==1) {return Gcd(a/2, b);}
    return Gcd(a, b-a);
}

int main() {
    cout << Gcd(18,6);
    return 0;
}