#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queuev2.h"

int main() {
    int saldo = 0, pelanggan = 0, antrian = 0;
    int cmd;
    Queue pesan, masak, saji;
    CreateQueue(&pesan);
    srand(time(NULL));

    for(int urutan=0; urutan<3; urutan++) {
        CreatePesanan(&pesan, urutan);
    }

    printf("\nSelamat Datang di DINNER DASH\n\n");
    printf("SALDO : %d\n\n", saldo);

    displayPesanan(pesan);
    printf("\n1. COOK\n2. SERVE\n\nMasukkan Perintah : ");
    
    // scanf("&d", cmd);

}