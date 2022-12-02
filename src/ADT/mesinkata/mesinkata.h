/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../boolean.h"
#include "../mesinkarakter/mesinkarakter.h"

#define NMax 100
#define BLANK ' '
#define ENTER '\n'

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Kata */
extern boolean EndWord;
extern Word currentWord;
extern Word CCommand;

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTGAME(char *filename);
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void STARTWORD(char *filename);

void ADVKATA();

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void IgnoreDot();
/* Mengabaikan satu atau beberapa BLANK dan MARK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = ENTER */

void STARTCOMMAND();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = ENTER;
          atau EndWord = false, CCommand adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVCOMMAND();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : CComand adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin ENTER
          Jika currentChar = ENTER, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure CopyCommand */

void CopyCommand();
/* Mengakuisisi kata, menyimpan dalam CComand
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : CComand berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = ENTER;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

boolean IsKataSama(Word InputCommand, Word Command);
/* Mengirimkan true jika K1 = K2 : Length dan elemen tiap arraynya sama */

void PrintWord(Word K);
/* Mencetak kata ke layar
   I.S. : Kata K terdefinisi
   F.S. : Kata K tercetak pada layar */

int stringLength(char *string);
/* Mengirimkan panjang sebuah string */

Word toKata(char *command);
/* Mengirimkan kata yang elemen of arraynya berasal dari command */
void wordStringCopy(char *dest, Word src);
/* Mengcopy kata ke string */
char toChar(Word COMAND);
/* Mengirimkan karakter dari kata */

int toInt(char kata);

int toInteger(Word kata);

Word readfilename(Word currentWord);

Word copyword(Word CCommand);

char *convertInttoStr(int x);
char *KatakeString(Word kata);
#endif
