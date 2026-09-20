#pragma once
#include <iostream>
#include <string>

using namespace std;

class Booking {
private:
    string idBooking;
    string namaPemesan;
    string nim;
    string noHP;
    string nomorKamar;
    string tanggalBooking;
    string tanggalMasuk;

    int durasi;
    double uangMuka;
    string status;

public:
    // Constructor default
    Booking() {
        durasi = 0;
        uangMuka = 0;
        status = "DIBUAT";
    }

    // Constructor lengkap
    Booking(
        string idBooking,
        string namaPemesan,
        string nim,
        string noHP,
        string nomorKamar,
        string tanggalBooking,
        string tanggalMasuk,
        int durasi,
        double uangMuka
    ) {
        this->idBooking = idBooking;
        this->namaPemesan = namaPemesan;
        this->nim = nim;
        this->noHP = noHP;
        this->nomorKamar = nomorKamar;
        this->tanggalBooking = tanggalBooking;
        this->tanggalMasuk = tanggalMasuk;
        this->durasi = durasi;
        this->uangMuka = uangMuka;
        this->status = "DIBOOKING";
    }

    // Getter
    string getIdBooking() const {
        return idBooking;
    }

    string getNamaPemesan() const {
        return namaPemesan;
    }

    string getNim() const {
        return nim;
    }

    string getNoHP() const {
        return noHP;
    }

    string getNomorKamar() const {
        return nomorKamar;
    }

    string getTanggalBooking() const {
        return tanggalBooking;
    }

    string getTanggalMasuk() const {
        return tanggalMasuk;
    }

    int getDurasi() const {
        return durasi;
    }

    double getUangMuka() const {
        return uangMuka;
    }

    string getStatus() const {
        return status;
    }

    // Setter status
    void setStatus(string status) {
        this->status = status;
    }

    // Method membuat booking
    void buatBooking() {
        cout << "\nBooking berhasil dibuat.\n";
        cout << "ID Booking    : " << idBooking << endl;
        cout << "Nama Pemesan  : " << namaPemesan << endl;
        cout << "NIM           : " << nim << endl;
        cout << "No HP         : " << noHP << endl;
        cout << "Nomor Kamar   : " << nomorKamar << endl;
        cout << "Tanggal Masuk : " << tanggalMasuk << endl;
        cout << "Durasi        : " << durasi << " bulan" << endl;
        cout << "Uang Muka     : Rp" << uangMuka << endl;
        cout << "Status        : " << status << endl;
    }

    // Method menampilkan data booking
    void tampilkanBooking() const {
        cout << "ID Booking    : " << idBooking << endl;
        cout << "Nama Pemesan  : " << namaPemesan << endl;
        cout << "NIM           : " << nim << endl;
        cout << "No HP         : " << noHP << endl;
        cout << "Nomor Kamar   : " << nomorKamar << endl;
        cout << "Tanggal Booking : " << tanggalBooking << endl;
        cout << "Tanggal Masuk : " << tanggalMasuk << endl;
        cout << "Durasi        : " << durasi << " bulan" << endl;
        cout << "Uang Muka     : Rp" << uangMuka << endl;
        cout << "Status        : " << status << endl;
    }
};