#ifndef ADTLIST_H
#define ADTLIST_H

#define MAX 50
#define MAX_Kota 10

typedef struct node
{
    char nama[MAX];
    struct node *next;
} Node;

typedef struct 
{
    char KOTA[MAX];
    Node *p;
} Kota;

void initkota(Kota data[], int *n);
void tambahKota(Kota data[], int *n, char namaKota[]);
void tambahNama(Kota *k, char nama[]);
void hapusKota(Kota data[], int *n, char namaKota[]);
void tampilkanSemua(Kota data[], int n);
void tampilkanKota(Kota data[], int n, char namaKota[]);

#endif