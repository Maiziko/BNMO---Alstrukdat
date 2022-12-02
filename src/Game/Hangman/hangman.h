#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../ADT/mesinkata/mesinkata.h"
#include "../../ADT/mesinkarakter/mesinkarakter.h"
#include "../../ADT/arraydin/arraydin.h"
#include "../../ADT/map/map.h"
#include "../../ADT/set/set.h"

ArrayDin read(ArrayDin dest, char *filename);

Word getRandom(ArrayDin list);

boolean isDone(Word ans, ArrayDin *tries);

boolean isIn(Word ans, Word guess);

// void addPlayerData()

int Hangman();