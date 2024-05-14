#include "header.h"
#include <stdio.h>
#include <stdlib.h> // Tambahkan header file ini
#include <string.h>

struct Barang daftar_barang[MAX_BARANG];
int jumlah_barang = 0;

void baca_data_barang2() {
    FILE *file = fopen("barang.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        char *nama = strtok(line, ","); // Mengambil nama barang
        strcpy(daftar_barang[jumlah_barang].nama, nama);
        daftar_barang[jumlah_barang].stok = atoi(strtok(NULL, ",")); // Mengambil stok barang
        daftar_barang[jumlah_barang].harga = atof(strtok(NULL, ",")); // Mengambil harga barang
        jumlah_barang++;
    }

    fclose(file);
}

void tampilkan_daftar_barang() {
    printf("Daftar Barang:\n");
    printf("-------------\n");
    printf("No.  Nama Barang              Stok    Harga\n");
    printf("-----------------------------------------\n");

    for (int i = 0; i < jumlah_barang; i++) {
        printf("%-4d %-24s %-8d %.2lf\n", i + 1, daftar_barang[i].nama, daftar_barang[i].stok, daftar_barang[i].harga);
    }

    printf("-----------------------------------------\n");
}

// int main() {
//     baca_data_barang();

//     tampilkan_daftar_barang();

//     return 0;
// }