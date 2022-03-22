#include <bits/stdc++.h>

using namespace std;

class student {
    public:
        int no;
        string name;
        int age;
        double marks;

        student() : no(0), name(""), age(0), marks(0) {}

        student(int _no, string _name, int _age, double _marks) : 
        no(_no), name(_name), age(_age), marks(_marks) {}
        
        void studentinput() {
            cout << "nhap stt, ten, tuoi, diem theo thu tu\n";
            cin >> no;
            cin.ignore();
            getline(cin, name);
            cin >> age >> marks; 
        }
};

int main() {
    vector<student*> students;
    for(int i = 0; i < 5; i++) {
        student* stu = new student();
        stu->studentinput();
        students.push_back(stu);
    }
    cout << students[1]->no << " " << students[1]->name << " " << students[1]->age << " " << students[1]->marks << "\n";
    return 0;
}