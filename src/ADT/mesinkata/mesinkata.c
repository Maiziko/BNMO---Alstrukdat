#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "mesinkata.h"

boolean EndWord;
Word currentWord;
Word CCommand;

void IgnoreBlanks()
{
    /* Mengabaikan Satu atau beberapa BLANK
       I.S  : currentChar sembarang
       F.S  : currentChar != BLANK atau currentChar != ENTER */
    while ((currentChar == BLANK) || (currentChar == ENTER))
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
        ADVKATA();
    }
}

void STARTGAME(char *filename)
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
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
        IgnoreBlanks();
    }
}

void ADVKATA()
{
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika currentChar = MARK, EndWord = true.
       Proses : Akuisisi kata menggunakan procedure CopyWord */

    IgnoreBlanks();
    if (currentChar == ENTER)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
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
    while ((currentChar != MARK) && (currentChar != ENTER) && i < NMax)
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
    while ((currentChar == BLANK) || (currentChar == '.'))
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
    while ((currentChar != ENTER) && j != NMax)
    {
        CCommand.TabWord[j] = currentChar;
        ADVC();
        j++;
    }
    CCommand.Length = (j < NMax) ? j : NMax;
}

/* Fungsi Tambahan */
boolean IsKataSama(Word InputCommand, Word Command)
/* Mengirimkan true jika K1 = K2 : Length dan elemen tiap arraynya sama */
{
    boolean sama = true;
    if (InputCommand.Length != Command.Length)
    {
        return !sama;
    }
    else
    {
        int i = 0;
        while (sama && (i < Command.Length))
        {
            if (InputCommand.TabWord[i] != Command.TabWord[i])
            {
                sama = false;
            }
            i++;
        }
        return sama;
    }
}

void PrintWord(Word K)
/* Mencetak kata ke layar
   I.S. : Kata K terdefinisi
   F.S. : Kata K tercetak pada layar */
{
    for (int i = 0; i < K.Length; i++)
    {
        printf("%c", K.TabWord[i]);
    }
    printf("\n");
}

int stringLength(char *string)
/* Mengirimkan panjang sebuah string */
{
    int len = 0;
    while (string[len] != '\0')
    {
        len++;
    }
    return len;
}

Word toKata(char *command)
/* Mengirimkan kata yang elemen of arraynya berasal dari command */
{
    int i;
    Word output;
    for (i = 0; i < stringLength(command); i++)
    {
        output.TabWord[i] = command[i];
    }
    output.Length = stringLength(command);
    return output;
}

void wordStringCopy(char *dest, Word src)
{
    int i;
    for (i = 0; i < src.Length && src.TabWord[i] != '\0'; ++i)
    {
        dest[i] = src.TabWord[i];
    }
    dest[i] = '\0';
}

char toChar(Word COMAND)
{
    char output;
    output = COMAND.TabWord[0];
    return output;
}

int toInt(char kata)
{
    switch (kata)
    {
    case '1':
        return 1;
        break;
    case '2':
        return 2;
        break;
    case '3':
        return 3;
        break;
    case '4':
        return 4;
        break;
    case '5':
        return 5;
        break;
    case '6':
        return 6;
        break;
    case '7':
        return 7;
        break;
    case '8':
        return 8;
        break;
    case '9':
        return 9;
        break;
    default:
        return 0;
        break;
    }
}

int toInteger(Word kata)
{
    int i = kata.Length - 1;
    int result = 0, exp = 0;
    while (i >= 0)
    {
        result = result + toInt(kata.TabWord[i]) * pow(10, exp);
        i--;
        exp++;
    }
    return result;
}
char *convertInttoStr(int x)
{
    int i, copy, digit;
    int len = 0;
    copy = x;
    while (copy != 0)
    {
        len++;
        copy /= 10;
    }
    char *str = malloc(len * sizeof(char));
    while (str == NULL)
    {
        str = malloc(len * sizeof(char));
    }
    for (i = 0; i < len; i++)
    {
        digit = x % 10;
        x = x / 10;
        str[len - (i + 1)] = digit + '0';
    }
    str[len] = '\0';
    return str;
}