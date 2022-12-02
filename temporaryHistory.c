// History
#include "src/ADT/stack/stack.h"

int history()
{
    printf("+=======================================================+\n");
    printf("+                   RESET HISTORY                       +\n");
    printf("+=======================================================+\n");

    if (IsKataSama(CCommand, toKata("RESET HISTORY")))
    {
        printf("History yang sudah direset tidak dapat dikembalikan, Apakah kamu yakin ingin mereset historymu?\n");
        // char yatidak[10];
        if ("Ya")
        {
           CreateStack(History);
        }
        else
        {
            printf("Reset history dibatalkan\n");
            for(int i = 0; i < IDX_TOP(History); i++)
            {
            printf("%d. ", i+1);
            PrintWord(TOP(History));
            }
        }
    }
}

/* if (IDX_TOP(History) == Nill){
                printf("Wah belum ada game yang dimainkan :(\n");
            }*/