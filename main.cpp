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

// ==========================================
// GENERATOR ID
// ==========================================

string buatID(string prefix, int nomor)
{

    string angka = to_string(nomor);

    while (angka.length() < 3)
    {
        angka = "0" + angka;
    }

    return prefix + angka;
}

// ==========================================
// CARI KAMAR
// ==========================================

Kamar *cariKamar(
    vector<Kamar> &daftarKamar,
    string nomor)
{

    for (auto &k : daftarKamar)
    {

        if (k.getNomorKamar() == nomor)
        {
            return &k;
        }
    }

    return nullptr;
}

// ==========================================
// CARI PENGHUNI
// ==========================================

Penghuni *cariPenghuni(
    vector<Penghuni> &daftarPenghuni,
    string nim)
{

    for (auto &p : daftarPenghuni)
    {

        if (p.getNim() == nim)
        {
            return &p;
        }
    }

    return nullptr;
}

// ==========================================
// CARI BOOKING
// ==========================================

Booking *cariBooking(
    vector<Booking> &daftarBooking,
    string idBooking)
{

    for (auto &b : daftarBooking)
    {

        if (b.getIdBooking() == idBooking)
        {
            return &b;
        }
    }

    return nullptr;
}

// ==========================================
// CARI PEMBAYARAN
// ==========================================

Pembayaran *cariPembayaran(
    vector<Pembayaran> &daftarPembayaran,
    string idPembayaran)
{

    for (auto &p : daftarPembayaran)
    {

        if (p.getIdPembayaran() == idPembayaran)
        {
            return &p;
        }
    }

    return nullptr;
}

// ==========================================
// MAIN PROGRAM
// ==========================================

