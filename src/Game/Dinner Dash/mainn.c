#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*File : boolean.h*/

#ifndef boolean_H
#define boolean_H
#define true 1
#define false 0
#define boolean unsigned char
#endif

/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */

#ifndef QUEUEV2_H
#define QUEUEV2_H

#define IDX_UNDEF -1
#define CAPACITY 100

/* Definisi elemen dan address */
// typedef int ElType;
typedef struct {
        int urut;
        int durasi;
        int ketahanan;
        int harga;
        int d_awal;
} ElType;
typedef struct {
	ElType buffer[CAPACITY]; 
	int idxHead;
	int idxTail;
} Queue;


/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define     HEAD(q) (q).buffer[(q).idxHead]
#define     TAIL(q) (q).buffer[(q).idxTail]

/* *** Kreator *** */
void CreateQueue(Queue *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

void CreatePesanan(Queue *q, int NoUrut);

/* ********* Prototype ********* */
boolean isEmpty(Queue q);
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isFull(Queue q);
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
boolean isMember(int urut, Queue q);

int length(Queue q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeue(Queue *q, ElType *val);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

/* *** Display Queue *** */
void displayQueue(Queue q);
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */

void displayPesanan(Queue q);

void displayMasakan(Queue q);

void displaySajian(Queue q);

#endif

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
    (*q).buffer[urut].durasi = (rand() % 5)+1;
    (*q).buffer[urut].harga = ((rand() % (41)) + 10)*1000;
    (*q).buffer[urut].ketahanan = (rand() % 5)+1;
    (*q).buffer[urut].d_awal = (*q).buffer[urut].durasi;
}

/* ********* Prototype ********* */
boolean isEmpty(Queue q) {
    return (IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF);
}

boolean isFull(Queue q) {
    return IDX_HEAD(q) == 0? IDX_TAIL(q) == CAPACITY - 1 : IDX_TAIL(q) == IDX_HEAD(q) - 1; 
}

boolean isMember(int X, Queue q) {
    boolean found = false;
    int i = 0;
    while(i < length(q) && found == false) {
        if (q.buffer[i].urut == X) {
            found = true;
        } i++;
    }
    return found;
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

// ini buat yang pasti dilakuin di tiap putaran
// void putaran(Queue pesan, Queue masak, Queue saji, int apa) {
//     if(!isEmpty(masak)) {
//         for(int i = 0; i < length(masak); i++) {
//             masak.buffer[i].durasi -= 1;  
//             if (masak.buffer[i].durasi == 0) {
//                 printf("M%d uda mateng", masak.buffer[apa].urut); 
//                 enqueue(&saji, masak.buffer[apa]);
//                 dequeue(&masak, &(masak.buffer[apa]));                       
//             }
//         }
//     }
//     if(!isEmpty(saji)) {
//         for(int i = 0; i < length(saji); i++) {
//             saji.buffer[i].durasi -= 1;  
//             if (saji.buffer[i].durasi == 0) {
//                 printf("M%d uda basi", saji.buffer[apa].urut); 
//                 saji.buffer[apa].durasi = saji.buffer[apa].d_awal;
//                 enqueue(&masak, saji.buffer[apa]);
//                 dequeue(&saji, &(saji.buffer[apa]));                       
//             }
//         }
//     }
// }

void display(Queue pesan, Queue masak, Queue saji) {
    displayPesanan(pesan);
    printf("\n");
    displayMasakan(masak);
    printf("\n");
    displaySajian(saji);
}

int main() {
    int saldo = 0, pelanggan = 0, urutan = 0;
    int cmd;

    // bikin queue buat pesanan, masakan, dan sajian
    Queue pesan, masak, saji;
    CreateQueue(&pesan);
    CreateQueue(&masak);
    CreateQueue(&saji);

    srand(time(NULL)); //biar random bener2 random

    // bikin pesanan awal
    while (urutan < 3) {
        CreatePesanan(&pesan, urutan);
        urutan++;
    }
    
    // mulainya di sini
    printf("\n(^U^) Selamat Datang di DINNER DASH (^U^)\n\n");
    // printf("SALDO : %d\n", saldo);
    display(pesan, masak, saji);
    printf("\n1. COOK\n2. SERVE\n");

    // ini putarannya
    while(length(pesan) < 7 && pelanggan != 15) {
        // ini haram gaboleh dipake hrs diganti :3
        // cuma input command nya aja, tapi sisanya halal harusnya
        printf("\nMasukkan Perintah : ");
        scanf("%d", &cmd);
        int apa;
        if(cmd == 1) {
            printf("urutan brp: ");
            scanf("%d", &apa);

            for(int i = 0; i < length(pesan); i++) {
                printf("\n[%d]\n", pesan.buffer[i].urut);
            }

            if(isMember(apa, pesan)) {
                if(!isEmpty(masak)) {
                    for(int i = 0; i < length(masak); i++) {
                        masak.buffer[i].durasi -= 1;  
                        if (masak.buffer[i].durasi <= 0) {
                            printf("\n-> M%d uda mateng\n", masak.buffer[i].urut); 
                            // apa = masak.buffer[apa].urut;
                            enqueue(&saji, masak.buffer[i]);
                            dequeue(&masak, &(masak.buffer[i]));                       
                        }
                    }
                }
                
                if(!isEmpty(saji)) {
                    for(int i = 0; i < length(saji); i++) {
                        saji.buffer[i].durasi -= 1;  
                        if (saji.buffer[i].durasi == 0) {
                            printf("\n-> M%d uda basi\n", saji.buffer[i].urut); 
                            saji.buffer[i].durasi = saji.buffer[i].d_awal;
                            enqueue(&masak, saji.buffer[i]);
                            dequeue(&saji, &(saji.buffer[i]));                       
                        }
                    }
                }

                enqueue(&masak, pesan.buffer[apa]);
                // dequeue(&pesan, &(pesan.buffer[apa]));

                CreatePesanan(&pesan, urutan);
                urutan++;

                display(pesan, masak, saji);            
            } else {
                printf("Tidak ada pesanan %d pada daftar", apa);
                printf("\n=====================================================\n");
                continue;
            }

        } else if (cmd == 2) {
            printf("urutan brp: ");
            scanf("%d", &apa);

            for(int i = 0; i < length(pesan); i++) {
                printf("\n[%d]\n", pesan.buffer[i].urut);
            }

            if(isMember(apa, saji)) {
            // if(apa == masak.buffer[apa].urut) {
                saldo += pesan.buffer[apa].harga;

                if(!isEmpty(masak)) {
                    for(int i = 0; i < length(masak); i++) {
                        masak.buffer[i].durasi -= 1;  
                        if (masak.buffer[i].durasi == 0) {
                            printf("\n-> M%d uda mateng\n", masak.buffer[i].urut); 
                            // apa = masak.buffer[apa].urut;
                            enqueue(&saji, masak.buffer[i]);
                            dequeue(&masak, &(masak.buffer[i]));                       
                        }
                    }
                }

                // enqueue(&saji, pesan.buffer[apa]);
                // apa = masak.buffer[apa].urut;
                dequeue(&saji, &(pesan.buffer[apa]));
                dequeue(&pesan, &(pesan.buffer[apa]));
                // for(int i = 0; i < length(saji); i++) {
                //     if (saji.buffer[i].urut == apa) {
                //         dequeue(&pesan, &(pesan.buffer[i]));
                //         dequeue(&saji, &(pesan.buffer[i]));                      
                //     }
                // }  
                
                if(!isEmpty(saji)) {
                    for(int i = 0; i < length(saji); i++) {
                        saji.buffer[i].durasi -= 1;  
                        if (saji.buffer[i].durasi == 0) {
                            printf("\n-> M%d uda basi\n", saji.buffer[i].urut); 
                            saji.buffer[i].durasi = saji.buffer[i].d_awal;
                            enqueue(&masak, saji.buffer[i]);
                            dequeue(&saji, &(saji.buffer[i]));                       
                        }
                    }
                }          

                pelanggan += 1;

                CreatePesanan(&pesan, urutan);
                urutan++;

                display(pesan, masak, saji);                 
            } else {
                printf("Tidak ada pesanan %d pada daftar", apa);
                printf("\n=====================================================\n");
                continue;
            }
        } else {
            break;
        }
        printf("\n=====================================================\n");
        printf("SALDO : %d\n", saldo);
    }
    printf("\n=====================================================\n");
    if(length(pesan) == 7) {
    printf("Permainan Berakhir, sudah mencapai 7 antrian\n");
    printf("SALDO AKHIR : %d\n", saldo);        
    } else if (pelanggan == 15) {
        printf("Permainan Berakhir, sudah mencapai 15 pelanggan\n");
        printf("SALDO AKHIR : %d\n", saldo);   
    }
    printf("\n=====================================================\n");
}