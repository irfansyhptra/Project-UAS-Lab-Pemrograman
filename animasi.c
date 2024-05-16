// import header.h
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "header.h"

/* Regular colors
\e[0;30m 	Black
\e[0;31m 	Red
\e[0;32m 	Green
\e[0;33m 	Yellow
\e[0;34m 	Blue
\e[0;35m 	Purple
\e[0;36m 	Cyan
\e[0;37m 	White */

/* Bold colors
\e[1;30m 	Black
\e[1;31m 	Red
\e[1;32m 	Green
\e[1;33m 	Yellow
\e[1;34m 	Blue
\e[1;35m 	Purple
\e[1;36m 	Cyan
\e[1;37m 	White */

/* Underline colors
\e[4;30m 	Black
\e[4;31m 	Red
\e[4;32m 	Green
\e[4;33m 	Yellow
\e[4;34m 	Blue
\e[4;35m 	Purple
\e[4;36m 	Cyan
\e[4;37m 	White */

/* Background colors
\e[40m 	Black
\e[41m 	Red
\e[42m 	Green
\e[43m 	Yellow
\e[44m 	Blue
\e[45m 	Purple
\e[46m 	Cyan
\e[47m 	White */

/* High intensity colors
\e[0;90m 	Black
\e[0;91m 	Red
\e[0;92m 	Green
\e[0;93m 	Yellow
\e[0;94m 	Blue
\e[0;95m 	Purple
\e[0;96m 	Cyan
\e[0;97m 	White */

/* Bold high intensity colors
\e[1;90m 	Black
\e[1;91m 	Red
\e[1;92m 	Green
\e[1;93m 	Yellow
\e[1;94m 	Blue
\e[1;95m 	Purple
\e[1;96m 	Cyan
\e[1;97m 	White */

/* High intensity background colors
\e[0;100m 	Black
\e[0;101m 	Red
\e[0;102m 	Green
\e[0;103m 	Yellow
\e[0;104m 	Blue
\e[0;105m 	Purple
\e[0;106m 	Cyan
\e[0;107m 	White */

/* Reset
\e[0m 	Reset/Default */


// header function
// Menampilkan header dengan garis pemisah di atas dan di bawah teks.
void header()
{
    hyphen("\033[1;33m", 130, 10, "TRUE");
    printin_center("%*s", "\033[1;30;43m+[......Selamat Datang Di Program Kasir Toko toktok.........]+", 130, 10, "TRUE");
    hyphen("\033[1;33m", 130, 10, "TRUE");
}

// barang list length function
// Menghitung jumlah baris dalam file "barang.txt" untuk mengetahui panjang daftar buku.
int panjang_barang()
{
    FILE *input_fp;

    char barang[2048];
    int size = 0;

    input_fp = fopen("barang.txt", "r");

    if (input_fp == NULL)
    {
        printf("Error! file doesn't exist\n");

        return EXIT_FAILURE;
    }

    while (fgets(barang, sizeof(barang), input_fp) != NULL)
    {
        size++;
    }

    fclose(input_fp);

    return size;
}

// print text in_center function
// Mencetak teks yang diatur di tengah layar dengan jenis string tertentu dan margin tertentu.
void printin_center(char *typeof_str, char *string, int screen_xy, int margin, char *enter)
{
    screen_xy = (screen_xy / 2);

    int align_center = (screen_xy + (strlen(string) / 2));
    int condition;

    if (((align_center + margin) % 2) == 0)
    {
        condition = (align_center + margin) + 1;
    }
    else
    {
        condition = (align_center + margin);
    }

    printf(typeof_str, condition, string);
    printf("\033[0m");

    if (strcmp(enter, "TRUE") == 0)
    {
        printf("\n");
    }
    else if (strcmp(enter, "FALSE") == 0)
    {
        EXIT_SUCCESS;
    }
    else
    {
        EXIT_FAILURE;
    }
}