int main()
{

    cout << fixed << setprecision(0);

    // ==========================================
    // DATA AWAL
    // ==========================================

    Pemilik pemilik(
        "Admin SmartKos",
        "081234567890");

    vector<Kamar> daftarKamar;
    vector<Penghuni> daftarPenghuni;
    vector<Booking> daftarBooking;
    vector<unique_ptr<Sewa>> daftarSewa;
    vector<Pembayaran> daftarPembayaran;

    int counterBooking = 1;
    int counterSewa = 1;
    int counterPembayaran = 1;

    int pilihan;

    // ==========================================
    // MENU UTAMA
    // ==========================================

    do
    {

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

        if (cin.fail())
        {

            cin.clear();
            cin.ignore(10000, '\n');

            cout << "Input tidak valid.\n";

            continue;
        }

        // ==========================================
        // MENU 1 - DATA KAMAR
        // ==========================================

        switch (pilihan)
        {

        case 1:
        {

            pemilik.tampilkanSemuaKamar(
                daftarKamar);

            cout << "\nTambah kamar baru? (1=Ya / 0=Tidak): ";

            int tambah;
            cin >> tambah;

            if (tambah == 1)
            {

                pemilik.tambahKamar(
                    daftarKamar);
            }

            break;
        }

            // ==========================================
            // MENU 2 - DATA PENGHUNI
            // ==========================================

        case 2:
        {

            pemilik.lihatPenghuni(
                daftarPenghuni);

            break;
        }

            // ==========================================
            // MENU 3 - BOOKING KAMAR
            // ==========================================

        case 3:
        {

            string namaPemesan;
            string nim;
            string noHP;
            string nomorKamar;
            string tglBooking;
            string tglMasuk;

            int durasi;
            double uangMuka;

            cout << "\n===== BOOKING KAMAR =====\n";

            cin.ignore();

            cout << "Nama Pemesan      : ";
            getline(cin, namaPemesan);

            cout << "NIM               : ";
            cin >> nim;

            cout << "No HP             : ";
            cin >> noHP;

            cout << "Nomor Kamar       : ";
            cin >> nomorKamar;

            // ------------------------------------------
            // CARI KAMAR
            // ------------------------------------------

            Kamar *kamar = cariKamar(
                daftarKamar,
                nomorKamar);

            if (kamar == nullptr)
            {

                cout << "Kamar tidak ditemukan.\n";

                break;
            }

            // ------------------------------------------
            // CEK STATUS KAMAR
            // ------------------------------------------

            if (kamar->getStatus() != "TERSEDIA")
            {

                cout << "Kamar tidak tersedia.\n";

                break;
            }

            cout << "Tanggal Booking   : ";
            cin >> tglBooking;

            cout << "Tanggal Masuk     : ";
            cin >> tglMasuk;

            int jenisSewa;

            cout << "\nJenis Sewa:\n";
            cout << "1. Bulanan\n";
            cout << "2. Tahunan\n";
            cout << "Pilihan          : ";
            cin >> jenisSewa;

            cout << "Durasi Sewa ";

            if (jenisSewa == 1)
            {
                cout << "(bulan): ";
            }
            else if (jenisSewa == 2)
            {
                cout << "(tahun): ";
            }
            else
            {
                cout << "\nJenis sewa tidak valid.\n";
                break;
            }

            cin >> durasi;

            cout << "Uang Muka / DP    : Rp";
            cin >> uangMuka;

            if (uangMuka <= 0)
            {

                cout << "Uang muka harus lebih dari 0.\n";

                break;
            }

            // ------------------------------------------
            // BUAT BOOKING
            // ------------------------------------------

            string idBooking = buatID(
                "BK",
                counterBooking++);

            Booking booking(
                idBooking,
                namaPemesan,
                nim,
                noHP,
                nomorKamar,
                tglBooking,
                tglMasuk,
                durasi,
                uangMuka);

            daftarBooking.push_back(
                booking);

            kamar->ubahStatus(
                "DIBOOKING");

            // ------------------------------------------
            // BUAT PEMBAYARAN DP
            // ------------------------------------------

            string idPembayaran = buatID(
                "PB",
                counterPembayaran++);

            Pembayaran pembayaran(
                idPembayaran,
                idBooking,
                tglBooking,
                "DP Booking",
                uangMuka);

            // Karena uang muka langsung dibayarkan
            pembayaran.prosesPembayaran(
                uangMuka);

            daftarPembayaran.push_back(
                pembayaran);

            // ------------------------------------------
            // BUAT DATA PENGHUNI OTOMATIS
            // ------------------------------------------

            Penghuni penghuni(
                namaPemesan,
                noHP,
                nim,
                nomorKamar);

            penghuni.mulaiSewa();

            daftarPenghuni.push_back(
                penghuni);

            cout << "\n===================================\n";
            cout << "BOOKING BERHASIL\n";
            cout << "===================================\n";

            cout << "ID Booking     : "
                 << idBooking << endl;

            cout << "ID Pembayaran  : "
                 << idPembayaran << endl;

            cout << "Status Kamar   : DIBOOKING\n";

            cout << "Data penghuni berhasil dibuat.\n";

            cout << "===================================\n";

            break;
        }

            // ==========================================
            // MENU 4 - PENYEWAAN KAMAR
            // ==========================================

        case 4:
        {

            string nim;
            string tglMulai;
            int jenisSewa;

            cout << "\n===== PENYEWAAN KAMAR =====\n";

            cout << "NIM Penghuni : ";
            cin >> nim;

            Penghuni *penghuni = cariPenghuni(
                daftarPenghuni,
                nim);

            if (penghuni == nullptr)
            {

                cout << "Penghuni tidak ditemukan.\n";

                break;
            }

            string nomorKamar =
                penghuni->getNomorKamar();

            Kamar *kamar = cariKamar(
                daftarKamar,
                nomorKamar);

            if (kamar == nullptr)
            {

                cout << "Kamar tidak ditemukan.\n";

                break;
            }

            cout << "Tanggal Mulai Sewa : ";
            cin >> tglMulai;

            cout << "\nJenis Sewa\n";
            cout << "1. Bulanan\n";
            cout << "2. Tahunan\n";
            cout << "Pilihan : ";
            cin >> jenisSewa;

            string idSewa = buatID(
                "SW",
                counterSewa++);

            // ------------------------------------------
            // SEWA BULANAN
            // ------------------------------------------

            if (jenisSewa == 1)
            {

                int jumlahBulan;

                cout << "Durasi Kontrak (bulan): ";
                cin >> jumlahBulan;

                if (jumlahBulan <= 0)
                {

                    cout << "Durasi tidak valid.\n";

                    break;
                }

                auto sewa =
                    make_unique<SewaBulanan>(
                        idSewa,
                        penghuni,
                        nomorKamar,
                        tglMulai,
                        jumlahBulan,
                        kamar->getHargaBulanan());

                cout << "\nTotal Nilai Kontrak : Rp"
                     << sewa->hitungHarga()
                     << endl;

                cout << "Harga Tagihan Bulanan: Rp"
                     << kamar->getHargaBulanan()
                     << endl;

                daftarSewa.push_back(
                    move(sewa));
            }

            // ------------------------------------------
            // SEWA TAHUNAN
            // ------------------------------------------

            else if (jenisSewa == 2)
            {

                int jumlahTahun;

                cout << "Durasi Kontrak (tahun): ";
                cin >> jumlahTahun;

                if (jumlahTahun <= 0)
                {

                    cout << "Durasi tidak valid.\n";

                    break;
                }

                auto sewa =
                    make_unique<SewaTahunan>(
                        idSewa,
                        penghuni,
                        nomorKamar,
                        tglMulai,
                        jumlahTahun,
                        kamar->getHargaTahunan());

                cout << "\nTotal Nilai Kontrak : Rp"
                     << sewa->hitungHarga()
                     << endl;

                cout << "Harga Tagihan Tahunan: Rp"
                     << kamar->getHargaTahunan()
                     << endl;

                daftarSewa.push_back(
                    move(sewa));
            }

            else
            {

                cout << "Jenis sewa tidak valid.\n";

                break;
            }

            // ------------------------------------------
            // AKTIFKAN PENGHUNI DAN KAMAR
            // ------------------------------------------

            penghuni->mulaiSewa();

            kamar->ubahStatus(
                "TERISI");

            // ------------------------------------------
            // BUAT TAGIHAN AWAL
            // ------------------------------------------

            double tagihanAwal;

            if (jenisSewa == 1)
            {

                tagihanAwal =
                    kamar->getHargaBulanan();
            }
            else
            {

                tagihanAwal =
                    kamar->getHargaTahunan();
            }

            string idPembayaran = buatID(
                "PB",
                counterPembayaran++);

            Pembayaran pembayaran(
                idPembayaran,
                idSewa,
                tglMulai,
                jenisSewa == 1
                    ? "Tagihan Bulanan"
                    : "Tagihan Tahunan",
                tagihanAwal);

            daftarPembayaran.push_back(
                pembayaran);

            cout << "\n===================================\n";
            cout << "PENYEWAAN BERHASIL\n";
            cout << "===================================\n";

            cout << "ID Sewa        : "
                 << idSewa << endl;

            cout << "ID Pembayaran  : "
                 << idPembayaran << endl;

            cout << "Tagihan Awal   : Rp"
                 << tagihanAwal << endl;

            cout << "Status Kamar   : TERISI\n";

            cout << "===================================\n";

            break;
        }

            // ==========================================
            // MENU 5 - PEMBAYARAN
            // ==========================================

        case 5:
        {

            cout << "\n===== PEMBAYARAN =====\n";

            if (daftarPembayaran.empty())
            {

                cout << "Belum ada data pembayaran.\n";

                break;
            }

            pemilik.lihatPembayaran(
                daftarPembayaran);

            string idPembayaran;

            cout << "\nID Pembayaran : ";
            cin >> idPembayaran;

            Pembayaran *pembayaran =
                cariPembayaran(
                    daftarPembayaran,
                    idPembayaran);

            if (pembayaran == nullptr)
            {

                cout << "ID pembayaran tidak ditemukan.\n";

                break;
            }

            double jumlahBayar;

            cout << "Jumlah Pembayaran : Rp";
            cin >> jumlahBayar;

            bool lunas =
                pembayaran->prosesPembayaran(
                    jumlahBayar);

            // ------------------------------------------
            // JIKA LUNAS
            // ------------------------------------------

            if (lunas)
            {

                cout << "\nTagihan telah lunas.\n";

                for (auto &s : daftarSewa)
                {

                    if (
                        s->getIdSewa() == pembayaran->getIdSewa())
                    {

                        s->setStatus(
                            "AKTIF");

                        if (s->getPenghuni() != nullptr)
                        {

                            s->getPenghuni()
                                ->mulaiSewa();
                        }
                    }
                }
            }

            break;
        }

            // ==========================================
            // MENU 6 - PEMBATALAN SEWA
            // ==========================================

        case 6:
        {

            string nim;

            cout << "\n===== PEMBATALAN SEWA =====\n";

            cout << "NIM Penghuni : ";
            cin >> nim;

            Penghuni *penghuni =
                cariPenghuni(
                    daftarPenghuni,
                    nim);

            if (penghuni == nullptr)
            {

                cout << "Penghuni tidak ditemukan.\n";

                break;
            }

            Sewa *sewaAktif = nullptr;

            for (auto &s : daftarSewa)
            {

                if (
                    s->getPenghuni() == penghuni &&
                    s->getStatus() == "AKTIF")
                {

                    sewaAktif = s.get();

                    break;
                }
            }

            if (sewaAktif == nullptr)
            {

                cout << "Tidak ada penyewaan aktif.\n";

                break;
            }

            int lamaPenggunaan;

            cout << "Lama Penggunaan : ";
            cin >> lamaPenggunaan;

            if (lamaPenggunaan < 0)
            {

                cout << "Lama penggunaan tidak valid.\n";

                break;
            }

            PembatalanSewa pembatalan;

            pembatalan.hitungRefund(
                sewaAktif->hitungHarga(),
                sewaAktif->getDurasi(),
                lamaPenggunaan);

            // ------------------------------------------
            // UBAH STATUS
            // ------------------------------------------

            sewaAktif->setStatus(
                "DIBATALKAN");

            penghuni->berhentiSewa();

            Kamar *kamar =
                cariKamar(
                    daftarKamar,
                    sewaAktif->getNomorKamar());

            if (kamar != nullptr)
            {

                kamar->ubahStatus(
                    "TERSEDIA");
            }

            cout << "\n===================================\n";
            cout << "PEMBATALAN SEWA\n";
            cout << "===================================\n";

            cout << "Biaya Penggunaan : Rp"
                 << pembatalan.getBiayaTerpakai()
                 << endl;

            cout << "Penalti          : Rp"
                 << pembatalan.getPenalti()
                 << endl;

            cout << "Jumlah Refund    : Rp"
                 << pembatalan.getRefund()
                 << endl;

            cout << "Status Sewa      : DIBATALKAN\n";
            cout << "Status Kamar     : TERSEDIA\n";

            cout << "===================================\n";

            break;
        }

            // ==========================================
            // MENU 7 - LAPORAN
            // ==========================================

        case 7:
        {

            pemilik.lihatLaporan(
                daftarKamar,
                daftarPenghuni,
                daftarPembayaran,
                daftarSewa);

            break;
        }

            // ==========================================
            // KELUAR
            // ==========================================

        case 0:

            cout << "\nProgram selesai.\n";

            break;

        default:

            cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 0);

    return 0;
}