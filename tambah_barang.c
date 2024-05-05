#include <stdio.h>
#include <string.h>
#include "header.h"

void tambah_barang() {
    struct Barang barang;

    printf("Masukkan kode barang: ");   // Menambahkan input kode barang
    fgets(barang.kode, sizeof(barang.kode), stdin);
    barang.kode[strcspn(barang.kode, "\n")] = '\0';

    printf("Masukkan nama barang: ");
    getchar();  // Membersihkan input buffer
    fgets(barang.nama, sizeof(barang.nama), stdin);
    barang.nama[strcspn(barang.nama, "\n")] = '\0';

    printf("Masukkan stok barang: ");
    scanf("%d", &barang.stok);

    printf("Masukkan harga barang: ");
    scanf("%lf", &barang.harga);

    // Membuka file barang.txt dalam mode append
    FILE *file = fopen("barang.txt", "a");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    // Menulis data barang ke dalam file
    fprintf(file, "%s,%s,%d,%.2lf\n", barang.kode, barang.nama, barang.stok, barang.harga);

    fclose(file);

    printf("Barang berhasil ditambahkan.\n");
}