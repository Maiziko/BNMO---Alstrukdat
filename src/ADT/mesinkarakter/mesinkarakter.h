/* File: mesinkarakter.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "../boolean.h"
#include <stdio.h>

#define MARK '.'
#define ENTER '\n'

/* State Mesin */
extern char currentChar;
extern boolean EOP;

void STARTG(char *filename);
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

void START();

void ADV();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */
void COMMAND();
/*  Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
    Karakter pertama yang ada pada pita posisinya adalah pada jendela.
    filename merupakan nama file yang berisi pita karakter
    I.S. : sembarang
    F.S. : CC adalah karakter pertama pada pita
    Jika CC != ENTER maka EOP akan padam (false)
    Jika CC = ENTER maka EOP akan menyala (true) */

void ADVC();
/* Pita dimajukan satu karakter.
I.S. : Karakter pada jendela = CC, CC != ENTER
F.S. : CC adalah karakter berikutnya dari CC yang lama,

CC mungkin = ENTER
Jika CC = ENTER maka EOP akan menyala (true) */

char GetCC();
/* Mengirimkan currentChar */

boolean IsEOP();
/* Mengirimkan true jika currentChar = MARK */
int KSTART(char *filename);

#endif
