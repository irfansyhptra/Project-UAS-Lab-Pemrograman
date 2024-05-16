#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void pembayaran()
{
   struct Barang data[MAX_BARANG];
    int jumlahBarang, index = 0;
    char namaBarang[MAX_BARANG];
    float totalHarga, hargaBarang, diskon = 0;
    char kodeVoucher[20];

    // Membaca data barang dari file
    FILE *file = fopen("barang.txt", "r");
    if (file == NULL) {
        printf("Error: File barang.txt tidak dapat dibuka.\n");
        return;
    }
    while (fscanf(file, "%49s %f", data[index].nama, &data[index].harga) != EOF) {
        index++;
    }
    fclose(file);

    // Membaca input dari pengguna
    printf("Masukkan nama barang: ");
    if (scanf("%[^\n]%*c", &namaBarang) != 1) {
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
    for (int i = 0; i < index; i++) {
        if (strcmp(data[i].nama, namaBarang) == 0) {
            hargaBarang = data[i].harga;
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