// print text in left function
// Mencetak teks yang diatur di kiri layar dengan jenis string tertentu dan margin tertentu.
void printin_left(char *typeof_str, char *string, int margin, char *enter)
{
    printf(typeof_str, margin, string);
    printf("\033[0m");

    if (strcmp(enter, "TRUE") == 0)
    {
        printf("\n");
    }
    else if (strcmp(enter, "FALSE") == 0)
    {
        EXIT_SUCCESS;
    }
    else
    {
        EXIT_FAILURE;
    }
}

// print text in right function
// Mencetak teks yang diatur di kanan layar dengan jenis string tertentu dan margin tertentu.
void printin_right(char *typeof_str, char *string, int screen_xy, int margin, char *enter)
{
    int condition;

    if (((screen_xy + margin) % 2) == 0)
    {
        condition = (screen_xy + margin) - 1;
    }
    else
    {
        condition = (screen_xy + margin);
    }

    printf(typeof_str, condition, string);
    printf("\033[0m");

    if (strcmp(enter, "TRUE") == 0)
    {
        printf("\n");
    }
    else if (strcmp(enter, "FALSE") == 0)
    {
        EXIT_SUCCESS;
    }
    else
    {
        EXIT_FAILURE;
    }
}

// print text in uppercase function
// Mencetak teks dalam huruf kapital dari sebuah string.
void printin_uppercase(char *typeof_str, char *string)
{
    char temp_string[strlen(string)];

    strcpy(temp_string, string);

    for (int index = 0; temp_string[index] != '\0'; index++)
    {
        if (temp_string[index] >= 'a' && temp_string[index] <= 'z')
        {
            temp_string[index] = toupper(temp_string[index]);
        }
        else
        {
            continue;
        }
    }

    printf("%s", temp_string);
}

// print text in lowercase function
// Mencetak teks dalam huruf kecil dari sebuah string.
void printin_lowercase(char *typeof_str, char *string)
{

    char temp_string[strlen(string)];

    strcpy(temp_string, string);

    for (int index = 0; temp_string[index] != '\0'; index++)
    {
        if (temp_string[index] >= 'A' && temp_string[index] <= 'Z')
        {
            temp_string[index] = tolower(temp_string[index]);
        }
        else
        {
            continue;
        }
    }

    printf("%s", temp_string);
}

// print hyphen (-) function
// Mencetak garis pemisah (hyphen) sepanjang panjang tertentu dengan warna tertentu dan margin tertentu.
void hyphen(char *color, int hyphen_length, int margin, char *enter)
{
    int condition;

    if (((hyphen_length + margin) % 2) == 0)
    {
        condition = (hyphen_length + margin) - 1;
    }
    else
    {
        condition = (hyphen_length + margin);
    }

    for (int number = 1; number <= condition; number++)
    {
        printf("%s-", color);
    }

    printf("\033[0m");

    if (strcmp(enter, "TRUE") == 0)
    {
        printf("\n");
    }
    else if (strcmp(enter, "FALSE") == 0)
    {
        EXIT_SUCCESS;
    }
    else
    {
        EXIT_FAILURE;
    }
}

// print enter function
// Memasukkan baris kosong sebanyak yang diinginkan.
void enter(int row_length)
{
    for (int number = 1; number <= row_length; number++)
    {
        printf("\n");
    }
}

// print clear char function
// Menghapus karakter dari posisi saat ini sebanyak yang diinginkan.
void clear_char(int clear_length)
{
    for (int number = 1; number <= clear_length; number++)
    {
        printf("\r");
    }
}

// print backspace function
// Menghapus karakter sebelum posisi saat ini sebanyak yang diinginkan.
void backspace(int backspace_length)
{
    for (int number = 1; number <= backspace_length; number++)
    {
        printf("\b");
    }
}

