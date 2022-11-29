#include <stdio.h>
#include "../arraydin/arraydin.h"
#include "../mesinkata/mesinkata.h"
#include "../mesinkarakter/mesinkarakter.h"

void SAVE(ArrayDin file, Word CCommand)
{
    FILE *fptr;
    char gm[100];
    char gm1[100];
    char gm2[100];
    char m[100];
    char filetext[100];
    int i = 0;
    int j = 0;

    filetext[0] = 'D';
    filetext[1] = 'a';
    filetext[2] = 't';
    filetext[3] = 'a';
    filetext[4] = '/';

    for (j = 0; j < CCommand.Length; j++)
    {
        gm[j] = CCommand.TabWord[j];
    }
    gm[j] = '\0';

    for (j = 0; j < CCommand.Length; j++)
    {
        m[j] = CCommand.TabWord[j + 5];
    }

    for (j = 0; j < CCommand.Length; j++)
    {
        gm1[j] = gm[j + 5];
    }
    gm1[j] = '\0';

    for (j = 0; j < CCommand.Length; j++)
    {
        filetext[j + 5] = CCommand.TabWord[j + 5];
    }
    filetext[j] = '\0';

    for (j = 0; j < 4; j++)
    {
        gm2[j] = CCommand.TabWord[j];
    }
    gm2[j] = '\0';

    fptr = fopen(filetext, "w");
    for (int i = 0; i < file.Neff; i++)
    {
        for (int j = 0; j < file.A[i].Length; j++)
        {
            fprintf(fptr, "%c", file.A[i].TabWord[j]);
        }
        fprintf(fptr, "\n");
    }
    fprintf(fptr, ".");
    fclose(fptr);
}

void HELP()
{
    printf("\n");
    printf("Berikut adalah daftar perintah yang tersedia :\n");
    printf("\n");
    printf("1. START - Masukkan COMMAND                 : 'START' saat BNMO mulai berjalan\n");
    printf("\n");
    printf("2. LOAD <filename>.txt - Masukkan COMMAND   : LOAD + <filename>.txt saat BNMO mulai berjalan, jika tidak masukkan COMMAND: START\n");
    printf("\n");
    printf("3. SAVE <filename>.txt - Masukkan COMMAND   : 'LIST GAME' untuk melihat daftar game yang tersedia\n");
    printf("\n");
    printf("4. LIST GAME - Masukkan COMMAND             : LIST GAME jika ingin melihat list game yang tersedia pada sistem\n");
    printf("\n");
    printf("5. DELETE GAME - Masukkan COMMAND           : DELETE GAME jika ingin menghapus Game buatan\n");
    printf("\n");
    printf("6. CREATE GAME - Masukkan COMMAND           : CREATE GAME jika ingin membuat sebuah game baru\n");
    printf("\n");
    printf("7. QUEUE GAME - Masukkan COMMAND            : QUEUE GAME jika ingin melihat antrian game yang bisa dimainkan\n");
    printf("\n");
    printf("8. PLAY GAME - Masukkan COMMAND             : PLAY GAME jika ingin memainkan sebuah permainan (RNG/Diner Dash/Lainya)\n");
    printf("\n");
    printf("9. SKIPGAME <n> - Masukkan COMMAND          : SKIPGAME <n>  jika ingin berpindah pada <n> game berikutnya\n");
    printf("\n");
    printf("10. HELP - Jika Tidak tahu COMMAND yang sesuai\n");
    printf("\n");
    printf("11. QUIT - Jika Ingin Keluar dari mesin BNMO\n");
    printf("\n");
}
