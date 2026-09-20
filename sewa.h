#pragma once
#include <iostream>
#include <string>
using namespace std;

// ==========================================
// CLASS Sewa (Base Class - Abstract)
// ==========================================
class Sewa {
protected:
    string idSewa;
    string namaPenyewa;
    string nomorKamar;
    string tanggalMulai;
    int durasi;
    double totalHarga;
    string status; // "AKTIF", "SELESAI", "DIBATALKAN"

public:
    Sewa() {}
    Sewa(string idSewa, string namaPenyewa, string nomorKamar, string tanggalMulai, int durasi)
        : idSewa(idSewa), namaPenyewa(namaPenyewa), nomorKamar(nomorKamar),
          tanggalMulai(tanggalMulai), durasi(durasi), totalHarga(0), status("AKTIF") {}

    virtual ~Sewa() {}

    string getIdSewa() const { return idSewa; }
    string getNamaPenyewa() const { return namaPenyewa; }
    string getNomorKamar() const { return nomorKamar; }
    string getStatus() const { return status; }
    double getTotalHarga() const { return totalHarga; }
    int getDurasi() const { return durasi; }

    void setStatus(string s) { status = s; }

    virtual double hitungHarga() = 0; // method abstrak, wajib dioverride turunannya

    virtual void tampilkanSewa() {
        cout << "ID Sewa       : " << idSewa << endl;
        cout << "Penyewa       : " << namaPenyewa << endl;
        cout << "Nomor Kamar   : " << nomorKamar << endl;
        cout << "Tanggal Mulai : " << tanggalMulai << endl;
        cout << "Durasi        : " << durasi << endl;
        cout << "Total Harga   : Rp" << totalHarga << endl;
        cout << "Status        : " << status << endl;
    }
};

// ==========================================
// CLASS SewaBulanan EXTENDS Sewa
// ==========================================
class SewaBulanan : public Sewa {
private:
    double hargaPerBulan;

public:
    SewaBulanan() {}
    SewaBulanan(string idSewa, string namaPenyewa, string nomorKamar,
                string tanggalMulai, int durasi, double hargaPerBulan)
        : Sewa(idSewa, namaPenyewa, nomorKamar, tanggalMulai, durasi),
          hargaPerBulan(hargaPerBulan) {
        totalHarga = hitungHarga();
    }

    double hitungHarga() override {
        return hargaPerBulan * durasi;
    }
};

// ==========================================
// CLASS SewaTahunan EXTENDS Sewa
// ==========================================
class SewaTahunan : public Sewa {
private:
    double hargaPerTahun;

public:
    SewaTahunan() {}
    SewaTahunan(string idSewa, string namaPenyewa, string nomorKamar,
                string tanggalMulai, int durasi, double hargaPerTahun)
        : Sewa(idSewa, namaPenyewa, nomorKamar, tanggalMulai, durasi),
          hargaPerTahun(hargaPerTahun) {
        totalHarga = hitungHarga();
    }

    double hitungHarga() override {
        return hargaPerTahun * durasi;
    }
};