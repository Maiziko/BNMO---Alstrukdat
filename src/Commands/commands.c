// Isi-isi commands ada disini yah

// START
#include "mesinkata.h"

void start()
{
    STARTGAME("config.txt");
    char state = CCommand.Length;
    STARTWORD();
    while (&currentWord != "START")
    {
        printf("Input Tidak Valid");
        printf("\n");
        STARTWORD();
    }
    // Keluar loop, masuk ke command - command lain
    load();
}

void load()
{

}

void help()
{
    printf("BANTUAN\n");
    printf("1. START\n");
    printf("");

}