#include <iostream>
#include <vector>
#include <memory>
#include <iomanip>
#include "user.h"
#include "penghuni.h"
#include "kamar.h"
#include "booking.h"
#include "sewa.h"
#include "pembayaran.h"
#include "pembatalanSewa.h"
#include "pemilik.h"

using namespace std;

// Generator ID sederhana, contoh: BK001, SW001, PB001
string buatID(string prefix, int nomor) {
    string angka = to_string(nomor);
    while (angka.length() < 3) angka = "0" + angka;
    return prefix + angka;
}

Kamar* cariKamar(vector<Kamar>& daftarKamar, string nomor) {
    for (auto& k : daftarKamar) {
        if (k.getNomorKamar() == nomor) return &k;
    }
    return nullptr;
}

Penghuni* cariPenghuni(vector<Penghuni>& daftarPenghuni, string nim) {
    for (auto& p : daftarPenghuni) {
        if (p.getNim() == nim) return &p;
    }
    return nullptr;
}

int main() {
    // Format tampilan angka Rupiah: tanpa notasi ilmiah, tanpa desimal
    cout << fixed << setprecision(0);

    Pemilik pemilik("Admin SmartKos", "081234567890");

    vector<Kamar> daftarKamar;
    vector<Penghuni> daftarPenghuni;
    vector<Booking> daftarBooking;
    vector<unique_ptr<Sewa>> daftarSewa;
    vector<Pembayaran> daftarPembayaran;

    int counterBooking = 1, counterSewa = 1, counterPembayaran = 1;
    int pilihan;

    do {
        cout << "\n===================================\n";
        cout << "           MENU SMARTKOS\n";
        cout << "===================================\n";
        cout << "1. Data Kamar\n";
        cout << "2. Data Penghuni\n";
        cout << "3. Booking Kamar\n";
        cout << "4. Penyewaan Kamar\n";
        cout << "5. Pembayaran\n";
        cout << "6. Pembatalan Sewa\n";
        cout << "7. Laporan\n";
        cout << "0. Keluar\n";
        cout << "===================================\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Input tidak valid.\n";
            continue;
        }

        switch (pilihan) {
            case 1: {
                pemilik.tampilkanSemuaKamar(daftarKamar);
                cout << "\nTambah kamar baru? (1=Ya / 0=Tidak): ";
                int tambah; cin >> tambah;
                if (tambah == 1) pemilik.tambahKamar(daftarKamar);
                break;
            }

            case 2: {
                pemilik.tambahPenghuni(daftarPenghuni);
                break;
            }

            case 3: {
                string namaPemesan, nomorKamar, tglBooking, tglMasuk;
                int durasi; double uangMuka;

                cout << "\n--- Booking Kamar ---\n";
                cout << "Nama Pemesan   : "; cin.ignore(); getline(cin, namaPemesan);
                cout << "Nomor Kamar    : "; cin >> nomorKamar;

                Kamar* kamar = cariKamar(daftarKamar, nomorKamar);
                if (kamar == nullptr) {
                    cout << "Kamar tidak ditemukan.\n";
                    break;
                }

                // CEK status kamar
                if (kamar->getStatus() == "TERSEDIA") {
                    cout << "Tanggal Booking      : "; cin >> tglBooking;
                    cout << "Tanggal Masuk        : "; cin >> tglMasuk;
                    cout << "Durasi Sewa (bulan)  : "; cin >> durasi;
                    cout << "Uang Muka            : "; cin >> uangMuka;

                    string id = buatID("BK", counterBooking++);
                    Booking b(id, namaPemesan, nomorKamar, tglBooking, tglMasuk, durasi, uangMuka);
                    b.buatBooking();
                    daftarBooking.push_back(b);

                    kamar->ubahStatus("DIBOOKING");
                    cout << "Booking berhasil\n";
                } else {
                    cout << "Kamar tidak tersedia\n";
                }
                break;
            }

            case 4: {
                string nim, nomorKamar, tglMulai;

                cout << "\n--- Penyewaan Kamar ---\n";
                cout << "NIM Penghuni : "; cin >> nim;

                Penghuni* penghuni = cariPenghuni(daftarPenghuni, nim);
                if (penghuni == nullptr) {
                    cout << "Penghuni tidak ditemukan.\n";
                    break;
                }

                nomorKamar = penghuni->getNomorKamar();
                Kamar* kamar = cariKamar(daftarKamar, nomorKamar);
                if (kamar == nullptr) {
                    cout << "Kamar tidak ditemukan.\n";
                    break;
                }

                cout << "Tanggal Mulai Sewa           : "; cin >> tglMulai;
                cout << "Jenis Sewa (1=Bulanan/2=Tahunan) : ";
                int jenisSewa; cin >> jenisSewa;

                string idSewa = buatID("SW", counterSewa++);

                if (jenisSewa == 1) {
                    int jumlahBulan;
                    cout << "Jumlah Bulan : "; cin >> jumlahBulan;

                    auto sewa = make_unique<SewaBulanan>(idSewa, penghuni->getNama(), nomorKamar,
                                                        tglMulai, jumlahBulan, kamar->getHargaBulanan());
                    cout << "Total Harga  : Rp" << sewa->getTotalHarga() << endl;
                    daftarSewa.push_back(move(sewa));

                } else if (jenisSewa == 2) {
                    int jumlahTahun;
                    cout << "Jumlah Tahun : "; cin >> jumlahTahun;

                    auto sewa = make_unique<SewaTahunan>(idSewa, penghuni->getNama(), nomorKamar,
                                                        tglMulai, jumlahTahun, kamar->getHargaTahunan());
                    cout << "Total Harga  : Rp" << sewa->getTotalHarga() << endl;
                    daftarSewa.push_back(move(sewa));

                } else {
                    cout << "Jenis sewa tidak valid.\n";
                    break;
                }

                kamar->ubahStatus("TERISI");

                string idBayar = buatID("PB", counterPembayaran++);
                Pembayaran pembayaran(idBayar, idSewa, tglMulai, daftarSewa.back()->getTotalHarga());
                daftarPembayaran.push_back(pembayaran);

                cout << "Data penyewaan berhasil disimpan. (ID Pembayaran: " << idBayar << ")\n";
                break;
            }

            case 5: {
                cout << "\n--- Pembayaran ---\n";
                if (daftarPembayaran.empty()) {
                    cout << "Belum ada data pembayaran.\n";
                    break;
                }

                pemilik.lihatPembayaran(daftarPembayaran);

                string idBayar;
                cout << "Masukkan ID Pembayaran : "; cin >> idBayar;

                bool ditemukan = false;
                for (auto& p : daftarPembayaran) {
                    if (p.getIdPembayaran() == idBayar) {
                        ditemukan = true;
                        double jumlahBayar;
                        cout << "Jumlah Pembayaran : Rp"; cin >> jumlahBayar;

                        bool lunas = p.prosesPembayaran(jumlahBayar);
                        if (lunas) {
                            for (auto& s : daftarSewa) {
                                if (s->getIdSewa() == p.getIdSewa()) {
                                    s->setStatus("AKTIF");
                                }
                            }
                        }
                        break;
                    }
                }
                if (!ditemukan) cout << "ID Pembayaran tidak ditemukan.\n";
                break;
            }

            case 6: {
                string nim;
                cout << "\n--- Pembatalan Sewa ---\n";
                cout << "NIM Penghuni : "; cin >> nim;

                Penghuni* penghuni = cariPenghuni(daftarPenghuni, nim);
                if (penghuni == nullptr) {
                    cout << "Penghuni tidak ditemukan.\n";
                    break;
                }

                // Periksa status penyewaan
                Sewa* sewaAktif = nullptr;
                for (auto& s : daftarSewa) {
                    if (s->getNamaPenyewa() == penghuni->getNama() && s->getStatus() == "AKTIF") {
                        sewaAktif = s.get();
                        break;
                    }
                }

                if (sewaAktif != nullptr) {
                    int lamaPenggunaan;
                    cout << "Lama Penggunaan (satuan sesuai jenis sewa) : ";
                    cin >> lamaPenggunaan;

                    PembatalanSewa pembatalan;
                    pembatalan.hitungRefund(sewaAktif->getTotalHarga(), sewaAktif->getDurasi(), lamaPenggunaan);

                    sewaAktif->setStatus("DIBATALKAN");
                    penghuni->berhentiSewa();

                    Kamar* kamar = cariKamar(daftarKamar, sewaAktif->getNomorKamar());
                    if (kamar != nullptr) kamar->ubahStatus("TERSEDIA");

                    cout << fixed << setprecision(2);
                    cout << "\nBiaya Penggunaan : Rp" << pembatalan.getBiayaTerpakai() << endl;
                    cout << "Penalti          : Rp" << pembatalan.getPenalti() << endl;
                    cout << "Jumlah Refund    : Rp" << pembatalan.getRefund() << endl;
                } else {
                    cout << "Penyewaan tidak dapat dibatalkan\n";
                }
                break;
            }

            case 7: {
                pemilik.lihatLaporan(daftarKamar, daftarPenghuni, daftarPembayaran, daftarSewa);
                break;
            }

            case 0: {
                cout << "\nProgram selesai\n";
                break;
            }

            default:
                cout << "Pilihan tidak valid\n";
        }

    } while (pilihan != 0);

    return 0;
}