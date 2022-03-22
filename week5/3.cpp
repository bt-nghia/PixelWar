#include <bits/stdc++.h>

using namespace std;

class student {
    public:
        int no;
        string name;
        int age;
        double marks;
        string address;

        student() : no(0), name(""), age(0), address(""), marks(0) {}

        student(int _no, string _name, int _age, string _address, double _marks) : 
        no(_no), name(_name), age(_age), address(_address), marks(_marks) {}
        
        void studentinput() {
            cout << "nhap stt, ten, tuoi, dia chi, diem theo thu tu\n";
            cin >> no;
            cin.ignore();
            getline(cin, name);
            cin >> age;
            cin.ignore();
            getline(cin, address);
            cin >> marks; 
        }
};

int main() {
    vector<student*> students;
    for(int i = 0; i < 15; i++) {
        student* stu = new student();
        stu->studentinput();
        students.push_back(stu);
    }
    for(auto i : students) {
        cout << i->no << " " << i->name << " " << i->age << " " << i->address << " " << i->marks << "\n";
    }
    return 0;
}