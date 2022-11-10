// Isi-isi commands ada disini yah

// START
#include "mesinkata.h"

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
    ADVWORD();
    if (&currentWord == "LOAD")
    {
        load();
    }
    
}

void load()
{

}

void help()
{
    printf("BANTUAN\n");
    printf("1. START\n");
    printf("    Di dalam file 'config.txt' pada line pertama, tuliskan 'START' tanpa tanda kutip satu, lalu jalankan program.");
    printf("\n");
    printf("2. LOAD\n");

}