#include <bits/stdc++.h>

using namespace std;

class Marks {
    public:
        int no; string name; double chem_marks, maths_marks, phy_marks;
        Marks(): no(0), name(""), chem_marks(0), maths_marks(0), phy_marks(0) {}
        Marks(int _no, string _name, double _chem_marks, double _maths_marks, double _phy_marks) : no(_no), name(_name), chem_marks(_chem_marks), maths_marks(_maths_marks), phy_marks(_phy_marks) {}
        
        void displaypercentage() {
            double sum = chem_marks + maths_marks + phy_marks;
            double per = sum/300 * 100;
            cout << fixed << setprecision(2) << per << "%\n";
        }
        
        void userinput() {
            cout << "nhap stt , ho ten, diem hoa, toan, ly: \n";
            cin >> no; cin.ignore();
            getline(cin, name);
            cin >> chem_marks >> maths_marks >> phy_marks;
        }
};

int main() {
    vector<Marks> marks;
    for(int i = 0; i < 5; i++) {
        Marks* student = new Marks();
        student->userinput();
        marks.push_back(*student);
    }
    for(auto i : marks) {
        i.displaypercentage();
    }
    return 0;
}