#include <stdio.h>
#include <stdlib.h>

struct Transaksi {
    char namaBarang[50];
    int jumlahBarang;
    float totalHarga;
};

void tampilkanLaporan()
{
    FILE *file = fopen("laporan.txt", "r");
    if (file == NULL) {
        printf("Error: File laporan.txt tidak dapat dibuka.\n");
        return;
    }

    struct Transaksi data[100]; // Jumlah maksimum transaksi yang dapat dibaca
    int index = 0;
    while (fscanf(file, "%49s %d %f", data[index].namaBarang, &data[index].jumlahBarang, &data[index].totalHarga) != EOF) {
        index++;
    }
    fclose(file);

    printf("Laporan Penjualan:\n");
    printf("| %-20s | %-15s | %-12s |\n", "Nama Barang", "Jumlah Barang", "Total Harga");
    printf("---------------------------------------------\n");
    for (int i = 0; i < index; i++) {
        printf("| %-20s | %-15d | %-12.2f |\n", data[i].namaBarang, data[i].jumlahBarang, data[i].totalHarga);
    }
    printf("---------------------------------------------\n");
}

int main()
{
    tampilkanLaporan();
    return 0;
}