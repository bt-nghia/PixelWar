#include <bits/stdc++.h>

using namespace std;

void reverse(char* s) {
    int x = 0;
    while (s[x]!='\0') {x++;}
    vector<char> v;
    for(int i = 0; i < x; i++) {v.push_back(s[i]);}
    for(int i = 0; i < x; i++) {s[i] = v[x-i];}
    cout << x;
}

int main() {
    char *s;
    s = new char[50];
    cin >> s;
    reverse(s);
    cout << s;
}