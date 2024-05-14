#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Struktur data untuk menyimpan detail transaksi
struct Transaksi {
    int id;
    char barang_nama[50];
    float harga_barang;
};

// Fungsi untuk menambahkan transaksi baru ke dalam riwayat transaksi
void tambah_transaksi(struct Transaksi **riwayat, int *jumlah_transaksi, char barang_nama[], float harga_barang);

// Fungsi untuk melihat riwayat transaksi sebelumnya
void lihat_riwayat_transaksi(struct Transaksi *riwayat, int jumlah_transaksi);

// Fungsi untuk menghapus riwayat transaksi
void hapus_riwayat_transaksi(struct Transaksi **riwayat, int *jumlah_transaksi);

// Fungsi untuk mengosongkan riwayat transaksi
void kosongkan_riwayat_transaksi(struct Transaksi **riwayat, int *jumlah_transaksi);

void tambah_transaksi(struct Transaksi **riwayat, int *jumlah_transaksi, char barang_nama[], float harga_barang) {
    // Mengekspansi ukuran array riwayat transaksi
    *riwayat = realloc(*riwayat, (*jumlah_transaksi + 1) * sizeof(struct Transaksi));
    
    // Memeriksa apakah alokasi memori berhasil
    if (*riwayat == NULL) {
        printf("Alokasi memori gagal.\n");
        exit(1);
    }
    
    // Menambahkan transaksi baru ke dalam riwayat
    (*riwayat)[*jumlah_transaksi].id = *jumlah_transaksi + 1;
    strcpy((*riwayat)[*jumlah_transaksi].barang_nama, barang_nama);
    (*riwayat)[*jumlah_transaksi].harga_barang = harga_barang;
    
    // Menambahkan jumlah transaksi
    *jumlah_transaksi += 1;
}

void lihat_riwayat_transaksi(struct Transaksi *riwayat, int jumlah_transaksi) {
    printf("Riwayat Transaksi:\n");
    printf("ID\tNama Barang\tHarga\n");
    for (int i = 0; i < jumlah_transaksi; i++) {
        printf("%d\t%s\t\t%.2f\n", riwayat[i].id, riwayat[i].barang_nama, riwayat[i].harga_barang);
    }
}

void hapus_riwayat_transaksi(struct Transaksi **riwayat, int *jumlah_transaksi) {
    free(*riwayat);
    *riwayat = NULL;
    *jumlah_transaksi = 0;
}

void kosongkan_riwayat_transaksi(struct Transaksi **riwayat, int *jumlah_transaksi) {
    *riwayat = realloc(*riwayat, 0);
    *jumlah_transaksi = 0;
}