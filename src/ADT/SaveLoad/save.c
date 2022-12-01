#include <stdio.h>
#include "../arraydin/arraydin.h"
#include "../mesinkata/mesinkata.h"
#include "../mesinkarakter/mesinkarakter.h"

void SAVE(ArrayDin file, Word CCommand)
{
    FILE *fptr;
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
        filetext[j + 5] = CCommand.TabWord[j + 5];
    }
    filetext[j] = '\0';

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
    printf("10. SCOREBOARD                              : Untuk melihat scoreboard game permainan sebelumnya\n");
    printf("\n");
    printf("11. RESET SCOREBOARD                        : Untuk menghapus Scoreboard yang ada sesuai keinginanmu \n");
    printf("\n");
    printf("12. HISTORY <n>                             : Menampilkan history permainanmu sebanyak n permainan \n");
    printf("\n");
    printf("13. RESET HISTORY                           : Menghapus semua history yang ada\n");
    printf("\n");
    printf("14. HELP - Jika Tidak tahu COMMAND yang sesuai\n");
    printf("\n");
    printf("15. QUIT - Jika Ingin Keluar dari mesin BNMO\n");
    printf("\n");
}
