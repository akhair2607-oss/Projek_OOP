#pragma once
#include <iostream>
#include <string>

#include "User.h"

using namespace std;

// ==========================================
// CLASS Penghuni
// ==========================================

class Penghuni : public User {

private:
    string nim;
    string nomorKamar;
    string statusSewa;
    // "AKTIF" / "TIDAK AKTIF"

public:

    // Constructor default
    Penghuni() {
        statusSewa = "TIDAK AKTIF";
    }

    // Constructor
    Penghuni(
        string nama,
        string noHP,
        string nim,
        string nomorKamar
    ) : User(nama, noHP) {

        this->nim = nim;
        this->nomorKamar = nomorKamar;
        this->statusSewa = "AKTIF";
    }

    // ==============================
    // GETTER
    // ==============================

    string getNim() const {
        return nim;
    }

    string getNomorKamar() const {
        return nomorKamar;
    }

    string getStatusSewa() const {
        return statusSewa;
    }

    // ==============================
    // SETTER
    // ==============================

    void setNomorKamar(string nomorKamar) {
        this->nomorKamar = nomorKamar;
    }

    void setStatusSewa(string status) {
        this->statusSewa = status;
    }

    // ==============================
    // AKTIFKAN SEWA
    // ==============================

    void mulaiSewa() {

        statusSewa = "AKTIF";

        cout << "Status penghuni sekarang: AKTIF" << endl;
    }

    // ==============================
    // BERHENTI SEWA
    // ==============================

    void berhentiSewa() {

        statusSewa = "TIDAK AKTIF";

        cout << "Status sewa " << nama
             << " telah diubah menjadi TIDAK AKTIF."
             << endl;
    }

    // ==============================
    // TAMPILKAN DATA
    // ==============================

    void tampilkanData() override {

        cout << "\n------------------------------\n";
        cout << "Nama         : " << nama << endl;
        cout << "NIM          : " << nim << endl;
        cout << "No HP        : " << noHP << endl;
        cout << "Nomor Kamar  : " << nomorKamar << endl;
        cout << "Status Sewa  : " << statusSewa << endl;
        cout << "------------------------------\n";
    }
};