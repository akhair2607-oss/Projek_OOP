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
// CLASS Pemilik
// ==========================================

class Pemilik : public User {

public:

    // Constructor default
    Pemilik() {}

    // Constructor
    Pemilik(string nama, string noHP)
        : User(nama, noHP) {}

    // ==========================================
    // TAMBAH KAMAR
    // ==========================================

    void tambahKamar(vector<Kamar>& daftarKamar) {

        string nomor;
        double bulanan, tahunan;

        cout << "\n===== TAMBAH KAMAR =====\n";

        cout << "Nomor Kamar   : ";
        cin >> nomor;

        cout << "Harga / Bulan : ";
        cin >> bulanan;

        cout << "Harga / Tahun : ";
        cin >> tahunan;

        daftarKamar.push_back(
            Kamar(nomor, bulanan, tahunan)
        );

        cout << "\nKamar " << nomor
             << " berhasil ditambahkan.\n";
    }

    // ==========================================
    // TAMPILKAN SEMUA KAMAR
    // ==========================================

    void tampilkanSemuaKamar(
        vector<Kamar>& daftarKamar
    ) {

        cout << "\n===== DATA KAMAR =====\n";

        if (daftarKamar.empty()) {

            cout << "Belum ada data kamar.\n";
            return;
        }

        for (auto& k : daftarKamar) {

            k.tampilkanKamar();

            cout << "----------------------\n";
        }
    }

    // ==========================================
    // TAMPILKAN DATA PENGHUNI
    // ==========================================

    void lihatPenghuni(
        vector<Penghuni>& daftarPenghuni
    ) {

        cout << "\n===== DATA PENGHUNI =====\n";

        if (daftarPenghuni.empty()) {

            cout << "Belum ada penghuni.\n";
            return;
        }

        for (auto& p : daftarPenghuni) {

            p.tampilkanData();
        }
    }

    // ==========================================
    // TAMPILKAN DATA BOOKING
    // ==========================================

    void lihatBooking(
        vector<Booking>& daftarBooking
    ) {

        cout << "\n===== DATA BOOKING =====\n";

        if (daftarBooking.empty()) {

            cout << "Belum ada data booking.\n";
            return;
        }

        for (auto& b : daftarBooking) {

            b.tampilkanBooking();

            cout << "----------------------\n";
        }
    }

    // ==========================================
    // TAMPILKAN DATA PEMBAYARAN
    // ==========================================

    void lihatPembayaran(
        vector<Pembayaran>& daftarPembayaran
    ) {

        cout << "\n===== DATA PEMBAYARAN =====\n";

        if (daftarPembayaran.empty()) {

            cout << "Belum ada data pembayaran.\n";
            return;
        }

        for (auto& p : daftarPembayaran) {

            p.tampilkanPembayaran();
        }
    }

    // ==========================================
    // LAPORAN SMARTKOS
    // ==========================================

    void lihatLaporan(
        vector<Kamar>& daftarKamar,
        vector<Penghuni>& daftarPenghuni,
        vector<Pembayaran>& daftarPembayaran,
        vector<unique_ptr<Sewa>>& daftarSewa
    ) {

        int terisi = 0;
        int tersedia = 0;
        int dibooking = 0;

        int penghuniAktif = 0;
        int sewaAktif = 0;

        double totalPembayaran = 0;

        // ------------------------------
        // Hitung status kamar
        // ------------------------------

        for (auto& k : daftarKamar) {

            if (k.getStatus() == "TERISI") {

                terisi++;

            } else if (k.getStatus() == "TERSEDIA") {

                tersedia++;

            } else if (k.getStatus() == "DIBOOKING") {

                dibooking++;
            }
        }

        // ------------------------------
        // Hitung penghuni aktif
        // ------------------------------

        for (auto& p : daftarPenghuni) {

            if (p.getStatusSewa() == "AKTIF") {

                penghuniAktif++;
            }
        }

        // ------------------------------
        // Hitung pembayaran
        // ------------------------------

        for (auto& p : daftarPembayaran) {

            totalPembayaran += p.getJumlahDibayar();
        }

        // ------------------------------
        // Hitung sewa aktif
        // ------------------------------

        for (auto& s : daftarSewa) {

            if (s->getStatus() == "AKTIF") {

                sewaAktif++;
            }
        }

        // ------------------------------
        // Tampilkan laporan
        // ------------------------------

        cout << "\n";
        cout << "====================================\n";
        cout << "        LAPORAN SMARTKOS\n";
        cout << "====================================\n";

        cout << "Jumlah Kamar           : "
             << daftarKamar.size() << endl;

        cout << "Kamar Terisi           : "
             << terisi << endl;

        cout << "Kamar Tersedia         : "
             << tersedia << endl;

        cout << "Kamar Dibooking        : "
             << dibooking << endl;

        cout << "Jumlah Penghuni Aktif  : "
             << penghuniAktif << endl;

        cout << "Total Pembayaran       : Rp"
             << totalPembayaran << endl;

        cout << "Jumlah Penyewaan Aktif : "
             << sewaAktif << endl;

        cout << "====================================\n";
    }
};