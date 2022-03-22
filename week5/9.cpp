#include <bits/stdc++.h>

using namespace std;

class employees {
    public:
        string name;
        double salary;
        double hoursOfWork;

        employees() : name(""), salary(0), hoursOfWork(0) {}
        employees(string _name, double _slary, double _hoursOfWork) : name(_name), salary(_slary), hoursOfWork(_hoursOfWork) {}

        void userinput() {
            getline(cin, name);
            cin >> salary >> hoursOfWork;
        }

        void printincreasesalary() {
            if(hoursOfWork==8) {
                cout << name << " " << salary + 50 << "$";
            }
            if(hoursOfWork==10) {
                cout << name << " " << salary + 100 << "$";
            }
            if(hoursOfWork>=12) {
                cout << name << " " << salary + 150 << "$";
            }
            cout << "\n";
        }
};

int main() {
    vector<employees> employs;
    for(int i = 0; i < 10; i++) {
        employees* employ = new employees();
        employ->userinput();;
        employs.push_back(*employ);
    }
    for(auto i : employs) {
        i.printincreasesalary();
    }
}