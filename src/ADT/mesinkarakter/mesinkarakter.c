#include "mesinkarakter.h"
#include <stdio.h>

char currentChar;
boolean EOP;
static FILE *pita;
static FILE *command;
static int retval;

void START()
{
    /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
    Karakter pertama yang ada pada pita posisinya adalah pada jendela.
    filename merupakan nama file yang berisi pita karakter
    I.S. : sembarang
    F.S. : CC adalah karakter pertama pada pita
    Jika CC != MARK maka EOP akan padam (false)
    Jika CC = MARK maka EOP akan menyala (true) */
    pita = stdin;
    ADV();
}

void ADV() {
    /* Pita dimajukan satu karakter.
    I.S. : Karakter pada jendela = CC, CC != MARK
    F.S. : CC adalah karakter berikutnya dari CC yang lama,

    CC mungkin = MARK
    Jika CC = MARK maka EOP akan menyala (true) */

    retval = fscanf(pita, "%c", &currentChar);
    EOP = (currentChar == MARK);
}

void STARTG(char *filename) {
    pita = fopen(filename,"r");
    ADV();
}

void ADVG()
{
    /* Pita dimajukan satu karakter.
    I.S. : Karakter pada jendela = CC, CC != ENTER
    F.S. : CC adalah karakter berikutnya dari CC yang lama,*/
    retval = fscanf(pita, "%c", &currentChar);
    EOP = (currentChar == ENTER);
    if (EOP) {
        fclose(pita);
    }
}

char GetCC()
{
    return (currentChar);
}

boolean IsEOP()
{
    return (currentChar == MARK);
}
