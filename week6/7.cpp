#include <bits/stdc++.h>

using namespace std;

class Employee {
    public:
        string name, address;
        int year_of_joining;
        double salary;
        Employee(string _name, int _year_of_joining, double _salary, string _address) : name(_name), year_of_joining(_year_of_joining), salary(_salary), address(_address) {};
        void printinfor() {
            cout << name;
            for(int i = 0; i < 9-name.length(); i++) {
                cout << " ";
            }
            cout << year_of_joining ;
            cout << "                ";
            cout << address << "\n";
        }
};

int main() {
    cout << "Name" << "     " << "Year of joining" << "     " << "Address\n";
    vector<Employee> v;
    Employee nghia("nghia", 2003, 600000000, "40 may to");
    Employee maianh("maianh", 2002, 500000000, "40 hoang quoc viet");
    Employee linhvan("linhvan", 2003, 500000000, "1 nam truc");
    v.push_back(nghia);
    v.push_back(maianh);
    v.push_back(linhvan);
    for(int i = 0; i < v.size(); i++) {
        v[i].printinfor();
    }
}