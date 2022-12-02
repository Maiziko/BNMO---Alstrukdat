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
/*****************************************************************Fungsi SAVE & LOAD **********************************************/

// ngambil kata sebelum spasi
Word copyword(Word CCommand)
{
    int i = 0;
    Word tempword;
    tempword.Length = 0;
    while (i < CCommand.Length && CCommand.TabWord[i] != ' ')
    {
        tempword.TabWord[i] = CCommand.TabWord[i];
        tempword.Length++;
        i++;
    }
    return tempword;
}

Word readfilename(Word currentWord)
{
    int i = 0;
    int n = 0;
    Word tempword;
    tempword.Length = 0;
    while (i < CCommand.Length && CCommand.TabWord[i] != ' ')
    {
        i++;
    }
    i++;
    while (i < CCommand.Length && CCommand.TabWord[i] != '\n')
    {
        tempword.TabWord[n] = CCommand.TabWord[i];
        tempword.Length++;
        i++;
        n++;
    }
    return tempword;
}

/* *** ******* ******* ******* ******** ******* ******** Program Utama ******* ******** *** ******* ******* ******* ******** */
int main()
{
    ArrayDin gamefile = MakeArrayDin();
    ArrayData dataplayer = MakeArrayData();
    History history;
    CreateHistory(&history);

    // HELP();
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
<<<<<<< HEAD
        Load(readfilename(CCommand),gamefile,dataplayer,history);
=======
        Load(readfilename(CCommand), gamefile, dataplayer, history);
        for (int i = 0; i < gamefile.Neff; i++)
        {
            PrintWord(gamefile.A[i]);
        }
>>>>>>> 5f9873e375ae1c90d2a84661b3e20bed7cb19ca3
    }
}