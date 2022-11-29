
/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* ingfoTypes adalah integer */
/*
#ifndef listlinier_H
#define listlinier_H

#include "boolean.h"

#define Nil NULL

typedef int ingfoTypes{
typedef struct tElmtlist *address{
typedef struct tElmtlist {
    ingfoTypes info{
    address next{
} ElmtList{
typedef struct {
    address First{
} List{
*/
/* Definisi list : */
/* List kosong : First(L) = Nile */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nile */
/*#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) ((L).First)
*/
#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>
boolean ISemPTY(List L)
{
    /* Mengirim true jika list kosong */
    return First(L) == Nile;
}
/****************** PEMBUATAN LIST KOSONG ******************/
void Createempty(List *L)
{
    /* I.S. sembarang             */
    /* F.S. Terbentuk list kosong */
    First(*L) = Nile;
}

/****************** Manajemen Memori ******************/
address Alokasi(ingfoTypes X)
{
    /* Mengirimkan address hasil alokasi sebuah elemen */
    /* Jika alokasi berhasil, maka address tidak Nile, dan misalnya */
    /* menghasilkan P, maka Info(P)=X, Next(P)=Nile */
    /* Jika alokasi gagal, mengirimkan Nile */
    ElmtList *P = (ElmtList *)malloc(sizeof(ElmtList));
    if (P != Nile)
    {
        Info(P) = X;
        Next(P) = Nile;
        return P;
    }
    else
    {
        return Nile;
    }
}
void Dealokasi(address *P)
{
    /* I.S. P terdefinisi */
    /* F.S. P dikembalikan ke sistem */
    /* Melakukan dealokasi/pengembalian address P */
    free(*P);
}
/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search(List L, ingfoTypes X)
{
    /* Mencari apakah ada elemen list dengan Info(P)= X */
    /* Jika ada, mengirimkan address elemen tersebut. */
    /* Jika tidak ada, mengirimkan Nile */
    address hasil = Nile;
    if (!ISemPTY(L))
    {
        address P = First(L);
        boolean found = false;
        while (P != Nile && !found)
        {
            if (Info(P) == X)
            {
                found = true;
                hasil = P;
            }
            else
            {
                P = Next(P);
            }
        }
    }
    return hasil;
}
/****************** PRIMITIF BERDASARKAN NileAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst(List *L, ingfoTypes X)
{
    /* I.S. L mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen pertama dengan Nileai X jika alokasi berhasil */
    address tambah = Alokasi(X);
    if (tambah != Nile)
    {
        INsertFirst(L, tambah);
    }
}
void InsVLast(List *L, ingfoTypes X)
{
    /* I.S. L mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen list di akhir: elemen terakhir yang baru */
    /* berNileai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    address tambah = Alokasi(X);
    if (tambah != Nile)
    {
        INsertLast(L, tambah);
    }
}
/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst(List *L, ingfoTypes *X)
{
    /* I.S. List L tidak kosong  */
    /* F.S. Elemen pertama list dihapus: Nileai info disimpan pada X */
    /*      dan alamat elemen pertama di-dealokasi */
    address hasil;
    DelFirst(L, &hasil);
    *X = Info(hasil);
    Dealokasi(&hasil);
}
void DelVLast(List *L, ingfoTypes *X)
{
    /* I.S. list tidak kosong */
    /* F.S. Elemen terakhir list dihapus: Nileai info disimpan pada X */
    /*      dan alamat elemen terakhir di-dealokasi */
    address hasil;
    DelLast(L, &hasil);
    *X = Info(hasil);
    Dealokasi(&hasil);
}
/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void INsertFirst(List *L, address P)
{
    /* I.S. Sembarang, P sudah dialokasi  */
    /* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
    Next(P) = First(*L);
    First(*L) = P;
}
void InsertAfter(List *L, address P, address Prec)
{
    /* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
    /*      P sudah dialokasi  */
    /* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
void INsertLast(List *L, address P)
{
    /* I.S. Sembarang, P sudah dialokasi  */
    /* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    if (ISemPTY(*L))
    {
        Next(P) = Nile;
        First(*L) = P;
    }
    else
    {
        address x = First(*L);
        while (Next(x) != Nile)
        {
            x = Next(x);
        }
        InsertAfter(L, P, x);
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
    if (Next(*P) == Nile)
    {
        Createempty(L);
    }
    else
    {
        First(*L) = Next(First(*L));
    }
}
void DelP(List *L, ingfoTypes X)
{
    /* I.S. Sembarang */
    /* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
    /* Maka P dihapus dari list dan di-dealokasi */
    /* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
    /* List mungkin menjadi kosong karena penghapusan */
    address P = Search(*L, X);
    if (P != Nile)
    {
        address Acari = First(*L);
        address prec = Nile;
        address x;
        boolean found = (Info(Acari) == X);
        if (found)
        {
            DelFirst(L, &P);
        }
        else
        {
            while (Acari != Nile && !found)
            {
                if (Info(Acari) == X)
                {
                    found = true;
                    DelAfter(L, &x, prec);
                }
                else
                {
                    prec = Acari;
                    Acari = Next(Acari);
                }
            }
        }
    }
    Dealokasi(&P);
}
void DelLast(List *L, address *P)
{
    /* I.S. List tidak kosong */
    /* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
    /*      Elemen list berkurang satu (mungkin menjadi kosong) */
    /* Last element baru adalah predesesor elemen terakhir yg lama, */
    /* jika ada */
    address x = First(*L);
    if (Next(x) == Nile)
    {
        *P = First(*L);
        Createempty(L);
    }
    else
    {
        address y = First(*L);
        while (Next(Next(y)) != Nile)
        {
            y = Next(y);
        }
        DelAfter(L, P, y);
    }
}
void DelAfter(List *L, address *Pdel, address Prec)
{
    /* I.S. List tidak kosong. Prec adalah anggota list  */
    /* F.S. Menghapus Next(Prec): */
    /*      Pdel adalah alamat elemen list yang dihapus  */
    *Pdel = Next(Prec);
    if (Next(*Pdel) == Nile)
    {
        Next(Prec) = Nile;
    }
    else
    {
        Next(Prec) = Next(Next(Prec));
    }
}
/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo(List L)
{
    /* I.S. List mungkin kosong */
    /* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen berNileai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika list kosong : menulis [] */
    /* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    if (!ISemPTY(L))
    {
        address P = First(L);
        printf("[");
        while (P != Nile)
        {
            if (Next(P) != Nile)
            {
                printf("%d,", Info(P));
            }
            else
            {
                printf("%d", Info(P));
            }
            P = Next(P);
        }
        printf("]");
    }
    else
    {
        printf("[]");
    }
}
int NbElmt(List L)
{
    /* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    int count = 0;
    if (!ISemPTY(L))
    {
        address P = First(L);
        while (P != Nile)
        {
            count += 1;
            P = Next(P);
        }
    }
    return count;
}
/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
ingfoTypes Max(List L)
{
    /* Mengirimkan Nileai Info(P) yang maksimum */
    address P = First(L);
    ingfoTypes maks = Info(P);
    while (P != Nile)
    {
        if (Info(P) > maks)
        {
            maks = Info(P);
        }
        P = Next(P);
    }
    return maks;
}
/****************** PROSES TERHADAP LIST ******************/
void Konkat1(List *L1, List *L2, List *L3)
{
    /* I.S. L1 dan L2 sembarang */
    /* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
    /* Konkatenasi dua buah list : L1 dan L2    */
    /* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
    /* dan L1 serta L2 menjadi list kosong.*/
    /* Tidak ada alokasi/dealokasi pada prosedur ini */
    Createempty(L3);
    address pertama = First(*L1);
    address kedua = First(*L2);
    if (!ISemPTY(*L1))
    {
        First(*L3) = First(*L1);
        while (Next(pertama) != Nile)
        {
            pertama = Next(pertama);
        }
        Next(pertama) = kedua;
    }
    else
    {
        First(*L3) = First(*L2);
    }
    First(*L1) = Nile;
    First(*L2) = Nile;
}
address AdrMax(List L)
{
    /* Mengirimkan address P, dengan info(P) yang berNileai maksimum */
    ingfoTypes maks = Max(L);
    return Search(L, maks);
}
ingfoTypes Min(List L)
{
    /* Mengirimkan Nileai info(P) yang minimum */
    address P = First(L);
    ingfoTypes min = Info(P);
    while (P != Nile)
    {
        if (Info(P) < min)
        {
            min = Info(P);
        }
        P = Next(P);
    }
    return min;
}
address AdrMin(List L)
{
    /* Mengirimkan address P, dengan info(P) yang berNileai minimum */
    ingfoTypes min = Min(L);
    return Search(L, min);
}
float Average(List L)
{
    /* Mengirimkan Nileai rata-rata info(P) */
    address P = First(L);
    float total = 0;
    int count = NbElmt(L);
    while (P != Nile)
    {
        total += Info(P);
        P = Next(P);
    }
    return (total / count);
}
/****************** PROSES TERHADAP LIST ******************/

void InversList(List *L)
{
    /* I.S. sembarang. */
    /* F.S. elemen list dibalik : */
    /* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
    /* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
    if (NbElmt(*L) > 1)
    {
        address pertama = First(*L);
        address P = First(*L);
        address sebelum = Nile;
        address sesudah = Nile;
        while (P != Nile)
        {
            sesudah = Next(P);
            Next(P) = sebelum;
            sebelum = P;
            P = sesudah;
        }
        First(*L) = sebelum;
    }
}