#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk; //float karna angkanya desimal
}; //struct sesuai soal yeee

int main() {
    const int jumlah = 5; // tenttukan cuman bisa 5 mahasiswa
    Mahasiswa mhs[jumlah]; // bikin array kids
    int indexTertinggi;

    cout << "Input data " << jumlah << " mahasiswa" << endl;

    for (int i = 0; i < jumlah; i++) {
        cout << "Data mahasiswa ke-" << i + 1 << endl;

        cout << "Nama: ";
        cin >> mhs[i].nama;

        cout << "NIM: ";
        cin >> mhs[i].nim;

        cout << "IPK: ";
        cin >> mhs[i].ipk;
    } // loop buat isi 1 1 data di struct

    cout << "Data semua mahasiswa:" << endl;
    for (int i = 0; i < jumlah; i++) {
        cout << i + 1 << ". ";
        cout << "Nama: " << mhs[i].nama << ", ";
        cout << "NIM: " << mhs[i].nim << ", ";
        cout << "IPK: " << mhs[i].ipk << endl;
    } // print

    indexTertinggi = 0;
    for (int i = 1; i < jumlah; i++) {
        if (mhs[i].ipk > mhs[indexTertinggi].ipk) {
            indexTertinggi = i;
        }
    } // nentuin ipk tertinggi

    cout << "Mahasiswa dengan IPK tertinggi:" << endl;
    cout << "Nama : " << mhs[indexTertinggi].nama << endl;
    cout << "NIM  : " << mhs[indexTertinggi].nim  << endl;
    cout << "IPK  : " << mhs[indexTertinggi].ipk  << endl;

    // print semuanya
    return 0;
}
