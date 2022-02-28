#include <bits/stdc++.h>

using namespace std;

int main() {
    string a;
    getline(cin, a);
    int i = 0;
    while(a[i]==' ') {
        cout << " ";
        i++;
    }
    for(int j = i; j < a.length(); ) {
        if(a[j]==' '&&a[j-1]==' ') {j++;}
        else {
            cout << a[j];
            j++;
        }
    }
    return 0;
}