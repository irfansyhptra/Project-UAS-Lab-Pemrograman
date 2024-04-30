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
        strtok(line, ","); // Mengambil nama barang
        daftar_barang[jumlah_barang].stok = atoi(strtok(NULL, ",")); // Mengambil stok barang
        strtok(NULL, ","); // Mengabaikan harga barang
        jumlah_barang++;
    }

    fclose(file);
}

void kurangi_barang(const char *nama_barang, int jumlah) {
    int index = -1;

    for (int i = 0; i < jumlah_barang; i++) {
        if (strcmp(daftar_barang[i].nama, nama_barang) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Barang dengan nama %s tidak ditemukan.\n", nama_barang);
        return;
    }

    if (daftar_barang[index].stok < jumlah) {
        printf("Stok barang %s tidak mencukupi.\n", nama_barang);
        return;
    }

    daftar_barang[index].stok -= jumlah;
    printf("Stok barang %s berhasil dikurangi sebanyak %d.\n", nama_barang, jumlah);

    // Menulis ulang data stok barang ke dalam file barang.txt
    FILE *file = fopen("barang.txt", "w");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    for (int i = 0; i < jumlah_barang; i++) {
        fprintf(file, "%s,%d,%.2lf\n", daftar_barang[i].nama, daftar_barang[i].stok, daftar_barang[i].harga);
    }

    fclose(file);
}

int main() {
    baca_data_barang();

    kurangi_barang("Baju", 3);
    kurangi_barang("Sepatu", 2);

    return 0;
}