// time sleep function
// Memberi jeda waktu dengan batas waktu tertentu.
void timesleep(float limit, char *print_escape, char *power_arg){
    float seconds = 0;
    clock_t start, time;

    start = clock();

    while (seconds <= limit)
    {
        time = clock();

        if (strcmp(power_arg, "WIN") == 0)
        {
            seconds = ((time - start) / pow(10, 3));
        }
        else if (strcmp(power_arg, "LINUX") == 0)
        {
            seconds = ((time - start) / pow(10, 6));
        }
        else
        {
            EXIT_FAILURE;
        }

        if (strcmp(print_escape, "TRUE") == 0)
        {
            printf("\e");
        }
        else if (strcmp(print_escape, "FALSE") == 0)
        {
            continue;
        }
        else
        {
            EXIT_FAILURE;
        }
    }
}

// loading screen function
// Menampilkan layar loading dengan animasi loading.
void loading(int screen_width, char *arg)
{
    int half_screen_width = (screen_width / 2);

    if ((half_screen_width % 2) != 0)
    {
        enter(half_screen_width - 1);
    }
    else
    {
        enter(half_screen_width);
    }

    printin_center("%*s", "\033[1;33mLoading", 130, 10 - 2, "TRUE");
    printf("%*s", ((130 - 10) / 2) + 1, " ");

    for (int loading = 1; loading <= 10; loading++)
    {
        if (strcmp(arg, "WIN") == 0)
        {
            timesleep(0.3, "TRUE", arg);
        }
        else if (strcmp(arg, "LINUX") == 0)
        {
            timesleep(0.3, "TRUE", arg);
        }
        else
        {
            EXIT_FAILURE;
        }

        printf("\033[0m%*s\033[1;30;43m%s", 0, " ", " ");
        printf("\033[0m");
    }

    enter(half_screen_width);

    system_clear(arg);
}

// system clear function
// Membersihkan layar konsol tergantung pada platform yang digunakan (Windows atau Linux).
void system_clear(char *clear_arg)
{
    if (strcmp(clear_arg, "WIN") == 0)
    {
        system("cls");
    }
    else if (strcmp(clear_arg, "LINUX") == 0)
    {
        system("clear");
    }
}
void welcome_screen()
{
    enter(16);
    printin_center("%*s", "\033[1;30;43m+[ SELAMAT DATANG DI SYSTEM KASIR TOKO TOKTOK ]+", 130, 10, "FALSE");
    printf("\033[0m");
    enter(2);
    printin_center("%*s", "\033[1;33m Access the shop anywhere and anytime", 130, 10 - 2, "FALSE");
    printf("\033[0m");
    enter(16);
}

// home screen function
// Menampilkan layar beranda dengan opsi untuk login sebagai administrator atau user.
void home_screen()
{
    hyphen("\033[1;33m", 130, 10, "TRUE");
    printin_center("%*s", "\033[1;30;43m+[ KASIR TOKO TOKTOK ]+", 130, 10, "TRUE");
    hyphen("\033[1;33m", 130, 10, "TRUE");

    printf("\033[1;33m SELAMAT DATANG DI SYSTEM KASIR TOKO TOKTOK \n");
    printf("\033[0m");
    printf("\033[33m E-KASIR merupakan platform pengolahan data toko digital \n Kamu dapat mengtur sistem toko TOKTOK");
    enter(2);
    printf("\033[1;33m Silahkan Log in untuk melanjutkan");
    enter(2);
    printf("\033[0m");

    printf("\033[1;33m Log in as: \n");
    printf("\033[0m");
    printf("\033[33m1. Administrator (full access) \n");
    printf("\033[33m2. Karyawan (limited access) \n");
    printf("\033[33m3. Create new account (Karyawan) \n");
    printf("\033[33m4. Exit \n");
    printf("\033[0m");
    enter(19);

    hyphen("\033[1;33m", 130, 10, "TRUE");
}

void home_escape()
{
    printf("\033[1;30;43m[HOME/ESCAPE]");
    printf("\033[0m");
    printf("\033[33m: ");
}

