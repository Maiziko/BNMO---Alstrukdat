#include "stack.h"

/* *** Konstruktor/Kreator *** */
void CreateStack(Stack *s)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah s kosong */
{
    IDX_TOP(*s) = IDX_UNDEF;
}

void CreateHistory(History *h)
{
    IDX_TOP(*h) = IDX_UNDEF;
}

/* ************ Prototype ************ */
boolean isEmpty(Stack s)
/* Mengirim true jika s kosong: lihat definisi di atas */
{
    return IDX_TOP(s) == IDX_UNDEF;
}

boolean isHistEmpty(Stack h)
{
    return IDX_TOP(h) == IDX_UNDEF;
}

boolean isFull(Stack s)
/* Mengirim true jika tabel penampung nilai s stack penuh */
{
    return IDX_TOP(s) == CAPACITY - 1;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void push(Stack *s, ElTType val)
/* Menambahkan val sebagai elemen Stack s */
/* I.S. s mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 */
{
    IDX_TOP(*s)
    ++;
    TOP(*s) = val;
}

void pushGame(History *h, GameType game)
{
    IDX_TOP(*h)
    ++;
    TOP(*h) = game;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void pop(Stack *s, ElTType *val)
/* Menghapus val dari Stack s */
/* I.S. s tidak mungkin kosong */
/* F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 */
{
    *val = TOP(*s);
    IDX_TOP(*s)
    --;
}

/*prosedur untuk menghapus history game*/
void popGame(History *h, GameType *game)
{
    *game = TOP(*h);
    IDX_TOP(*h)
    --;
}

/*Untuk menampilkan history permainan*/
void displayHistory(History h)
{
    int i;
    for (i = 0; i < (h.idxTop + 1); i++)
    {
        printf("%d. ", i + 1);
        PrintWord(h.buffer[i]);
    }
}