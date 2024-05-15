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

void tulis_data_barang() {
    FILE *file = fopen("barang.txt", "w");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    for (int i = 0; i < jumlah_barang; i++) {
        fprintf(file, "%s,%s,%d,%.2lf\n", daftar_barang[i].kode, daftar_barang[i].nama, daftar_barang[i].stok, daftar_barang[i].harga);
    }

    fclose(file);
}

void tambah_barang() {
    struct Barang barang;

    printf("Masukkan kode barang: ");
    fgets(barang.kode, sizeof(barang.kode), stdin);
    barang.kode[strcspn(barang.kode, "\n")] = '\0';

    printf("Masukkan nama barang: ");
    fgets(barang.nama, sizeof(barang.nama), stdin);
    barang.nama[strcspn(barang.nama, "\n")] = '\0';

    printf("Masukkan stok barang: ");
    scanf("%d", &barang.stok);

    printf("Masukkan harga barang: ");
    scanf("%lf", &barang.harga);

    // Menambahkan barang ke daftar
    strcpy(daftar_barang[jumlah_barang].kode, barang.kode);
    strcpy(daftar_barang[jumlah_barang].nama, barang.nama);
    daftar_barang[jumlah_barang].stok = barang.stok;
    daftar_barang[jumlah_barang].harga = barang.harga;
    jumlah_barang++;

    // Menulis data barang ke dalam file
    tulis_data_barang();

    printf("Barang berhasil ditambahkan.\n");
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

    tulis_data_barang();
}

void hapus_barang(const char *nama_barang) {
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

    for (int i = index; i < jumlah_barang - 1; i++) {
        daftar_barang[i] = daftar_barang[i + 1];
    }

    jumlah_barang--;
    printf("Barang dengan nama %s berhasil dihapus.\n", nama_barang);

    tulis_data_barang();
}

void tampilkan_daftar_barang() {
    printf("Daftar Barang:\n");
    printf("-------------\n");
    printf("No.  Kode    Nama Barang              Stok    Harga\n");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < jumlah_barang; i++) {
        printf("%-5d%-8s%-25s%-8d%.2lf\n", i + 1, daftar_barang[i].kode, daftar_barang[i].nama, daftar_barang[i].stok, daftar_barang[i].harga);
    }
}

int main() {
    baca_data_barang();

    int pilihan;
    char nama_barang[50];
    int jumlah;

    do {
        printf("\n");
        printf("Program Laporan Barang\n");
        printf("----------------------\n");
        printf("1. Tambah Barang\n");
        printf("2. Kurangi Barang\n");
        printf("3. Hapus Barang\n");
        printf("4. Tampilkan Daftar Barang\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        getchar(); // Menghapus karakter newline (\n) yang masih tersisa di buffer

        switch (pilihan) {
            case 1:
                tambah_barang();
                break;
            case 2:
                printf("Masukkan nama barang: ");
                fgets(nama_barang, sizeof(nama_barang), stdin);
                nama_barang[strcspn(nama_barang, "\n")] = '\0';

                printf("Masukkan jumlah barang yang dikurangi: ");
                scanf("%d", &jumlah);
                getchar();

                kurangi_barang(nama_barang, jumlah);
                break;
            case 3:
                printf("Masukkan nama barang: ");
                fgets(nama_barang, sizeof(nama_barang), stdin);
                nama_barang[strcspn(nama_barang, "\n")] = '\0';

                hapus_barang(nama_barang);
                break;
            case 4:
                tampilkan_daftar_barang();
                break;
            case 0:
                printf("Terima kasih. Sampai jumpa!\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
                break;
        }
    } while (pilihan != 0);

    return 0;
}