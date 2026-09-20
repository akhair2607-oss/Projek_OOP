#pragma once
#include <iostream>
#include <string>
using namespace std;

// ==========================================
// CLASS Kamar
// ==========================================
class Kamar {
private:
    string nomorKamar;
    double hargaBulanan;
    double hargaTahunan;
    string status; // "TERSEDIA", "DIBOOKING", "TERISI"

public:
    Kamar() {}
    Kamar(string nomorKamar, double hargaBulanan, double hargaTahunan)
        : nomorKamar(nomorKamar), hargaBulanan(hargaBulanan),
          hargaTahunan(hargaTahunan), status("TERSEDIA") {}

    string getNomorKamar() const { return nomorKamar; }
    double getHargaBulanan() const { return hargaBulanan; }
    double getHargaTahunan() const { return hargaTahunan; }
    string getStatus() const { return status; }

    void tampilkanKamar() {
        cout << "No. Kamar    : " << nomorKamar << endl;
        cout << "Harga/Bulan  : Rp" << hargaBulanan << endl;
        cout << "Harga/Tahun  : Rp" << hargaTahunan << endl;
        cout << "Status       : " << status << endl;
    }

    void ubahStatus(string statusBaru) {
        status = statusBaru;
    }
};