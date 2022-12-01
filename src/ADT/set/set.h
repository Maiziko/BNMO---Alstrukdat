#ifndef set_H
#define set_H
#include <stdio.h>
#include "../../boolean.h"
#include "../mesinkarakter/mesinkarakter.h"
#include "../mesinkata/mesinkata.h"

#define Nil 0
#define CAPACITY 100
#define Undefined -999

typedef Word Eltype;

typedef struct{
    Eltype buffer[CAPACITY-1];
    int Length;
} Set;

void CreateSet(Set *S);

boolean isSetEmpty(Set S);

void addToSet(Set *S, Eltype e);

void removeFromSet(Set *S, Eltype e);

boolean isIn(Set S, Eltype e);

#endif