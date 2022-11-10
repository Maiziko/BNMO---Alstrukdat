#include <stdio.h>
#include <stdlib.h>
#include "src/ADT/mesinkarakter/mesinkarakter.c"
#include "src/ADT/mesinkata/mesinkata.c"
#include "src/ADT/arraydin/arraydin.c"

void SAVE(ArrayDin file, Word kata)
{
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
                fprintf(fptr, "%c", "\n");
            }
            fprintf(fptr, " ");
        }
    }
    printf("Save file berhasil disimpan.\n");
    fclose(fptr);
}
