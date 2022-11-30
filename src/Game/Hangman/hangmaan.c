#include <stdio.h>
#include <time.h>
#include "../../ADT/mesinkata/mesinkata.c"
#include "../../ADT/mesinkarakter/mesinkarakter.c"
#include "../../ADT/arraydin/arraydin.c"

// void addTo(ArrayDin file, Word kata) {
//     FILE *fptr;
//     char filename[100];
//     char filetxt[100];
//     char filetxt2[10];
//     int i = 0;
//     for (i = 0; i < kata.Length; i++)
//     {
//         filename[i] = kata.TabWord[i];
//     }
//     filename[i] = '\0';

//     for (i = 0; i < kata.Length; i++)
//     {
//         filetxt[i] = kata.TabWord[i + 5];
//     }
//     filetxt[i] = '\0';

//     for (i = 0; i < 4; i++)
//     {
//         filetxt2[i] = kata.TabWord[i];
//     }
//     filetxt2[i] = '\0';
//     Word Kata = toKata(filetxt);
//     if (IsKataSama(toKata(filetxt2), toKata("SAVE")))
//     {
//         wordStringCopy(filetxt, Kata);
//         fptr = fopen(filetxt, "w");
//         for (int i = 0; i < file.Neff; i++)
//         {
//             for (int j = 0; j < file.A[i].Length; j++)
//             {
//                 fprintf(fptr, "%c", file.A[i].TabWord[j]);
//             }
//             fprintf(fptr, "\n");
//         }
//         fprintf(fptr, ".");
//     }
//     fclose(fptr);
// }

ArrayDin read(ArrayDin dest, char * filename) {
    Word current;
    dest = MakeArrayDin();
    int i = 0;
    STARTWORD("lib.txt");
    while(!EndWord) {
        current = currentWord;
        InsertAt(&dest, current, i);
        ADVWORD();
        i++;
    }
    return dest;
}

Word getRandom(ArrayDin list) {
    time_t t;
    srand((unsigned)time(&t));
    return Get(list, rand() % list.Neff + 1);
}

// boolean isIn(Word ans, ArrayDin * tries){
//     boolean found = false;
//     int j = 0;
//     for(int i = 0; i < ans.Length; i++) {
//         while (!found && j < (*tries).Neff) {
//             if ((*tries).A[j].TabWord[0] == ans.TabWord[i]) {
//                 found = true;
//             } 
//             j++;     
//         }
//     }
// }

void display(Word ans, ArrayDin * tries) {
    for(int i = 0; i < ans.Length; i++) {
        for (int j = 0; j < (*tries).Neff; j++) {
            if (IsKataSama((*tries).A[j], toKata(&(ans.TabWord[i])))) {
                printf("%c ", ans.TabWord[i]);
            } 
            else {
                printf("_ ");
            }
        }
    } printf("\n");
}

int main() {
    ArrayDin tries = MakeArrayDin(), lib = read(lib, "lib.txt");
    int score, chances = 10;
    Word guess, ans;
    // PrintWord(ans);
    ArrayDin tes = lib;
    ans = getRandom(lib);
    // printf("Tebak : ");
    // STARTCOMMAND();
    // InsertAt(&tries, currentWord, 0);

    while (chances > 0) {
        // ans = getRandom(lib);
        // boolean win = false;
        // while (!win) {
            printf("Tebak : ");
            STARTCOMMAND();
            printf("\n");
            InsertLast(&tries, CCommand);
            for (int j = 0; j < ans.Length; j++) {
                if (IsKataSama((*tries).A[j], toKata(&(ans.TabWord[j])))) {
                    printf("%c ", ans.TabWord[j]);
                } 
                else {
                    printf("_ ");
                }
        }
            // display(ans, &tries);            
        // }
    }
}
