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
    double jumlah;
    string tanggal;
    string status; // "BELUM LUNAS", "LUNAS"
    double totalTagihan;

public:
    Pembayaran() {}
    Pembayaran(string idPembayaran, string idSewa, string tanggal, double totalTagihan)
        : idPembayaran(idPembayaran), idSewa(idSewa), jumlah(0),
          tanggal(tanggal), status("BELUM LUNAS"), totalTagihan(totalTagihan) {}

    string getIdPembayaran() const { return idPembayaran; }
    string getIdSewa() const { return idSewa; }
    string getStatus() const { return status; }
    double getJumlah() const { return jumlah; }

    bool prosesPembayaran(double jumlahBayar) {
        jumlah += jumlahBayar;
        if (jumlah >= totalTagihan) {
            status = "LUNAS";
            cout << "Pembayaran berhasil, status: LUNAS" << endl;
            return true;
        } else {
            cout << "Pembayaran diterima, namun belum lunas. Sisa tagihan: Rp"
                 << (totalTagihan - jumlah) << endl;
            return false;
        }
    }

    void tampilkanPembayaran() {
        cout << "ID Pembayaran  : " << idPembayaran << endl;
        cout << "ID Sewa        : " << idSewa << endl;
        cout << "Total Tagihan  : Rp" << totalTagihan << endl;
        cout << "Jumlah Dibayar : Rp" << jumlah << endl;
        cout << "Tanggal        : " << tanggal << endl;
        cout << "Status         : " << status << endl;
    }
};