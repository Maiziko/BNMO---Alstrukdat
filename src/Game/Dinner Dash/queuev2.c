#include "queuev2.h"
#include <stdio.h>

/* *** Kreator *** */
void CreateQueue(Queue *q) {
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

void CreatePesanan(Queue *q, int urut) {
    if (isEmpty(*q)) {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    } else {
        IDX_TAIL(*q)++;         
    }
    (*q).buffer[urut].urut = urut;
    (*q).buffer[urut].durasi = Durasi();
    (*q).buffer[urut].harga = Harga();
    (*q).buffer[urut].ketahanan = Ketahanan();
}

/* ********* Prototype ********* */
boolean isEmpty(Queue q) {
    return (IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF);
}

boolean isFull(Queue q) {
    return IDX_HEAD(q) == 0? IDX_TAIL(q) == CAPACITY - 1 : IDX_TAIL(q) == IDX_HEAD(q) - 1; 
}

int length(Queue q) {
    if (isEmpty(q)) {
        return 0;
    } else {
        if (IDX_TAIL(q) < IDX_HEAD(q)) {
            return (CAPACITY - (IDX_HEAD(q) - IDX_TAIL(q) - 1));
        } else {
            return (IDX_TAIL(q) - IDX_HEAD(q) + 1);
        }      
    }
}

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val) {
    if (isEmpty(*q)) {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    } else if (IDX_TAIL(*q) == (CAPACITY-1)) {
        IDX_TAIL(*q) = 0;
    } else {
        IDX_TAIL(*q)++;         
    } TAIL(*q) = val;
}

void dequeue(Queue *q, ElType *val) {
    *val = HEAD(*q);
    if (IDX_HEAD(*q) == IDX_TAIL(*q)) {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    } else {
        IDX_HEAD(*q)++; }
}

/* *** Display Queue *** */
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
    printf("DAFTAR PESANAN\n");
    printf("Makanan\t|Durasi memasak\t|Ketahanan\t|Harga\t\n");
    printf("------------------------------------------------\t\n");
    if (isEmpty(q)) {
        printf("kosonk\n"); }
    else {
        int i;
        for (i = IDX_HEAD(q); i < IDX_TAIL(q)+1; i++) {
            printf("");
            printf("M%d\t|", q.buffer[i].urut);
            printf("%d\t\t|", q.buffer[i].durasi);
            printf("%d\t\t|", q.buffer[i].ketahanan);
            printf("%d\t\t", q.buffer[i].harga);
            if(i != IDX_TAIL(q)) {
                printf("\n");
            }
        }
    }      
}

void displayMasakan(Queue q) {
    printf("Daftar Makanan yang sedang dimasak\n");
    printf("Makanan\t|Sisa Durasi memasak\t\n");
    printf("-----------------------------\t\n");
    if (isEmpty(q)) {
        printf("kosonk\n"); }
    else {
        int i;
        for (i = IDX_HEAD(q); i < IDX_TAIL(q)+1; i++) {
            printf("");
            printf("M%d\t|", q.buffer[i].urut);
            printf("%d\t\t|", q.buffer[i].durasi);
            if(i != IDX_TAIL(q)) {
                printf("\n");
            }
        }
    }      
}

int Durasi() {
    return (rand() % 5)+1;
}

int Ketahanan() {
    return (rand() % 5)+1;
}

int Harga() {
    return ((rand() % (41)) + 10)*1000;
}