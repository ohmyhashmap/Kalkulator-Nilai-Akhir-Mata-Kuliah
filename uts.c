// Christian Alberto Sitohang
// NIM 11S24039

#include <stdio.h>
#include <string.h>
#define MAX_LEN 100
struct Component
{
    char nama[MAX_LEN];
    char _persentasechar[MAX_LEN];
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
        char delimiter[] = "#";       // Delimiter adalah (#)
        char ganti_delimiter[] = ";"; // Delimiter adalah (;) //cara ganti nya pakai fungsi apa??? aelah lupa wkw
        char *token;                  // Variable to store tokens

        printf("%s\n", component[i]._persentasechar);
        printf("Tokens:\n");

        token = strtok(component[i]._persentasechar, delimiter);
        while (token != NULL)
        {
            printf("%s\n", token);
            token = strtok(NULL, delimiter);
        }
    }

    // NOTE :
    // Jadi Hal yang kurang dipahami disini adalah :
    // 1. Cara mengganti token ke nilai integer agar nantinya bisa di olah datanya.
    // 2. Cara membuat nya ke bentuk format "<Nama Komponen>;<Persentase Bobot>;<Nilai>".
    // 3. Jika nilai akhir ≥ 50.0, maka program mencetak "passed". Jika nilai akhir < 50.0, maka program mencetak "failed". if else biasa di akhir untuk cek lulus tidaknya.
    // Thq UTS nya (<>~^^~<>) cmiw
    // btw bang mungkin kode program ini bisa dilanjutkan di review pertemuan praktikum berikutnya
    // padahal mudah loh <><><><> LOL
    return 0;
}