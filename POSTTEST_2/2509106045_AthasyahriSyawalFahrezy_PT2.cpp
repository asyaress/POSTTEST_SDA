#include <algorithm>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

// Struct & array of struct
struct Hewan
{
    int id;
    string nama;
    string jenis;
    int umur;
    double harga;
};

// swap nye
void swapHewan(Hewan *a, Hewan *b)
{
    Hewan temp = *a; // Pointer
    *a = *b;
    *b = temp;
}

void inisialisasiData(Hewan *&arr, int kapasitas, int &jumlah)
{
    arr = new Hewan[kapasitas];
    jumlah = 3;

    (arr + 0)->id = 101;
    (arr + 0)->nama = "Milo";
    (arr + 0)->jenis = "Kucing";
    (arr + 0)->umur = 2;
    (arr + 0)->harga = 350000;

    (arr + 1)->id = 102;
    (arr + 1)->nama = "Bobby";
    (arr + 1)->jenis = "Anjing";
    (arr + 1)->umur = 1;
    (arr + 1)->harga = 500000;

    (arr + 2)->id = 103;
    (arr + 2)->nama = "Coco";
    (arr + 2)->jenis = "Kelinci";
    (arr + 2)->umur = 1;
    (arr + 2)->harga = 200000;
}

void tampilData(const Hewan *arr, int jumlah)
{
    if (jumlah == 0)
    {
        cout << "Data hewan masih kosong.\n";
        return;
    }

    cout << "\n=== DATA HEWAN PAWCARE ===\n";
    cout << left << setw(6) << "ID" << setw(15) << "Nama" << setw(15) << "Jenis"
         << setw(8) << "Umur" << "Harga\n";
    cout << "---------------------------------------------------\n";

    // pointer aritmatika
    for (int i = 0; i < jumlah; ++i)
    {
        cout << left << setw(6) << (arr + i)->id << setw(15) << (arr + i)->nama
             << setw(15) << (arr + i)->jenis << setw(8) << (arr + i)->umur
             << fixed << setprecision(0) << (arr + i)->harga << '\n';
    }
}

void tambahData(Hewan *arr, int &jumlah, int kapasitas)
{
    if (jumlah >= kapasitas)
    {
        cout << "Kapasitas penuh. Tidak bisa tambah data.\n";
        return;
    }

    // pointer aritmatika
    Hewan *baru = arr + jumlah;
    cout << "Masukkan ID hewan   : ";
    cin >> baru->id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Masukkan nama hewan : ";
    getline(cin, baru->nama);

    cout << "Masukkan jenis      : ";
    getline(cin, baru->jenis);

    cout << "Masukkan umur (th)  : ";
    cin >> baru->umur;

    cout << "Masukkan harga      : ";
    cin >> baru->harga;

    ++jumlah;
    cout << "Data berhasil ditambahkan.\n";
}

// Linear Search nya woii
int linearSearchNama(const Hewan *arr, int jumlah, const string &targetNama)
{
    for (int i = 0; i < jumlah; ++i)
    {
        if ((arr + i)->nama == targetNama)
        {
            return i;
        }
    }
    return -1;
}

// Bubble Sort nya
void bubbleSortNama(Hewan *arr, int jumlah)
{
    for (int i = 0; i < jumlah - 1; ++i)
    {
        for (int j = 0; j < jumlah - i - 1; ++j)
        {
            if ((arr + j)->nama > (arr + j + 1)->nama)
            {
                swapHewan(arr + j, arr + j + 1);
            }
        }
    }
}

// selection yna
void selectionSortHarga(Hewan *arr, int jumlah)
{
    for (int i = 0; i < jumlah - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < jumlah; ++j)
        {
            if ((arr + j)->harga < (arr + minIndex)->harga)
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swapHewan(arr + i, arr + minIndex);
        }
    }
}

void sortIdNaik(Hewan *arr, int jumlah)
{
    for (int i = 0; i < jumlah - 1; ++i)
    {
        for (int j = 0; j < jumlah - i - 1; ++j)
        {
            if ((arr + j)->id > (arr + j + 1)->id)
            {
                swapHewan(arr + j, arr + j + 1);
            }
        }
    }
}

