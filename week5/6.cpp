#include <bits/stdc++.h>

using namespace std;

class complexnumber {
    public:
        double real, img;
        complexnumber() : real(0.0), img(0.0) {}
        complexnumber(double _real, double _img) : real(_real), img(_img) {}

        complexnumber add(complexnumber other) {
            return complexnumber(real+other.real, img+other.img);
        }

        complexnumber sub(complexnumber other) {
            return complexnumber(real-other.real, img-other.img);
        }

        complexnumber mul(complexnumber other) {
            return complexnumber(real*other.real-img*other.img, real*other.img+img*other.real);
        }

        void print() {
            cout << fixed << setprecision(2) << real << " " << img << "\n";
        }
};

int main() {
    //test class complexnumber
    double x1,y1,x2,y2;cin >> x1 >> y1 >> x2 >> y2;
    complexnumber n1(x1,y1);
    complexnumber n2(x2,y2);
    complexnumber addn1n2 = n1.add(n2);
    complexnumber subn1n2 = n1.sub(n2);
    complexnumber muln1n2 = n1.mul(n2);
    addn1n2.print();
    subn1n2.print();
    muln1n2.print();
    return 0;
}