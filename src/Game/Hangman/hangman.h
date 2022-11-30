#include <stdio.h>
#include <time.h>
#include "../../ADT/mesinkata/mesinkata.c"
#include "../../ADT/mesinkarakter/mesinkarakter.c"
#include "../../ADT/arraydin/arraydin.c"

ArrayDin read(ArrayDin dest, char * filename);

Word getRandom(ArrayDin list);

boolean isDone(Word ans, ArrayDin * tries);

boolean isIn(Word ans, Word guess);

void hangman();