#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BARANG 100

struct Barang {
    char nama[50];
    int stok;
    double harga;
};

struct Barang daftar_barang[MAX_BARANG];
int jumlah_barang = 0;

void tambah_stok(const char *nama_barang, int tambahan) {
    for (int i = 0; i < jumlah_barang; i++) {
        if (strcmp(daftar_barang[i].nama, nama_barang) == 0) {
            daftar_barang[i].stok += tambahan;
            printf("Stok barang %s berhasil ditambahkan sebanyak %d.\n", nama_barang, tambahan);
            return;
        }
    }

    printf("Barang dengan nama %s tidak ditemukan.\n", nama_barang);
}

void ubah_harga(const char *nama_barang, double harga_baru) {
    for (int i = 0; i < jumlah_barang; i++) {
        if (strcmp(daftar_barang[i].nama, nama_barang) == 0) {
            daftar_barang[i].harga = harga_baru;
            printf("Harga barang %s berhasil diubah menjadi %.2lf.\n", nama_barang, harga_baru);
            return;
        }
    }

    printf("Barang dengan nama %s tidak ditemukan.\n", nama_barang);
}

void laporan_stok() {
    printf("Laporan Stok Barang:\n");
    printf("--------------------\n");
    printf("No.  Nama Barang              Stok    Harga\n");
    printf("-----------------------------------------\n");

    for (int i = 0; i < jumlah_barang; i++) {
        printf("%-4d %-24s %-8d %.2lf\n", i + 1, daftar_barang[i].nama, daftar_barang[i].stok, daftar_barang[i].harga);
    }

    printf("-----------------------------------------\n");
}

int main() {
    // Contoh penggunaan fungsi-fungsi pengelolaan stok
    strcpy(daftar_barang[0].nama, "Baju");
    daftar_barang[0].stok = 10;
    daftar_barang[0].harga = 50.0;
    jumlah_barang++;

    strcpy(daftar_barang[1].nama, "Celana");
    daftar_barang[1].stok = 5;
    daftar_barang[1].harga = 100.0;
    jumlah_barang++;

    tambah_stok("Baju", 5);
    tambah_stok("Sepatu", 3);

    ubah_harga("Celana", 150.0);
    ubah_harga("Sepatu", 200.0);

    laporan_stok();

    return 0;
}