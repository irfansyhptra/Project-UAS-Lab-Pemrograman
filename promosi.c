#include "header.h"
#include <stdio.h>
#include <string.h>

void tambahkanDiskon(float persenDiskon) {
    FILE *file = fopen("barang.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file barang.txt\n");
        return;
    }

    char kode[3];
    char nama[50];
    int stok;
    double harga;

    while (fscanf(file, "%s %s %d %lf", kode, nama, &stok, &harga) == 4) {
        if (stok > 0) {
            double diskon = harga * persenDiskon / 100;
            harga -= diskon;

            printf("Kode: %s\n", kode);
            printf("Nama: %s\n", nama);
            printf("Harga setelah diskon: %.2lf\n", harga);
            printf("------------------------------\n");
        }
    }

    fclose(file);
}

void hapusDiskon() {
    FILE *file = fopen("barang.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file barang.txt\n");
        return;
    }

    char kode[3];
    char nama[50];
    int stok;
    double harga;

    while (fscanf(file, "%s %s %d %lf", kode, nama, &stok, &harga) == 4) {
        printf("Kode: %s\n", kode);
        printf("Nama: %s\n", nama);
        printf("Harga: %.2lf\n", harga);
        printf("------------------------------\n");
    }

    fclose(file);
}

void tambahkanVoucherPotongan() {
    FILE *file = fopen("barang.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file barang.txt\n");
        return;
    }

    char kode[3];
    char nama[50];
    int stok;
    double harga;

    while (fscanf(file, "%s %s %d %lf", kode, nama, &stok, &harga) == 4) {
        if (stok > 0) {
            harga -= 10000;

            printf("Kode: %s\n", kode);
            printf("Nama: %s\n", nama);
            printf("Harga setelah voucher potongan: %.2lf\n", harga);
            printf("------------------------------\n");
        }
    }

    fclose(file);
}

void hapusVoucherPotongan() {
    FILE *file = fopen("barang.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file barang.txt\n");
        return;
    }

    char kode[3];
    char nama[50];
    int stok;
    double harga;

    while (fscanf(file, "%s %s %d %lf", kode, nama, &stok, &harga) == 4) {
        printf("Kode: %s\n", kode);
        printf("Nama: %s\n", nama);
        printf("Harga: %.2lf\n", harga);
        printf("------------------------------\n");
    }

    fclose(file);
}
