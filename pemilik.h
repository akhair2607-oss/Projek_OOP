#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "User.h"
#include "Kamar.h"
#include "Penghuni.h"
#include "Booking.h"
#include "Pembayaran.h"
#include "Sewa.h"
using namespace std;

// ==========================================
// CLASS Pemilik EXTENDS User
// ==========================================
class Pemilik : public User {
public:
    Pemilik() {}
    Pemilik(string nama, string noHP) : User(nama, noHP) {}

    void tambahKamar(vector<Kamar>& daftarKamar) {
        string nomor;
        double bulanan, tahunan;

        cout << "\n--- Tambah Kamar ---\n";
        cout << "Nomor Kamar    : "; cin >> nomor;
        cout << "Harga / Bulan  : "; cin >> bulanan;
        cout << "Harga / Tahun  : "; cin >> tahunan;

        daftarKamar.push_back(Kamar(nomor, bulanan, tahunan));
        cout << "Kamar " << nomor << " berhasil ditambahkan.\n";
    }

    void tampilkanSemuaKamar(vector<Kamar>& daftarKamar) {
        cout << "\n--- Data Kamar ---\n";
        if (daftarKamar.empty()) {
            cout << "Belum ada data kamar.\n";
            return;
        }
        for (auto& k : daftarKamar) {
            k.tampilkanKamar();
            cout << "----------------------\n";
        }
    }

    void tambahPenghuni(vector<Penghuni>& daftarPenghuni) {
    string nama, noHP, nim, nomorKamar;

        cout << "\n--- Tambah Penghuni ---\n";
        cout << "Nama        : "; cin.ignore(); getline(cin, nama);
        cout << "NIM         : "; cin >> nim;
        cout << "No HP       : "; cin >> noHP;
        cout << "Nomor Kamar : "; cin >> nomorKamar;

        daftarPenghuni.push_back(Penghuni(nama, noHP, nim, nomorKamar));
        cout << "Data penghuni " << nama << " berhasil disimpan.\n";
    }

    void lihatBooking(vector<Booking>& daftarBooking) {
        cout << "\n--- Data Booking ---\n";
        if (daftarBooking.empty()) {
            cout << "Belum ada data booking.\n";
            return;
        }
        for (auto& b : daftarBooking) {
            b.tampilkanBooking();
            cout << "----------------------\n";
        }
    }

    void lihatPembayaran(vector<Pembayaran>& daftarPembayaran) {
        cout << "\n--- Data Pembayaran ---\n";
        if (daftarPembayaran.empty()) {
            cout << "Belum ada data pembayaran.\n";
            return;
        }
        for (auto& p : daftarPembayaran) {
            p.tampilkanPembayaran();
            cout << "----------------------\n";
        }
    }

    void lihatLaporan(vector<Kamar>& daftarKamar, vector<Penghuni>& daftarPenghuni,
                        vector<Pembayaran>& daftarPembayaran,
                        vector<unique_ptr<Sewa>>& daftarSewa) {
        int terisi = 0, tersedia = 0, dibooking = 0;
        double totalPembayaran = 0;
        int sewaAktif = 0;
        int penghuniAktif = 0;

        for (auto& k : daftarKamar) {
            if (k.getStatus() == "TERISI") terisi++;
            else if (k.getStatus() == "TERSEDIA") tersedia++;
            else if (k.getStatus() == "DIBOOKING") dibooking++;
        }
        for (auto& p : daftarPembayaran) {
            totalPembayaran += p.getJumlah();
        }
        for (auto& s : daftarSewa) {
            if (s->getStatus() == "AKTIF") sewaAktif++;
        }
        for (auto& p : daftarPenghuni) {
    if (p.getStatusSewa() == "AKTIF") {
        penghuniAktif++;
    }
}

        cout << "\n===== LAPORAN SMARTKOS =====\n";
        cout << "Jumlah Kamar           : " << daftarKamar.size() << endl;
        cout << "Kamar Terisi           : " << terisi << endl;
        cout << "Kamar Tersedia         : " << tersedia << endl;
        cout << "Kamar Dibooking        : " << dibooking << endl;
        cout << "Jumlah Penghuni Aktif  : " << penghuniAktif << endl;
        cout << "Total Pembayaran       : Rp" << totalPembayaran << endl;
        cout << "Jumlah Penyewaan Aktif : " << sewaAktif << endl;
        cout << "=============================\n";
    }
};