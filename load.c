#include <stdio.h>
#include <stdlib.h>
#include "src/ADT/mesinkata/mesinkata.c"
#include "src/ADT/mesinkarakter/mesinkarakter.c"
#include "src/ADT/arraydin/arraydin.c"

int main()
{
    ArrayDin ffile = MakeArrayDin();
    char gm[100];
    char gm1[100];
    char gm2[100];
    char m[100];
    STARTCOMMAND();
    int i = 0;
    int j = 0;
    for (j = 0; j < CCommand.Length; j++)
    {
        gm[j] = CCommand.TabWord[j];
    }
    gm[j] = '\0';

    for (j = 0; j < CCommand.Length; j++)
    {
        gm1[j] = gm[j + 5];
    }
    gm1[j] = '\0';

    for (j = 0; j < CCommand.Length; j++)
    {
        m[j] = gm[j + 5];
    }
    m[j] = '\0';

    for (j = 0; j < 4; j++)
    {
        gm2[j] = CCommand.TabWord[j];
    }
    gm2[j] = '\0';

    printf("%s\n", gm1);

    printf("%s\n", gm2);

    if (IsKataSama(toKata(gm2), toKata("LOAD")))
    {
        if (IsKataSama(toKata(gm1), toKata(m)))
        {
            STARTGAME(m);
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
            int k = 0;
            for (int j = 1; j < ffile.Neff; j++)
            {
                printf("%d. ", k + j);
                PrintWord(ffile.A[j]);
                // PrintWord(currentWord);
            }
        }
    }
    // PrintWord(currentWord);
    return 0;
}
