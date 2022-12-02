/* *** ******* ******* ******* ******** ******* ******** KELOMPOK 04 ******* ******** *** ******* ******* ******* ******** */
/* 18221007 Nurshafa Qanita */
/* 18221008 Gyan Maiziko */
/* 18221018 Jennifer Grachel A */
/* 18221019 Anindita Putri Paramarta */
/* 18221011 Muhammad Rifky Fahrizain */

/* *** ******* ******* ******* ******** ******* ******** Library yang Digunakan ******* ******** *** ******* ******* ******* ******** */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* *** ******* ******* ******* ******** ******* ******** File Header ******* ******** *** ******* ******* ******* ******** */

#include "src/ADT/mesinkata/mesinkata.c"
#include "src/ADT/mesinkarakter/mesinkarakter.c"
#include "src/ADT/queue/queue.c"
#include "src/ADT/arraydin/arraydin.c"
#include "src/ADT/stack/stack.c"
#include "src/ADT/SaveLoad/load.c"
#include "src/ADT/SaveLoad/save.c"
// #include "src/Game/TowerOfHanoi/towerofhanoi.c"
// #include "src/Game/RNG/RNG.c"
// #include "src/Game/SnakeOnMeteor/snakeonmeteor.c"
#include "src/ADT/map/map.c"
// #include "src/ADT/set/set.c"
// #include "src/Game/Hangman/Hangman.c"
// #include "src/Game/GameBuatan/gamebuatan.c"
// #include "src/Game/DinnerDash/Dinner_Dash.c"
// fungsi pembantu ;

/* *** ******* ******* ******* ******** ******* ******** Program Utama ******* ******** *** ******* ******* ******* ******** */
int main()
{
    ArrayDin file = MakeArrayDin();
    ArrayData dataplayer = MakeArrayData();
    History history; CreateHistory(&history);

    printf("\n");
    printf("SILAHKAN  MASUKKAN  COMMAND (START/LOAD <namafile.txt>) : ");
    STARTCOMMAND();
    Word tempword = copyword(CCommand);

    if (IsKataSama(tempword, toKata("START")))
    {
        printf("p");
    }

    else
    {
        while (!IsKataSama(tempword, toKata("LOAD")))
        {
            printf("\nMasukkan salah!\n");
            printf("SILAHKAN  MASUKKAN  COMMAND (START/LOAD <namafile.txt>) : ");
            STARTCOMMAND();
            tempword = copyword(CCommand);
        }
        Load(readfilename(CCommand), file, dataplayer, history);
        printf("\n%d\n", file.Neff);
        printf("%d\n", dataplayer.Neff);
        printf("%d", history.idxTop);
    }
}