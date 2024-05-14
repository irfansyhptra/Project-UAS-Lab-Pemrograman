#include "header.h"
#include <stdio.h>
#include <string.h>

void tampilkan_menu() {
    printf("\nMenu:\n");
    printf("1. Daftar Barang\n");
    printf("2. Kurangi Barang\n");
    printf("3. Tambah Barang\n");
    printf("4. Pembayaran\n");
    printf("5. Lihat Riwayat Transaksi\n");
    printf("0. Keluar\n");
}

int main() {
    int pilihan = -1;
    while (pilihan != 0) {
        tampilkan_menu();
        printf("Masukkan pilihan: ");
        scanf("%d", &pilihan);

        // Membersihkan buffer
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}

        switch (pilihan) {
            case 1:
                baca_data_barang2();
                tampilkan_daftar_barang();
                break;
            case 2: {
                // Kurangi Barang
                baca_data_barang();
                char nama_barang[50];
                printf("Masukkan nama barang yang akan dikurangi: ");
                fgets(nama_barang, sizeof(nama_barang), stdin);
                nama_barang[strcspn(nama_barang, "\n")] = '\0'; // Menghapus karakter newline dari input
                kurangi_barang(nama_barang, 1); // Mengurangi stok sebanyak 1
                break;
            }
            case 3:
                tambah_barang();
                break;
            case 4: {
                // Pembayaran
                int total = 0;
                float hitung_total_harga(struct Barang daftar_barang[], int jumlah_barang);
                pembayaran(total);
                break;
            }
            case 5:
                // Lihat Riwayat Transaksi
                lihat_riwayat_transaksi(lihat_riwayat_transaksi, tambah_transaksi);
                break;
            case 0:
                printf("Keluar\n");
                break;
            default:
                printf("Pilihan tidak valid\n");
        }
    }

    return 0;
}
