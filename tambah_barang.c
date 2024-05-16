#include <stdio.h>
#include <string.h>
#include "header.h"

void tambah_barang() {
    struct Barang barang;

        printf("\033[33m ID Barang\t\t: ");
    if (scanf("%9s", barang.id) != 1) {
        printf("Gagal membaca input ID Barang.\n");
        return;
    }
    getchar(); // Menggunakan getchar() untuk mengonsumsi karakter newline setelah input ID Barang

    printf("\033[33m Nama Barang\t\t: ");
    if (fgets(barang.nama, sizeof(barang.nama), stdin) == NULL) {
        printf("Gagal membaca input Nama Barang.\n");
        return;
    }
    barang.nama[strcspn(barang.nama, "\n")] = '\0'; // Menghapus karakter newline

    printf("\033[33m Masukan Jumlah Stok\t: ");
    if (scanf("%d", &barang.stok) != 1) {
        printf("Gagal membaca input Jumlah Stok.\n");
        return;
    }
    getchar(); // Menggunakan getchar() untuk mengonsumsi karakter newline setelah input Jumlah Stok

    printf("\033[33m Masukan Harga Barang\t: ");
    if (scanf("%lf", &barang.harga) != 1) {
        printf("Gagal membaca input Harga Barang.\n");
        return;
    }
    printf("\033[0m");
    enter(1);

    FILE *file = fopen("barang.txt", "a");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    fprintf(file, "%s,%s,%d,%.2lf\n", barang.id, barang.nama, barang.stok, barang.harga);
    fflush(file); // Memastikan data ditulis ke file

    fclose(file);

    printf("\033[33m Barang berhasil ditambahkan.\n");
}