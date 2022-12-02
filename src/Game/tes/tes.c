#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../../ADT/stack/stack.c"
#include "../../ADT/arraydin/arraydin.c"
#include "../../ADT/mesinkata/mesinkata.c"
#include "../../ADT/mesinkarakter/mesinkarakter.c"
#include "../../ADT/map/map.c"
#include "../../ADT/set/set.c"

int toInteger(Word kata)
{
    int i = kata.Length - 1;
    int result = 0, exp = 0;
    while (i >= 0)
    {
        result = result + toInt(kata.TabWord[i]) * pow(10, exp);
        i--;
        exp++;
    }

    return result;
}

void loadData(char *filename)
{
    ArrayDin gamefile = MakeArrayDin();
    ArrayData dataplayer = MakeArrayData();
    History history;
    CreateHistory(&history);
    STARTWORD(filename);

    int totalgame = toInteger(currentWord);
    for (int i = 0; i < totalgame; i++)
    {
        ADVWORD();
        InsertAt(&gamefile, currentWord, i);
    }

    ADVWORD();
    int temp = toInteger(currentWord);
    for (int i = 0; i < temp; i++)
    {
        ADVWORD();
        pushGame(&history, currentWord);
    }

    for (int i = 0; i < totalgame; i++)
    { // total game
        ADVWORD();
        data tempdata;
        createEmptyData(&tempdata);
        tempdata.game = gamefile.A[i];
        temp = toInt(currentWord.TabWord[0]);
        for (int j = 0; j < temp; j++)
        { // total players
            Word tempname, tempscore;
            tempscore.Length = 0;
            tempname.Length = 0;
            ADVWORD();
            int k = 0;
            for (int n = 0; n < currentWord.Length; n++)
            { // data players
                if (currentWord.TabWord[n] == ' ')
                {
                    for (int p = 0; p < currentWord.Length - n; p++)
                    {
                        tempscore.TabWord[p] = currentWord.TabWord[n + 1];
                        tempscore.Length++;
                        n++;
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
}
// <<<<<<< HEAD
//     // }

// =======
// }

// int main(){
//     loadData("config.txt");
// >>>>>>> 16a56fa7bef3ca82765f9d0c2272e7e3b97da6b8
// }