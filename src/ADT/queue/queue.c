#include "queue.h"
#include <stdio.h>

/* *** Kreator *** */
void CreateQueue(Queue *q)
{
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

void CreatePesanan(dinQueue *q) {
    (*q).juml = IDX_UNDEF;
}

/* ********* Prototype ********* */
void InsertPesanan(dinQueue *q, int urut) {
    if (isDinEmpty(*q)) {
        (*q).juml = 0;
    } else {
        (*q).juml++;         
    }
    (*q).din[urut].urut = urut;
    (*q).din[urut].durasi = (rand() % 5)+1;
    (*q).din[urut].harga = ((rand() % (41)) + 10)*1000;
    (*q).din[urut].ketahanan = (rand() % 5)+1;
    (*q).din[urut].d_awal = (*q).din[urut].durasi;
}

boolean isEmpty(Queue q)
{
    return (IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF);
}

boolean isFull(Queue q)
{
    return IDX_HEAD(q) == 0 ? IDX_TAIL(q) == CAPACITY - 1 : IDX_TAIL(q) == IDX_HEAD(q) - 1;
}

boolean isMember(int X, dinQueue q) {
    boolean found = false;
    int i = 0;
    while(i < lengthDin(q) && found == false) {
        if (q.din[i].urut == X) {
            found = true;
        } i++;
    }
    return found;
}

boolean isDinEmpty(dinQueue q)
{
    return q.juml == 0;
}

boolean isDinFull(dinQueue q)
{
    return q.juml == CAPACITY;
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
void enqueue(Queue *q, ElType val)
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

void dequeue(Queue *q, ElType *val)
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

void dequeuee(Queue *q, ElType *val)
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
        IDX_TAIL(*q)--;
        // memindahkan elemen head ke elemen awal
    }
}

void enqueueDin(Queue *q, dintype val);

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

void displayQueue(Queue q) {
    if (isEmpty(q)) {
        printf("[]\n"); }
    else {
        int i;
        printf("[");
        for (i = IDX_HEAD(q); i <= IDX_TAIL(q); i++) {
            if (i == IDX_TAIL(q)) {
                printf("%d", q.buffer[i]);
            } else {
                printf("%d,", q.buffer[i]);
            }
        }
        printf("]\n");
    }   
}

void displayPesanan(Queue q) {
    printf("\nDAFTAR PESANAN\n");
    printf("Makanan\t|Durasi memasak\t|Ketahanan\t|Harga\t\n");
    printf("------------------------------------------------\t\n");
    if (isEmpty(q)) {
        printf("\t|\n\t\t\n");
    }
    else {
        int i;
        for (i = IDX_HEAD(q); i < IDX_TAIL(q)+1; i++) {
            printf("");
            printf("M%d\t|", q.buffer[i].urut);
            printf("%d\t\t|", q.buffer[i].d_awal);
            printf("%d\t\t|", q.buffer[i].ketahanan);
            printf("%d\t\t", q.buffer[i].harga);
            if(i != IDX_TAIL(q)) {
                printf("\n");
            }
        }
    }      
}

void displayMasakan(Queue q) {
    printf("\nDaftar Makanan yang sedang dimasak\n");
    printf("Makanan\t|Sisa Durasi memasak\t\n");
    printf("-----------------------------\t\n");
    if (isEmpty(q)) {
        printf("\t|\n\t\t\n"); 
    }
    else {
        int i;
        for (i = IDX_HEAD(q); i < IDX_TAIL(q)+1; i++) {
            printf("");
            printf("M%d\t|", q.buffer[i].urut);
            printf("%d\t\t", q.buffer[i].durasi);
            if(i != IDX_TAIL(q)) {
                printf("\n");
            }
        }
    }      
}

void displaySajian(Queue q) {
    printf("\nDaftar Makanan yang dapat disajikan\n");
    printf("Makanan\t|Sisa Ketahanan memasak\t\n");
    printf("-----------------------------\t\n");
    if (isEmpty(q)) {
        printf("\t|\n\t\t\n");
    }
    else {
        int i;
        for (i = IDX_HEAD(q); i < IDX_TAIL(q)+1; i++) {
            printf("");
            printf("M%d\t|", q.buffer[i].urut);
            printf("%d\t\t", q.buffer[i].ketahanan);
            if(i != IDX_TAIL(q)) {
                printf("\n");
            }
        }
    }      
}