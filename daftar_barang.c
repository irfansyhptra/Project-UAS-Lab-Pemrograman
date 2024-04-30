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

void baca_data_barang() {
    FILE *file = fopen("barang.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        char *nama = strtok(line, ","); // Mengambil nama barang
        strcpy(daftar_barang[jumlah_barang].nama, nama);
        daftar_barang[jumlah_barang].stok = atoi(strtok(NULL, ",")); // Mengambil stok barang
        daftar_barang[jumlah_barang].harga = atof(strtok(NULL, ",")); // Mengambil harga barang
        jumlah_barang++;
    }

    fclose(file);
}

void daftar_barang() {
    printf("Daftar Barang:\n");
    printf("-------------\n");
    printf("No.  Nama Barang              Stok    Harga\n");
    printf("-----------------------------------------\n");

    for (int i = 0; i < jumlah_barang; i++) {
        printf("%-4d %-24s %-8d %.2lf\n", i + 1, daftar_barang[i].nama, daftar_barang[i].stok, daftar_barang[i].harga);
    }

    printf("-----------------------------------------\n");
}

void cari_barang(const char *kriteria) {
    printf("Hasil Pencarian Barang (Kriteria: %s):\n", kriteria);
    printf("-----------------------------------------\n");
    printf("No.  Nama Barang              Stok    Harga\n");
    printf("-----------------------------------------\n");

    for (int i = 0; i < jumlah_barang; i++) {
        if (strstr(daftar_barang[i].nama, kriteria) != NULL) {
            printf("%-4d %-24s %-8d %.2lf\n", i + 1, daftar_barang[i].nama, daftar_barang[i].stok, daftar_barang[i].harga);
        }
    }

    printf("-----------------------------------------\n");
}

int main() {
    baca_data_barang();

    daftar_barang();

    cari_barang("Baju");

    return 0;
}