#include "mesinkarakter.h"
#include <stdio.h>

char currentChar;
boolean EOP;
static FILE *pita;

void START(char* filename) {
    pita = stdin;
    ADV();
}

void ADV() {
    fscanf(pita,"%c",&currentChar);
    if (IsEOP()) {
        fclose(pita); 
    }
}

char GetCC() {
    return (currentChar);
}

boolean IsEOP() {
    return (currentChar == MARK);
}
