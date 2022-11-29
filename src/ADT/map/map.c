#include <stdio.h>
#include "map.h"

/* MODUL Map
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

// #define false 0
// #define true 1

// typedef int bool;

/* Definisi Map M kosong : M.Count = Nill */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreatEEmpty(Map *M)
{
    /* I.S. Sembarang */
    /* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
    /* Ciri Map kosong : count berNillai Nill */
    (*M).Count = Nill;
}

void createEmpty(map *M)
{
    /* I.S. Sembarang */
    /* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
    /* Ciri Map kosong : count berNillai Nill */
    (*M).Count = Nill;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean isMt(Map M)
{
    /* Mengirim true jika Map M kosong*/
    /* Ciri Map kosong : count berNillai Nill */
    return (M).Count == Nill;
}

boolean IsFull(Map M)
{
    /* Mengirim true jika Map M penuh */
    /* Ciri Map penuh : count berNillai MaxEl */
    return (M).Count == MaxEl;
}

/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytype k)
{
    /* Mengembalikan Nillai value dengan key k dari M */
    /* Jika tidak ada key k pada M, akan mengembalikan Undefined */
    int i = 0;
    while (i < M.Count)
    {
        if (M.Elements[i].Key == k)
        {
            return M.Elements[i].Value;
        }
        i++;
    }
    return Undefined;
}

void Insert(Map *M, keytype k, valuetype v)
{
    /* Menambahkan Elmt sebagai elemen Map M. */
    /* I.S. M mungkin kosong, M tidak penuh
            M mungkin sudah beranggotakan v dengan key k */
    /* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
    if (!IsMember(*M, k))
    {
        (*M).Elements[(*M).Count].Value = v;
        (*M).Elements[(*M).Count].Key = k;
        (*M).Count += 1;
    }
}

void Delete(Map *M, keytype k)
{
    /* Menghapus Elmt dari Map M. */
    /* I.S. M tidak kosong
            element dengan key k mungkin anggota / bukan anggota dari M */
    /* F.S. element dengan key k bukan anggota dari M */
    if (IsMember(*M, k))
    {
        int i = 0;
        boolean found = false;
        while (i < (*M).Count && !found)
        {
            if ((*M).Elements[i].Key == k)
            {
                (*M).Count--;
                while (i < (*M).Count)
                {
                    (*M).Elements[i] = (*M).Elements[i + 1];
                    i++;
                }
                found = true;
            }
            i++;
        }
    }
}

boolean IsMember(Map M, keytype k)
{
    /* Mengembalikan true jika k adalah member dari M */
    boolean found = false;
    int i = 0;
    while (i < M.Count && !found)
    {
        if (M.Elements[i].Key == k)
        {
            found = true;
        }
        i++;
    }
    return found;
}