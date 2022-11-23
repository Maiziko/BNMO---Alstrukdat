#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../arraydin/arraydin.h"
#include "../mesinkata/mesinkata.h"
#include "../mesinkarakter/mesinkarakter.h"

void SAVE(ArrayDin file, Word kata)
{
    /* I.S. file terdefinisi, kata terdefinisi */
    /* F.S. file eksternal terisi dengan data dari arraydin */
    FILE *fptr;
    char filename[100];
    char filetxt[100];
    char filetxt2[10];
    int i = 0;
    for (i = 0; i < kata.Length; i++)
    {
        filename[i] = kata.TabWord[i];
    }
    filename[i] = '\0';

    for (i = 0; i < kata.Length; i++)
    {
        filetxt[i] = kata.TabWord[i + 5];
    }
    filetxt[i] = '\0';

    for (i = 0; i < 4; i++)
    {
        filetxt2[i] = kata.TabWord[i];
    }
    filetxt2[i] = '\0';
    Word Kata = toKata(filetxt);
    if (IsKataSama(toKata(filetxt2), toKata("SAVE")))
    {
        wordStringCopy(filetxt, Kata);
        fptr = fopen(filetxt, "w");
        for (int i = 0; i < file.Neff; i++)
        {
            for (int j = 0; j < file.A[i].Length; j++)
            {
                fprintf(fptr, "%c", file.A[i].TabWord[j]);
            }
            fprintf(fptr, "\n");
        }
        fprintf(fptr, ".");
    }
    printf("Save file berhasil disimpan.\n");
    fclose(fptr);
}