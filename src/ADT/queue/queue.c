#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

/* *** Kreator *** */
void CreateQueue(Queue *q)
{
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */

/**************************************************** Untuk Dinner Dash***********************************************************/
void CreateDinner(Dinner_food *m)
{
    m->juml = IDX_UNDEf;
    idx_Kepala(*m) = IDX_UNDEf;
    idx_ekor(*m) = IDX_UNDEf;
    for (int i = 0; i < 10; i++)
    {
        (*m).Din[i].ID = IDX_UNDEf;
        (*m).Din[i].Durasi = IDX_UNDEf;
        (*m).Din[i].Ketahanan = IDX_UNDEf;
        (*m).Din[i].Harga = IDX_UNDEf;
    }
}

void enqdin(Dinner_food *Dinner, Dinner_food *pesanan, ElTipee idx)
{
    /*Menambahkan Elemen berupa beberapa komponen yang ada pada buffer Din*/
    if (isDinEmpty(*Dinner))
    {
        idx_Kepala(*Dinner) = 0;
        idx_ekor(*Dinner) = 0;
        (*Dinner).Din[idx_ekor(*Dinner)] = (*pesanan).Din[idx];
        Dinner->juml = 0;
        Dinner->juml = Dinner->juml + 1;
    }
    else if ((*Dinner).Din[idx_ekor(*Dinner)].ID == IDX_UNDEf)
    {
        idx_ekor(*Dinner) = (idx_ekor(*Dinner) - 1);
        (*Dinner).Din[idx_ekor(*Dinner)] = (*pesanan).Din[idx];
        Dinner->juml = Dinner->juml + 1;
    }
    else
    {
        idx_ekor(*Dinner) = (idx_ekor(*Dinner) + 1);
        (*Dinner).Din[idx_ekor(*Dinner)] = (*pesanan).Din[idx];
        Dinner->juml = Dinner->juml + 1;
    }
}
// void enqdinn(Dinner_food *Dinner, Dinner_food *pesanan)
// {
//     /*Menambahkan Elemen berupa beberapa komponen yang ada pada buffer Din*/
//     for (int i = 0; i < (*pesanan).juml; i++)
//     {
//         if ((*pesanan).Din[i].Durasi != 0)
//         {
//             if (isDinEmpty(*Dinner))
//             {
//                 idx_Kepala(*Dinner) = 0;
//                 idx_ekor(*Dinner) = 0;
//                 (*Dinner).Din[idx_ekor(*Dinner)] = (*pesanan).Din[i];
//                 Dinner->juml = 0;
//                 Dinner->juml = Dinner->juml + 1;
//             }
//             else
//             {
//                 idx_ekor(*Dinner) = idx_ekor(*Dinner) + 1;
//                 (*Dinner).Din[idx_ekor(*Dinner)] = (*pesanan).Din[i];
//                 Dinner->juml = Dinner->juml + 1;
//             }
//         }
//     }
// }

// void DelDin(Dinner_food *Dinner)
// {
//     Dinner_Temp Dinner_temp = MakeDinner_Temp();
//     /*Menghapus Elemen berupa beberapa komponen yang ada pada buffer Din*/
//     for (int i = 0; i < (*Dinner).juml; i++)
//     {
//         if ((*Dinner).Din[i].Durasi != 0)
//         {
//             InsertLastDinner_Temp((Dinner), &Dinner_temp, i);
//         }
//     }
//     CreateDinner(Dinner);
//     for (int j = 0; j < (Dinner_temp).Neff; j++)
//     {
//         enqdiin((&Dinner_temp), (Dinner));
//     }
// }
/*Menghapus Elemen pada antrian masak atau saji ketika ada dari mereka yang bernilai nol (Durasi / ketahanan)*/
boolean isDinEmpty(Dinner_food Dinner)
{
    return (idx_Kepala(Dinner) == IDX_UNDEf && idx_ekor(Dinner) == IDX_UNDEf);
}

int DinLength(Dinner_food Dinner)
{
    if (isDinEmpty(Dinner))
    {
        return 0;
    }
    else
    {
        return (idx_ekor(Dinner) - idx_Kepala(Dinner) + 1);
    }
}
/*Mengecek bahwa apakah idx kepala dan idx ekor dari memmen kosong atau tidak*/

/**************************************************** Untuk Dinner Dash***********************************************************/

boolean ISEMPTY(Queue q)
{
    return (IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF);
}

boolean ISFull(Queue q)
{
    return IDX_HEAD(q) == 0 ? IDX_TAIL(q) == CAPACITYY - 1 : IDX_TAIL(q) == IDX_HEAD(q) - 1;
}

int length(Queue q)
{
    if (ISEMPTY(q))
    {
        return 0;
    }
    else
    {
        if (IDX_TAIL(q) < IDX_HEAD(q))
        {
            return (CAPACITYY - (IDX_HEAD(q) - IDX_TAIL(q) - 1));
        }
        else
        {
            return (IDX_TAIL(q) - IDX_HEAD(q) + 1);
        }
    }
}

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, Eltype val)
{
    if (ISEMPTY(*q))
    {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    }
    else if (IDX_TAIL(*q) == (CAPACITYY - 1))
    {
        IDX_TAIL(*q) = 0;
    }
    else
    {
        IDX_TAIL(*q) = IDX_TAIL(*q) + 1;
    }
    (*q).buffer[IDX_TAIL(*q)] = val;
}

