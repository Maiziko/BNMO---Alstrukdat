// Isi-isi commands ada disini yah

// START
#include "mesinkata.h"

void start()
{
    STARTGAME("stdin");
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