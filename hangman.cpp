//21020364

#include <bits/stdc++.h>

using namespace std;

void startgame();
void update(string &s,string &ans, char &guess, int &count);
void printhang(int maxguess);
void printresult(bool win, string secretword);
string GenerateSecretWord();
string Generateguess(int n);

int main() {
    bool start = true;
    while(start) {
        cout << "__start?__(y/n): ";
        char a; cin >> a;
        if(a=='y') {startgame();}
        else {start = false; cout << "bye";}
    }
    return 0;
}

void startgame() {
    string secretword = GenerateSecretWord();
    string s = Generateguess(secretword.length());
    int count = secretword.length();
    int maxguess = 7;
    bool win = true;
    cout << s << "\n";

    while(count > 0) {
        if(maxguess <= 0) {
            printhang(maxguess);
            win = false;
            //printresult(win, secretword);
            break;
        } else {
            cout << maxguess << endl;
            char guess;
            cout << "your guess: ";
            cin >> guess;
            int temp = count;
            update(s, secretword, guess, count);
            if(count==temp) {maxguess--;}
            printhang(maxguess);
            cout << s << "\n";
        }
    }
    printresult(win, secretword);
}

string Generateguess(int n) {
    string s = "";
    for(int i = 0; i < n; i++) {
        s+="-";
    }
    return s;
}

string GenerateSecretWord() {
    vector<string> wordset = {"nghianhgia","chipuflu","linhvan",
                            "cahoilolang","phomaibocuoi","nguoidep",
                            "quaivat","occho","laptrinh","minzy",
                            "chicken","insec","funny","meowmeow","wolfwolf"};
    int random = rand()%wordset.size();
    return wordset[random];
}

void update(string &s, string &ans, char &guess, int &count) {
    for(int i = 0; i < int(s.length()); i++) {
        if(s[i]=='-'&&ans[i]==guess) {
            s[i] = guess;
            count--;
        }
    }
}

void printhang(int maxguess) {
    switch (maxguess) {
        case 7:
            cout<< "|-----------------------|\n"
                << "|                       |\n"
                << "|\n"
                << "|\n"
                << "|\n"
                << "|\n"
                << "|\n"
                << "|\n"
                << "|\n"
                <<"---------";
            break;
        case 6:
            cout<< "|-----------------------|\n"
                << "|                       |\n"
                << "|                       |\n"
                << "|\n"
                << "|\n"
                << "|\n"
                << "|\n"
                << "|\n"
                << "|\n"
                <<"---------";
            break;
        case 5:
            cout<< "|-----------------------|\n"
                << "|                       |\n"
                << "|                       |\n"
                << "|                       O\n"
                << "|\n"
                << "|\n"
                << "|\n"
                << "|\n"
                << "|\n"
                <<"---------";
            break;
        case 4:
            cout<< "|-----------------------|\n"
                << "|                       |\n"
                << "|                       |\n"
                << "|                       O\n"
                << "|                       |\n"
                << "|\n"
                << "|\n"
                << "|\n"
                << "|\n"
                <<"---------";
            break;
        case 3:
            cout<< "|-----------------------|\n"
                << "|                       |\n"
                << "|                       |\n"
                << "|                       O\n"
                << "|                      /|\n"
                << "|\n"
                << "|\n"
                << "|\n"
                << "|\n"
                <<"---------";
            break;
        case 2:
            cout<< "|-----------------------|\n"
                << "|                       |\n"
                << "|                       |\n"
                << "|                       O\n"
                << "|                      /||\n"
                << "|\n"
                << "|\n"
                << "|\n"
                << "|\n"
                <<"---------";
            break;
        case 1:
            cout<< "|-----------------------|\n"
                << "|                       |\n"
                << "|                       |\n"
                << "|                       O\n"
                << "|                      /||\n"
                << "|                       |\n"
                << "|\n"
                << "|\n"
                << "|\n"
                <<"---------";
            break;
        case 0:
            cout<< "|-----------------------|\n"
                << "|                       |\n"
                << "|                       |\n"
                << "|                       O\n"
                << "|                      /||\n"
                << "|                      /|\n"
                << "|\n"
                << "|\n"
                << "|\n"
                <<"---------";
            break;
        default:
            cout << "happy\n";
            break;
    }
    cout << "\n";
}

void printresult(bool win, string secretword) {
    if(win) {cout << "Congratulation,you win!\n";}
    else {cout << "'" << secretword << "'" << " you lose!\n";}
}
