#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Barang daftar_barang[MAX_BARANG];
int jumlah_barang = 0;

void baca_data_barang3() {
    FILE *file = fopen("barang.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%[^,],%d,%lf", daftar_barang[jumlah_barang].nama, &daftar_barang[jumlah_barang].stok, &daftar_barang[jumlah_barang].harga);
        jumlah_barang++;
    }

    fclose(file);
}

void tulis_data_barang2() {
    FILE *file = fopen("barang.txt", "w");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    for (int i = 0; i < jumlah_barang; i++) {
        fprintf(file, "%s,%d,%.2lf\n", daftar_barang[i].nama, daftar_barang[i].stok, daftar_barang[i].harga);
    }

    fclose(file);
}


void tambah_stok(const char *nama_barang, int jumlah) {
    int i;
    for (i = 0; i < jumlah_barang; i++) {
        if (strcmp(daftar_barang[i].nama, nama_barang) == 0) {
            daftar_barang[i].stok += jumlah;
            printf("Stok barang %s berhasil ditambahkan.\n", daftar_barang[i].nama);
            return;
        }
    }
    printf("Nama barang tidak ditemukan.\n");
}

void ubah_harga(const char *nama_barang, double harga_baru) {
    int i;
    for (i = 0; i < jumlah_barang; i++) {
        if (strcmp(daftar_barang[i].nama, nama_barang) == 0) {
            daftar_barang[i].harga = harga_baru;
            printf("Harga barang %s berhasil diubah.\n", daftar_barang[i].nama);
            return;
        }
    }
    printf("Nama barang tidak ditemukan.\n");
}

void laporan_stok() {
    int i;
    printf("Laporan Stok Barang:\n");
    for (i = 0; i < jumlah_barang; i++) {
        printf("Nama Barang: %s\n", daftar_barang[i].nama);
        printf("Stok: %d\n", daftar_barang[i].stok);
        printf("Harga: %.2f\n", daftar_barang[i].harga);
        printf("---------------------\n");
    }
}
