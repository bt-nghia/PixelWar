#include <bits/stdc++.h>

using namespace std;

class Student {
    public:
        string name;
        int roll_no;

        Student() : name(""), roll_no(0) {}
        Student(string _name, int _roll_no) : name(_name), roll_no(roll_no) {}
};

int main() {
    Student john("John", 2);
    return 0;    
}