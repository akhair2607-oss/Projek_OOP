#pragma once

// ==========================================
// CLASS PembatalanSewa
// ==========================================
class PembatalanSewa {
private:
    double totalSewa;
    double biayaTerpakai;
    double penalti;
    double refund;

public:
    PembatalanSewa() : totalSewa(0), biayaTerpakai(0), penalti(0), refund(0) {}

    // durasiTotal    = total durasi sewa (bulan/tahun, sesuai jenis sewa)
    // durasiTerpakai = lama sewa yang sudah dipakai penghuni
    // persenPenalti  = persentase penalti dari sisa masa sewa (default 10%)
    void hitungRefund(double totalHargaSewa, int durasiTotal, int durasiTerpakai,
                       double persenPenalti = 0.10) {
        totalSewa = totalHargaSewa;

        if (durasiTerpakai > durasiTotal) durasiTerpakai = durasiTotal;

        double hargaPerSatuan = totalHargaSewa / durasiTotal;
        biayaTerpakai = hargaPerSatuan * durasiTerpakai;

        double sisaSewa = totalHargaSewa - biayaTerpakai;
        penalti = sisaSewa * persenPenalti;
        refund = sisaSewa - penalti;

        if (refund < 0) refund = 0;
    }

    double getTotalSewa() const { return totalSewa; }
    double getBiayaTerpakai() const { return biayaTerpakai; }
    double getPenalti() const { return penalti; }
    double getRefund() const { return refund; }
};