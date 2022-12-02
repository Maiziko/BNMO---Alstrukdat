#include "Hangman.h"

ArrayDin read(ArrayDin dest, char *filename)
{
    Word current;
    dest = MakeArrayDin();
    int i = 0;
    STARTWORD("lib.txt");
    while (!EndWord)
    {
        current = currentWord;
        InsertAt(&dest, current, i);
        ADVWORD();
        i++;
    }
    return dest;
}

Word getRandom(ArrayDin list)
{
    time_t t;
    srand((unsigned)time(&t));
    return Get(list, rand() % list.Neff + 1);
}

boolean isDone(Word ans, ArrayDin *tries)
{
    boolean p;
    for (int j = 0; j < ans.Length; j++)
    {
        p = false;
        for (int k = 0; k < (*tries).Neff; k++)
        {
            if ((*tries).A[k].TabWord[0] == ans.TabWord[j])
            {
                p = true;
            }
        }
    }
    return p;
}

boolean isIn(Word ans, Word guess)
{
    boolean ada = false;
    int i = 0;
    while (!ada && i < ans.Length)
    {
        if (ans.TabWord[i] == guess.TabWord[0])
        {
            ada = true;
        }
        i++;
    }
    return ada;
}

int Hangman(int *score)
{
    ArrayDin tries = MakeArrayDin(), lib = read(lib, "lib.txt");
    int chances = 10;
    Word guess, ans;
    ArrayDin tes = lib;

    printf("==============================\n");
    printf("\t   HANGMAN  \t\n");
    printf("==============================\n");

    while (chances > 0)
    {
        tries = MakeArrayDin();
        ans = getRandom(lib);

        for (int i = 0; i < ans.Length; i++)
        {
            printf("_ ");
        }
        printf("\n");
        boolean win = false;

        while (!win)
        {
            int m = 0;
            printf("Tebak : ");
            STARTCOMMAND();
            printf("\n");

            while (isMemberOf(tries, CCommand))
            {
                printf("Huruf sudah ditebak. Coba lagi!\n");
                printf("Tebak : ");
                STARTCOMMAND();
                printf("\n");
            }

            if (!isIn(ans, CCommand))
            {
                chances -= 1;
            }

            InsertAt(&tries, CCommand, m++);

            printf("Tebakan sebelumnya : ");
            for (int k = 0; k < tries.Neff; k++)
            {
                printf("%c ", tries.A[k].TabWord[0]);
            }
            printf("\n");

            boolean q = true;
            for (int j = 0; j < ans.Length; j++)
            {
                boolean p = false;
                for (int k = 0; k < tries.Neff; k++)
                {
                    if (tries.A[k].TabWord[0] == ans.TabWord[j])
                    {
                        printf("%c ", tries.A[k].TabWord[0]);
                        p = true;
                    }
                }
                if (!p)
                {
                    printf("_ ");
                    q = false;
                }
            }
            printf("\n");

            if (chances <= 0)
            {
                printf("Kesempatan kamu habis!\n");
                break;
            }

            printf("Kesempatan : %d\n", chances);
            printf("==============================\n");

            if (q == true)
            {
                (*score) += ans.Length;
                DeleteAt(&lib, SearchArrayDin(lib, ans));
                DeallocateArrayDin(&tries);
                win = true;
            }
        }
    }
    printf("==============================\n");
    printf("PERMAINAN SELESAI!\nSkor Kamu : %d\n", (*score));
    printf("==============================\n");
}

// int main() {
//     Hangman();
// }