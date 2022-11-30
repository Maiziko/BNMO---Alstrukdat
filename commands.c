#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* *** ******* ******* ******* ******** ******* ******** File Header ******* ******** *** ******* ******* ******* ******** */

#include "src/ADT/mesinkata/mesinkata.h"
#include "src/ADT/mesinkarakter/mesinkarakter.h"
#include "src/ADT/queue/queue.h"
#include "src/ADT/arraydin/arraydin.h"
#include "src/ADT/stack/stack.h"
#include "src/ADT/SaveLoad/load.h"
#include "src/ADT/SaveLoad/save.h"
#include "src/Game/TowerOfHanoi/towerofhanoi.h"
#include "src/Game/RNG/RNG.h"
#include "src/Game/SnakeOnMeteor/snakeonmeteor.h"
#include "src/ADT/map/map.h"
// #include "src/Game/HANGMAN/hangman.h"
#include "src/Game/GameBuatan/gamebuatan.h"
// #include "src/Game/DinnerDash/Dinner_Dash.h"

/*
START
LOAD
SAVE
LIST GAME
DELETE GAME
CREATE GAME
QUEUE GAME
PLAY GAME
SKIPGAME
HELP
QUIT
*/

void listGame(ArrayDin file) {
    printf("\n");
    printf("+========================================================================================+\n");
    printf("|                                      LIST GAMEMU {^-^}                                 |\n");
    printf("+========================================================================================+\n");
    printf("\n");
    printf("Berikut adalah daftar game yang tersedia\n");
    printf("\n");
    printf("================================================\n");
    printf("\n");
    ListGame(file);
    printf("\n");
    printf("================================================\n");
    printf("\n");
}

ArrayDin deleteGame(ArrayDin file, Word kata, Word CCommand) {
    printf("\n");
    printf("+========================================================================================+\n");
    printf("|                                      LIST GAMEMU {^-^}                                 |\n");
    printf("+========================================================================================+\n");
    printf("\n");
    printf("Berikut adalah daftar game yang tersedia\n");
    printf("\n");
    printf("================================================\n");
    printf("\n");
    ListGame(file);
    printf("\n");
    printf("================================================\n");
    printf("\n");
    printf("Masukkan nomor game yang akan dihapus: ");
    STARTCOMMAND();
    int k = toInteger(CCommand);
    if (k < file.Neff)
    {
        wordStringCopy(kata, file.A[k]);
        if (k >= 10)
        {
            DeleteAt(&file, k);
            printf("\n");
            printf("Game %s Berhasil Dihapus\n", kata);
            printf("\n");
        }
        else
        {
            printf("\n");
            printf("Game %s Gagal Dihapus, karena game ini milik sistem T_T .\n", kata);
            printf("\n");
        }
    }
    else
    {
        printf("\n");
        printf("NOMOR GAME YANG KAMU MASUKKAN TIDAK VALID T_T\n");
        printf("\n");
    }
}