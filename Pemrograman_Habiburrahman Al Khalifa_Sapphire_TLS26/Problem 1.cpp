#include <iostream>
using namespace std;

int main() {
    int N, K;
    printf("Jumlah Astronot: ");
    cin >> N;
    printf("Nilai K: ");
    cin >> K;

    int astronot[100];
    for (int i = 0; i < N; i++) {
        astronot[i] = i + 1;
    }

    int posisi = 0;
    int sisa = N;

    while (sisa > 1) {
        int langkah = 0;

        while (langkah < K) {
            if (astronot[posisi] != 0) {
                langkah++;
            }
            if (langkah < K) {
                posisi = (posisi + 1) % N;
            }
        }

        int dieleminasi = astronot[posisi];
        printf("Astronot %d dieleminasi\n", dieleminasi);
        astronot[posisi] = 0;
        sisa--;

        if (dieleminasi % 2 == 0) {
            K += 2;
        } else {
            K -= 1;
        } 

        if (K < 2) {
            K = 2;
        }
    }

    // Pengecekan pemenang dipindah ke luar while
    for (int i = 0; i < N; i++) {
        if (astronot[i] != 0) {
            printf("Astronot terakhir yang bertahan: %d\n", astronot[i]);
            break;
        }
    }

    return 0;
}