#pragma once
#include <iostream>
#include <string>
using namespace std;

// ==========================================
// CLASS Booking
// ==========================================
class Booking {
private:
    string idBooking;
    string namaPemesan;
    string nomorKamar;
    string tanggalBooking;
    string tanggalMasuk;
    int durasi;
    double uangMuka;
    string status; // "MENUNGGU", "DIKONFIRMASI", "DIBATALKAN"

public:
    Booking() {}
    Booking(string idBooking, string namaPemesan, string nomorKamar,
            string tanggalBooking, string tanggalMasuk, int durasi, double uangMuka)
        : idBooking(idBooking), namaPemesan(namaPemesan), nomorKamar(nomorKamar),
          tanggalBooking(tanggalBooking), tanggalMasuk(tanggalMasuk),
          durasi(durasi), uangMuka(uangMuka), status("MENUNGGU") {}

    string getIdBooking() const { return idBooking; }
    string getNamaPemesan() const { return namaPemesan; }
    string getNomorKamar() const { return nomorKamar; }
    string getStatus() const { return status; }

    void buatBooking() {
        status = "MENUNGGU";
        cout << "Booking " << idBooking << " berhasil dibuat, menunggu konfirmasi." << endl;
    }

    void konfirmasiBooking() {
        status = "DIKONFIRMASI";
        cout << "Booking " << idBooking << " telah dikonfirmasi." << endl;
    }

    void batalkanBooking() {
        status = "DIBATALKAN";
        cout << "Booking " << idBooking << " telah dibatalkan." << endl;
    }

    void tampilkanBooking() {
        cout << "ID Booking      : " << idBooking << endl;
        cout << "Nama Pemesan    : " << namaPemesan << endl;
        cout << "Nomor Kamar     : " << nomorKamar << endl;
        cout << "Tanggal Booking : " << tanggalBooking << endl;
        cout << "Tanggal Masuk   : " << tanggalMasuk << endl;
        cout << "Durasi          : " << durasi << " bulan" << endl;
        cout << "Uang Muka       : Rp" << uangMuka << endl;
        cout << "Status          : " << status << endl;
    }
};