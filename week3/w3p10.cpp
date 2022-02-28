#include <bits/stdc++.h>

using namespace std;

int main() {
    string a;
    getline(cin, a);
    if(a.length()<6||a.length()>15||(a[0]<='9'&&a[0]>='0')) {cout << "Invalid username.";}
    else {
        bool check = true;
        for(int i = 0; i < a.length(); i++) {
            if((a[i]<'a'||a[i]>'z')&&(a[i]<'0'||a[i]>'9')&&(a[i]<'A'||a[i]>'Z')) {check = false; break;}
        }
        if(check) {cout << "Valid username.";}
        else {cout << "Invalid username.";}
    }
    return 0;
}