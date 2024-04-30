#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur data untuk menyimpan informasi barang
typedef struct {
    char name[100];
    int quantity;
    double price;
} Item;

// Fungsi untuk menambahkan barang ke toko
void addItem(Item* items, int* itemCount) {
    Item newItem;
    printf("Enter the name of the item: ");
    scanf("%s", newItem.name);
    printf("Enter the quantity of the item: ");
    scanf("%d", &newItem.quantity);
    printf("Enter the price of the item: ");
    scanf("%lf", &newItem.price);
    items[*itemCount] = newItem;
    (*itemCount)++;
    printf("Item added successfully!\n");
}

// Fungsi untuk mengurangi barang dari toko
void removeItem(Item* items, int* itemCount) {
    int index;
    printf("Enter the index of the item to remove: ");
    scanf("%d", &index);
    if (index >= 0 && index < *itemCount) {
        for (int i = index; i < (*itemCount) - 1; i++) {
            items[i] = items[i + 1];
        }
        (*itemCount)--;
        printf("Item removed successfully!\n");
    } else {
        printf("Invalid index!\n");
    }
}

// Fungsi untuk melihat daftar barang
void viewItems(Item* items, int itemCount) {
    printf("Item List:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d. %s - Quantity: %d, Price: %.2lf\n", i + 1, items[i].name, items[i].quantity, items[i].price);
    }
}

// Fungsi untuk melakukan pembayaran
void makePayment(Item* items, int itemCount) {
    double total = 0;
    printf("Item List:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d. %s - Quantity: %d, Price: %.2lf\n", i + 1, items[i].name, items[i].quantity, items[i].price);
        total += items[i].quantity * items[i].price;
    }
    printf("Total payment: %.2lf\n", total);
}

// Fungsi untuk login
int login() {
    char username[100], password[100];
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);
    // Lakukan validasi login sesuai dengan kebutuhan Anda
    if (strcmp(username, "admin") == 0 && strcmp(password, "admin123") == 0) {
        printf("Login successful!\n");
        return 1; // Jika login berhasil
    } else {
        printf("Invalid username or password!\n");
        return 0; // Jika login gagal
    }
}

int main() {
    Item items[100]; // Batasi jumlah barang yang dapat disimpan
    int itemCount = 0;
    int loggedIn = 0;

    loggedIn = login();
    if (loggedIn) {
        int choice;
        while (1) {
            printf("\n===== Kasir Sederhana =====\n");
            printf("1. Add item\n");
            printf("2. Remove item\n");
            printf("3. View item list\n");
            printf("4. Make payment\n");
            printf("5. Logout\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    addItem(items, &itemCount);
                    break;
                case 2:
                    removeItem(items, &itemCount);
                    break;
                case 3:
                    viewItems(items, itemCount);
                    break;
                case 4:
                    makePayment(items, itemCount);
                    break;
                case 5:
                    printf("Logged out!\n");
                    loggedIn = 0;
                    break;
                default:
                    printf("Invalid choice!\n");
                    break;
            }

            if (!loggedIn) {
                break; // Keluar dari loop jika telah logout
            }
        }
    }

    return 0;
}