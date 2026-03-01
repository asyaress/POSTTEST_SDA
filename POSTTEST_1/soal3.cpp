#include <iostream>
using namespace std;

// pointernye

void reverseArray(int *arr, int n)
{
    int *kiri = arr;          // nunjuk ke elemen pertama array
    int *kanan = arr + n - 1; // nunjuk ke elemen terakhir array

    while (kiri < kanan) // kalau pointer kiri masih di kiri dan pointer kanan di reverse
    {
        int temp = *kiri; // simpan nilai kiri sementara
        *kiri = *kanan;   // kiri ganti ke kanan
        *kanan = temp;    // nilai kanan ganti pakai nilai kiri sementara
        kiri++;           // geser kiri 1 lagngkah
        kanan--;          // geser kanan 1 langkah ke kiri
    }
}

void tampilkanArray(int *arr, int n)
{
    int *p = arr;               // mulai dari elemen pertama
    for (int i = 0; i < n; i++) // ngulang dari awal sampai akhir
    {
        cout << *p;
        if (i < n - 1)
            cout << " ";
        p++;
    }
    cout << endl;
}

void tampilkanDetail(int *arr, int n)
{
    int *p = arr;
    for (int i = 0; i < n; i++)
    {
        cout << "Elemen ke-" << i << " = " << *p
             << " (alamat: " << p << ")" << endl;
        p++;
    }
}

int main()
{
    int prima[] = {2, 3, 5, 7, 11, 13, 17}; // sesuai soal = prima (2, 3, 5, 7, 11, 13, 17)
    int n = 7;                              // sesuai jumlah nay

    // print pakai fungsi diatas

    cout << "Array sebelum dibalik: ";
    tampilkanArray(prima, n);

    cout << "Detail array sebelum dibalik:" << endl;
    tampilkanDetail(prima, n);

    reverseArray(prima, n);

    cout << "Array sesudah dibalik: ";
    tampilkanArray(prima, n);

    cout << "Detail array sesudah dibalik:" << endl;
    tampilkanDetail(prima, n);

    return 0;
}
