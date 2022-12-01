#ifndef map_H
#define map_H
#include <stdio.h>
#include "../../boolean.h"
#include "../mesinkarakter/mesinkarakter.h"
#include "../mesinkata/mesinkata.h"

/* MODUL Map
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

// #define false 0
// #define true 1
#define Nill 0
#define MaxEl 10
#define Undefined -999

// typedef int bool;
typedef int keytype;
typedef int valuetype;
typedef int addresss;
typedef char  temp;
typedef Word keyName;
typedef int value;

typedef struct {
	keytype Key;
	valuetype Value;
} infotypee;

typedef struct {
    keytype key;
    temp containt;
} infoTipe;

typedef struct {
    keyName name;
    value score;
} player;

typedef struct {
	infotypee Elements[MaxEl];
	addresss Count;
} Map;

typedef struct {
    temp Element[MaxEl][MaxEl];
    addresss Count;
} map;

typedef struct {
    player Element[MaxEl];
    addresss Count;
} data;

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreatEEmpty(Map *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

void createEmpty(map *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

void createEmptyData(data *M);

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean isMt(Map M);
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsFull(Map M);
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytype k);
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

value scoreIs(data M, keyName k);

void Insert(Map *M, keytype k, valuetype v);
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void InsertData(data *M, keyName k, value v);

void Delete(Map *M, keytype k);
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMember(Map M, keytype k);
/* Mengembalikan true jika k adalah member dari M */

boolean IsDataValid(data M, keyName k);
#endif