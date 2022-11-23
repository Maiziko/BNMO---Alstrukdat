#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../arraydin/arraydin.h"
#include "../mesinkata/mesinkata.h"
#include "../mesinkarakter/mesinkarakter.h"

ArrayDin Load(Word kata)
{
    /* I.S. : File eksternal terdefinisi */
    /* F.S. : Mengembalikan arraydin yang berisi data dari file eksternal */
    ArrayDin ffile = MakeArrayDin();
    char gm[100];
    char gm1[100];
    char gm2[100];
    char m[100];
    int i = 0;
    int j = 0;
    for (j = 0; j < CCommand.Length; j++)
    {
        gm[j] = CCommand.TabWord[j];
    }
    gm[j] = '\0';

    for (j = 0; j < CCommand.Length; j++)
    {
        m[j] = CCommand.TabWord[j + 5];
    }

    for (j = 0; j < CCommand.Length; j++)
    {
        gm1[j] = gm[j + 5];
    }
    gm1[j] = '\0';

    for (j = 0; j < 4; j++)
    {
        gm2[j] = CCommand.TabWord[j];
    }
    gm2[j] = '\0';

    if (IsKataSama(toKata(gm2), toKata("LOAD")))
    {
        if (IsKataSama(toKata(gm1), toKata(m)))
        {
            STARTGAME(gm1);
            while (!EndWord)
            {
                for (int j = 0; j < currentWord.Length; j++)
                {
                    ffile.A[i].TabWord[j] = currentWord.TabWord[j];
                }
                ffile.A[i].Length = currentWord.Length;
                ADVWORD();
                i++;
            }
            ffile.Neff = i;
        }
    }
    return (ffile);
}