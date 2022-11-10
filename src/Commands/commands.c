// Isi-isi commands ada disini yah

// START
#include "mesinkata.h"
#include <stdio.h>
#include <stdlib.h>

void start()
{
    STARTGAME("config.txt");
    STARTWORD();
    while (&currentWord != "START")
    {
        printf("Input Tidak Valid");
        printf("\n");
        STARTWORD();
    }
    // Keluar loop, masuk ke command - command lain
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.");
    ADVWORD();
    if (&currentWord == "LOAD")
    {
        load();
    }
    else
    {
        commandLain();
    }
}

void load()
{

}

void create() {

}

void list() {

}

void delete() {

}

void queue() {

}

void play() {

}

void skip(int n) {
    
}

void quit() {
    printf(" Anda keluar dari game BNMO");
    printf("Bye Bye ^U^");
    exit;
}

void help()
{
    printf("BANTUAN\n");
    printf("1. START\n");
    printf("    Di dalam file 'config.txt' pada line pertama, tuliskan 'START' tanpa tanda kutip satu, lalu jalankan program.");
    printf("\n");
    printf("2. LOAD\n");
    printf("    Untuk menjalankan command LOAD, di dalam file 'config.txt' pada line berikutnya, tuliskan 'LOAD <namafile.txt>' tanpa tanda kutip satu, lalu jalankan program.");
    printf("\n");

}

void commandLain()
{
    // COMMAND yang gajelas masuk ke sini
    printf("Command tidak dikenali, silahkan masukkan command yang valid.");
    printf("\n");
    printf("Jika membutuhkan bantuan, gunakan fungsi 'HELP' tanpa tanda kutip satu.");
}