#include "queue.h"
#include <stdio.h>

/* *** Kreator *** */
void CreateQueue(Queue *q)
{
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
void CreateMem(memmen *m)
{
    m->juml = 0;
    for (int i = 0; i < 10; i++)
    {
        (*m).Din[i].ID = IDX_UNDEF;
        (*m).Din[i].Durasi = IDX_UNDEF;
        (*m).Din[i].Ketahanan = IDX_UNDEF;
        (*m).Din[i].Harga = IDX_UNDEF;
        (*m).Din[i].D_awal = IDX_UNDEF;
    }
}
boolean isEmpty(Queue q)
{
    return (IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF);
}

boolean isMEmpty(memmen m) {
    boolean empty = true;
    m.juml = 0;
    for (int i = 0; i < 10; i++)
        {
        if (
        (m).Din[i].ID != IDX_UNDEF ||
        (m).Din[i].Durasi != IDX_UNDEF ||
        (m).Din[i].Ketahanan != IDX_UNDEF ||
        (m).Din[i].Harga != IDX_UNDEF ||
        (m).Din[i].D_awal != IDX_UNDEF ) {
            empty = false;
        }
    } return empty;
}

boolean isFull(Queue q)
{
    return IDX_HEAD(q) == 0 ? IDX_TAIL(q) == CAPACITY - 1 : IDX_TAIL(q) == IDX_HEAD(q) - 1;
}

int length(Queue q)
{
    if (isEmpty(q))
    {
        return 0;
    }
    else
    {
        if (IDX_TAIL(q) < IDX_HEAD(q))
        {
            return (CAPACITY - (IDX_HEAD(q) - IDX_TAIL(q) - 1));
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
    if (isEmpty(*q))
    {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    }
    else if (IDX_TAIL(*q) == (CAPACITY - 1))
    {
        IDX_TAIL(*q) = 0;
    }
    else
    {
        IDX_TAIL(*q)
        ++;
    }
    (*q).buffer[(*q).idxTail] = val;
}

// void enqueuem(memmen *m, infotype Din) {
//     if (isEmpty(*m))
//     {
//     (*m).Din[i].ID = IDX_UNDEF;
//     (*m).Din[i].Durasi = IDX_UNDEF;
//     (*m).Din[i].Ketahanan = IDX_UNDEF;
//     (*m).Din[i].Harga = IDX_UNDEF;
//     (*m).Din[i].D_awal = IDX_UNDEF;
//     }
//     else if (IDX_TAIL(*q) == (CAPACITY - 1))
//     {
//         IDX_TAIL(*q) = 0;
//     }
//     else
//     {
//         IDX_TAIL(*q)
//         ++;
//     }
//     (*q).buffer[(*q).idxTail] = val;
// }

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

void dequeuee(Queue *q, Eltype *val)
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
    if (isEmpty(q))
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

void DelMem(memmen *mem, ElTypee val)
{
    int i = 0;
    if ((*mem).juml > 1)
    {
        for (i = 0; i < (*mem).juml; i++)
        {
            if ((*mem).Din[i].ID == val)
            {
                (*mem).juml -= 1;
            }
        }
    }
    else if ((*mem).juml == 1)
    {

        (*mem).Din[0].Durasi = IDX_UNDEF;
        (*mem).juml -= 1;
    }
}
