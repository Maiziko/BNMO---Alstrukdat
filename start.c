#include <stdio.h>
#include <stdlib.h>
#include "src/ADT/mesinkarakter/mesinkarakter.c"
#include "src/ADT/mesinkata/mesinkata.c"
#include "src/ADT/arraydin/arraydin.c"

int toInteger(Word kata)
{
    int i = 0;
    int result = 0;
    while (i < kata.Length)
    {
        result = result * 10 + (kata.TabWord[i] - '0');
        i++;
    }
    return result;
}

int main()
{
    int i = 0;
    int j = 0;
    char kata1[100];
    char num[100];
    char nummm[100];
    STARTCOMMAND();
    /*while (currentChar != MARK)
    {
        PrintWord(CCommand);
        ADVWORD();
    }*/

    for (i; i < CCommand.Length; i++)
    {
        kata1[i] = CCommand.TabWord[i];
    }
    kata1[i] = '\0';

    for (i = 0; i < 8; i++)
    {
        num[i] = kata1[i];
    }
    num[i] = '\0';

    for (i = 0; i < 1; i++)
    {
        nummm[i] = kata1[i + 9];
    }
    nummm[i] = '\0';

    PrintWord(toKata(kata1));
    PrintWord(toKata(num));
    PrintWord(toKata(nummm));
    PrintWord(toKata(&kata1[9]));

    if (toInteger(toKata(nummm)) == 1)
    {
        printf("1");
    }

    return 0;
}