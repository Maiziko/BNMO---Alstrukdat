#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../ADT/map/map.h"
#include "../../ADT/mesinkata/mesinkata.h"
#include "../../ADT/mesinkarakter/mesinkarakter.h"
#include "../../ADT/listlinier/listlinier.h"

void MoveUp(map new, char pemain, char makanan)
{
    /* Membuat pergerakan snake ke atas dari posisi awal*/
}
void MoveDown(map new, char pemain, char makanan)
{
    /* Membuat pergerakan snake ke bawah dari posisi awal*/
}
void MoveLeft()
{
    /* Membuat pergerakan snake ke kiri dari posisi awal*/
}
void MoveRight()
{
    /* Membuat pergerakan snake ke kanan dari posisi awal*/
}
map GenerateMap(map board, char player, char makanan)
{
    /* Menghasilkan sebuah Map*/
    int i, j;
    int KF_Y = 5;
    int KF_X = 5;
    int y = 1;
    int x = 1;

    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 7; j++)
        {
            if (i == 0 || i == 6)
            {
                board.Element[i][j] = '#';
            }
            else if (j == 0 || j == 6)
            {
                board.Element[i][j] = '|';
            }
            else
            {
                board.Element[i][j] = ' ';
            }
        }
    }
    board.Element[y][x] = player;
    if (KF_X != x && KF_Y != y)
    {
        board.Element[KF_Y][KF_X] = makanan;
    }
    return board;
}

void PrintMap(map new, int score)
{
    /* Menampilkan Map yang telah dibuat*/
    printf("BERIKUT PETA PERMAINANMU\n");
    printf("\n");
    int i, j;
    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 7; j++)
        {
            printf("%c", new.Element[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("===================");
    printf("\n");
    printf("Score Anda sekarang: %d\n", score);
}

int RandPosisi()
{
    /* Menghasilkan posisi random untuk meteor */
    srand((unsigned)time(0));
    return (rand() % 5) + 1;
}

int main()
{
    /**/
    printf("\n");
    printf("+===========================================================================+\n");
    printf("|               SELAMAT DATANG DI GAME SNAKE ON METEOR  {*-*}               |\n");
    printf("+===========================================================================+\n");
    printf("\n");
    printf("Mengenerate peta, snake dan makanan . . .\n");
    printf("\n");
    printf("Berhasil digenerate !\n");
    printf("\n");
    printf("======== P E R A T U R A N  P E R M A I N A N =======\n");
    printf("\n");
    printf("1. command 'w' akan membuat snake bergerak ke atas.\n");
    printf("2. command 's' akan membuat snake bergerak ke bawah.\n");
    printf("3. command 'a' akan membuat snake bergerak ke kiri.\n");
    printf("4. command 'd' akan membuat snake bergerak ke kanan.\n");
    printf("\n");
    printf("SILAHKAN MASUKKAN COMMAND YANG VALID YAH (^-^).\n");
    printf("\n");
    printf("S E L A M A T  B E R M A I N !!\n");
    printf("\n");
    printf("===================\n");
    map papan;
    char pemain = 'H';
    char food = 'O';
    char meteor = 'm';
    char tail = '*';
    int nilai = 0;
    int turn = 1;
    int y = 1;
    int x = 1;
    createEmpty(&papan);
    papan = GenerateMap(papan, pemain, food);
    PrintMap(papan, nilai);
    printf("\n");
    printf("TURN %d : \n", turn);
    printf("SILAHKAN  MASUKKAN  COMMAND (w/a/s/d) : ");
    STARTCOMMAND();
    while (toChar(CCommand) != 'q')
    {
        if (toChar(CCommand) == 'w' && CCommand.Length == 1)
        {
            printf("\n");
            printf("Kamu Berhasil Bergerak ke atas ^-^ !\n");
            printf("\n");
            MoveUp(papan, pemain, food);
            PrintMap(papan, nilai);
            turn += 1;
        }
        else if (toChar(CCommand) == 's' && CCommand.Length == 1)
        {
            printf("\n");
            printf("Kamu Berhasil Bergerak ke bawah ^-^ !\n");
            printf("\n");
            MoveDown(papan, pemain, food);
            PrintMap(papan, nilai);
            turn += 1;
        }
        else if (toChar(CCommand) == 'a' && CCommand.Length == 1)
        {
            printf("\n");
            printf("Kamu Berhasil Bergerak ke kiri ^-^ !\n");
            printf("\n");
            // MoveLeft();
            PrintMap(papan, nilai);
            turn += 1;
        }
        else if (toChar(CCommand) == 'd' && CCommand.Length == 1)
        {
            printf("\n");
            printf("Kamu Berhasil Bergerak ke kanan ^-^ !\n");
            printf("\n");
            // MoveRight();
            PrintMap(papan, nilai);
            turn += 1;
        }
        else
        {
            printf("COMMAND ANDA TIDAK VALID T_T , SILAHKAN INPUT COMMAND ('w'/'a'/'s'/'d')\n");
        }
        printf("\n");
        printf("TURN %d : \n", turn);
        printf("SILAHKAN  MASUKKAN  COMMAND (w/a/s/d) : ");
        STARTCOMMAND();
    }
}
