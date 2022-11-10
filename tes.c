#include <stdio.h>
#include <stdlib.h>
#include "src/ADT/mesinkata/mesinkata.c"
#include "src/ADT/mesinkarakter/mesinkarakter.c"
#include "src/ADT/arraydin/arraydin.c"

int main()
{
    ArrayDin *arraydin;
    STARTGAME("config.txt");
    while (currentChar != MARK)
    {
        PrintWord(currentWord);
        ADVWORD();
    }
    PrintWord(currentWord);
    return 0;
}