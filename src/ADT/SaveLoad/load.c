#include "load.h"

// char toKar()

void Load(Word kata, ArrayDin file, ArrayData dataplayer, History history)
{
    char filetext[100];
    int i = 0, j = 0, n = 5;

    filetext[0] = 'D';
    filetext[1] = 'a';
    filetext[2] = 't';
    filetext[3] = 'a';
    filetext[4] = '/';

    for (j = 0; j < kata.Length; j++)
    {
        filetext[n] = kata.TabWord[j];
        n++;
    }
    filetext[n] = '\0';

    if (KSTART(filetext) == 1)
    {
    STARTWORD(filetext);

    int totalgame = toInt(currentWord.TabWord[0]);
    for(int i = 0; i < totalgame; i++) {
        ADVWORD();
        InsertAt(&file, currentWord, i);
    }

    ADVWORD();
    int temp = toInt(currentWord.TabWord[0]);
    for(int i = 0; i < temp; i++) {
        ADVWORD();
        pushGame(&history, currentWord);
    }

    for (int i = 0; i < totalgame; i++) { //total game
        ADVWORD();
        data tempdata; createEmptyData(&tempdata);
        tempdata.game = file.A[i];
        temp = toInt(currentWord.TabWord[0]);
        for(int j = 0; j < temp; j++) { // total players
            Word tempname, tempscore;
            tempscore.Length = 0;
            tempname.Length = 0;
            ADVWORD();
            int k = 0;
            for(int n = 0; n < currentWord.Length; n++){ // data players
                if (currentWord.TabWord[n] == ' ') {
                    for(int p = 0; p < currentWord.Length-n; p++){           
                        tempscore.TabWord[p] = currentWord.TabWord[n+1];
                        tempscore.Length++;
                        n++;
                    } break;
                }
                tempname.TabWord[k] = currentWord.TabWord[n];
                tempname.Length++;
                k++;
            }
            tempdata.Element[i].name = tempname;
            tempdata.game = file.A[i];
            tempdata.Element[i].score = toInteger(tempscore);
            InsertDataAt(&dataplayer, tempdata, i);          
        }
    }
    }
    else
    {
        file.Neff = 0;
        dataplayer.Neff = 0;
        history.idxTop = 0;
    }
}