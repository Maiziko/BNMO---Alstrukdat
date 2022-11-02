#include <stdio.h>
#include "mesinkata.h"

boolean EndWord;
Word currentWord;
Word CCommand;

void IgnoreBlanks() {
    while ((currentChar == BLANK) && (currentChar != MARK)) {
    ADV();
    }
}

void STARTWORD() {
    START();
    IgnoreBlanks();
    if (currentChar == MARK) {
        EndWord = true;
    } else {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD() {
    IgnoreBlanks();
    if (currentChar == MARK) {
        EndWord = true;
    } else {
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord() {
    int i = 0;
    while ((currentChar != MARK) && (currentChar != BLANK) && (i < NMax)) {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    currentWord.Length = i;
}

void IgnoreDot(){
/* Mengabaikan satu atau beberapa BLANK dan MARK
   I.S. : currentChar sembarang 
   F.S. : currentChar ≠ BLANK atau currentChar = ENTER */
   while ((currentChar == BLANK) && (currentChar == '.')){
        ADVC();
   }
}

void STARTCOMMAND(){
/* I.S. : currentChar sembarang 
   F.S. : EndWord = true, dan currentChar = ENTER; 
          atau EndWord = false, CCommand adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
   COMMAND();
   IgnoreDot();
   if(currentChar == ENTER){
        EndWord = true;
   } else {
        EndWord = false;
        ADVCOMMAND();
   }
}

void ADVCOMMAND(){
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CComand adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin ENTER
          Jika currentChar = ENTER, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinCommand */
   IgnoreDot();
   if(currentChar == ENTER && !EndKata){
        EndWord = true;
   } else {
        CopyCommand();
        IgnoreDot();
   }
}

void CopyCommand(){
/* Mengakuisisi kata, menyimpan dalam CComand
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : CComand berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = ENTER; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
   int j = 0;
   while((currentChar != BLANK) && (currentChar != ENTER) && j != NMax){
        CCommand.TabWord[j] = currentChar;
        ADVC();
        j++;
   }
   CCommand.Length = (j < NMax) ? j : NMax;
}
