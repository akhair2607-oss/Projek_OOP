#pragma once
#include <iostream>
#include <string>

#include "Penghuni.h"

using namespace std;

// ==========================================
// CLASS SEWA
// ==========================================

class Sewa {

protected:
    string idSewa;
    Penghuni* penghuni;
    string nomorKamar;
    string tanggalMulai;
    int durasi;
    double harga;
    string status;

public:

    // Constructor default
    Sewa() {
        penghuni = nullptr;
        durasi = 0;
        harga = 0;
        status = "BELUM AKTIF";
    }

    // Constructor
    Sewa(
        string idSewa,
        Penghuni* penghuni,
        string nomorKamar,
        string tanggalMulai,
        int durasi,
        double harga
    ) {
        this->idSewa = idSewa;
        this->penghuni = penghuni;
        this->nomorKamar = nomorKamar;
        this->tanggalMulai = tanggalMulai;
        this->durasi = durasi;
        this->harga = harga;
        this->status = "BELUM AKTIF";
    }

    // Destructor virtual
    virtual ~Sewa() {}

    // ==============================
    // GETTER
    // ==============================

    string getIdSewa() const {
        return idSewa;
    }

    string getNomorKamar() const {
        return nomorKamar;
    }

    string getTanggalMulai() const {
        return tanggalMulai;
    }

    int getDurasi() const {
        return durasi;
    }

    double getHarga() const {
        return harga;
    }

    string getStatus() const {
        return status;
    }

    Penghuni* getPenghuni() const {
        return penghuni;
    }

    // ==============================
    // SETTER
    // ==============================

    void setStatus(string status) {
        this->status = status;
    }

    // ==============================
    // POLYMORPHISM
    // ==============================

    virtual double hitungHarga() const = 0;

    virtual void tampilkanData() const {

        cout << "\n------------------------------\n";
        cout << "ID Sewa       : " << idSewa << endl;

        if (penghuni != nullptr) {
            cout << "Nama Penghuni : "
                 << penghuni->getNama() << endl;

            cout << "NIM           : "
                 << penghuni->getNim() << endl;
        }

        cout << "Nomor Kamar   : " << nomorKamar << endl;
        cout << "Tanggal Mulai : " << tanggalMulai << endl;
        cout << "Durasi        : " << durasi << endl;
        cout << "Harga         : Rp" << harga << endl;
        cout << "Status        : " << status << endl;
        cout << "------------------------------\n";
    }
};


// ==========================================
// CLASS SewaBulanan
// ==========================================

class SewaBulanan : public Sewa {

public:

    SewaBulanan(
        string idSewa,
        Penghuni* penghuni,
        string nomorKamar,
        string tanggalMulai,
        int durasi,
        double hargaBulanan
    ) : Sewa(
        idSewa,
        penghuni,
        nomorKamar,
        tanggalMulai,
        durasi,
        hargaBulanan
    ) {}

    // Polymorphism
    double hitungHarga() const override {
        return harga * durasi;
    }

    void tampilkanData() const override {

        cout << "\n===== SEWA BULANAN =====\n";

        Sewa::tampilkanData();

        cout << "Jenis Sewa    : Bulanan" << endl;
        cout << "Harga / Bulan : Rp" << harga << endl;
        cout << "Total Kontrak : Rp" << hitungHarga() << endl;
    }
};


// ==========================================
// CLASS SewaTahunan
// ==========================================

class SewaTahunan : public Sewa {

public:

    SewaTahunan(
        string idSewa,
        Penghuni* penghuni,
        string nomorKamar,
        string tanggalMulai,
        int durasi,
        double hargaTahunan
    ) : Sewa(
        idSewa,
        penghuni,
        nomorKamar,
        tanggalMulai,
        durasi,
        hargaTahunan
    ) {}

    // Polymorphism
    double hitungHarga() const override {
        return harga * durasi;
    }

    void tampilkanData() const override {

        cout << "\n===== SEWA TAHUNAN =====\n";

        Sewa::tampilkanData();

        cout << "Jenis Sewa    : Tahunan" << endl;
        cout << "Harga / Tahun : Rp" << harga << endl;
        cout << "Total Kontrak : Rp" << hitungHarga() << endl;
    }
};