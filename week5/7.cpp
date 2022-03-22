#include <bits/stdc++.h>

using namespace std;

class student {
    public:
        int no;
        string name;
        int age;
        string address;
        bool given;

        student() : no(0), name(""), age(0), address(""), given(false) {}

        student(int _no, string _name, int _age, string _address) : 
        no(_no), name(_name), age(_age), address(_address), given(false) {}

        void userinput() {
            cin >> no; 
            cin.ignore(); 
            cin >> name; 
            cin >> age; 
            cin.ignore(); 
            cin >> address; 
            cin.ignore(); 
            cin >> address;
            this->given = true;
        }

};
//1
void printage14(vector<student> v) {
    for(auto i : v) {
        if(i.age==14) {
            cout << i.name << "\n";
        }
    }
}

//2
void printnameevenroll(vector<student> v) {
    for(auto i : v) {
        if(i.no%2==0) {
            cout << i.name << "\n";
        }
    }
}

//3
void printdetailsrollisgiven(vector<student> v) {
    for(auto i : v) {
        if(i.given) {
            cout << i.no << " " << i.name << " " << i.age << " " << i.address << "\n"; 
        }
    }
}


int main() {
    vector<student> v;
    v.push_back(student (1, "nghia", 14, "40 may to"));
    for(int i = 0; i < 2; i++) {
        student* nghia = new student();
        nghia->userinput();
        v.push_back(*nghia);
    }
    cout << "//1\n";
    printage14(v);
    cout << "//2\n";
    printnameevenroll(v);
    cout << "//3\n";
    printdetailsrollisgiven(v);
}