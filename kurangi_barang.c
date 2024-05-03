#include "header.h"
#include <stdio.h>
#include <string.h>


void baca_data_barang() {
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

void tulis_data_barang() {
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

void kurangi_barang(const char *nama_barang, int jumlah) {
    int index = -1;

    for (int i = 0; i < jumlah_barang; i++) {
        if (strcmp(daftar_barang[i].nama, nama_barang) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Barang dengan nama %s tidak ditemukan.\n", nama_barang);
        return;
    }

    if (daftar_barang[index].stok < jumlah) {
        printf("Stok barang %s tidak mencukupi.\n", nama_barang);
        return;
    }

    daftar_barang[index].stok -= jumlah;
    printf("Stok barang %s berhasil dikurangi sebanyak %d.\n", nama_barang, jumlah);

    tulis_data_barang();
}

void hapus_barang(const char *nama_barang) {
    int index = -1;

    for (int i = 0; i < jumlah_barang; i++) {
        if (strcmp(daftar_barang[i].nama, nama_barang) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Barang dengan nama %s tidak ditemukan.\n", nama_barang);
        return;
    }

    for (int i = index; i < jumlah_barang - 1; i++) {
        daftar_barang[i] = daftar_barang[i + 1];
    }

    jumlah_barang--;
    printf("Barang dengan nama %s berhasil dihapus.\n", nama_barang);

    tulis_data_barang();
}