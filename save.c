#include <stdio.h>
#include <stdlib.h>
#include "src/ADT/mesinkarakter/mesinkarakter.c"
#include "src/ADT/mesinkata/mesinkata.c"
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
    int k = 0;
    for (int j = 1; j < file.Neff; j++)
    {
        printf("%d. ", k + j);
        PrintWord(file.A[j]);
        // PrintWord(currentWord);
    }
    return 0;
}