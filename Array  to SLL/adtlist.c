#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adtlist.h"

void initkota(Kota data[], int *n)
{
    *n = 0
}

void tambahKota(Kota data[], int *n, char namaKota[])
{
    strcpy(data[*n].kota, namaKota);
    data[*n].p = NULL;
    (*n)++;
}

void tambahNama(Kota *k, char nama[])
{
    Node *baru = (Node *)malloc(sizeof(Node));
    strcpy(baru->nama, nama);
    baru->next = NULL;

    if(k->p == NULL)
    {
        k->p = baru;
    }
    else
    {
        Node *bantu = k->p;
        while (bantu->next != NULL)
        {
            bantu = bantu->next;
        }
        bantu->next = baru;
    }
}

void hapusKota(Kota data[], int *n, char namaKota[])
{
    int i, found = 0;
    while (i < *n && found == 0)
    {
        if(strcmp(data[i].kota, namaKota)== 0)
        {
            found = 1;
        }
        else 
        {
            i++;
        }
    }

    if(found)
    {
        Node *curr = data[i].p;
        while(curr != NULL)
        {
            Node *hapus = curr;
            curr = curr->next;
            free(hapus);
        }

        int j = i;
        while(j < *n - i)
        {
            data[j] = data[j + 1];
            j++;
        }
        (*n)--;
        printf("Kota %s dan semua nama di dalamnya telah dihapus.\n", namaKota);
    }
    else
    {
        printf("Kota %s tidak ditemukan.\n");
    }
}

void tampilkanSemua(Kota data[], int n)
{
    int i = 0;
    while (i < n)
    {
        printf("kota: %s\n", data[i].kota);
        Node *bantu = data[i].p;
        while(bantu != NULL)
        {
            printf("   - %s\n", bantu->nama);
            bantu = bantu->next;
        }
        i++
    }
}

void tampilkanKota(Kota data[], int n, char namaKota[])
{
    int i = 0;
    while (i < n)
    {
        if(strcmp(data[i].kota, namaKota)== 0)
        {
            printf("Kota: %s\n", data[i].kota);
            Node *bantu = data[i].p;
            while(bantu != NULL)
            {
                printf("  -%s\n", bantu->nama);
                bantu = bantu->next;
            }
            return;
        }
        i++;
    }
    printf("Kota tidak ditemukan.\n");
}