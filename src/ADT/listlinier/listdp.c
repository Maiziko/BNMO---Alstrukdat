
// Deskripsi : Implementasi ADT list dengan representasi pointer

#include <stdio.h>
#include "listdp.h"
#include <stdlib.h>
/* File : listdp.h */
/* ADT List dengan Double Pointer */
/* Representasi berkait dengan address adalah pointer */
/* infotype adalah integer */

// #ifndef listdp_H
// #define listdp_H

// #include "boolean.h"

// #define Nil NULL

// /* Definisi Type Data */
// typedef int infotype;
// typedef struct tElmtlist *address;
// typedef struct tElmtlist
// {
//     infotype info;
//     address next;
//     address prev;
// } ElmtList;
// typedef struct
// {
//     address First;
//     address Last;
// } List;

// /* Definisi list : */
// /* List kosong : First(L) = Nil dan Last(L) = Nil */
// /* Setiap elemen dengan address P dapat diacu Info(P), Next(P), Prev(P) */
// /* Elemen terakhir list: Last(L) */

// /* Notasi Akses */
// #define Info(P) (P)->info
// #define Next(P) (P)->next
// #define Prev(P) (P)->prev
// #define First(L) ((L).First)
// #define Last(L) ((L).Last)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty(List L)
{
    /* Mengirim true jika list kosong. Lihat definisi di atas. */
    return (First(L) == Nil && Last(L) == Nil);
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty(List *L)
{
    /* I.S. L sembarang  */
    /* F.S. Terbentuk list kosong. Lihat definisi di atas. */
    First(*L) = Nil;
    Last(*L) = Nil;
}
/****************** Manajemen Memori ******************/
address Alokasi(infotype X)
{
    /* Mengirimkan address hasil alokasi sebuah elemen */
    /* Jika alokasi berhasil, maka address tidak nil. */
    /* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
    /* Jika alokasi gagal, mengirimkan Nil. */
    address P = (address)malloc(sizeof(ElmtList));
    if (P != Nil)
    {
        Info(P) = X;
        Next(P) = Nil;
        Prev(P) = Nil;
    }
    return P;
}
void Dealokasi(address P)
{
    /* I.S. P terdefinisi */
    /* F.S. P dikembalikan ke sistem */
    /* Melakukan dealokasi/pengembalian address P */
    free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search(List L, infotype X)
{
    /* Mencari apakah ada elemen list dengan Info(P)=X */
    /* Jika ada, mengirimkan address elemen tersebut. */
    /* Jika tidak ada, mengirimkan Nil */
    address P = First(L);
    while (P != Nil && Info(P) != X)
    {
        P = Next(P);
    }
    return P;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst(List *L, infotype X)
{
    /* I.S. L mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
    address P = Alokasi(X);
    if (P != Nil)
    {
        if (IsEmpty(*L))
        {
            First(*L) = P;
            Last(*L) = P;
        }
        else
        {
            Next(P) = First(*L);
            Prev(First(*L)) = P;
            First(*L) = P;
        }
    }
}
void InsVLast(List *L, infotype X)
{
    /* I.S. L mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen list di akhir: elemen terakhir yang baru */
    /* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    address P = Alokasi(X);
    if (P != Nil)
    {
        if (IsEmpty(*L))
        {
            First(*L) = P;
            Last(*L) = P;
        }
        else
        {
            Next(Last(*L)) = P;
            Prev(P) = Last(*L);
            Last(*L) = P;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst(List *L, infotype *X)
{
    /* I.S. List L tidak kosong  */
    /* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
    /*      dan alamat elemen pertama di-dealokasi */
    address P = First(*L);
    *X = Info(P);
    if (Next(P) == Nil)
    {
        First(*L) = Nil;
        Last(*L) = Nil;
    }
    else
    {
        First(*L) = Next(P);
        Prev(First(*L)) = Nil;
    }
    Dealokasi(P);
}
void DelVLast(List *L, infotype *X)
{
    /* I.S. list tidak kosong */
    /* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
    /*      dan alamat elemen terakhir di-dealokasi */
    address P = Last(*L);
    *X = Info(P);
    if (Prev(P) == Nil)
    {
        First(*L) = Nil;
        Last(*L) = Nil;
    }
    else
    {
        Last(*L) = Prev(P);
        Next(Last(*L)) = Nil;
    }
    Dealokasi(P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst(List *L, address P)
{
    /* I.S. Sembarang, P sudah dialokasi  */
    /* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
    if (IsEmpty(*L))
    {
        First(*L) = P;
        Last(*L) = P;
    }
    else
    {
        Next(P) = First(*L);
        Prev(First(*L)) = P;
        First(*L) = P;
    }
}
void InsertLast(List *L, address P)
{
    /* I.S. Sembarang, P sudah dialokasi  */
    /* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    if (IsEmpty(*L))
    {
        First(*L) = P;
        Last(*L) = P;
    }
    else
    {
        Next(Last(*L)) = P;
        Prev(P) = Last(*L);
        Last(*L) = P;
    }
}
void InsertAfter(List *L, address P, address Prec)
{
    /* I.S. Prec pastilah elemen list{ P sudah dialokasi  */
    /* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    if (Next(Prec) == Nil)
    {
        InsertLast(L, P);
    }
    else
    {
        Next(P) = Next(Prec);
        Prev(Next(Prec)) = P;
        Next(Prec) = P;
        Prev(P) = Prec;
    }
}
void InsertBefore(List *L, address P, address Succ)
{
    /* I.S. Succ pastilah elemen list{ P sudah dialokasi  */
    /* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
    if (Prev(Succ) == Nil)
    {
        InsertFirst(L, P);
    }
    else
    {
        Prev(P) = Prev(Succ);
        Next(Prev(Succ)) = P;
        Prev(Succ) = P;
        Next(P) = Succ;
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst(List *L, address *P)
{
    /* I.S. List tidak kosong */
    /* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
    /*      Elemen list berkurang satu (mungkin menjadi kosong) */
    /* First element yg baru adalah suksesor elemen pertama yang lama */
    *P = First(*L);
    if (Next(First(*L)) == Nil)
    {
        First(*L) = Nil;
        Last(*L) = Nil;
    }
    else
    {
        First(*L) = Next(First(*L));
        Prev(First(*L)) = Nil;
    }
    Next(*P) = Nil;
    Prev(*P) = Nil;
}
void DelLast(List *L, address *P)
{
    /* I.S. List tidak kosong */
    /* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
    /*      Elemen list berkurang satu (mungkin menjadi kosong) */
    /* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
    *P = Last(*L);
    if (Prev(Last(*L)) == Nil)
    {
        First(*L) = Nil;
        Last(*L) = Nil;
    }
    else
    {
        Last(*L) = Prev(Last(*L));
        Next(Last(*L)) = Nil;
    }
    Next(*P) = Nil;
    Prev(*P) = Nil;
}
void DelP(List *L, infotype X)
{
    /* I.S. Sembarang */
    /* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
    /* maka P dihapus dari list dan didealokasi */
    /* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
    /* List mungkin menjadi kosong karena penghapusan */
    address P = Search(*L, X);
    if (P != Nil)
    {
        if (P == First(*L))
        {
            DelFirst(L, &P);
        }
        else if (P == Last(*L))
        {
            DelLast(L, &P);
        }
        else
        {
            Next(Prev(P)) = Next(P);
            Prev(Next(P)) = Prev(P);
            Next(P) = Nil;
            Prev(P) = Nil;
        }
        Dealokasi(P);
    }
}
void DelAfter(List *L, address *Pdel, address Prec)
{
    /* I.S. List tidak kosong. Prec adalah anggota list. */
    /* F.S. Menghapus Next(Prec): */
    /*      Pdel adalah alamat elemen list yang dihapus  */
    *Pdel = Next(Prec);
    if (Next(Prec) == Last(*L))
    {
        DelLast(L, Pdel);
    }
    else
    {
        Next(Prec) = Next(Next(Prec));
        Prev(Next(Prec)) = Prec;
        Next(*Pdel) = Nil;
        Prev(*Pdel) = Nil;
    }
}
void DelBefore(List *L, address *Pdel, address Succ)
{
    /* I.S. List tidak kosong. Succ adalah anggota list. */
    /* F.S. Menghapus Prev(Succ): */
    /*      Pdel adalah alamat elemen list yang dihapus  */
    *Pdel = Prev(Succ);
    if (Prev(Succ) == First(*L))
    {
        DelFirst(L, Pdel);
    }
    else
    {
        Prev(Succ) = Prev(Prev(Succ));
        Next(Prev(Succ)) = Succ;
        Next(*Pdel) = Nil;
        Prev(*Pdel) = Nil;
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward(List L)
{
    /* I.S. List mungkin kosong */
    /* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
    /* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika list kosong : menulis [] */
    /* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    address P = First(L);
    printf("[");
    while (P != Nil)
    {
        printf("%d", Info(P));
        if (Next(P) != Nil)
        {
            printf(",");
        }
        P = Next(P);
    }
    printf("]\n");
}
void PrintBackward(List L)
{
    /* I.S. List mungkin kosong */
    /* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
    /* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
    /* Jika list kosong : menulis [] */
    /* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    address P = Last(L);
    printf("[");
    while (P != Nil)
    {
        printf("%d", Info(P));
        if (Prev(P) != Nil)
        {
            printf(",");
        }
        P = Prev(P);
    }
    printf("]\n");
}
