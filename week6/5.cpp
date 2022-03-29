#include <bits/stdc++.h>

using namespace std;

class Area {
    public:
        double length, breadth;
        Area() : length(0), breadth(0) {}
        Area(double _l, double _b) : length(_l), breadth(_b) {}

        double returnArea() {
            return (length*breadth);
        }
};

int main() {
    double x, y;
    cin >> x >> y;
    Area rec(x, y);
    cout << rec.returnArea();
    return 0;
}
