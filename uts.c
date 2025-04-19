// Christian Alberto Sitohang
// NIM 11S24039

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 100

struct Component
{
    char nama[MAX_LEN];
    char _persentasechar[MAX_LEN];
    int persen_nilai[1];
    float _nilai_akhir;
};

int main()
{
    int jumlah_komponen;
    printf("Masukkan jumlah komponen penilaian (1-5): ");
    scanf("%d", &jumlah_komponen);

    if (jumlah_komponen < 1 || jumlah_komponen > 5)
    {
        printf("Jumlah komponen harus antara 1 dan 5!\n");
        return 0;
    }

    struct Component component[jumlah_komponen];

    for (int i = 0; i < jumlah_komponen; i++)
    {
        printf("Masukkan nama komponen ke-%d: ", i + 1);
        scanf("%s", component[i].nama);
    }

    for (int i = 0; i < jumlah_komponen; i++)
    {
        printf("Masukkan persentase dan nilai untuk %s (format: persentase#nilai): ", component[i].nama);
        scanf("%s", component[i]._persentasechar); // Masukkan persentase yang masih dalam bentuk char
    }

    for (int i = 0; i < jumlah_komponen; i++)
    {
        char *token;

        token = strtok(component[i]._persentasechar, "#");

        float bobot = atof(token); // ambil persentase bobot
        component[i].persen_nilai[0] = (int)bobot;

        token = strtok(NULL, "#");

        float nilai = atof(token); // ambil nilai
        component[i].persen_nilai[1] = (int)nilai;

        component[i]._nilai_akhir = (bobot / 100.0) * nilai;
    }

    int persentase_bobot = 0;

    for (int i = 0; i < jumlah_komponen; i++)
    {
        persentase_bobot += component[i].persen_nilai[0];
    }

    if (persentase_bobot != 100)
    {
        printf("Total persentase harus 100%%! Saat ini: %d%%\n", persentase_bobot);
        return 1;
    }

    for (int i = 0; i < jumlah_komponen; i++)
    {
        printf("%s;%d;%d\n", component[i].nama, component[i].persen_nilai[0], component[i].persen_nilai[0]);
    }

    float jumlah_akhir = 0;

    for (int i = 0; i < jumlah_komponen; i++)
    {
        jumlah_akhir += component[i]._nilai_akhir;
    }

    printf("%.1f\n", jumlah_akhir);
    if (jumlah_akhir >= 50)
        printf("passed");
    else
        printf("failed");
    return 0;
}