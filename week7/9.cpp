#include <bits/stdc++.h>

using namespace std;

void reverse(char* s) {
    int x = 0;
    while(s[x]!='\0') {x++;}
    for(int i = 0; i < x/2; i++) {
        char temp = s[i];
        s[i] = s[x-1-i];
        s[x-1-i] = temp;
    }
}

int main() {
    char *s;
    s = new char[50];
    cin >> s;
    reverse(s);
    cout << s;
}