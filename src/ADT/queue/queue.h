/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */

#ifndef QUEUE_H
#define QUEUE_H

#include "../boolean.h"
#include "../mesinkata/mesinkata.h"
#include "../arraydin/arraydin.h"

#define IDX_UNDEF -1
#define CAPACITYY 10
#define IDX_UNDEf -1
#define capacity 10
/* Definisi elemen dan address */
typedef int ElTypee;
typedef Word Eltype;

typedef int ElTipee;

typedef struct
{
        ElTipee ID;
        ElTipee Durasi;
        ElTipee Ketahanan;
        ElTipee Harga;
} infotipe;

typedef struct
{
        infotipe Din[10];
        int Kepala;
        int ekor;
        int juml;
} Dinner_food;
typedef struct
{
        Eltype buffer[CAPACITYY];
        int idxHead;
        int idxTail;
} Queue;

/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define HEAD(q) (q).buffer[(q).idxHead]
#define TAIL(q) (q).buffer[(q).idxTail]
#define idx_Kepala(m) (m).Kepala
#define idx_ekor(m) (m).ekor

/* *** Kreator *** */
void CreateQueue(Queue *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
/**************************************************** Untuk Dinner Dash***********************************************************/

void CreateDinner(Dinner_food *m);
/*Membuat sebuah antrian kosong yang akan di gunakan untuk Dinner Dash*/

void enqdin(Dinner_food *Dinner, Dinner_food *pesanan, ElTipee idx);
/*Menambahkan Elemen berupa beberapa komponen yang ada pada buffer Din*/

void enqdiin(Dinner_food *masak, Dinner_Temp *DT);

void DelDin(Dinner_food *Dinner);
/*Menghapus Elemen pada antrian masak atau saji ketika ada dari mereka yang bernilai nol (Durasi / ketahanan)*/
boolean isDinEmpty();
/*Mengecek bahwa apakah idx kepala dan idx ekor dari memmen kosong atau tidak*/
int DinLength(Dinner_food Dinner);

/**************************************************** End line ********************************************************************/
/* ********* Prototype ********* */
boolean ISEMPTY(Queue q);
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean ISFull(Queue q);
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int length(Queue q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, Eltype val);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeue(Queue *q, Eltype *val);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */
void dequeuee(Queue *q, ElTypee idx);

void dequeueee(Queue *q, Eltype *val);

/* *** Display Queue *** */
void displayQueue(Queue q);
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */

void DelMem(Dinner_food *mem, ElTypee val);

// Dinner_Temp MakeDinner_Temp();
// void InsertLastDinner_Temp(Dinner_food *Dinner, Dinner_Temp *DT, int idx);
// void RemoveDinner_Temp(Dinner_Temp *DT, int idx);
Dinner_Temp MakeDinner_Temp();
void InsertLastDinner_Temp(Dinner_food *Dinner, Dinner_Temp *DT);
#endif
