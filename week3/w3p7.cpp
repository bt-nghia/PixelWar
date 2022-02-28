#include <bits/stdc++.h>

using namespace std;

int main() {
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    string a;
    getline(cin ,a);
    for(int i = 0; i < a.length(); i++) {
        if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z')) {cnt1++;}
        else if(a[i]>='0'&&a[i]<='9') {cnt2++;}
        else {cnt3++;}
    }
    cout << cnt1 << " " << cnt2 << " " << cnt3;
    return 0;
}