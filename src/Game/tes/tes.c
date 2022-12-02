#include <stdio.h>
#include <stdlib.h>
#include "../../ADT/stack/stack.c"
#include "../../ADT/arraydin/arraydin.c"
#include "../../ADT/mesinkata/mesinkata.c"
#include "../../ADT/mesinkarakter/mesinkarakter.c"
#include "../../ADT/map/map.c"
#include "../../ADT/set/set.c"

int toInteger(Word kata)
{
    int i = kata.Length;
    int result = 0;
    while (i >= 0)
    {
        result = result * 10 + toInt(kata.TabWord[i]);
        i--;
    }

    return result;
}

int main()
{
    ArrayDin gamefile = MakeArrayDin();
    ArrayData dataplayer = MakeArrayData();
    History history;
    CreateHistory(&history);
    data RNGPlayers, DinerDashPlayers, HangmanPlayers, TowerPlayers, SnakePlayers;
    createEmptyData(&RNGPlayers);
    createEmptyData(&DinerDashPlayers);
    createEmptyData(&HangmanPlayers);
    createEmptyData(&TowerPlayers);
    createEmptyData(&SnakePlayers);

    STARTWORD("config.txt");

    // while(!EndWord) {
    int totalgame = toInt(currentWord.TabWord[0]);
    for (int i = 0; i < totalgame; i++)
    {
        ADVWORD();
        InsertAt(&gamefile, currentWord, i);
    }

    ADVWORD();
    int temp = toInt(currentWord.TabWord[0]);
    for (int i = 0; i < temp; i++)
    {
        ADVWORD();
        pushGame(&history, currentWord);
    }

    for (int i = 0; i < totalgame; i++)
    {
        ADVWORD();
        Word tempname, tempscore;
        data tempdata;
        createEmptyData(&tempdata);
        temp = toInt(currentWord.TabWord[0]);
        for (int j = 0; j < temp; j++)
        {
            ADVWORD();
            int k = 0;
            for (int i = 0; i < currentWord.Length; i++)
            {
                if (currentWord.TabWord[i] == ' ')
                {
                    for (int p = 0; p < currentWord.Length - i; p++)
                    {
                        tempscore.TabWord[p] = currentWord.TabWord[i + 1];
                        tempscore.Length++;
                        i++;
                    }
                    break;
                }
                tempname.TabWord[k] = currentWord.TabWord[i];
                tempname.Length++;
                k++;
            }
            tempdata.Element[i].name = tempname;
            tempdata.Element[i].score = toInteger(tempscore);
            InsertDataAt(&dataplayer, tempdata, i);
        }
    }
    // }
}