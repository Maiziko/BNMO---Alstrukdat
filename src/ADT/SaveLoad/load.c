#include <stdio.h>
#include "../../ADT/stack/stack.h"
#include "../../ADT/arraydin/arraydin.h"
#include "../../ADT/mesinkata/mesinkata.h"
#include "../../ADT/mesinkarakter/mesinkarakter.h"
#include "../../ADT/map/map.h"
#include "../../ADT/set/set.h"

// char toKar()

void Load(Word kata, ArrayDin gamefile, ArrayData dataplayer, History history)
{
    PrintWord(kata);
    char filetext[100];
    int i = 0, j = 0;
    // int n = 5;

    filetext[0] = 'D';
    filetext[1] = 'a';
    filetext[2] = 't';
    filetext[3] = 'a';
    filetext[4] = '/';
    // printf("%s\n", filetext);

    for (int j = 0; j < kata.Length; j++)
    {
        filetext[j+5] = kata.TabWord[j];
    }
    j++;
    filetext[j] = '\0';
    printf("Data/"+toChar(kata));

    if (KSTART(filetext) == 1)
    {

    STARTWORD(filetext);

    int totalgame = toInteger(currentWord);
    for(int i = 0; i < totalgame; i++) {
        ADVWORD();
        InsertAt(&gamefile, currentWord, i);
    }

    ADVWORD();
    int temp = toInteger(currentWord);
    for(int i = 0; i < temp; i++) {
        ADVWORD();
        pushGame(&history, currentWord);
    }

    for (int i = 0; i < totalgame; i++) { //total game
        ADVWORD();
        data tempdata; createEmptyData(&tempdata);
        tempdata.game = gamefile.A[i];
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
    else
    {
        printf("p");
        gamefile.Neff = 0;
        dataplayer.Neff = 0;
        history.idxTop = 0;
    }
}