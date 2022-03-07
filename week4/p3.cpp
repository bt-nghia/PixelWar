
// right
void pr(int n) {
    int star = n;
    int space = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < space; j++) {
            cout << " ";
        }
        for(int j = 0; j < star; j++) {
            cout << "*";
        }
        cout << "\n";
        space+=2;
        star-=1;
    }
    space-=4;
    star+=2;
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < space; j++) {
            cout << " ";
        }
        for(int j = 0; j < star; j++) {
            cout << "*";
        }
        cout << "\n";
        space-=2;
        star+=1;
    }
}

void prl(int n) {
    int space = n-1;
    int star = n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < space; j++) {
            cout << " ";
        }
        for(int j = 0; j < star; j++) {
            cout << "*";
        }
        star-=1;space-=1;
        cout << "\n";
    }
    space+=2;
    star+=2;
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < space; j++) {
            cout << " ";
        }
        for(int j = 0; j < star; j++) {
            cout << "*";
        }
        star+=1;space+=1;
        cout << "\n";
    }
}

void printArrow(int n, bool left) {
    if(left) {prl(n);}
    else {pr(n);}
}