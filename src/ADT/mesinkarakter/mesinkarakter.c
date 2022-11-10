#include "mesinkarakter.h"
#include <stdio.h>

char currentChar;
boolean EOP;
static FILE *pita;
static FILE *command;
static int retval;

void START(char *filename)
{
    /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
    Karakter pertama yang ada pada pita posisinya adalah pada jendela.
    filename merupakan nama file yang berisi pita karakter
    I.S. : sembarang
    F.S. : CC adalah karakter pertama pada pita
    Jika CC != MARK maka EOP akan padam (false)
    Jika CC = MARK maka EOP akan menyala (true) */
<<<<<<< HEAD

    pita = fopen(filename, "r");
=======
    pita = stdin;
>>>>>>> fc1601a522ff3d98096e8d145598c34ce0d77e31
    ADV();
}

void ADV() {
    /* Pita dimajukan satu karakter.
    I.S. : Karakter pada jendela = CC, CC != MARK
    F.S. : CC adalah karakter berikutnya dari CC yang lama,

    CC mungkin = MARK
    Jika CC = MARK maka EOP akan menyala (true) */

    retval = fscanf(pita, "%c", &currentChar);
<<<<<<< HEAD
    if (IsEOP())
    {
        fclose(pita);
    }
=======
    EOP = (currentChar == MARK);
>>>>>>> fc1601a522ff3d98096e8d145598c34ce0d77e31
}

void STARTG(char *filename) {
    pita = fopen(filename,"r");
    ADVG();
}

void ADVG()
{
    /* Pita dimajukan satu karakter.
    I.S. : Karakter pada jendela = CC, CC != ENTER
    F.S. : CC adalah karakter berikutnya dari CC yang lama,*/
    retval = fscanf(pita, "%c", &currentChar);
    EOP = (currentChar == ENTER);
<<<<<<< HEAD
=======
    if (EOP) {
        fclose(pita);
    }
>>>>>>> fc1601a522ff3d98096e8d145598c34ce0d77e31
}

char GetCC()
{
    return (currentChar);
}

boolean IsEOP()
{
    return (currentChar == MARK);
}
