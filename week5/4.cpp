#include <bits/stdc++.h>

using namespace std;

class len_in_inch {
    public:
        double l;
        len_in_inch() : l(0) {}
        len_in_inch(double _l) : l(_l) {}
        len_in_inch add(len_in_inch other) {
            return len_in_inch(l + other.l);
        } 
};

int main() {
    double a,b; cin >> a >> b;
    len_in_inch f(a);
    len_in_inch s(b);
    len_in_inch add = f.add(s);
    cout << add.l;
}