// Fibonacci nye
int fibonacciSearchId(Hewan *arr, int jumlah, int targetId)
{
    if (jumlah == 0)
    {
        return -1;
    }

    sortIdNaik(arr, jumlah);

    int fibMm2 = 0;
    int fibMm1 = 1;
    int fibM = fibMm1 + fibMm2;

    while (fibM < jumlah)
    {
        fibMm2 = fibMm1;
        fibMm1 = fibM;
        fibM = fibMm1 + fibMm2;
    }

    int offset = -1;
    int iterasi = 1;

    // search dan iterasinye
    while (fibM > 1)
    {
        int i = min(offset + fibMm2, jumlah - 1);

        cout << "Iterasi " << iterasi << ": cek index " << i << " (ID = "
             << (arr + i)->id << ")\n";

        if ((arr + i)->id < targetId)
        {
            fibM = fibMm1;
            fibMm1 = fibMm2;
            fibMm2 = fibM - fibMm1;
            offset = i;
        }
        else if ((arr + i)->id > targetId)
        {
            fibM = fibMm2;
            fibMm1 = fibMm1 - fibMm2;
            fibMm2 = fibM - fibMm1;
        }
        else
        {
            return i;
        }

        ++iterasi;
    }

    if (fibMm1 && (offset + 1) < jumlah)
    {
        cout << "Iterasi " << iterasi << ": cek index " << (offset + 1)
             << " (ID = " << (arr + offset + 1)->id << ")\n";
        if ((arr + offset + 1)->id == targetId)
        {
            return offset + 1;
        }
    }

    return -1;
}

// func menu
void tampilMenu()
{
    cout << "\n=== MENU PAWCARE PETSHOP ===\n";
    cout << "1. Tampil semua data hewan\n";
    cout << "2. Tambah data hewan baru\n";
    cout << "3. Linear Search (nama hewan)\n";
    cout << "4. Fibonacci Search (ID hewan)\n";
    cout << "5. Bubble Sort nama (A-Z)\n";
    cout << "6. Selection Sort harga (murah-mahal)\n";
    cout << "0. Keluar\n";
    cout << "Pilih menu: ";
}

int main()
{
    const int kapasitas = 100;
    Hewan *dataHewan = nullptr;
    int jumlahData = 0;
    int pilihan = -1;

    inisialisasiData(dataHewan, kapasitas, jumlahData);

    // ni menu make switch
    do
    {
        tampilMenu();
        cin >> pilihan;

        if (!cin)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input harus angka.\n";
            continue;
        }

        switch (pilihan)
        {
        case 1:
            tampilData(dataHewan, jumlahData);
            break;

        case 2:
            tambahData(dataHewan, jumlahData, kapasitas);
            break;

        case 3:
        {
            if (jumlahData == 0)
            {
                cout << "Data masih kosong.\n";
                break;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            string namaCari;
            cout << "Masukkan nama hewan yang dicari: ";
            getline(cin, namaCari);

            int index = linearSearchNama(dataHewan, jumlahData, namaCari);
            if (index != -1)
            {
                const Hewan *hasil = dataHewan + index;
                cout << "Data ditemukan -> ID: " << hasil->id
                     << ", Nama: " << hasil->nama
                     << ", Jenis: " << hasil->jenis
                     << ", Umur: " << hasil->umur
                     << ", Harga: " << fixed << setprecision(0) << hasil->harga
                     << '\n';
            }
            else
            {
                cout << "Data tidak ditemukan.\n";
            }
            break;
        }

        case 4:
        {
            if (jumlahData == 0)
            {
                cout << "Data masih kosong.\n";
                break;
            }

            int idCari = 0;
            cout << "Masukkan ID hewan yang dicari: ";
            cin >> idCari;

            int index = fibonacciSearchId(dataHewan, jumlahData, idCari);
            if (index != -1)
            {
                Hewan *hasil = dataHewan + index;
                cout << "Data ditemukan -> ID: " << hasil->id
                     << ", Nama: " << hasil->nama
                     << ", Jenis: " << hasil->jenis
                     << ", Umur: " << hasil->umur
                     << ", Harga: " << fixed << setprecision(0) << hasil->harga
                     << '\n';
            }
            else
            {
                cout << "Data tidak ditemukan.\n";
            }
            break;
        }

        case 5:
            bubbleSortNama(dataHewan, jumlahData);
            cout << "Data berhasil diurutkan berdasarkan nama (A-Z).\n";
            break;

        case 6:
            selectionSortHarga(dataHewan, jumlahData);
            cout << "Data berhasil diurutkan berdasarkan harga (murah-mahal).\n";
            break;

        case 0:
            cout << "Program selesai.\n";
            break;

        default:
            cout << "Menu tidak tersedia.\n";
            break;
        }
    } while (pilihan != 0);

    delete[] dataHewan; // bersihkan datanya
    return 0;
}