// home/escape function
// Menampilkan instruksi untuk kembali ke beranda atau keluar dari program.
// table border function
// Fungsi untuk mencetak garis pembatas tabel.
void table_border(char *enter)
{
    printf("\033[1;33m+");
    hyphen("\033[1;33m", 5, 2, "FALSE");
    printf("\033[1;33m+");
    hyphen("\033[1;33m", 50, 0, "FALSE");
    printf("\033[1;33m+");
    hyphen("\033[1;33m", 36, 1, "FALSE");
    printf("\033[1;33m+");
    hyphen("\033[1;33m", 14, 0, "FALSE");
    printf("\033[1;33m+");
    hyphen("\033[1;33m", 14, 0, "FALSE");
    printf("\033[1;33m+");
    hyphen("\033[1;33m", 14, 0, "FALSE");
    printf("\033[1;33m+");

    if (strcmp(enter, "TRUE") == 0)
    {
        printf("\n");
    }
    else if (strcmp(enter, "FALSE") == 0)
    {
        EXIT_SUCCESS;
    }
    else
    {
        EXIT_FAILURE;
    }
}


// table row function
// Fungsi untuk mencetak satu baris tabel dengan data buku pada indeks tertentu.
void table_row(barang data[], int index) {
    printf("| %-5d | %-8s | %-10s | %15.2f | %13d |\n",
           index + 1,
           data[index].id,
           data[index].nama,
           data[index].harga,
           data[index].stok);
}
// create new account invalid function
// Menampilkan pesan kesalahan ketika pembuatan akun baru gagal karena nama pengguna sudah ada.
void newacc_invalid()
{
    enter(17);
    printin_center("%*s", "\033[1;33mUsername already exists. Please try again!", 130, 10, "FALSE");
    printf("\033[0m");
    enter(17);
}

// create new account end function
// Menampilkan pesan kesalahan saat pembuatan akun baru gagal setelah 3 kali percobaan yang tidak valid.
void newacc_end()
{
    enter(16);
    printin_center("%*s", "\033[1;33mInvalid username 3 times. Try again later!", 130, 10, "FALSE");
    enter(2);
    printin_center("%*s", "\033[1;33mThe program will close in 3 seconds", 130, 10 - 2, "FALSE");
    printf("\033[0m");
    enter(16);
}

// create new account success function
// Menampilkan pesan sukses saat pembuatan akun baru berhasil.
void newacc_success()
{
    enter(17);
    printin_center("%*s", "\033[1;33mAccount successfully created!", 130, 10, "FALSE");
    printf("\033[0m");
    enter(17);
}

// log in invalid function
// Menampilkan pesan kesalahan ketika login gagal karena nama pengguna atau kata sandi tidak valid.
void login_invalid()
{
    enter(17);
    printin_center("%*s", "\033[1;33mInvalid username or password. Please try again!", 130, 10, "FALSE");
    printf("\033[0m");
    enter(17);
}

// log in end function
// Menampilkan pesan kesalahan saat login gagal setelah 3 kali percobaan yang tidak valid.
void login_end()
{
    enter(16);
    printin_center("%*s", "\033[1;33mInvalid username or password 3 times. Try again later!", 130, 10, "FALSE");
    enter(2);
    printin_center("%*s", "\033[1;33mThe program will close in 3 seconds", 130, 10 - 2, "FALSE");
    printf("\033[0m");
    enter(16);
}

// option length function
// Menampilkan panjang opsi yang tersedia untuk dipilih.
void option_length(int length)
{
    printf("\033[1;30;43m[");

    for (int num = 1; num <= length; num++)
    {
        printf("\033[1;30;43m%d", num);

        if (num < length)
        {
            printf("\033[1;30;43m/");
        }
        else
        {
            break;
        }
    }

    printf("\033[1;30;43m]");
    printf("\033[0m");
    printf("\033[33m: ");
}

// option invalid function
// Menampilkan pesan kesalahan ketika opsi yang dimasukkan tidak valid.
void option_invalid()
{
    printf("\033[1;33m-> ");
    printf("\033[0m");
    printf("\033[33mInvalid option. Please try again!");
    printf("\033[0m");
    enter(1);
}

