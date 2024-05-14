#include "header.h"
#include <stdio.h>

// Definisi fungsi hitung_total
void hitung_total(float harga[], int jumlah_barang);

// Definisi fungsi pembayaran
void pembayaran();

void hitung_total(float harga[], int jumlah_barang) {
    float total = 0.0;
    
    // Menghitung total harga dengan menjumlahkan harga semua barang
    for (int i = 0; i < jumlah_barang; i++) {
        total += harga[i];
    }
    
    // Menampilkan total harga
    printf("Total harga barang adalah: %.2f\n", total);
}

void pembayaran() {
    // Inisialisasi harga barang
    float harga[] = {10000.0, 20000.0, 15000.0}; // Contoh harga barang
    int jumlah_barang = 3; // Jumlah barang yang akan dibeli
    
    // Memanggil fungsi hitung_total
    hitung_total(harga, jumlah_barang);
}