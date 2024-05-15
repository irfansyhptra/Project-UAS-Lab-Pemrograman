#include "header.h"
#include <stdio.h>
#include <string.h>

struct Promosi {
    char kode_voucher[10];
    double potongan_harga;
};

struct BarangPromosi {
    char nama_barang[50];
    double diskon;
};

struct Promosi daftar_promosi[10];
struct BarangPromosi daftar_barang_promosi[10];
int jumlah_promosi = 0;
int jumlah_barang_promosi = 0;

void tambah_promosi() {
    if (jumlah_promosi >= 10) {
        printf("Jumlah promosi telah mencapai batas maksimal.\n");
        return;
    }

    struct Promosi promosi;

    printf("Masukkan kode voucher: ");
    fgets(promosi.kode_voucher, sizeof(promosi.kode_voucher), stdin);
    promosi.kode_voucher[strcspn(promosi.kode_voucher, "\n")] = '\0'; // Menghapus karakter newline

    printf("Masukkan potongan harga: ");
    scanf("%lf", &promosi.potongan_harga);

    // Membersihkan buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    daftar_promosi[jumlah_promosi++] = promosi;

    printf("Promosi berhasil ditambahkan.\n");
}

void tambah_diskon_barang() {
    if (jumlah_barang_promosi >= 10) {
        printf("Jumlah barang promosi telah mencapai batas maksimal.\n");
        return;
    }

    struct BarangPromosi barang_promosi;

    printf("Masukkan nama barang: ");
    fgets(barang_promosi.nama_barang, sizeof(barang_promosi.nama_barang), stdin);
    barang_promosi.nama_barang[strcspn(barang_promosi.nama_barang, "\n")] = '\0'; // Menghapus karakter newline

    printf("Masukkan diskon (dalam persen): ");
    scanf("%lf", &barang_promosi.diskon);

    // Membersihkan buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    daftar_barang_promosi[jumlah_barang_promosi++] = barang_promosi;

    printf("Diskon barang berhasil ditambahkan.\n");
}

void hapus_diskon_barang() {
    if (jumlah_barang_promosi == 0) {
        printf("Tidak ada diskon barang yang tersedia.\n");
        return;
    }

    char nama_barang[50];
    printf("Masukkan nama barang yang akan dihapus diskonnya: ");
    scanf("%s", nama_barang);

    int i;
    int found = 0;
    for (i = 0; i < jumlah_barang_promosi; i++) {
        if (strcmp(daftar_barang_promosi[i].nama_barang, nama_barang) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        // Menggeser elemen-elemen setelahnya ke posisi sebelumnya
        for (; i < jumlah_barang_promosi - 1; i++) {
            daftar_barang_promosi[i] = daftar_barang_promosi[i + 1];
        }

        jumlah_barang_promosi--;

        printf("Diskon barang dengan nama %s berhasil dihapus.\n", nama_barang);
    } else {
        printf("Diskon barang dengan nama %s tidak ditemukan.\n", nama_barang);
    }
}
