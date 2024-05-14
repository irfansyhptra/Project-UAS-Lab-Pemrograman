#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Deklarasi fungsi login
void login(char username[], char password[]);

// Definisi fungsi login
void login(char username[], char password[]) {
    // Simulasi data pengguna yang disimpan dalam database
    char user_database[20] = "user123";
    char pass_database[20] = "pass123";
    
    // Memeriksa apakah username dan password cocok dengan data yang tersimpan
    if (strcmp(username, user_database) == 0 && strcmp(password, pass_database) == 0) {
        printf("Login berhasil. Selamat datang, %s!\n", username);
    } else {
        printf("Login gagal. Username atau password salah.\n");
    }
}