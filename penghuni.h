#pragma once
#include "User.h"

// ==========================================
// CLASS Penghuni EXTENDS User
// ==========================================
class Penghuni : public User {
private:
    string nim;
    string nomorKamar;
    string statusSewa; // "AKTIF" / "TIDAK AKTIF"

public:
    Penghuni() {}
    Penghuni(string nama, string noHP, string nim, string nomorKamar)
        : User(nama, noHP), nim(nim), nomorKamar(nomorKamar), statusSewa("AKTIF") {}

    string getNim() const { return nim; }
    string getNomorKamar() const { return nomorKamar; }
    string getStatusSewa() const { return statusSewa; }
    void setStatusSewa(string status) { statusSewa = status; }

    void tampilkanData() override {
        cout << "Nama         : " << nama << endl;
        cout << "NIM          : " << nim << endl;
        cout << "No HP        : " << noHP << endl;
        cout << "Nomor Kamar  : " << nomorKamar << endl;
        cout << "Status Sewa  : " << statusSewa << endl;
    }

    void berhentiSewa() {
        statusSewa = "TIDAK AKTIF";
        cout << "Status sewa " << nama << " telah diubah menjadi TIDAK AKTIF." << endl;
    }
};