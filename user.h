#pragma once
#include <iostream>
#include <string>
using namespace std;

// ==========================================
// CLASS User (Base Class)
// ==========================================
class User {
protected:
    string nama;
    string noHP;

public:
    User() {}
    User(string nama, string noHP) : nama(nama), noHP(noHP) {}
    virtual ~User() {}

    string getNama() const { return nama; }
    string getNoHP() const { return noHP; }

    virtual void tampilkanData() {
        cout << "Nama  : " << nama << endl;
        cout << "No HP : " << noHP << endl;
    }
};