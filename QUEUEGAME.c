#include <stdio.h>
#include <stdlib.h>
#include "src/ADT/mesinkata/mesinkata.c"
#include "src/ADT/mesinkarakter/mesinkarakter.c"
#include "src/ADT/arraydin/arraydin.c"

int toInteger(Word kata)
{
    int i = 0;
    int result = 0;
    while (i < kata.Length)
    {
        result = result * 10 + (kata.TabWord[i] - '0');
        i++;
    }
    return result;
}

// void QUEUEGAME(ArrayDin List)
// {
//     // ArrayDin Temp;
//     // if (Temp.Neff == 0)
//     // {
//     //     printf("Berikut adalah daftar antrian game-mu\n");
//     // }
//     // else
//     // {
//     //     printf("Berikut adalah daftar antrian game-mu\n");
//     //     for (int i = 1; i <= Temp.Neff; i++)
//     //     {
//     //         printf("%d. ", i);
//     //         printf("%s ", Temp.A[i]);
//     //     }
//     // }
//     // printf("\n");
//     // printf("Berikut adalah daftar game yang tersedia\n");
//     int j = 0;
//     for (int j = 1; j < List.Neff; j++)
//     {
//         printf("%d. ", j + 1);
//         PrintWord(List.A[j]);
//         // PrintWord(currentWord);
//     }

//     // int m = toInteger(CCommand);
//     // if (m > List.Neff)
//     // {
//     //     printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.\n");
//     // }
//     // else
//     // {
//     //     Temp.Neff++;
//     //     Temp.A[Temp.Neff] = List.A[m];
//     //     printf("Game berhasil ditambahkan ke antrian\n");
//     // }
// }

int main() // Ini untuk Command LOAD
{
    int i = 0;
    STARTGAME("config.txt");
    ArrayDin file = MakeArrayDin();
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
    int j = 0;
    for (int j = 1; j < file.Neff; j++)
    {

        PrintWord(file.A[j]);
        // PrintWord(currentWord);
    }
    return 0;
}
