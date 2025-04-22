#include <stdio.h>
#include <string.h>
#include "adtlist.h"

int main() {
    Kota data[MAX_Kota];
    int jumlahKota;
    initkota(data, &jumlahKota);

    tambahKota(data, &jumlahKota, "Bandung");
    tambahNama(&data[0], "Amir");
    tambahNama(&data[0], "Wahab");
    tambahNama(&data[0], "Yahya");

    tambahKota(data, &jumlahKota, "Jakarta");
    tambahNama(&data[1], "Badu");
    tambahNama(&data[1], "Hasan");

    int pilihan = 1;
    char kota[MAX], nama[MAX];

    while (pilihan != 0) {
        printf("\nMenu:\n");
        printf("1. Tambah Kota\n");
        printf("2. Tambah Nama ke Kota\n");
        printf("3. Hapus Kota\n");
        printf("4. Tampilkan Semua\n");
        printf("5. Tampilkan Kota\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        if (pilihan == 1) {
            printf("Nama kota: ");
            scanf("%s", kota);
            tambahKota(data, &jumlahKota, kota);
        } else if (pilihan == 2) {
            printf("Nama kota: ");
            scanf("%s", kota);
            int i = 0;
            while (i < jumlahKota) {
                if (strcmp(data[i].kota, kota) == 0) {
                    printf("Nama: ");
                    scanf("%s", nama);
                    tambahNama(&data[i], nama);
                    break;
                }
                i++;
            }
        } else if (pilihan == 3) {
            printf("Nama kota yang ingin dihapus: ");
            scanf("%s", kota);
            hapusKota(data, &jumlahKota, kota);
        } else if (pilihan == 4) {
            tampilkanSemua(data, jumlahKota);
        } else if (pilihan == 5) {
            printf("Nama kota: ");
            scanf("%s", kota);
            tampilkanKota(data, jumlahKota, kota);
        } else if (pilihan == 0) {
            printf("Keluar dari program.\n");
        } else {
            printf("Pilihan tidak valid.\n");
        }
    }

    return 0;
}
