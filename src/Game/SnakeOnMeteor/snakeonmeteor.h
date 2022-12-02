#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../ADT/map/map.h"
#include "../../ADT/mesinkata/mesinkata.h"
#include "../../ADT/mesinkarakter/mesinkarakter.h"
#include "../../ADT/listlinier/listlinier.h"

void MoveUp(map new, char pemain, char makanan);
/* Membuat pergerakan snake ke atas dari posisi awal*/

void MoveDown(map new, char pemain, char makanan);
/* Membuat pergerakan snake ke bawah dari posisi awal*/

void MoveLeft();
/* Membuat pergerakan snake ke kiri dari posisi awal*/

void MoveRight();
/* Membuat pergerakan snake ke kanan dari posisi awal*/

map GenerateMap(map board, char player, char makanan);
/* Menghasilkan sebuah Map*/

void PrintMap(map new, int score);
/* Menampilkan Map yang telah dibuat*/

int RandPosisi();
/* Menghasilkan posisi random untuk makanan*/

int SnakeOnMeteor(int *score);

/**/