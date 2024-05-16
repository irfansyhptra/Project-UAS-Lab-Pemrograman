// #include <stdio.h>
// #include "header.h"

// int jumlahAkun = 0;
//     int status = 0; // 0 untuk belum login, 1 untuk admin, 2 untuk user
//     int role; // Untuk menentukan admin atau user
//     unsigned int idCari;
//    int indeksCari;

// int MenuLogin() {
//     while (1) {
//         if (!status) {
//             char username[20];
//             char password[20];

//             printf("Masukkan username: ");
//             scanf("%s", username);

//             printf("Masukkan password: ");
//             scanf("%s", password);

//             // Memeriksa data akun
//             int ditemukan = 0;
//             for (int i = 0; i < jumlahAkun; i++) {
//                 if (strcmp(username, akun[i].username) == 0 && strcmp(password, akun[i].password) == 0) {
//                     status = 1;
//                     role = akun[i].role;
//                     ditemukan = 1;
//                     break;
//                 }
//             }

//             if (!ditemukan) {
//                 printf("Username atau password salah.\n");
//             }
//         } else {
//             if (role == 1) { // Admin
//                 int pilihan;
//                 tampilkanMenuAdmin();
//                 scanf("%d", &pilihan);
//                 switch (pilihan) {} else if (role == 2) { // User
//                 int pilihan;
//                 tampilkanMenuUser();
//                 scanf("%d", &pilihan); }
//             }
//         }

//     }

// }