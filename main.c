#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pengelolahan_barang.c"

int main() {
    baca_data_barang();

    printf("======= Aplikasi Pengelolaan Barang =======\n");
    printf("1. Tampilkan Daftar Barang\n");
    printf("2. Cari Barang\n");
    printf("===========================================\n");

    int pilihan;
    printf("Masukkan pilihan: ");
    scanf("%d", &pilihan);

    switch (pilihan) {
        case 1:
            tampilkan_daftar_barang();
            break;
        case 2:
            getchar(); // Membersihkan newline di buffer
            char kode_barang[10];
            printf("Masukkan kode barang yang akan dicari: ");
            fgets(kode_barang, sizeof(kode_barang), stdin);
            kode_barang[strcspn(kode_barang, "\n")] = '\0'; // Menghapus karakter newline dari input
            pilih_barang(kode_barang);
            break;
        default:
            printf("Pilihan tidak valid.\n");
            break;
    }

    return 0;
}