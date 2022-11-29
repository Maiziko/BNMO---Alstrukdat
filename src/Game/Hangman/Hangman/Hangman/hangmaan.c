#include <stdio.h>
<<<<<<< HEAD
#include <time.h>
#include "../../ADT/mesinkata/mesinkata.c"
#include "../../ADT/mesinkarakter/mesinkarakter.c"
#include "../../ADT/arraydin/arraydin.c"

// void addTo(ArrayDin file, Word kata) {
//     FILE *fptr;
//     char filename[100];
//     char filetxt[100];
//     char filetxt2[10];
//     int i = 0;
//     for (i = 0; i < kata.Length; i++)
//     {
//         filename[i] = kata.TabWord[i];
//     }
//     filename[i] = '\0';

//     for (i = 0; i < kata.Length; i++)
//     {
//         filetxt[i] = kata.TabWord[i + 5];
//     }
//     filetxt[i] = '\0';

//     for (i = 0; i < 4; i++)
//     {
//         filetxt2[i] = kata.TabWord[i];
//     }
//     filetxt2[i] = '\0';
//     Word Kata = toKata(filetxt);
//     if (IsKataSama(toKata(filetxt2), toKata("SAVE")))
//     {
//         wordStringCopy(filetxt, Kata);
//         fptr = fopen(filetxt, "w");
//         for (int i = 0; i < file.Neff; i++)
//         {
//             for (int j = 0; j < file.A[i].Length; j++)
//             {
//                 fprintf(fptr, "%c", file.A[i].TabWord[j]);
//             }
//             fprintf(fptr, "\n");
//         }
//         fprintf(fptr, ".");
//     }
//     fclose(fptr);
// }

ArrayDin read(ArrayDin dest, char * filename) {
    Word current;
    dest = MakeArrayDin();
    int i = 0;
    STARTWORD("lib.txt");
    while(!EndWord) {
        current = currentWord;
        InsertAt(&dest, current, i);
        ADVWORD();
        i++;
    }
    return dest;
}

Word getRandom(ArrayDin list) {
    time_t t;
    srand((unsigned)time(&t));
    return Get(list, rand() % list.Neff + 1);
}

boolean isIn(Word ans, ArrayDin * tries){
    boolean found = false;
    int j = 0;
    for(int i = 0; i < ans.Length; i++) {
        while (!found && j < (*tries).Neff) {
            if ((*tries).A[j].TabWord[0] == ans.TabWord[i]) {
                found = true;
            } 
            j++;     
        }
    }
}

void display(Word ans, ArrayDin * tries) {
    for(int i = 0; i < ans.Length; i++) {
        if (isIn(ans, tries)) {
            printf("%c ", ans.TabWord[i]);
        } else {
            printf("_ ");
        }
        // for(int j = 0; j < (*tries).Neff; j++) {
        //     if ((*tries).A[j].TabWord[0] == ans.TabWord[i]) {
        //         printf("%c", ans.TabWord[i]);
        //     } else {
        //         printf("_");
        //     }            
        // }

    } printf("\n");
}

int main() {
    ArrayDin tries = MakeArrayDin(), lib = read(lib, "lib.txt");
    int score, chances = 10;
    Word guess, ans = getRandom(lib);
    ArrayDin tes = lib;

    printf("%c", Get(tes, SearchArrayDin(tes, ans)));

    while (chances > 0) {
        int i = 0;
        printf("Tebak : ");
        STARTCOMMAND();
        InsertAt(&tries, guess, i);
        i++;
        display(ans, &tries);
    }

    // for(int i = 0; i < ans.Length; i++) {
    //     // if (ans.TabWord[i] == guess) {
    //         printf("%c", ans.TabWord[i]);
    // //     } else {
    // //         printf("_");
    //     }
    // // } printf("\n");
}
=======
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
	srand(time(NULL));
	char tebakKata[][16] = {
		"ayam", 
		"mata",
		"smart",
		"kudanil",
		"kucing",
		"bebek",
        "halo"	
	};
	printf(" \n ===========================================||  H A N G M A N ||===========================================");
	printf(" \n [ ketik 'keluar' jika ingin keluar dari permainan ]\n");
	int randomIndex = rand() % 7; // index for random word
	int kesempatan = 10;
	int numCorrect = 0;
	int oldCorrect = 0;
	int panjangKata = strlen(tebakKata[randomIndex]);
	int tebakHuruf[8] = { 0,0,0,0,0,0,0,0 };
	int keluar = 0;	
	int loopIndex = 0;
	int sudahditebak = 0; 
	char tebak[16]; 
	char hurufMasuk;	
	
	while ( numCorrect < panjangKata ) {     // game loop	
	
		printf("\n\nSelamat datang di Hangman! \nKata:");
	
		for( loopIndex = 0; loopIndex < panjangKata; loopIndex++) {
		
			if(tebakHuruf[loopIndex] == 1) {
				printf("%c",tebakKata[randomIndex][loopIndex]);				
			} else {
				printf("-");
			}
		
		}	
		
		printf("\n");
        printf("Kesempatan :%d\n",kesempatan);
		printf("Masukkan tebakan:");
		fgets(tebak, 16, stdin);
		
		if( strncmp(tebak, "keluar", 4) == 0) {
			keluar = 1;
			break;
		}
		
		hurufMasuk = tebak[0];
		sudahditebak = 0; 
		oldCorrect = numCorrect;
		
		for( loopIndex = 0; loopIndex < panjangKata; loopIndex++) {
		
			if(tebakHuruf[loopIndex] == 1) {
				if(tebakKata[randomIndex][loopIndex] == hurufMasuk) {
					sudahditebak = 1; 
					break;
				} 
				continue;
			}
		
			if( hurufMasuk == tebakKata[randomIndex][loopIndex] ) {
				tebakHuruf[loopIndex] = 1;
				numCorrect++;				
			}		
		}	
		
		if( oldCorrect == numCorrect && sudahditebak == 0) {
			kesempatan--;
			printf("Maaf, jawaban anda salah:(\n");
			if (kesempatan == 0) {
				break;
			}
		} else {
			printf("Yay jawaban anda benar! :)\n");
		}
	
	} 
	
	if( keluar == 1 ) {	 // while loop
		printf("\nAnda telah keluar dari permainan\n");
	} else if (kesempatan == 0) {
		printf("\n Maaf tebakan anda salah! jawabannya adalah : %s\n",
		tebakKata[randomIndex]);	
	} else  {	
		printf("\nBerhasil menebak kata %s! SELAMAT ANDA MENANG!! :) \n", tebakKata[randomIndex]);
		main();
	} 
	
	return 0;
}

>>>>>>> cdd981df97cf540a1fa9e735975d9628aaedd720
