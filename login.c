#include <stdio.h>
#include "header.h"


struct Akun akun[100];

void simpanDataAkun(struct Akun *akun, int jumlahAkun) {
    FILE *file = fopen("data_akun.txt", "w");
    if (file != NULL) {
        for (int i = 0; i < jumlahAkun; i++) {
            fprintf(file, "%s;%s;%d\n", akun[i].username, akun[i].password, akun[i].role);
        }
        fclose(file);
    } else {
        printf("Gagal membuka file untuk menyimpan data akun.\n");
    }
}

// Fungsi untuk memuat data akun dari file
void bacaDataAkun(struct Akun *akun, int *jumlahAkun) {
    FILE *file = fopen("data_akun.txt", "r");
    if (file != NULL) {
        while (fscanf(file, "%[^;];%[^;];%d\n", akun[*jumlahAkun].username, akun[*jumlahAkun].password, &akun[*jumlahAkun].role) == 3) {
            (*jumlahAkun)++;
        }
        fclose(file);
    } else {
        printf("Gagal membuka file untuk membaca data akun.\n");
    }
}
