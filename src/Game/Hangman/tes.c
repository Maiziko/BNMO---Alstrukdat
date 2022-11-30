#include <stdio.h>
#include <time.h>
#include "../../ADT/mesinkata/mesinkata.c"
#include "../../ADT/mesinkarakter/mesinkarakter.c"
#include "../../ADT/arraydin/arraydin.c"
// #include "kamus.txt"

// ArrayDin read(ArrayDin dest, char * filename) {
//     Word current;
//     dest = MakeArrayDin();
//     int i = 0;
//     STARTWORD("lib.txt");
//     while(!EndWord) {
//         current = currentWord;
//         InsertAt(&dest, current, i);
//         ADVWORD();
//         i++;
//     }
//     return dest;
// }

// Word getRandom(ArrayDin list) {
//     time_t t;
//     srand((unsigned)time(&t));
//     return Get(list, rand() % list.Neff + 1);
// }

int main() {
    // ArrayDin lib = read(lib, "lib.txt");
    // Word ans = getRandom(lib);
    // PrintWord(ans);
    // Word current;
    // ArrayDin dest = MakeArrayDin();
    // int i = 0;
    STARTWORD("lib.txt");
    PrintWord(currentWord);
    // ADVWORD();
    // current = currentWord;
    // InsertAt(&dest, current, i);
    // PrintWord(current);
    // while(!EndWord) {
    //     current = currentWord;
    //     // InsertAt(&dest, current, i);
    //     PrintWord(current);
    //     ADVWORD();
    //     i++;
    // }
    // printf("p");
}
