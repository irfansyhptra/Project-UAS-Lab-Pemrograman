#ifndef HEADER_H
#define HEADER_H

#define MAX_BARANG 100
// #define MAX_PANJANG_KODE 10
// #define MAX_PANJANG_NAMA 50
// #define MAX_PANJANG_LOKASI 30

// Mendeklarasikan variabel
struct Barang {
    char id[10];
    char nama[50];
    float harga;
    int stok;
};

// Definisi struct untuk data akun
struct Akun {
    char username[20];
    char password[20];
    int role; // 1 untuk admin, 2 untuk user
}; 

typedef struct {
    char id[10];
    char nama[50];
    float harga;
    int stok;
} barang;

// user karyawan struct
typedef struct {
    char username[32];
    char id[10];
    unsigned int no_barang;
} user;


extern struct Barang daftar_barang[MAX_BARANG];
extern int jumlah_barang;

void baca_data_barang();
void baca_data_barang2();
void baca_data_barang3();
void tulis_data_barang();
void kurangi_barang(const char *nama_barang, int jumlah);
void hapus_barang(barang data[], int ukuran_barang, char *win_linux, char *file_name);
void tampilkan_daftar_barang();
void tambah_barang();
int login();
int MenuLogin();
void simpanDataAkun();
void bacaDataAkun();
void tampilkanMenuKaryawan();
void tampilkanLokasiBarang();
void pilih_barang();
void timesleep(float limit, char *print_escape, char *power_arg);
void printin_center(char *typeof_str, char *string, int screen_xy, int margin, char *enter);
void printin_left(char *typeof_str, char *string, int margin, char *enter);
void printin_right(char *typeof_str, char *string, int screen_xy, int margin, char *enter);
void printin_uppercase(char *typeof_str, char *string);
void printin_lowercase(char *typeof_str, char *string);
void hyphen(char *color, int hyphen_length, int margin, char *enter);
void enter(int row_length);
void clear_char(int clear_length);
void backspace(int backspace_length);
void loading();
void system_clear(char *clear_arg);
void welcome_screen();
void home_screen();
void welcome_screen();
void option_length();
void header();
void home_escape();
void table_border(char *enter);
void table_row();
void newacc_invalid();
void newacc_end();
void newacc_success();
void login_invalid();
void login_end();
void option_invalid();
void option_end();
void print_newlist();
int panjang_barang();
void goodbye_screen();
int panjang_dibeli();
void admin_menu();
void barang_tersedia();
void edit_barang(barang data[], int ukuran_barang, int *jumlah_percobaan);
void tampilkan_barang();
void status_barang();
void menu_karyawan();
int ukuran_daftar_barang();
void print_dibeli(user karyawan[], int ukuran_dibeli, char id_barang);
void baris_tabel_dibeli();
void karyawan_pembeli();
void  pembayaran();
#endif