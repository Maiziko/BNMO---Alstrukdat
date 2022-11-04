#include <stdio.h>
#include "mesinkata.h"

boolean EndWord;
Word currentWord;
Word CCommand;

void IgnoreBlanks()
{
    /* Mengabaikan Satu atau beberapa BLANK
       I.S  : currentChar sembarang
       F.S  : currentChar != BLANK atau currentChar != ENTER */
    while ((currentChar == BLANK) || (currentChar != ENTER))
    {
        ADV();
    }
}

void STARTWORD(char *filename)
{
    /* I.S. : currentChar sembarang
       F.S. : EndWord = true, dan currentChar = MARK;
              atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
              currentChar karakter pertama sesudah karakter terakhir kata */

    START(filename);
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        ADVWORD();
        CopyWord();
    }
}

void ADVWORD()
{
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika currentChar = MARK, EndWord = true.
       Proses : Akuisisi kata menggunakan procedure CopyWord */

    IgnoreBlanks();
    if (currentChar == MARK && !EndWord)
    {
        EndWord = true;
    }
    else
    {
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord()
{
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentWord berisi kata yang sudah diakuisisi;
              currentChar = BLANK atau currentChar = MARK;
              currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

    int i = 0;
    while ((currentChar != MARK) && (currentChar != BLANK) && (i < NMax))
    {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    currentWord.Length = i;
}

void IgnoreDot()
{
    /* Mengabaikan satu atau beberapa BLANK dan MARK
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = ENTER */
    while ((currentChar == BLANK) && (currentChar == '.'))
    {
        ADVC();
    }
}

void STARTCOMMAND()
{
    /* I.S. : currentChar sembarang
       F.S. : EndWord = true, dan currentChar = ENTER;
              atau EndWord = false, CCommand adalah kata yang sudah diakuisisi,
              currentChar karakter pertama sesudah karakter terakhir kata */
    COMMAND();
    IgnoreDot();
    if (currentChar == ENTER)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        ADVCOMMAND();
    }
}

void ADVCOMMAND()
{
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : CComand adalah kata terakhir yang sudah diakuisisi,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin ENTER
              Jika currentChar = ENTER, EndWord = true.
       Proses : Akuisisi kata menggunakan procedure SalinCommand */
    IgnoreDot();
    if (currentChar == ENTER && !EndWord)
    {
        EndWord = true;
    }
    else
    {
        CopyCommand();
        IgnoreDot();
    }
}

void CopyCommand()
{
    /* Mengakuisisi kata, menyimpan dalam CComand
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : CComand berisi kata yang sudah diakuisisi;
              currentChar = BLANK atau currentChar = ENTER;
              currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    int j = 0;
    while ((currentChar != BLANK) && (currentChar != ENTER) && j != NMax)
    {
        CCommand.TabWord[j] = currentChar;
        ADVC();
        j++;
    }
    CCommand.Length = (j < NMax) ? j : NMax;
}
