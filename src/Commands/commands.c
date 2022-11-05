// Isi-isi commands ada disini yah

// START
#include "mesinkata.h"

void start()
{
    STARTWORD();
    while (&currentWord != "START")
    {
        printf("Input Tidak Valid");
        printf("\n");
    }
    // Keluar loop, masuk ke command - command lain
    load();
}

void load()
{

}