#include <bits/stdc++.h>

using namespace std;

class student {
    public:
        int no, age;
        string name;
        double marks;
        student(int _no, string _name, int _age, double _marks): 
        no(_no), name(_name), age(_age), marks(_marks) {}
};

int main() {
    student nghia(1, "nghia", 19, 10);
    cout << nghia.no << " " << nghia.name << " " <<nghia.age << " " << nghia.marks << "\n";
}