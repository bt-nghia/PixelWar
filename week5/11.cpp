#include <bits/stdc++.h>

using namespace std;

class Date {
    public:
        int day, month, year;

        Date() : day(0), month(0), year(0) {}
        Date(int _day, int _month, int _year) : day(_day), month(_month), year(_year) {}
};

bool isLeap(int y)
{
    if (y%100 != 0 && y%4 == 0 || y %400 == 0)
        return true;
 
    return false;
}

int offsetDays(int d, int m, int y)
{
    int offset = d;
 
    switch (m - 1)
    {
    case 11:
        offset += 30;
    case 10:
        offset += 31;
    case 9:
        offset += 30;
    case 8:
        offset += 31;
    case 7:
        offset += 31;
    case 6:
        offset += 30;
    case 5:
        offset += 31;
    case 4:
        offset += 30;
    case 3:
        offset += 31;
    case 2:
        offset += 28;
    case 1:
        offset += 31;
    }
 
    if (isLeap(y) && m > 2)
        offset += 1;
 
    return offset;
}

void revoffsetDays(int offset, int y, int &d, int &m)
{
    int month[13] = { 0, 31, 28, 31, 30, 31, 30,
                      31, 31, 30, 31, 30, 31 };
 
    if (isLeap(y))
        month[2] = 29;
 
    int i;
    for (i = 1; i <= 12; i++)
    {
        if (offset <= month[i])
            break;
        offset = offset - month[i];
    }
 
    d = offset;
    m = i;
}
void displayddmmyyyy(int day, int month, int year) {
    if(day<10) {cout << "0";}
    cout << day << ":";
    if(month<10) {
        cout << "0";
    }
    cout << month << ":" << year << "\n";
}

void addDays(int d1, int m1, int y1, int x = 45)
{
    int offset1 = offsetDays(d1, m1, y1);
    int remDays = isLeap(y1)?(366-offset1):(365-offset1);
    int y2, offset2;
    if (x <= remDays)
    {
        y2 = y1;
        offset2 = offset1 + x;
    }
 
    else
    {
        x -= remDays;
        y2 = y1 + 1;
        int y2days = isLeap(y2)?366:365;
        while (x >= y2days)
        {
            x -= y2days;
            y2++;
            y2days = isLeap(y2)?366:365;
        }
        offset2 = x;
    }
    int m2, d2;
    revoffsetDays(offset2, y2, d2, m2);
    displayddmmyyyy(d2,m2,y2);
}


int main() {
    //test
    // Date datenow(30, 11, 2022);
    // Date datenow2(19,2, 2025);
    // addDays(datenow.day, datenow.month, datenow.year);
    // addDays(datenow2.day, datenow2.month, datenow2.year);
}