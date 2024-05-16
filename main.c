#include <stdlib.h>
#include "header.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) 
{ 
        
     /* Resolution:
    width: 140
    height: 35
    ratio: 1:4 */

    FILE *input_fp, *output_fp;

    int ukuran_barang = panjang_barang(); // Menentukan ukuran buku
    int ukuran_dibeli = panjang_dibeli(); // Menentukan ukuran buku yang dipinjam

    barang data[64]; // Array untuk menyimpan data buku
    user karyawan[32];
    // user karyawan[32]; // Array untuk menyimpan data peminjam
    char account_id[128], password[128]; // Variabel untuk menyimpan ID dan kata sandi pengguna
    char account_file[128], password_file[128]; //  Variabel untuk menyimpan ID dan kata sandi dari file
    char win_linux[8], accounts[256]; // Variabel untuk sistem operasi dan akun
    char cmd_option[10]; // Variabel untuk opsi perintah
    char id; // ID buku
    int temp_index; // Indeks sementara


    system_clear("WIN"); // Membersihkan layar
    loading(35); // Memuat tampilan loading

    welcome_screen(); // Menampilkan layar selamat datang

    timesleep(3, "TRUE","WIN"); // Menunggu beberapa detik
    system_clear("WIN"); // Membersihkan layar+

    home:
    home_screen(); // Menampilkan layar utama

    int option = 0, numof_trials = 0; // Variabel untuk opsi dan jumlah percobaan

    option:
    option_length(4); // Menentukan panjang opsi

    scanf("%d", &option); // Memasukkan opsi
    printf("\033[0m"); // Membersihkan terminal
    
    if (option ==1 ) // Jika opsi adalah 1 (masuk sebagai admin)
    {
        numof_trials = 0;
        system_clear("WIN");
        loading(35, "WIN");
        admin_login:
        FILE *input_fp;
        input_fp = fopen("admin.txt", "r"); // Membuka file admin.txt untuk login sebagai admin

        if (input_fp == NULL) // Jika file tidak ditemukan
        {
            printf("\033[33mError! file doesn't exist\n"); // Menampilkan pesan kesalahan

            return EXIT_FAILURE;
        }

        header(); // Menampilkan header

        // Menampilkan pesan untuk masuk sebagai admin
        printf("\033[1;33mAdmin log in \n");
        printf("\033[0m");
        printf("\033[33mAdmin ID\t: ");
        scanf("%s", account_id);
        printf("\033[33mPassword\t: ");
        scanf("%s", password);
    
    
        // Loop untuk membaca dan membandingkan ID admin dan password yang dimasukkan dengan yang ada dalam file
        while (fgets(accounts, sizeof(accounts), input_fp) != NULL)
        {
            sscanf(accounts, "\"%[^\"]\" \"%[^\"]\"", account_file, password_file);

            // Memeriksa apakah ID admin dan password yang dimasukkan cocok dengan yang ada dalam file
            if (strcmp(account_id, account_file) == 0 && strcmp(password, password_file) == 0)
            {
                break;
            }
            else
            {
                continue;
            }
        }

        enter(28); // Memberi jarak setelah proses autentikasi admin
        hyphen("\033[1;33m", 130, 10, "TRUE"); // Membuat garis pemisah dengan panjang ddan warna tertentu
        printf("\033[0m"); // Menampilkan pesan standar untuk kembali ke tampilan awal

        // Memeriksa apakah autentikasi admin berhasil
        if (strcmp(account_id, account_file) == 0 && strcmp(password, password_file) == 0)
        {
            numof_trials = 0; // Mengatur jumlah percobaan kembali ke nol setelah berhasil masuk

            fclose(input_fp); // Menutup file yang digunakan untuk autentikasi

            system_clear("WIN");
            loading(35, "WIN"); 


            admin_menu:
            header();
            admin_menu(); // Menampilkan menu admin
            enter(23); // Memberi jarak setelah menu admin ditampilkan
            hyphen("\033[1;33m", 130, 10, "TRUE"); // Membuat garis pemisah setelah menu admin

            admin_option:
            // Menampilkan opsi admin dan mengambil pilihan dari admin
            option_length(6);
            scanf("%d", &option);
            printf("\033[0m");

            // Memeriksa pilihan admin
             if (option >= 1 && option <= 4)
            {
                system_clear("WIN");
                loading(35, "WIN");

                    barang data[100]; // Asumsi maksimal 100 barang
                    int ukuran_barang;

                    if (option == 1) 
                    {
                    numof_trials = 0;
                    ukuran_barang = 0;

                    barang_tersedia(data, &ukuran_barang); // Baca data dari file dan simpan ke dalam array data[]

                    // Tampilkan daftar barang
                    header();
                    printf("\033[1;33m Daftar Seluruh Barang \033[0m");
                    enter(1);

                    printf("\033[33m");
                    table_border("TRUE");
                    printf("| %-5s | %-12s | %-15s | %-11s | %-11s |\n", "NO", "KODE BARANG", "NAMA BARANG", "HARGA", "STOCK");
                    table_border("TRUE");
                    printf("\033[0m");

                    for (int index = 0; index < ukuran_barang; index++) {
                    table_row(data, index);
                    }

                    table_border("TRUE");
                    printf("\033[0m");

                    enter(29 - ukuran_barang - 4);
                    hyphen("\033[1;33m", 130, 10, "TRUE");

                    admin_cmd_option1:
                    home_escape();
                    scanf("%s", cmd_option);
                    printf("\033[0m");

                    if (strcmp(cmd_option, "HOME") == 0) // Memeriksa pilihan perintah
                    {
                        system_clear("WIN");
                        loading(35, "WIN");

                        goto home; // Kembali ke menu utama
                    }
                    else if (strcmp(cmd_option, "ESCAPE") == 0)
                    {
                        system_clear("WIN");
                        loading(35, "WIN");

                        goto admin_menu; // Kembali ke menu admin
                    }
                    else
                    {
                        numof_trials++;

                        if (numof_trials < 3) // Memeriksa jumlah percobaan
                        {
                            // Jika pilihan tidak valid, berikan pesan dan beri kesempatan untuk memasukkan lagi
                            option_invalid();

                            goto admin_cmd_option1;
                        }
                        else
                        {
                            // Jika percobaan lebih dari 3, beri pesan dan keluar dari program
                            option_end();

                            timesleep(3, "FALSE", "WIN");
                            system_clear("WIN");

                            return EXIT_FAILURE;
                        }
                    }
                }
            
                else if (option == 2) // Opsi untuk menambah barang
                {

                    // // Menu untuk menambah barang
                    tambah_barang:
                    header();

                    // Meminta input atribut barang dari admin
                    printf("\033[1;33m Masukan Barang");
                    printf("\033[0m");
                    enter(1);

                    tambah_barang();
                    admin_cmd_option2:
                    home_escape();

                    scanf("%s", cmd_option);
                    printf("\033[0m");

                    if (strcmp(cmd_option, "HOME") == 0) // Memeriksa pilihan perintah
                    {
                        system_clear("WIN");
                        loading(35, "WIN");
                        goto home; // Kembali ke menu utama
                    }
                    else if (strcmp(cmd_option, "ESCAPE") == 0)
                    {
                        system_clear("WIN");
                        loading(35, "WIN");
                        goto admin_menu; // Kembali ke menu admin
                    }
                    else
                    {
                        numof_trials++;

                        // Memeriksa jumlah percobaan
                        if (numof_trials < 3)
                        {
                            // Jika pilihan tidak valid, beri pesan dan beri kesempatan untuk memasukkan lagi
                            option_invalid();
                            goto admin_cmd_option2;
                        }
                        else
                        {
                            // Jika percobaan lebih dari 3, beri pesan dan keluar dari program
                            option_end();
                            timesleep(3, "FALSE", "WIN");
                            system_clear("WIN");
                            return EXIT_FAILURE;
                        }
                    }
                }

                else if (option == 3) // Opsi untuk menghapus barang
                {

                    // Menu untuk menghapus barang
                    header(); // Header dan judul untuk opsi penghapusan barang

                    printf("\033[1;33mDelete barang");
                    printf("\033[0m");
                    enter(1);

                    barang barang_array[100];
                    int ukuran_barang = 50;
                    char win_linux[] = "WIN"; // Misalkan sistem operasi yang digunakan adalah Li

                    hapus_barang(data, ukuran_barang,win_linux,"barang.txt");
                

                    // Menu untuk perintah setelah menghapus barang
                    admin_cmd_option3:
                    home_escape();

                    scanf("%s", cmd_option);
                    printf("\033[0m");

                    if (strcmp(cmd_option, "HOME") == 0) // Memeriksa pilihan perintah
                    {
                        system_clear("WIN");
                        loading(35, "WIN");

                        goto home; // Kembali ke menu utama
                    }
                    else if (strcmp(cmd_option, "ESCAPE") == 0)
                    {
                        system_clear("WIN");
                        loading(35, "WIN");

                        goto admin_menu; // Kembali ke menu admin
                    }
                    else
                    {
                        // Memeriksa jumlah percobaan
                        numof_trials++;

                        if (numof_trials < 3)
                        {
                            // Jika pilihan tidak valid, beri pesan dan beri kesempatan untuk memasukkan lagi 
                            option_invalid();

                            goto admin_cmd_option3;
                        }
                        else
                        {
                            // Jika percobaan lebih dari 3, beri pesan dan keluar dari program
                            option_end();

                            timesleep(3, "FALSE", "WIN");
                            system_clear("WIN");

                            return EXIT_FAILURE;
                        }
                    }
                    }
                
                    else
                    {
                    // Reset jumlah percobaan dan ukuran barang
                    numof_trials = 0;
                    ukuran_barang = 0;    
                    barang data[100]; // Asumsi maksimal 100 data barang
                    int ukuran_barang = sizeof(data) / sizeof(data[0]);
                    int jumlah_percobaan = 0;

                    // Menampilkan header dan judul untuk opsi modifikasi barang
                    edit_barang:
                    header();
                    printf("\033[1;33m Modif Barang");
                    printf("\033[0m");
                    enter(1);

                    // Mendapatkan jumlah barang yang tesedia dan menampilkannya
                    ukuran_barang = panjang_barang();
                    edit_barang(data, ukuran_barang, &jumlah_percobaan);

                    // Meminta admin untuk memasukkan ID barang yang ingin dimodifikasi
                    printf("\033[33mEnter barang ID: ");
                    scanf("%u", &id);
                    enter(1);
                    printf("\033[0m");

                    for (int index = 0; index < ukuran_barang; index++)
                    {
                        if (index == (ukuran_barang - 1))
                        {
                            // Jika ID barang tidak ditemukan, berikan pesan dan minta input lagi
                            if (*data[index].id != id)
                            {
                                status_barang("WIN", 2);

                                goto edit_barang;
                            }
                            else
                            {
                                break;
                            }
                        }
                        else
                        {
                            // Memeriksa setiap ID barang dalam daftar barang
                            if (*data[index].id == id)
                            {
                                break;
                            }
                            else
                            {
                                continue;
                            }
                        }
                    }

                    // Memberikan jeda sebelum menampilkan opsi modifikasi barang
                    timesleep(1, "TRUE", "WIN");

                    // Menampilkan opsi untuk memodifikasi barang
                    printf("\033[1;33mOption");
                    printf("\033[0m");
                    enter(1);

                    printf("\033[33m1. ID\n");
                    printf("\033[33m2. Nama Barang\n");
                    printf("\033[33m3. Stok\n");
                    printf("\033[33m4. Harga\n");
                    printf("\033[0m");

                    // Memberikan jarak setelah menampilkan opsi dan membuat garis pemisah
                    enter(21);
                    hyphen("\033[1;33m", 130, 10, "TRUE");

                    modify_options:
                    // Menentukan panjang opsi modifikasi
                    option_length(5);

                    scanf("%d", &option);
                    printf("\033[0m");

                    system_clear("WIN");
                    loading(35, "WIN");

                // Memeriksa pilihan opsi modifikasi
                if (option >= 1 && option <= 5)
                    {
                        // Memanggil fungsi untuk memodifikasi barang
                        edit_barang(data, ukuran_barang, &jumlah_percobaan);
                    }
                    else
                    {
                        // Jika pilihan tidak valid, tingkatkan jumlah percobaan
                        numof_trials++;

                        if (numof_trials < 3)
                        {
                            // Jiika percobaan masih kurang dari 3, beri pesan dan minta input lagi
                            option_invalid();

                            goto modify_options;
                        }
                        else
                        {
                            // Jika percobaan lebih dari 3, beri pesan dan keluar dari program
                            option_end();

                            timesleep(3, "FALSE", "WIN");
                            system_clear("WIN");

                            return EXIT_FAILURE;
                        }
                    }
            
                    // Memberikan jeda setelah proses modifikasi barang dan menampilkan pesan sukses
                    timesleep(1, "FALSE", "WIN");

                    printf("\033[33mBook successfully modified!");
                    printf("\033[0m");
                    // Memberikan jarak setelah pesan sukses dan membuat garis pemisah
                    enter(27);
                    hyphen("\033[1;33m", 130, 10, "TRUE");

                    admin_cmd_option4:
                    // Menu untuk perintah setelah memodifikasi barang
                    home_escape();

                    scanf("%s", cmd_option);
                    printf("\033[0m");

                    if (strcmp(cmd_option, "HOME") == 0) // Memeriksa pilihan perintah
                    {
                        system_clear("WIN");
                        loading(35, "WIN");

                        goto home; // Kembali ke menu utama
                    }
                    else if (strcmp(cmd_option, "ESCAPE") == 0)
                    {
                        system_clear("WIN");
                        loading(35, "WIN");

                        goto admin_menu; // Kembali ke menu admin
                    }
                    else
                    {
                        // Memeriksa jumlah percobaan
                        numof_trials++;

                        if (numof_trials < 3)
                        {
                            // Jika pilihan tidak valid, beri pesan dan beri kesempatan untuk memasukkan lagi
                            option_invalid();

                            goto admin_cmd_option4;
                        }
                        else
                        {
                            // Jika percobaan lebih dari 3 , beri pesan dan keluar dari program
                            option_end();

                            timesleep(3, "FALSE", "WIN");
                            system_clear("WIN");

                            return EXIT_FAILURE;
                        }
                    }
                }
            }

            else if (option == 5) // Opsi untuk kembali ke menu utama
            {
                system_clear("WIN");
                loading(35, "WIN");

                goto home;
            }

            else if (option == 6) // Opsi untuk keluar dari program
            {
                system_clear("WIN");
                loading(35, "WIN");

                goodbye_screen();

                timesleep(2, "FALSE", "WIN");
                system_clear("WIN");

                return EXIT_SUCCESS;
            }
            else
            {
                // Jika pilihan tidak valid, tingkatkan jumlah percobaan
                numof_trials++;

                if (numof_trials < 3)
                {
                    // Jika percobaan masih kurang dari 3, beri pesan dan minta input lagi
                    option_invalid();

                    goto admin_option;
                }
                else
                {
                    // Jika percobaan lebih dari 3, beri pesan dan keluar dari program
                    option_end();

                    timesleep(3, "FALSE", "WIN");
                    system_clear("WIN");

                    return EXIT_FAILURE;
                }
            }
        }
        else
        {
            // Jika opsi yang dimasukkan tidak valid, jumlah percobaan ditingkatkan
            numof_trials++;

            fclose(input_fp);

            system_clear("WIN");
            
            // Jika percobaan masih kurang dari 3
            if (numof_trials < 3)
            {
                // Menampilkan pesan kesalahan login
                login_invalid();

                // Jeda selama 2 detik sebelum membersihkan layar dan kembali ke proses login
                timesleep(2, "FALSE", "WIN");
                system_clear("WIN");

                goto admin_login;
            
            }
            else
            {
                 // Jika percobaan sudah lebih dari 3, menampilkan pesan akhir
                loading(35, "WIN");

                login_end();

                // Jeda selama 3 detik sebelum membersihkan layar dan keluar dari program 
                timesleep(3, "FALSE", "WIN");
                system_clear("WIN");

                return EXIT_FAILURE;
            }
        }
    }
    else if (option == 2)
    {
        // Jika pengguna memilih opsi 2, menginisialisasi ulang jumlah percobaan dan membersihkan layar
        numof_trials = 0;

        system_clear("WIN");
        loading(35, "WIN");

    user_login:
        // Membuka file users.txt untuk dibaca
        input_fp = fopen("users.txt", "r");

        // Memeriksa apakah file berhasil dibuka
        if (input_fp == NULL)
        {
            // Jika file tidak dapat dibuka , menampilkan pesan kesalahan
            printf("\033[33mError! file doesn't exist\n");

            return EXIT_FAILURE;
        }

        // Menampilkan header dan pesan login untuk pengguna
        header();

        printf("\033[1;33mUser log in \n");
        printf("\033[0m");
        printf("\033[33mUser ID\t\t: ");
        scanf("%s", account_id);
        printf("\033[33mPassword\t: ");
        scanf("%s", password);

        // Membaca baris-baris dari file dan memeriksa akun pengguna
        while (fgets(accounts, sizeof(accounts), input_fp) != NULL)
        {
            sscanf(accounts, "\"%[^\"]\" \"%[^\"]\"", account_file, password_file);

            // Memeriksa apakah akun dan kata sandi yang dimasukkan sesuai dengan yang ada di file
            if (strcmp(account_id, account_file) == 0 && strcmp(password, password_file) == 0)
            {
                // Jika cocok, keluar dari loop
                break;
            }
            else
            {
                // Jika tidak cocok, lanjut ke baris berikutnya
                continue;
            }
        }

        // Memberikan jarak sebelum menampilkan garis pemisah
        enter(28);
        hyphen("\033[1;33m", 130, 10, "TRUE");
        printf("\033[0m");

        // Memeriksa apakah akun yang dimasukkan sesuai dengan yang ada di file
        if (strcmp(account_id, account_file) == 0 && strcmp(password, password_file) == 0)
        {
            // Jika sesuai, menginisialisasi ulang jumlah percobaan, menutup file, membersihkan layar, dan menampilkan tampilan loading
            numof_trials = 0;

            fclose(input_fp);

            system_clear("WIN");
            loading(35,"WIN");

        menu_karyawan:
            // Menampilkan header dan menu pengguna
            header();

            menu_karyawan();
            enter(23);

            hyphen("\033[1;33m", 130, 10, "TRUE");

        user_option:
            option_length(6); // Menentukan panjang opsi

            // Membaca opsi yang dimasukkan pengguna
            scanf("%d", &option); 
            printf("\033[0m");

            // Memeriksa apakah opsi yang dimasukan berada dalam rentang yang valid
            if (option >= 1 && option <= 4)
            {
                system_clear("WIN");
                loading(35,"WIN");

                if (option == 1)
                {   
                    
                header();
                pembayaran();

                user_cmd_option1:
                    // Mengatur input dan aksi dari pengguna
                    home_escape();

                    scanf("%s", cmd_option);
                    printf("\033[0m");

                    if (strcmp(cmd_option, "HOME") == 0)
                    {
                        system_clear("WIN");
                        loading(35,"WIN");

                        goto home; // Kembali ke menu utama
                    }
                    else if (strcmp(cmd_option, "ESCAPE") == 0)
                    {
                        system_clear("WIN");
                        loading(35,"WIN");

                        goto menu_karyawan; // Kembali ke menu user
                    }
                    else
                    {
                        // Menangani input yang tidak valid
                        numof_trials++;

                        if (numof_trials < 3)
                        {
                            option_invalid();

                            goto user_cmd_option1;
                        }
                        else
                        {
                            // Jika percobaan melebihi batas, menampilkan pesan dan mengakhiri programnya
                            option_end();

                            timesleep(3, "FALSE", win_linux);
                            system_clear("WIN");

                            return EXIT_FAILURE;
                        }
                    }
                }
                else if (option == 2)
                {
                    // Inisialisasi ulang jumlah percobaan dan variabel yang berhubungan dengan buku
                    numof_trials = 0;
                    ukuran_barang = 0;
                    ukuran_dibeli = 0;

                    // Mendapatkan jumlah buku yang tersedia dan dipinjam oleh user, serta menampilkan daftar pinjaman
                    ukuran_barang = ukuran_daftar_barang();
                    barang_tersedia(data);

                    ukuran_dibeli = panjang_dibeli();
                    karyawan_pembeli(karyawan);

                beli_barangs:
                    // Menampilkan header dan menu peminjaman buku
                    header();

                    printf("\033[1;33m Barang dibeli");
                    printf("\033[0m");
                    enter(1);

                    printf("\033[33mEnter barang ID: ");
                    scanf("%u", &id);
                    enter(1);
                    printf("\033[0m");

                    // Memeriksa apakah buku sudah dipinjam oleh user atau tidak
                    for (int index = 0; index < ukuran_dibeli; index++)
                    {
                        if (index < (ukuran_dibeli - 1))
                        {
                           if ((strcmp(karyawan[index].username, account_id) == 0) && (*karyawan[index].id == id))
                            {
                                // Jika sudah dipinjam, menampilkan pesan dan meminta input lagi
                                status_barang(win_linux, 1);

                                goto beli_barang;
                            }
                            else
                            {
                                continue;
                            }
                        }
                        else
                        {
                            if ((strcmp(karyawan[index].username, account_id) == 0) && (*karyawan[index].id == id))
                            {
                                // Jika sudah dipinjam, menampilkan pesan dan meminta input lagi
                                status_barang(win_linux, 1);

                                goto beli_barang;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }

                    // Memeriksa apakah buku tersedia untuk dipinjam
                    for (int index = 0; index < ukuran_barang; index++)
                    {
                        if (*data[index].id == id)
                        {
                            if (data[index].stok == 0)
                            {
                                // Jika tidak tersedia, menampilkan pesan dan meminta input lagi
                                status_barang(win_linux, 2);

                                goto beli_barang;
                            }
                            else
                            {
                                // Jika tersedia, mengurangi jumlah buku yang tersedia dan menampilkan pesan sukses
                                --(data[index].stok);
                                temp_index = index;

                                timesleep(1, "TRUE", win_linux);

                                printf("\033[33m Barang suskses dibeli!");
                                printf("\033[0m");
                                enter(1);

                                break;
                            }
                        }
                        else if ((index == (ukuran_barang - 1)) && (*data[index].id != id))
                        {
                            // Jika buku tidak ditemukan, menampilkan pesan dan meminta input lagi
                            status_barang(win_linux, 2);

                            goto beli_barang;
                        }
                        else
                        {
                            continue;
                        }
                    }

                    // Menampilkan daftar buku yang baru dipinjam
                    enter(26);
                    hyphen("\033[1;33m", 130, 10, "TRUE");

                    print_newlist(data, account_id, ukuran_barang, temp_index);

                user_cmd_option2:
                    // Mengatur input dan aksi dari pengguna setelah peminjaman buku
                    home_escape();

                    scanf("%s", cmd_option);
                    printf("\033[0m");

                    if (strcmp(cmd_option, "HOME") == 0)
                    {
                        // Kembali ke menu utama
                        system_clear("WIN");
                        loading(35,"WIN");

                        goto home;
                    }
                    else if (strcmp(cmd_option, "ESCAPE") == 0)
                    {
                        // Kembali ke menu pengguna
                        system_clear("WIN");
                        loading(35,"WIN");

                        goto menu_karyawan;
                    }
                    else
                    {
                        // Mengatur input yang tidak valid
                        numof_trials++;

                        if (numof_trials < 3)
                        {
                            option_invalid();

                            goto user_cmd_option2;
                        }
                        else
                        {
                            // Jika percobaan melebihi batas, menampilkan pesan dan mengakhiri program
                            option_end();

                            timesleep(3, "FALSE", win_linux);
                            system_clear("WIN");

                            return EXIT_FAILURE;
                        }
                    }
                }
                else if (option == 3)
                {
                    // Reset jumlah percobaan dan ukuran daftar buku serta daftar buku yang dipinjam
                    numof_trials = 0;
                    ukuran_barang = 0;
                    ukuran_dibeli = 0;

                    // Mengambil ukuran daftar buku yang tersedia dan daftar buku yang dipinjam
                    ukuran_barang = ukuran_daftar_barang();
                    barang_tersedia(data);

                    ukuran_dibeli = panjang_dibeli();
                    karyawan_pembeli(karyawan);

                    // Menampilkan header
                    header();

                    printf("\033[1;33mOn loan (%s)", account_id);
                    printf("\033[0m");
                    enter(1);

                    // Menampilkan daftar buku yang sedang dipinjam oleh pengguna
                    printf("\033[33m");
                    table_border("TRUE");
                    int index = 0; // Misalkan index adalah 0
                    printf("| %-5s | %-47s | %-11u | %-11u |\n", data[index].id, data[index].nama, data[index].harga, data[index].stok);
                    table_border("TRUE");
                    printf("\033[0m");

                    // Menampilkan detail setiap buku yang dipinjam
                    for (int karyawan_index = 0; karyawan_index < ukuran_dibeli; karyawan_index++)
                    {
                        int num_barang = 3;
                        for (int i = 0; i < num_barang; i++) 
                        {
                            unsigned int index = 0;
                        
                          if (karyawan[karyawan_index].id == data[i].id)
                            {
                              baris_tabel_dibeli(data, i);

                                table_border("TRUE");
                                printf("\033[0m");
                            }
                            else
                            {
                                continue;
                            }
                        }
                    }

                    // Menghitung jumlah ruang kosong untuk keseimbangan tata letak
                    int free_space = ukuran_dibeli * 2;

                    enter(35 - free_space - 9);
                    hyphen("\033[1;33m", 130, 10, "TRUE");

                user_cmd_option3:
                    // Mengatur input dan aksi dari pengguna setelah menampilkan daftar buku yang dipinjam
                    home_escape();

                    scanf("%s", cmd_option);
                    printf("\033[0m");

                    if (strcmp(cmd_option, "HOME") == 0)
                    {
                        // Kembali ke menu utama
                        system_clear("WIN");
                        loading(35,"WIN");

                        goto home;
                    }
                    else if (strcmp(cmd_option, "ESCAPE") == 0)
                    {
                        // Kembali ke menu user
                        system_clear("WIN");
                        loading(35,"WIN");

                        goto menu_karyawan;
                    }
                    else
                    {
                        // Mengatur input yang tidak valid
                        numof_trials++;

                        if (numof_trials < 3)
                        {
                            option_invalid();

                            goto user_cmd_option3;
                        }
                        else
                        {
                            // Jika percobaan melebihi batas, menampilkan pesan dan mengakhiri program
                            option_end();

                            timesleep(3, "FALSE", win_linux);
                            system_clear("WIN");

                            return EXIT_FAILURE;
                        }
                    }
                }
                else
                {
                    // Jika opsi yang dimasukkan tidak valid, reset jumlah percobaan dan ukuran daftar bukku serta daftar buku yang dipinjam
                    numof_trials = 0;
                    ukuran_barang = 0;
                    ukuran_dibeli = 0;

                    // Mengambil ukuran daftar buku yang tersedia dan daftar buku yang dipinjam
                    ukuran_barang = ukuran_daftar_barang();
                    barang_tersedia(data);

                    ukuran_dibeli = panjang_dibeli();
                    karyawan_pembeli(karyawan);

                return_barangs:
                    // Menampilkan header untuk menu pengembalian buku
                    header();

                    printf("\033[1;33mReturn barang");
                    printf("\033[0m");
                    enter(1);

                    // Meminta pengguna untuk memasukkan ID buku yang akan dikemablikan
                    printf("\033[33mEnter barang ID: ");
                    scanf("%u", &id);
                    enter(1);
                    printf("\033[0m");

                    // Mengecek apakah pengguna memeiliki buyku yang sedang dipinjam
                    for (int index = 0; index < ukuran_dibeli; index++)
                    {
                        if (index == (ukuran_dibeli - 1))
                        {
                            if ((strcmp(karyawan[index].username, account_id) == 0) && (*karyawan[index].id != id))
                            {
                                // Menampilkan pesan jika buku tidak ditemukan dalam daftar yang sedang dipinjam
                                status_barang(win_linux, 2);

                                goto return_barangs;
                            }
                            else
                            {
                                break;
                            }
                        }
                        else
                        {
                            if ((strcmp(karyawan[index].username, account_id) == 0) && (*karyawan[index].id == id))
                            {
                                break;
                            }
                            else
                            {
                                continue;
                            }
                        }
                    }

                    // Mencari buku yang akan dikemablikan dalam daftar buku yang tersedia
                    for (int index = 0; index < ukuran_barang; index++)
                    {
                       if (*data[index].id == id)
                        {
                            // Menampilkan pesan bahwa buku berhasil dikembalikan dan meningkatkan jumlah buku yang tersedia
                            timesleep(1, "TRUE", win_linux);

                            printf("\033[33mBook successfully returned!");
                            printf("\033[0m");
                            enter(1);

                            data[index].stok++;
                        }
                    }

                    // Menampilkan daftar buku yang tersedia seteleha pengembalian
                    tampilkan_barang(data, ukuran_barang);
                    // Memperbarui daftar peminjaman setelah pengembalian
                    print_dibeli(karyawan, ukuran_dibeli, id);
                    

                    // Menambahkan spasi dan garis pemisah
                    enter(26);
                    hyphen("\033[1;33m", 130, 10, "TRUE");

                user_cmd_option4:
                    // Mengatur input dan aksi dari pengguna setelah melakukan pengembalian buku
                    home_escape();

                    scanf("%s", cmd_option);
                    printf("\033[0m");

                    if (strcmp(cmd_option, "HOME") == 0)
                    {
                        // Kembali ke menu utama
                        system_clear("WIN");
                        loading(35,"WIN");

                        goto home;
                    }
                    else if (strcmp(cmd_option, "ESCAPE") == 0)
                    {
                        // Kembali ke menu user
                        system_clear("WIN");
                        loading(35,"WIN");

                        goto menu_karyawan;
                    }
                    else
                    {
                        // Mengatur input yang tidak valid
                        numof_trials++;

                        if (numof_trials < 3)
                        {
                            option_invalid();

                            goto user_cmd_option4;
                        }
                        else
                        {
                            // Jika percobaan melebihi batas, menampilkan pesan dan mengakhiri program
                            option_end();

                            timesleep(3, "FALSE", win_linux);
                            system_clear("WIN");

                            return EXIT_FAILURE;
                        }
                    }
                }
            }
            else if (option == 5) // Opsi untuk kembali ke menu utama
            {
                system_clear("WIN");
                loading(35,"WIN");

                goto home;
            }
            else if (option == 6) // Opsi untuk mengakhiri program
            {
                system_clear("WIN");
                loading(35,"WIN");

                goodbye_screen();

                timesleep(2, "FALSE", win_linux);
                system_clear("WIN");

                return EXIT_SUCCESS;
            }
            else
            {
                // Mengatur opsi yang tidak valid
                numof_trials++;

                if (numof_trials < 3)
                {
                    option_invalid();

                    goto user_option;
                }
                else
                {
                    // Jika percobaan melebihi batas, menampilkan pesan dan mengakhiri program
                    option_end();

                    timesleep(3, "FALSE", win_linux);
                    system_clear("WIN");

                    return EXIT_FAILURE;
                }
            }
        }
        else
        {
            // Mengatur jika opsi tidak valid
            numof_trials++;

            fclose(input_fp);

            system_clear("WIN");

            if (numof_trials < 3)
            {
                // Menampilkan pesan bahwa login tidak valid dan meminta masukan kembali
                login_invalid();

                timesleep(2, "FALSE", win_linux);
                system_clear("WIN");

                goto user_login;
            }
            else
            {
                // Jika percobaan melebihi batas, menampilkan pesan dan mengakhiri program
                loading(35,"WIN");

                login_end();

                timesleep(3, "FALSE", win_linux);
                system_clear("WIN");

                return EXIT_FAILURE;
            }
        }
    }
    else if (option == 3)
    {
        // Reset nilai percobaan dan menampilkan menu utama
        int indicator;
        numof_trials = 0;

        system_clear("WIN");
        loading(35,"WIN");

    create_account:
        // Membuka file untuk dibaca
        input_fp = fopen("users.txt", "r");

        // Memeriksa apakah file berhasil dibuka
        if (input_fp == NULL)
        {
            // Menampilkan pesan error jika file tidak dapat dibuka
            printf("\033[33mError! file doesn't exist\n");

            return EXIT_FAILURE;
        }

        // Menampilkan header dan meminta input ID pengguna dan kata sandi baru
        header();

        printf("\033[1;33mCreate new account (User)\n");
        printf("\033[0m");
        printf("\033[33mUser ID\t\t: ");
        scanf("%s", account_id);
        printf("\033[33mPassword\t: ");
        scanf("%s", password);

        // Membaca setiap baris dari file pengguna
        while (fgets(accounts, sizeof(accounts), input_fp) != NULL)
        {
            sscanf(accounts, "\"%[^\"]\" \"%[^\"]\"", account_file, password_file);

            // Memeriksa apakah ID pengguna sudah ada dalam file
            if (strcmp(account_id, account_file) == 0)
            {
                // Jika ID pengguna sudah ada, indikator menjadi 1 dan hentikan pencarian
                indicator = 1;

                break;
            }
            else
            {
                // Jika ID pengguna belum ada, indikator menjadi 0 dan lanjutkan pencarian
                indicator = 0;

                continue;
            }
        }

        // Memeriksa nilai indikator
        if (indicator != 1)
        {
            // Jika ID pengguna belum ada dalam file
            fclose(input_fp);

            // Membuka file untuk menulis dan menambahkan ID pengguna baru
            output_fp = fopen("users.txt", "a");

            fprintf(output_fp, "\n\"%s\" \"%s\"", account_id, password);

            fclose(output_fp);

            // Membersihkan layar, menampilkan pesan sukses, dan kembali ke menu utama
            system_clear("WIN");
            loading(35,"WIN");
            newacc_success();

            timesleep(2, "FALSE", win_linux);
            system_clear("WIN");

            goto home;
        }
        else
        {
            // Jika ID pengguna sudah ada dalam file
            numof_trials++;

            fclose(input_fp);


            system_clear("WIN");

            if (numof_trials < 3)
            {
                // Menampilkan pesan kesalahan dan meminta input baru jika percobaan masih dalam batas
                newacc_invalid();

                timesleep(2, "FALSE", win_linux);
                system_clear("WIN");

                goto create_account;
            }
            else
            {
                // Menampilkan pesan bahwa pembuatan akun baru gagal dan mengakhiri program
                loading(35,"WIN");

                newacc_end();

                timesleep(3, "FALSE", win_linux);
                system_clear("WIN");

                return EXIT_FAILURE;
            }
        }
    }
    
    else if (option == 4)
    {
        // Membersihkan layar, menampilkan layar selamat tinggal, dan keluar dari program
        system_clear("WIN");
        loading(35, "WIN");

        goodbye_screen();

        timesleep(2, "FALSE", "WIN");
        system_clear("WIN");

        return EXIT_SUCCESS;
    }
    else
    {
        // Jika opsi tidak valid, menambah jumlah percobaan dan memeriksa jumlah percobaan
        numof_trials++;

        if (numof_trials < 3)
        {
            // Jika jumlah percobaan masih dalam batas, menampilkan pesan kesalahan dan kembali ke opsi
            option_invalid();

            goto option;
        }
        else
        {
            // Jika jumlah percobaan sudah melewati batas, menampilkan pesan akhir dan keluar dari program
            option_end();

            timesleep(3, "FALSE", "WIN");
            system_clear("WIN");

            return EXIT_FAILURE;
        }
    }
    

    // Menutup file input dan output
    fclose(input_fp);
    fclose(output_fp);

    return EXIT_SUCCESS;  
}