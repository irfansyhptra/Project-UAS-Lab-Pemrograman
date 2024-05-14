CC = gcc
CFLAGS = -Wall -Werror -std=c99

SOURCES = main.c baca_data_barang2.c tampilkan_daftar_barang.c baca_data_barang.c kurangi_barang.c tambah_barang.c pembayaran.c lihat_riwayat_transaksi.c tambah_transaksi.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = main

main :
	gcc -o output kurangi_barang.c daftar_barang.c tambah_barang.c main.c
	./output

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
	
