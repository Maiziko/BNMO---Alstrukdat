#include <stdio.h>
#include "../arraydin/arraydin.h"
#include "../mesinkata/mesinkata.h"
#include "../mesinkarakter/mesinkarakter.h"

ArrayDin Load(Word kata)
{
    ArrayDin ffile = MakeArrayDin();
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
        filetext[j + 5] = CCommand.TabWord[j + 5];
    }
    filetext[j] = '\0';

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

    return (ffile);
}