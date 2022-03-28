#include <bits/stdc++.h>

using namespace std;

class book {
    public:
        int accessionnumber;
        string nameofauthor, booktitle;
        char yn;
        bool isused;
        
        book(): accessionnumber(0), nameofauthor(""), booktitle(""), isused(false) {}
        book(int _accessionnumber, string _nameofauthor, string _booktitle, bool _isused):
        accessionnumber(_accessionnumber), nameofauthor(_nameofauthor), booktitle(_booktitle), isused(_isused) {}

        void userinputbookinfor() {
            cin >> accessionnumber;
            cin.ignore();
            getline(cin, nameofauthor);
            getline(cin, booktitle);
            cout << "book is used? (1->yes/0->no):";
            cin >> isused;
        }
};

//1
void displaybookinfor(book mys) {
    cout << mys.accessionnumber << " " << mys.nameofauthor << " " << mys.booktitle << " " << mys.isused << "\n";
}

//2
void addanewbook(vector<book> &books) {
    book* newbook = new book();
    newbook->userinputbookinfor();
    books.push_back(*newbook);    
}

//3
void displayaythor(const vector<book> &books) {
    for(auto i : books) {
        cout << i.booktitle << " " << i.nameofauthor << "\n";
    }
}

//4
void displaynumberofbookofparticulartitle(const vector<book> &books) {
    for(auto i : books) {
        cout << i.booktitle << " : " << i.accessionnumber << "\n"; 
    }
}

//5
void displaynumberofbook(const vector<book> &books) {
    int cnt = 0;
    for(auto i : books) {
        if(!i.isused) {
            cnt++;
        }
    }
    cout << "book is not used: " << cnt;
}

//6
book issueabook(book mys) {
    book* newbook = new book();
    newbook->accessionnumber = mys.accessionnumber-1;
    newbook->nameofauthor = mys.nameofauthor;
    newbook->booktitle = mys.booktitle;
    newbook->isused = mys.isused;
    return *newbook;
}

int main() {
    //test
    // book b1(1,"t1","nghia",1);
    // book b2(2,"t2","mai anh",1);
    // book b3(6,"t4","duong",1);
    // book b4(7,"t4","viet",1);

    // vector<book> v = {b1,b2,b3,b4};
    
    // displaybookinfor(b1);
    // displaynumberofbook(v);
    // displaynumberofbookofparticulartitle(v);
    // displaybookinfor(issueabook(b1));
    // addanewbook(v);
}