// option end function
// Menampilkan pesan kesalahan setelah 3 kali percobaan memasukkan opsi yang tidak valid.
void option_end()
{
    printf("\033[33mInvalid option 3 times. Try again later! \nThe program will close in 3 seconds");
    printf("\033[0m");
    enter(1);
}

// print new barang list to both file function
// Fungsi untuk mencetak daftar buku baru ke file "dibeli.txt" dan "barang.txt".
void print_newlist(barang data[], char *account_id, int ukuran_barang, int temp_index)
{
    FILE *output_fp;

    output_fp = fopen("dibeli.txt", "a");

    fprintf(output_fp, "\n\"%s\" %u %d", account_id, data[temp_index].id, 1);
    fclose(output_fp);

    output_fp = fopen("barang.txt", "w");

    for (int index = 0; index < ukuran_barang; index++)
    {
        fprintf(output_fp, "%s \"%s\" %f %u", data[index].id, data[index].nama, data[index].harga, data[index].stok);

        if (index < (ukuran_barang - 1))
        {
            fprintf(output_fp, "\n");
        }
        else
        {
            continue;
        }
    }

    fclose(output_fp);
}

// dibeli barang length function
// Menghitung jumlah baris dalam file "dibeli.txt" untuk mengetahui panjang daftar buku yang dipinjam.
int panjang_dibeli()
{
    FILE *input_fp;

    char data[1024];
    int size = 0;

    input_fp = fopen("dibeli.txt", "r");

    if (input_fp == NULL)
    {
        printf("Error! file doesn't exist\n");

        return EXIT_FAILURE;
    }

    while (fgets(data, sizeof(data), input_fp) != NULL)
    {
        size++;
    }

    fclose(input_fp);

    return size;
}

void admin_menu()
{
    printf("\033[1;33mAdmin Menu\n");
    printf("\033[0m");
    printf("\033[33m1. Daftar Barang\n");
    printf("\033[33m2. Tambah barang\n");
    printf("\033[33m3. Hapus barang\n");
    printf("\033[33m4. Modify barang\n");
    printf("\033[33m5. Home\n");
    printf("\033[33m6. Exit\n");
    printf("\033[0m");
}

// barang available function
// Fungsi untuk membaca data buku dari file "barang.txt" dan menyimpannya dalam array 'data'.
void barang_tersedia(barang data[], int *ukuran_barang) {
    FILE *input_fp;
    char barang[100];
    int index = 0;

    input_fp = fopen("barang.txt", "r");

    if (input_fp == NULL) {
        printf("Error! file doesn't exist\n");
        return;
    }

    // Baca data dari file dan simpan ke dalam array data[]
    while (fscanf(input_fp, "%[^,],%[^,],%u,%f", data[index].id, data[index].nama, &data[index].stok, &data[index].harga) == 4) {
        index++;
    }

    *ukuran_barang = index; // Simpan jumlah barang yang dibaca
    fclose(input_fp);
}

