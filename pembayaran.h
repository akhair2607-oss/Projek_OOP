#pragma once
#include <iostream>
#include <string>

using namespace std;

// ==========================================
// CLASS Pembayaran
// ==========================================

class Pembayaran {

private:
    string idPembayaran;
    string idSewa;
    string tanggal;
    string keterangan;

    double totalTagihan;
    double jumlahDibayar;
    string status; // "BELUM LUNAS", "LUNAS"

public:

    // Constructor default
    Pembayaran() {
        totalTagihan = 0;
        jumlahDibayar = 0;
        status = "BELUM LUNAS";
    }

    // Constructor
    Pembayaran(
        string idPembayaran,
        string idSewa,
        string tanggal,
        string keterangan,
        double totalTagihan
    ) {
        this->idPembayaran = idPembayaran;
        this->idSewa = idSewa;
        this->tanggal = tanggal;
        this->keterangan = keterangan;
        this->totalTagihan = totalTagihan;
        this->jumlahDibayar = 0;
        this->status = "BELUM LUNAS";
    }

    // ==============================
    // GETTER
    // ==============================

    string getIdPembayaran() const {
        return idPembayaran;
    }

    string getIdSewa() const {
        return idSewa;
    }

    string getTanggal() const {
        return tanggal;
    }

    string getKeterangan() const {
        return keterangan;
    }

    double getTotalTagihan() const {
        return totalTagihan;
    }

    double getJumlahDibayar() const {
        return jumlahDibayar;
    }

    double getSisaTagihan() const {
        return totalTagihan - jumlahDibayar;
    }

    string getStatus() const {
        return status;
    }

    // ==============================
    // PROSES PEMBAYARAN
    // ==============================

    bool prosesPembayaran(double jumlahBayar) {

        if (jumlahBayar <= 0) {
            cout << "Jumlah pembayaran tidak valid.\n";
            return false;
        }

        if (jumlahBayar > getSisaTagihan()) {
            cout << "Pembayaran melebihi sisa tagihan.\n";
            return false;
        }

        jumlahDibayar += jumlahBayar;

        if (jumlahDibayar >= totalTagihan) {

            jumlahDibayar = totalTagihan;
            status = "LUNAS";

            cout << "Pembayaran berhasil.\n";
            cout << "Status: LUNAS\n";

            return true;

        } else {

            status = "BELUM LUNAS";

            cout << "Pembayaran berhasil.\n";
            cout << "Sisa tagihan: Rp"
                 << getSisaTagihan() << endl;

            return false;
        }
    }

    // ==============================
    // TAMPILKAN PEMBAYARAN
    // ==============================

    void tampilkanPembayaran() const {

        cout << "\n------------------------------\n";
        cout << "ID Pembayaran  : " << idPembayaran << endl;
        cout << "ID Sewa        : " << idSewa << endl;
        cout << "Keterangan     : " << keterangan << endl;
        cout << "Total Tagihan  : Rp" << totalTagihan << endl;
        cout << "Jumlah Dibayar : Rp" << jumlahDibayar << endl;
        cout << "Sisa Tagihan   : Rp" << getSisaTagihan() << endl;
        cout << "Tanggal        : " << tanggal << endl;
        cout << "Status         : " << status << endl;
        cout << "------------------------------\n";
    }
};