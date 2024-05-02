#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BARANG 100

struct Barang {
    char kode[10];
    char nama[50];
    int stok;
    double harga;
};

struct Barang daftar_barang[MAX_BARANG];
int jumlah_barang = 0;

void baca_data_barang() {
    FILE *file = fopen("barang.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        char *kode = strtok(line, ","); // Mengambil kode barang
        strcpy(daftar_barang[jumlah_barang].kode, kode);
        strcpy(daftar_barang[jumlah_barang].nama, strtok(NULL, ",")); // Mengambil nama barang
        daftar_barang[jumlah_barang].stok = atoi(strtok(NULL, ",")); // Mengambil stok barang
        daftar_barang[jumlah_barang].harga = atof(strtok(NULL, ",")); // Mengambil harga barang
        jumlah_barang++;
    }

    fclose(file);
}


void pilih_barang(const char *kode_barang) {
    printf("Informasi Barang (Kode: %s):\n", kode_barang);
    printf("---------------------------------------------\n");
    printf("Kode    Nama Barang              Stok    Harga\n");
    printf("---------------------------------------------\n");

    for (int i = 0; i < jumlah_barang; i++) {
        if (strcmp(daftar_barang[i].kode, kode_barang) == 0) {
            printf("%-8s%-24s%-8d%.2lf\n", daftar_barang[i].kode, daftar_barang[i].nama, daftar_barang[i].stok, daftar_barang[i].harga);
            return;
        }
    }

    printf("Barang dengan kode %s tidak ditemukan.\n", kode_barang);
    printf("---------------------------------------------\n");
}

int main() {
    baca_data_barang();

    char kode_barang[10];
    printf("Masukkan kode barang yang akan dipilih: ");
    fgets(kode_barang, sizeof(kode_barang), stdin);
    kode_barang[strcspn(kode_barang, "\n")] = '\0'; // Menghapus karakter newline dari input

    pilih_barang(kode_barang);

    return 0;
}