// Modify barang function
// Fungsi untuk mengubah data buku dalam array 'data' berdasarkan pilihan.
void edit_barang(barang data[], int ukuran_barang, int *jumlah_percobaan)
{
    int option;
    char id[10];
    char nama[128];
    float harga;
    int stok;
    char option_again;

    printf("\033[33mPilih Opsi:\033[0m\n");
    printf("1. Ubah ID Barang\n");
    printf("2. Ubah Nama Barang\n");
    printf("3. Ubah Harga Barang\n");
    printf("4. Ubah Stok Barang\n");
    printf("Masukkan Pilihan (1-4): ");
    scanf("%d", &option);
    enter(1);

   do {
    switch (option) {
        case 1:
            printf("\033[33mMasukkan ID Baru: ");
            scanf(" %[^\n]s", id);
            enter(1);
            printf("\033[0m");

            for (int i = 0; i < ukuran_barang; i++) {
                if (strcmp(data[i].id, id) == 0) {
                    strcpy(data[i].id, id);
                    break;
                }
            }
            break;

        case 2:
            printf("\033[33mMasukkan Nama Baru: ");
            scanf(" %[^\n]s", nama);
            enter(1);
            printf("\033[0m");

            for (int i = 0; i < ukuran_barang; i++) {
                if (strcmp(data[i].id, id) == 0) {
                    strcpy(data[i].nama, nama);
                    break;
                }
            }
            break;

        case 3:
            printf("\033[33mMasukkan Harga Baru: ");
            scanf("%f", &harga);
            enter(1);
            printf("\033[0m");

            for (int i = 0; i < ukuran_barang; i++) {
                if (strcmp(data[i].id, id) == 0) {
                    data[i].harga = harga;
                    break;
                }
            }
            break;

        case 4:
            printf("\033[33mMasukkan Stok Baru: ");
            scanf("%d", &stok);
            enter(1);
            printf("\033[0m");

            for (int i = 0; i < ukuran_barang; i++) {
                if (strcmp(data[i].id, id) == 0) {
                    data[i].stok = stok;
                    break;
                }
            }
            break;

        default:
            printf("\033[1;31mOpsi tidak valid.\033[0m\n");
            break;
    }

    *jumlah_percobaan = 0;
    tampilkan_barang(data, ukuran_barang);

   

    printf("\nApakah Anda ingin melakukan perubahan lagi? (y/n): ");
    scanf(" %c", &option_again);
   } while (option_again == 'y' || option_again == 'Y'); }


    // print new barang list to file function
// Fungsi untuk mencetak daftar buku baru ke file "barang.txt".
void tampilkan_barang(char id[], char nama[], int stock, double harga, char *win_linux, int ukuran_barang)
{
    FILE *output_fp;

    output_fp = fopen("barang.txt", "w");

    for (int index = 0; index < ukuran_barang; index++)
    {
    fprintf(output_fp, "\n%s \"%s\" %u %u", id, nama, stock, harga);
        if (index < (ukuran_barang - 1))
        {
            fprintf(output_fp, "\n");
        }
        else
        {
            continue;
        }
    }

    fclose(output_fp);
}

// barang status function
// Fungsi untuk mencetak status buku berdasarkan pilihan.
void status_barang(char *win_linux, int option)
{
    if (option == 1)
    {
        printf("\033[33mBook have been dibeli!");
        printf("\033[0m");

        timesleep(1, "TRUE", win_linux);
        system_clear(win_linux);
    }
    else if (option == 2)
    {
        printf("\033[33mBook is not available!");
        printf("\033[0m");

        timesleep(1, "TRUE", win_linux);
        system_clear(win_linux);
    }
    else if (option == 3)
    {
        printf("\033[33mBook already available!");
        printf("\033[0m");

        timesleep(1, "TRUE", win_linux);
        system_clear(win_linux);
    }
    else
    {
        EXIT_FAILURE;
    }
}

// print to file (deleted barang) function
// Fungsi untuk menghapus data buku dari file "barang.txt" berdasarkan ID buku.
void hapus_barang(barang data[], int ukuran_barang, char *win_linux, char *file_name) {
    FILE *fp;
    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("\033[33m Tidak dapat membuka file %s.\n", file_name);
        return;
    }

    // Baca nama barang dari file
    char nama_barang[100];
    printf("Masukkan nama barang yang ingin dihapus: ");
    scanf("%s", nama_barang);

    int found = 0;
    int count = 0;
    while (fscanf(fp, "%[^,],%[^,],%u,%f\n", data[count].id, data[count].nama, &data[count].stok, &data[count].harga) == 4) {
        count++;
        if (count >= ukuran_barang) {
            break;
        }
    }
    fclose(fp);

    int index = -1;
    for (int i = 0; i < count; i++) {
        if (strcmp(data[i].nama, nama_barang) == 0) {
            index = i;
            found = 1;
            break;
        }
    }

    if (found) {
        FILE *output_fp;
        output_fp = fopen(file_name, "w");
        if (output_fp == NULL) {
            printf("\033[33m Tidak dapat membuka file %s untuk menulis.\n", file_name);
            return;
        }

        for (int i = 0; i < count; i++) {
            if (i != index) {
                fprintf(output_fp, "%s,%s,%u,%.2f\n", data[i].id, data[i].nama, data[i].stok, data[i].harga);
            }
        }
        fclose(output_fp);
        printf("\033[33m Barang dengan nama %s berhasil dihapus!\033[0m\n", nama_barang);
    } else {
        printf("\033[33m Tidak ada barang dengan nama %s ditemukan.\n", nama_barang);
    }
}

