#include <stdio.h>
#include <string.h>
#include "header.h"

void baca_data_barang3(struct Barang daftarBarang[], int *jumlahBarang) {
    FILE *file = fopen("barang.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file barang.txt\n");
        return;
    }

    *jumlahBarang = 0;
    while (fscanf(file, "%s,%[^,],%d,%lf", daftarBarang[*jumlahBarang].kode, daftarBarang[*jumlahBarang].nama, &daftarBarang[*jumlahBarang].jumlah, &daftarBarang[*jumlahBarang].harga) != EOF) {
        (*jumlahBarang)++;
    }

    fclose(file);
}
void tampilkanLokasiBarang(struct Barang daftarBarang[], int jumlahBarang, const char *kodeBarang) {
    int ditemukan = 0;

    for (int i = 0; i < jumlahBarang; i++) {
        if (strcmp(daftarBarang[i].kode, kodeBarang) == 0 || strcmp(daftarBarang[i].nama, kodeBarang) == 0) {
            printf("Informasi Barang:\n");
            printf("Kode Barang : %s\n", daftarBarang[i].kode);
            printf("Nama Barang : %s\n", daftarBarang[i].nama);
            printf("Lokasi Rak  : Rak Display 1 tingkat %d\n", i + 1);
            ditemukan = 1;
            break;
        }
    }

    if (!ditemukan) {
        printf("Barang dengan kode atau nama '%s' tidak ditemukan.\n", kodeBarang);
    }
}