void enqdiin(Dinner_food *masak, Dinner_Temp *DT)
{
    for (int i = 0; i < DT->Neff; i++)
    {
        if (DT->Dinner_temp[i].durasi != 0)
        {
            if (isDinEmpty(*masak))
            {
                idx_Kepala(*masak) = 0;
                idx_ekor(*masak) = 0;
                (*masak).Din[idx_ekor(*masak)].ID = DT->Dinner_temp[i].Id;
                (*masak).Din[idx_ekor(*masak)].Durasi = DT->Dinner_temp[i].durasi;
                (*masak).Din[idx_ekor(*masak)].Ketahanan = DT->Dinner_temp[i].ketahanan;
                (*masak).Din[idx_ekor(*masak)].Harga = DT->Dinner_temp[i].HaRga;
                masak->juml = 0;
                masak->juml = masak->juml + 1;
            }
            else
            {
                idx_ekor(*masak) = idx_ekor(*masak) + 1;
                (*masak).Din[idx_ekor(*masak)].ID = DT->Dinner_temp[i].Id;
                (*masak).Din[idx_ekor(*masak)].Durasi = DT->Dinner_temp[i].durasi;
                (*masak).Din[idx_ekor(*masak)].Ketahanan = DT->Dinner_temp[i].ketahanan;
                (*masak).Din[idx_ekor(*masak)].Harga = DT->Dinner_temp[i].HaRga;
                masak->juml = masak->juml + 1;
            }
        }
    }
}
void dequeue(Queue *q, Eltype *val)
{
    *val = (*q).buffer[(*q).idxHead];
    if (IDX_HEAD(*q) == IDX_TAIL(*q))
    {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else
    {
        IDX_HEAD(*q)
        ++;
    }
}

void dequeuee(Queue *q, ElTypee idx)
{
    if (idx < length(*q))
    {
        HEAD(*q) = (*q).buffer[idx];
        int lengt = length(*q);
        lengt = lengt - idx;
        int i = 0;
        for (i; i < lengt; i++)
        {
            (*q).buffer[i] = (*q).buffer[(i + 1) + (idx - 1)];
        }
    }
}

void dequeueee(Queue *q, Eltype *val)
{
    *val = (*q).buffer[(*q).idxHead];
    if (IDX_HEAD(*q) == IDX_TAIL(*q))
    {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else
    {
        for (int i = IDX_HEAD(*q); i < IDX_TAIL(*q); i++)
        {
            (*q).buffer[i] = (*q).buffer[i + 1];
        }
        IDX_TAIL(*q)
        --;
        // memindahkan elemen head ke elemen awal
    }
}

/* *** Display Queue *** */
void displayQueue(Queue q)
{
    if (ISEMPTY(q))
    {
        printf("[]\n");
    }
    else
    {
        int i;
        printf("[");
        for (i = IDX_HEAD(q); i <= IDX_TAIL(q); i++)
        {
            if (i == IDX_TAIL(q))
            {
                printf("%d", q.buffer[i]);
            }
            else
            {
                printf("%d,", q.buffer[i]);
            }
        }
        printf("]\n");
    }
}

Dinner_Temp MakeDinner_Temp()
{
    Dinner_Temp DT;
    DT.Neff = 0;
    DT.Capacity = 10;
    DT.Dinner_temp = (element *)malloc(DT.Capacity * sizeof(element));
    return DT;
}

void InsertLastDinner_Temp(Dinner_food *Dinner, Dinner_Temp *DT)
{
    for (int i = 0; i < (*Dinner).juml; i++)
    {
        if ((*Dinner).Din[i].ID != 0)
        {
            (*DT).Dinner_temp[(*DT).Neff].Id = (*Dinner).Din[i].ID;
            (*DT).Dinner_temp[(*DT).Neff].durasi = (*Dinner).Din[i].Durasi;
            (*DT).Dinner_temp[(*DT).Neff].ketahanan = (*Dinner).Din[i].Ketahanan;
            (*DT).Dinner_temp[(*DT).Neff].HaRga = (*Dinner).Din[i].Harga;
            (*DT).Neff += 1;
        }
    }
}