// user barang function
// Menampilkan barang untuk user
// Termasuk pilihan untuk melihat buku yang tersedia, meminjam buku, melihat buku yang dipinjam, mengembalikan buku, kembali ke beranda, dan keluar.
void menu_karyawan()
{
    printf("\033[1;33mUser barang\n");
    printf("\033[0m");
    printf("\033[33m1. Kasir\n");
    printf("\033[33m2. Cek Infromasi Barang\n");
    printf("\033[33m3. Laporan\n");
    printf("\033[33m5. Home\n");
    printf("\033[33m6. Exit\n");
    printf("\033[0m");
}

// barang list length function
// Menghitung jumlah baris dalam file "barang.txt" untuk mengetahui panjang daftar buku.
int ukuran_daftar_barang()
{
    FILE *input_fp;

    char barang[2048];
    int size = 0;

    input_fp = fopen("barang.txt", "r");

    if (input_fp == NULL)
    {
        printf("Error! file doesn't exist\n");

        return EXIT_FAILURE;
    }

    while (fgets(barang, sizeof(barang), input_fp) != NULL)
    {
        size++;
    }

    fclose(input_fp);

    return size;
}

// print new loans function
// Fungsi untuk mencetak daftar peminjaman baru ke file "dibeli.txt" berdasarkan ID buku.
void print_dibeli(user karyawan[], int ukuran_dibeli, char id)
{
    FILE *output_fp;

    output_fp = fopen("dibeli.txt", "w");

    for (int index = 0; index < ukuran_dibeli; index++)
    {
        if (*karyawan[index].id == id)
        {
            continue;
        }
        else
        {
            fprintf(output_fp, "\"%s\" %u %u", karyawan[index].username, karyawan[index].id, 1);

            if (index < (ukuran_dibeli - 1))
            {
                fprintf(output_fp, "\n");
            }
            else
            {
                break;
            }
        }
    }

    fclose(output_fp);
}
// on loan table row function
// Fungsi untuk mencetak satu baris tabel untuk buku yang sedang dipinjam.
void baris_tabel_dibeli(barang data[], int index)
{
    printf("\033[33m");
    printf("| %-5s | %-47s | %-11u | %-11u |\n", data[index].id, data[index].nama, data[index].harga, data[index].stok, 1);
    printf("\033[0m");
}

// user loans function
// Fungsi untuk membaca data peminjaman buku dari file "dibeli.txt" dan menyimpannya dalam array 'karyawan'.
void karyawan_pembeli(user karyawan[]) {
    barang data[MAX_BARANG]; // Deklarasi array dengan tipe Barang
    int index = 0;

    FILE *input_fp;

    char dibeli[512];

    input_fp = fopen("dibeli.txt", "r");

    if (input_fp == NULL) {
        printf("\033[33mError! file doesn't exist\n");
        exit(EXIT_FAILURE);
    }

    for (int index = 0; fgets(dibeli, sizeof(dibeli), input_fp) != NULL; index++) {
        sscanf(dibeli, "%s \"%[^\"]\" %u %u", &data[index].id, data[index].nama, &data[index].harga, &data[index].stok);
    }

    fclose(input_fp);
}

// goodbye screen function
// Menampilkan layar perpisahan dengan teks "Goodbye!".
void goodbye_screen()
{
    enter(17);
    printin_center("%*s", "\033[1;30;43m+[ Goodbye! ]+", 130, 10, "FALSE");
    printf("\033[0m");
    enter(17);
}