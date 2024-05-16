#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void pembayaran() {
    barang data[MAX_BARANG];
    int ukuran_barang;
    int jumlahBarang, index = 0;
    char nama[50];
    float totalHarga, hargaBarang, diskon = 0;
    char kodeVoucher[20];

    // Baca data barang dari file menggunakan fungsi barang_tersedia()
    barang_tersedia(data, &ukuran_barang);

    // Baca input dari pengguna
    printf("Masukkan nama barang: ");
    if (scanf("%s", &nama) != 1) {
        printf("Error: Gagal membaca input nama barang.\n");
        return;
    }

    printf("Masukkan jumlah barang: ");
    if (scanf("%d", &jumlahBarang) != 1) {
        printf("Error: Gagal membaca input jumlah barang.\n");
        return;
    }

    printf("Masukkan kode voucher: ");
    if (scanf("%s", kodeVoucher) != 1) {
        printf("Error: Gagal membaca input kode voucher.\n");
        return;
    }

    // Mencari harga barang berdasarkan nama barang yang diinputkan
    for (int i = 0; i < ukuran_barang; i++) {
        if (strcmp(data[i].nama, nama) == 0) {
            hargaBarang = data[i].harga;
            if (jumlahBarang > data[i].stok) {
                printf("Maaf, stok barang tidak mencukupi.\n");
                return;
            }
            break;
        }
    }

    // Menghitung total harga setelah diskon
    if (hargaBarang != -1) {
        if (strcmp(kodeVoucher, "DISKON123") == 0) {
            diskon = 0.1; // 10% diskon
        }
        totalHarga = (hargaBarang * jumlahBarang) - (hargaBarang * jumlahBarang * diskon);
        printf("Total harga setelah diskon: %.2f\n", totalHarga);
    } else {
        printf("Error: Barang tidak ditemukan.\n");
    }
}