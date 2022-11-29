#include <stdio.h>
#include "../arraydin/arraydin.h"
#include "../mesinkata/mesinkata.h"
#include "../mesinkarakter/mesinkarakter.h"

ArrayDin Load(Word kata)
{
    ArrayDin ffile = MakeArrayDin();
    char gm[100];
    char gm1[100];
    char gm2[100];
    char m[100];
    char filetext[100];
    int i = 0;
    int j = 0;

    filetext[0] = 'D';
    filetext[1] = 'a';
    filetext[2] = 't';
    filetext[3] = 'a';
    filetext[4] = '/';

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

    for (j = 0; j < CCommand.Length; j++)
    {
        filetext[j + 5] = CCommand.TabWord[j + 5];
    }
    filetext[j] = '\0';

    for (j = 0; j < 4; j++)
    {
        gm2[j] = CCommand.TabWord[j];
    }
    gm2[j] = '\0';

    if (IsKataSama(toKata(gm2), toKata("LOAD")))
    {
        if (IsKataSama(toKata(gm1), toKata(m)))
        {
            if (KSTART(filetext) == 1)
            {
                STARTGAME(filetext);
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
            else
            {
                ffile.Neff = 0;
            }
        }
    }
    return (ffile);
}