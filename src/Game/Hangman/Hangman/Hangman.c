#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    srand(time(NULL));
    char tebakKata[][16] = {
        "ayam",
        "mata",
        "smart",
        "kudanil",
        "kucing",
        "bebek",
        "halo"};

    int randomIndex = rand() % 7; // index for random word
    int kesempatan = 10;
    int numCorrect = 0;
    int oldCorrect = 0;
    int panjangKata = strlen(tebakKata[randomIndex]);
    int tebakHuruf[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int keluar = 0;
    int loopIndex = 0;
    int sudahditebak = 0;
    char tebak[16];
    char hurufMasuk;

    while (numCorrect < panjangKata)
    { // game loop

        printf("\n\nSelamat datang di Hangman!\nKata:");

        for (loopIndex = 0; loopIndex < panjangKata; loopIndex++)
        {

            if (tebakHuruf[loopIndex] == 1)
            {
                printf("%c", tebakKata[randomIndex][loopIndex]);
            }
            else
            {
                printf("-");
            }
        }

        printf("\n");
        printf("Kesempatan :%d\n", kesempatan);
        printf("Masukkan tebakan:");
        fgets(tebak, 16, stdin);

        if (strncmp(tebak, "keluar", 4) == 0)
        {
            keluar = 1;
            break;
        }

        hurufMasuk = tebak[0];
        sudahditebak = 0;
        oldCorrect = numCorrect;

        for (loopIndex = 0; loopIndex < panjangKata; loopIndex++)
        {

            if (tebakHuruf[loopIndex] == 1)
            {
                if (tebakKata[randomIndex][loopIndex] == hurufMasuk)
                {
                    sudahditebak = 1;
                    break;
                }
                continue;
            }

            if (hurufMasuk == tebakKata[randomIndex][loopIndex])
            {
                tebakHuruf[loopIndex] = 1;
                numCorrect++;
            }
        }

        if (oldCorrect == numCorrect && sudahditebak == 0)
        {
            kesempatan--;
            printf("Maaf, jawaban anda salah:(\n");
            if (kesempatan == 0)
            {
                break;
            }
        }
        else
        {
            printf("Yay jawaban anda benar! :)\n");
        }
    }

    if (keluar == 1)
    { // while loop
        printf("\nAnda telah keluar dari permainan\n");
    }
    else if (kesempatan == 0)
    {
        printf("\n Maaf tebakan anda salah! jawabannya adalah : %s\n",
               tebakKata[randomIndex]);
    }
    else
    {
        printf("\nBerhasil menebak kata %s! SELAMAT ANDA MENANG!! :) \n", tebakKata[randomIndex]);
        main();
    }

    return 0;
}
