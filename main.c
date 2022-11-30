/* *** ******* ******* ******* ******** ******* ******** KELOMPOK 04 ******* ******** *** ******* ******* ******* ******** */
/* 18221007 Nurshafa Qonita */
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
#include "src/Game/HANGMAN/hangman.h"
#include "src/Game/GameBuatan/gamebuatan.h"
#include "src/Game/DinnerDash/Dinner_Dash.h"
// fungsi pembantu ;
/*****************************************************************Fungsi SAVE & LOAD **********************************************/

/* *** ******* ******* ******* ******** ******* ******** Program Utama ******* ******** *** ******* ******* ******* ******** */
int main()
{
    system("cls");
    printf("\t \t +===============================================================================================================+\n");
    printf("\n");
    printf(" \t \t | \t \t \t \t BBBBBBBBBBBBBB        NNNNNNNNNN            NNNNNNNN \t \t \t \t | \n");
    printf(" \t \t | \t \t \t \t BBBBBBBBBBBBBBBBB     NNNNNNNNNNNN           NNNNNN  \t \t \t \t | \n");
    printf(" \t \t | \t \t \t \t BBBBBB     BBBBBBBB   NNNNNN NNNNNNN         NNNNNN  \t \t \t \t | \n");
    printf(" \t \t | \t \t \t \t BBBBBB      BBBBBBB   NNNNNN  NNNNNNN        NNNNNN  \t \t \t \t | \n");
    printf(" \t \t | \t \t \t \t BBBBBB      BBBBBBB   NNNNNN   NNNNNNN       NNNNNN  \t \t \t \t | \n");
    printf(" \t \t | \t \t \t \t BBBBBB     BBBBBBB    NNNNNN    NNNNNNN      NNNNNN  \t \t \t \t | \n");
    printf(" \t \t | \t \t \t \t BBBBBBBBBBBBBBB       NNNNNN     NNNNNNN     NNNNNN  \t \t \t \t | \n");
    printf(" \t \t | \t \t \t \t BBBBBBBBBBBBBBB       NNNNNN      NNNNNNN    NNNNNN  \t \t \t \t | \n");
    printf(" \t \t | \t \t \t \t BBBBBB     BBBBBBB    NNNNNN       NNNNNNN   NNNNNN  \t \t \t \t | \n");
    printf(" \t \t | \t \t \t \t BBBBBB      BBBBBBB   NNNNNN        NNNNNNN  NNNNNN  \t \t \t \t | \n");
    printf(" \t \t | \t \t \t \t BBBBBB      BBBBBBB   NNNNNN         NNNNNNN NNNNNN  \t \t \t \t | \n");
    printf(" \t \t | \t \t \t \t BBBBBB     BBBBBBBB   NNNNNN          NNNNNNNNNNNNN  \t \t \t \t | \n");
    printf(" \t \t | \t \t \t \t BBBBBBBBBBBBBBBBB     NNNNNN           NNNNNNNNNNNN  \t \t \t \t | \n");
    printf(" \t \t | \t \t \t \t BBBBBBBBBBBBBB       NNNNNNNN           NNNNNNNNNNN  \t \t \t \t | \n");
    printf("  \n");
    printf(" \t \t | \t \t \t \t MMMMMMMMM         MMMMMMMMMM       OOOOOOOOOOOOO     \t \t \t \t | \n");
    printf(" \t \t | \t \t \t \t MMMMMMMMMM       MMMMMMMMMMM     OOOOOOOOOOOOOOOOO   \t \t \t \t | \n");
    printf(" \t \t | \t \t \t \t MMMMMMMMMMMM    MMMMMMMMMMMM    OOOOOO       OOOOOO  \t \t \t \t | \n");
    printf(" \t \t | \t \t \t \t MMMMMM MMMMMM  MMMMMMM MMMMM   OOOOOO         OOOOOO \t \t \t \t | \n");
    printf(" \t \t | \t \t \t \t MMMMMM  MMMMMMMMMMMM  MMMMMM   OOOOOO         OOOOOO \t \t \t \t | \n");
    printf(" \t \t | \t \t \t \t MMMMMM   MMMMMMMMMM   MMMMMM   OOOOOO         OOOOOO \t \t \t \t | \n");
    printf(" \t \t | \t \t \t \t MMMMMM                MMMMMM   OOOOOO         OOOOOO \t \t \t \t | \n");
    printf(" \t \t | \t \t \t \t MMMMMM                MMMMMM   OOOOOO         OOOOOO \t \t \t \t | \n");
    printf(" \t \t | \t \t \t \t MMMMMM                MMMMMM   OOOOOO         OOOOOO \t \t \t \t | \n");
    printf(" \t \t | \t \t \t \t MMMMMM                MMMMMM   OOOOOOO       OOOOOOO \t \t \t \t | \n");
    printf(" \t \t | \t \t \t \t MMMMMM                MMMMMM    OOOOOOOOOOOOOOOOOOO  \t \t \t \t | \n");
    printf(" \t \t | \t \t \t \t MMMMMM                MMMMMM      OOOOOOOOOOOOOOO    \t \t \t \t | \n");
    printf("\n");
    printf("\t \t +===============================================================================================================+\n");
    printf("\t \t |----- Kelas K3 ---------------- IF2111 Algoritma dan Struktur Data STI ----------- Kelompok 4 -----------------|\n");
    printf("\t \t +===============================================================================================================+\n");
    printf("\n");
    printf("\t \t \t +==========================================================================================+\n");
    printf("\t \t \t |                   S E L A M A T   D A T A N G   D I  M E S I N  B N M O                  |\n");
    printf("\t \t \t +==========================================================================================+\n");
    printf("\n");
    printf("\t +====================================================================================================================================+\n");
    printf("\t | B E R I K U T  B E B E R A P A  P A N D U A N   P E R M A I N A N  G A M E   Y A N G   T E R D A P A T   D I   M E S I N   B N M O |\n");
    printf("\t +====================================================================================================================================+\n");
    printf("\n");
    HELP();
    printf("\n");
    printf("SILAHKAN  MASUKKAN  COMMAND (START/LOAD <namafile.txt>) :  ");
    STARTCOMMAND();
    system("cls");

    char namafile[100];
    char nas[100];
    char nas1[100];
    char kata[100];
    char kata1[100];
    char num[10];
    char nummm[10];
    char namagame[50];
    int l = 0;
    int temp = 0;
    ArrayDin file = MakeArrayDin();
    Queue Game;
    CreateQueue(&Game);
    History History;
    CreateHistory(&History);
    int skip = 0;
    int i = 0;
    int j = 0;
    for (j = 0; j < 4; j++)
    {
        nas[j] = CCommand.TabWord[j];
    }
    nas[j] = '\0';

    for (j = 0; j < CCommand.Length; j++)
    {
        namafile[j] = CCommand.TabWord[j + 5];
    }
    namafile[j] = '\0';

    for (j = 0; j < CCommand.Length; j++)
    {
        nas1[j] = CCommand.TabWord[j + 5];
    }
    nas1[j] = '\0';

    /* *** ******* ******* ******* ******** ******* ******** Ketika Inputan Tidak sesuai dengan yang diminta saat pertama program dijalankan ******* ******** *** ******* ******* ******* ******** */
    while ((!IsKataSama(toKata(nas), toKata("LOAD")) && !IsKataSama(CCommand, toKata("START"))))
    {

        printf("\n");
        printf("COMMAND KAMU TIDAK VALID T_T !!!\n");
        printf("\n");
        printf("SILAHKAN  MASUKKAN  COMMAND (START/LOAD <namafile.txt>) : ");
        STARTCOMMAND();
        system("cls");

        for (j = 0; j < 4; j++)
        {
            nas[j] = CCommand.TabWord[j];
        }
        nas[j] = '\0';
    }

    /* *** ******* ******* ******* ******** ******* ******** Ketika Command LOAD di Input ******* ******** *** ******* ******* ******* ******** */
    if ((IsKataSama(toKata(nas), toKata("LOAD"))))
    {
        file = Load(CCommand);

        while (IsKataSama(toKata(namafile), toKata(namafile)) && file.Neff == 0)
        {
            printf("\n");
            printf("File %s tidak ditemukan\n", namafile);
            printf("\n");
            printf("SILAHKAN  MASUKKAN  COMMAND (START/LOAD <namafile.txt>) : ");
            STARTCOMMAND();
            system("cls");
            for (j = 0; j < CCommand.Length; j++)
            {
                namafile[j] = CCommand.TabWord[j + 5];
            }
            namafile[j] = '\0';

            file = Load(CCommand);
        }
        if (IsKataSama(toKata(namafile), toKata(namafile)) && file.Neff != 0)
        {
            file = Load(CCommand);
            printf("\n");
            printf("+==================================================================+\n");
            printf("| SAVE %s BERHASIL DIBACA, BNMO BERHASIL DIJALANKAN {^-^} |\n", namafile);
            printf("+==================================================================+\n");
            printf("\n");
        }
    }

    /* *** ******* ******* ******* ******** ******* ******** Ketika Command START ******* ******** *** ******* ******* ******* ******** */
    else if (IsKataSama(CCommand, toKata("START")))
    {
        int i = 0;
        STARTGAME("Data/config.txt");
        while (!EndWord)
        {
            for (int j = 0; j < currentWord.Length; j++)
            {
                file.A[i].TabWord[j] = currentWord.TabWord[j];
            }
            file.A[i].Length = currentWord.Length;
            ADVWORD();
            i++;
        }
        file.Neff = i;
        printf("\n");
        printf("+================================================================+\n");
        printf("|    BERHASIL  MENJALANKAN BNMO  DAN MEMBACA FILE KONFIGURASI    |\n");
        printf("+================================================================+\n");
        printf("\n");
    }

    /* *** ******* ******* ******* ******** ******* ******** Ketika Command belum sama dengan QUIT ******* ******** *** ******* ******* ******* ******** */

    while (!IsKataSama(CCommand, toKata("QUIT")))
    {
        printf("SILAHKAN  MASUKKAN  COMMAND  \n");
        printf("ENTER COMMAND : ");
        STARTCOMMAND();
        system("cls");
        for (i = 0; i < CCommand.Length; i++)
        {
            kata1[i] = CCommand.TabWord[i];
        }
        kata1[i] = '\0';

        for (i = 0; i < 8; i++)
        {
            num[i] = kata1[i];
        }
        num[i] = '\0';

        for (i = 0; i < 1; i++)
        {
            nummm[i] = kata1[i + 9];
        }
        nummm[i] = '\0';
        for (j = 0; j < 4; j++)
        {
            nas[j] = CCommand.TabWord[j];
        }
        nas[j] = '\0';

        for (j = 0; j < CCommand.Length; j++)
        {
            namafile[j] = CCommand.TabWord[j + 5];
        }
        namafile[j] = '\0';
        for (j = 0; j < CCommand.Length; j++)
        {
            nas1[j] = CCommand.TabWord[j + 5];
        }
        nas1[j] = '\0';

        /* *** ******* ******* ******* ******** ******* ******** LIST GAME ******* ******** *** ******* ******* ******* ******** */

        if (IsKataSama(CCommand, toKata("LIST GAME")))
        {
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

        /* *** ******* ******* ******* ******** ******* ******** DELETE GAME ******* ******** *** ******* ******* ******* ******** */
        else if (IsKataSama(CCommand, toKata("DELETE GAME")))
        {
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

        /* *** ******* ******* ******* ******** ******* ******** CREATE GAME ******* ******** *** ******* ******* ******* ******** */
        else if (IsKataSama(CCommand, toKata("CREATE GAME")))
        {
            printf("\n");
            printf("Masukkan nama game yang akan ditambahkan: ");
            STARTCOMMAND();
            for (i = 0; i < CCommand.Length; i++)
            {
                namagame[i] = CCommand.TabWord[i];
            }
            namagame[i] = '\0';
            if (SearchArrayDin(file, CCommand) == -1)
            {
                InsertLast(&file, CCommand);
                printf("\n");
                printf("Game %s Berhasil Ditambahkan\n", namagame);
                printf("\n");
            }
            else
            {
                printf("\n");
                printf("Game %s Gagal Ditambahkan, karena sudah ada\n", namagame);
                printf("\n");
            }
        }

        /* *** ******* ******* ******* ******** ******* ******** PLAY GAME ******* ******** *** ******* ******* ******* ******** */
        else if (IsKataSama(CCommand, toKata("PLAY GAME")))
        {
            printf("\n");
            printf("+========================================================================================+\n");
            printf("|                                 DAFTAR ANTRIAN GAMEMU (^-^)                            |\n");
            printf("+========================================================================================+\n");
            printf("\n");
            printf("Berikut adalah daftar antrian Game-mu\n");
            printf("\n");
            printf("================================================\n");
            printf("\n");
            if (Game.idxHead == IDX_UNDEF)
            {
                printf("SAYANG SEKALI, ANTRIAN KOSONG :( \n");
            }
            else
            {
                if (Game.idxHead != IDX_UNDEF)
                {

                    for (int i = Game.idxHead; i < length(Game); i++)
                    {
                        printf("%d. ", i + 1);
                        PrintWord(Game.buffer[i]);
                    }
                }
            }
            printf("\n");
            printf("================================================\n");
            wordStringCopy(kata, Game.buffer[Game.idxHead]);

            if (IsKataSama(toKata(kata), toKata("RNG")))
            {
                pushGame(&History, toKata("RNG"));
                printf("\n");
                RNG();
            }
            else if (IsKataSama(Game.buffer[Game.idxHead], toKata("Diner DASH")))
            {
                // Dinner_Dash();
                // Ini game Dinner DASH
                pushGame(&History, toKata("Diner DASH"));
            }
            else if (IsKataSama(Game.buffer[Game.idxHead], toKata("Tower Of Hanoi")))
            {
                pushGame(&History, toKata("Tower of Hanoi"));
                printf("\n");
                printf("Selamat datang di game %s\n", kata);
                TowerOfHanoi();
            }
            else if (IsKataSama(Game.buffer[Game.idxHead], toKata("Kerang Ajaib")))
            {
                pushGame(&History, toKata("Kerang Ajaib"));
                KerangAjaib();
            }
            else if (IsKataSama(Game.buffer[Game.idxHead], toKata("Hangman")))
            {
                pushGame(&History, toKata("Hangman"));
                printf("Game Hangman belum tersedia \n");
                // Hangman();
            }
            else if (IsKataSama(Game.buffer[Game.idxHead], toKata("Snake On Meteor")))
            {
                pushGame(&History, toKata("Snake on Meteor"));
                SnakeOnMeteor();
            }
            else if (IsKataSama(Game.buffer[Game.idxHead], toKata("DINOSAUR IN EARTH")) || IsKataSama(toKata(kata), toKata("RISEWOMAN")) || IsKataSama(toKata(kata), toKata("EIFFEL TOWER")) && Game.idxHead != IDX_UNDEF)
            {

                char karak[100];
                wordStringCopy(karak, Game.buffer[Game.idxHead]);
                printf("\n");
                printf("Game %s masih dalam maintenace, belum dapat dimainkan.\n", karak);
                printf("\n");
                printf("COBA MAINKAN GAME YANG LAIN.\n");
                printf("\n");
            }
            else if (!ISEMPTY(Game))
            {
                printf("\n");
                int RandAngka = random(100);
                wordStringCopy(kata, Game.buffer[Game.idxHead]);
                printf("\n");
                printf("Score anda atas game %s adalah %d\n", kata, RandAngka);
                printf("\n");
            }
            dequeueee(&Game, &Game.buffer[Game.idxHead]);
        }

        /* *** ******* ******* ******* ******** ******* ******** SKIPGAME ******* ******** *** ******* ******* ******* ******** */
        else if (IsKataSama(toKata(num), toKata("SKIPGAME")) && (toInteger(toKata(nummm)) == toInteger(toKata(&kata1[9]))))
        {

            int i = 0;
            skip = toInteger(toKata(nummm));

            if (Game.idxHead != IDX_UNDEF)
            {
                printf("\n");
                printf("+========================================================================================+\n");
                printf("|                                 DAFTAR ANTRIAN GAMEMU (^-^)                            |\n");
                printf("+========================================================================================+\n");
                printf("\n");
                printf("Berikut adalah daftar Game-mu\n");
                printf("\n");
                printf("================================================\n");
                printf("\n");
                for (i = 0; i < (length(Game)); i++)
                {
                    printf("%d. ", i + 1);
                    PrintWord(Game.buffer[i]);
                }
                printf("\n");
                printf("================================================\n");

                if (skip < length(Game) && skip != 0)
                {
                    dequeuee(&Game, skip);

                    if (IsKataSama(Game.buffer[Game.idxHead], toKata("RNG")) && !ISEMPTY(Game))
                    {
                        wordStringCopy(kata, Game.buffer[Game.idxHead]);
                        printf("\n");
                        RNG();
                    }
                    else if (IsKataSama((Game.buffer[Game.idxHead]), toKata("Diner DASH")) && !ISEMPTY(Game))
                    {
                        // wordStringCopy(kata, Game.buffer[Game.idxHead]);
                        // Dinner_Dash();
                    }
                    else if (IsKataSama(Game.buffer[Game.idxHead], toKata("Tower Of Hanoi")))
                    {
                        printf("Selamat datang di game %s\n", kata);
                        TowerOfHanoi();
                    }
                    else if (IsKataSama(Game.buffer[Game.idxHead], toKata("Kerang Ajaib")))
                    {
                        KerangAjaib();
                    }
                    else if (IsKataSama(Game.buffer[Game.idxHead], toKata("Hangman")))
                    {
                        printf("Game Hangman belum tersedia \n");
                        // Hangman();
                    }
                    else if (IsKataSama(Game.buffer[Game.idxHead], toKata("Snake On Meteor")))
                    {
                        SnakeOnMeteor();
                    }
                    else if (IsKataSama(Game.buffer[Game.idxHead], toKata("DINOSAUR IN EARTH")) || IsKataSama(toKata(kata), toKata("RISEWOMAN")) || IsKataSama(toKata(kata), toKata("EIFFEL TOWER")) && Game.idxHead != IDX_UNDEF)
                    {

                        char karak[100];
                        wordStringCopy(karak, Game.buffer[Game.idxHead]);
                        printf("\n");
                        printf("Game %s masih dalam maintenace, belum dapat dimainkan.\n", karak);
                        printf("\n");
                        printf("COBA MAINKAN GAME YANG LAIN.\n");
                        printf("\n");
                    }
                    else if (!ISEMPTY(Game))
                    {
                        int RandAngka = random(100);
                        wordStringCopy(kata, Game.buffer[Game.idxHead]);
                        printf("\n");
                        printf("Score anda atas game %s adalah %d\n", kata, RandAngka);
                        printf("\n");
                    }
                    dequeuee(&Game, 1);
                    skip = skip + 1;
                    if (length(Game) - skip == 0)
                    {
                        Game.idxHead = IDX_UNDEF;
                        Game.idxTail = IDX_UNDEF;
                    }

                    temp = length(Game) - skip;
                    Game.idxTail = (Game.idxTail) - (skip);
                }
                else
                {
                    printf("\n");
                    printf("DAFTAR  ANTRIAN  GAMEMU %d , JADI TIDAK BISA DISEKIP T_T. \n", length(Game));
                    printf("\n");
                }
            }
            else
            {
                printf("\n");
                printf("ANTRIAN GAME TIDAK DAPAT DISKIP, MUNGKIN ANTRIANMU KOSONG ATAU KAMU MEMASUKKAN ANGKA 0 !! \n");
                printf("\n");
            }
        }

        /* *** ******* ******* ******* ******** ******* ******** QUEUE GAME ******* ******** *** ******* ******* ******* ******** */
        else if (IsKataSama(CCommand, toKata("QUEUE GAME")))
        {
            printf("\n");
            printf("+========================================================================================+\n");
            printf("|                                 DAFTAR ANTRIAN GAMEMU (^-^)                            |\n");
            printf("+========================================================================================+\n");
            printf("\n");
            printf("Berikut adalah daftar antrian game-mu\n");
            printf("\n");
            int z = 0;
            printf("================================================\n");
            if (Game.idxHead == IDX_UNDEF)
            {
                printf("SAYANG SEKALI, ANTRIAN KOSONG :( \n");
                skip = 0;
            }
            else
            {

                for (int z = Game.idxHead; z < (Game.idxTail + 1); z++)
                {
                    printf("%d. ", z + 1);
                    PrintWord(Game.buffer[z]);
                    if (skip == 0)
                    {
                        temp = length(Game);
                    }
                }
            }
            printf("================================================\n");
            printf("\n");
            printf("+========================================================================================+\n");
            printf("|                                       LIST GAMEMU ^-^                                  |\n");
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
            printf("Nomor game yang mau ditambahkan ke antrian: ");
            STARTCOMMAND();
            int m = toInteger(CCommand);
            int n = file.Neff;
            if (m < file.Neff && m != 0)
            {
                enqueue(&Game, file.A[m]);

                printf("\n");
                wordStringCopy(kata, file.A[m]);
                printf("Game %s Berhasil Ditambahkan ke dalam daftar antrian\n", kata);
                printf("\n");
            }
            else if (m >= file.Neff || m <= 0)
            {
                printf("\n");
                printf("Nomor permainan tidak valid, Silahkan masukkan nomor game pada list\n");
                printf("\n");
            }
        }

        /* *** ******* ******* ******* ******** ******* ******** HELP ******* ******** *** ******* ******* ******* ******** */
        else if (IsKataSama(CCommand, toKata("HELP")))
        {
            printf("\n");
            HELP();
        }

        /* *** ******* ******* ******* ******** ******* ******** SAVE GAME ******* ******** *** ******* ******* ******* ******** */
        else if ((IsKataSama(CCommand, toKata("SAVE"))))
        {

            SAVE(file, CCommand);
            printf("\n");
            printf("+====================================+\n");
            printf("| FILE %s BERHASIL DISIMPAN |\n", namafile);
            printf("+====================================+\n");
            printf("\n");
        }

        /* *** ******* ******* ******* ******** ******* ******** SCOREBOARD ******* ******** *** ******* ******* ******* ******** */
        else if ((IsKataSama(toKata(nas), toKata("SCOREBOARD")))) {
            printf("\n");
            printf("+========================================================================================+\n");
            printf("|                                   DAFTAR SCOREBOARD (^-^)                              |\n");
            printf("+========================================================================================+\n");
            printf("\n");
        }

        /* *** ******* ******* ******* ******** ******* ******** HISTORY ******* ******** *** ******* ******* ******* ******** */
        else if ((IsKataSama(CCommand, toKata("HISTORY")))) {
            printf("\n");
            printf("+========================================================================================+\n");
            printf("|                                    DAFTAR HISTORY (^-^)                                |\n");
            printf("+========================================================================================+\n");
            printf("\n");
            for(int i = 0; i <= IDX_TOP(History); i++){
                printf("%d. ", i+1);
                PrintWord(TOP(History));
                popGame(&History, &TOP(History));
            }

        }

        /* *** ******* ******* ******* ******** ******* ******** QUIT ******* ******** *** ******* ******* ******* ******** */
        else if (!IsKataSama(CCommand, toKata("QUIT")))
        {
            printf("\n");
            printf("COMMAND YANG DIINPUT TIDAK VALID T_T .\n");
            printf("\n");
        }

 }
    printf("\n");
    if ((IsKataSama(CCommand, toKata("QUIT"))))
    {
        printf("+============================================================================+\n");
        printf("|                 TERIMA KASIH TELAH BERMAIN  GAME BNMO                      |\n");
        printf("+============================================================================+\n");
        printf("\n");
    }
}