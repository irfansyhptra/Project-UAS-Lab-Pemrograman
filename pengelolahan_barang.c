#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// #define MAX_BARANG 100

// struct Barang {
//     char id[10];
//     char nama[50];
//     int stok;
//     double harga;
// };

struct Barang daftar_barang2[MAX_BARANG];
int jumlah_barang2 = 0;

void baca_data_barang3() {
    FILE *file = fopen("barang.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        char *id = strtok(line, ","); // Mengambil id barang
        strcpy(daftar_barang2[jumlah_barang2].id, id);
        strcpy(daftar_barang2[jumlah_barang2].nama, strtok(NULL, ",")); // Mengambil nama barang
        daftar_barang2[jumlah_barang2].stok = atoi(strtok(NULL, ",")); // Mengambil stok barang
        daftar_barang2[jumlah_barang2].harga = atof(strtok(NULL, ",")); // Mengambil harga barang
        jumlah_barang2++;
    }

    fclose(file);
}


void pilih_barang(const char *id_barang) {
    scanf("Informasi Barang (Kode: %s )", &id_barang);
    printf("---------------------------------------------\n");
    printf("Kode    Nama Barang              Stok    Harga\n");
    printf("---------------------------------------------\n");

    for (int i = 0; i < jumlah_barang2; i++) {
        if (strcmp(daftar_barang2[i].id, id_barang) == 0) {
            printf("%-8s%-24s%-8d%.2lf\n", daftar_barang2[i].id, daftar_barang2[i].nama, daftar_barang2[i].stok, daftar_barang2[i].harga);
            return;
        }
    }

    printf("Barang dengan id %s tidak ditemukan.\n", id_barang);
    printf("---------------------------------------------\n");
}