#ifndef HEADER_H
#define HEADER_H

#define MAX_BARANG 100

struct Barang {
    char kode[3];
    char nama[50];
    int stok;
    double harga;
};

extern struct Barang daftar_barang[MAX_BARANG];
extern int jumlah_barang;

void baca_data_barang();
void baca_data_barang2();
void tulis_data_barang();
void kurangi_barang(const char *nama_barang, int jumlah);
void hapus_barang(const char *nama_barang);
void tampilkan_daftar_barang();
void tambah_barang();

#endif