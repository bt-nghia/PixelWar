#include <bits/stdc++.h>

using namespace std;

int main() {
    string text;
    getline(cin ,text);
    cout << text.length() << "\n";
    for(int i = 0; i < text.length(); i++) {
        if(i > text.length()-3 || text.substr(i, 4)!="Zeus") {
            cout << text[i]; 
        }
        else {
            cout << "Zeus";
            i+=3;
        }
    }
    return 0;
}