#include "set.c"
#include "../mesinkarakter/mesinkarakter.c"
#include "../mesinkata/mesinkata.c"

int main(){
    Set S;
    CreateSet(&S);
    int i = 0; 
    while (i < 5) {
        printf("Masukan : ");
        STARTCOMMAND();
        addToSet(&S, CCommand);
        i++;
    }
    printf("\nSET AWAL\n");
    printf("Length : %d\n", S.Length);
    for(int j = 0; j < S.Length; j++){
        PrintWord(S.buffer[j]);
    }
    printf("\n");

    removeFromSet(&S, S.buffer[2]);

    printf("SET AKHIR\n");
    printf("Length : %d\n", S.Length);
    for(int j = 0; j < S.Length; j++){
        PrintWord(S.buffer[j]);
    }
}