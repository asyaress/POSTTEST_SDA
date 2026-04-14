#include <algorithm>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

const int KAPASITAS_AWAL = 10;

// Struct & array of struct
struct Hewan
{
    int id;
    string nama;
    string jenis;
    int umur;
    double harga;
    Hewan *next;
};

struct Pasien // node untuk antrian dan riwayat
{
    int id;
    string nama;
    string tindakan;
    Pasien *next;
};

struct QueuePemeriksaan // linked list queue
{
    Pasien *front;
    Pasien *rear;
    int jumlah;
};

struct StackRiwayat // linked list stack
{
    Pasien *top;
    int jumlah;
};

// swap nye
void swapHewan(Hewan *a, Hewan *b)
{
    Hewan temp = *a; // Pointer
    *a = *b;
    *b = temp;
}

void inisialisasiData(Hewan *&arr, int &kapasitas, int &jumlah)
{
    kapasitas = KAPASITAS_AWAL;
    arr = new Hewan[kapasitas];
    jumlah = 3;

    (arr + 0)->id = 101;
    (arr + 0)->nama = "Milo";
    (arr + 0)->jenis = "Kucing";
    (arr + 0)->umur = 2;
    (arr + 0)->harga = 350000;
    (arr + 0)->next = nullptr;

    (arr + 1)->id = 102;
    (arr + 1)->nama = "Bobby";
    (arr + 1)->jenis = "Anjing";
    (arr + 1)->umur = 1;
    (arr + 1)->harga = 500000;
    (arr + 1)->next = nullptr;

    (arr + 2)->id = 103;
    (arr + 2)->nama = "Coco";
    (arr + 2)->jenis = "Kelinci";
    (arr + 2)->umur = 1;
    (arr + 2)->harga = 200000;
    (arr + 2)->next = nullptr;
}

void pastikanKapasitas(Hewan *&arr, int &kapasitas, int jumlah)
{
    if (jumlah < kapasitas)
    {
        return;
    }

    int kapasitasBaru = kapasitas * 2;
    Hewan *arrBaru = new Hewan[kapasitasBaru];

    for (int i = 0; i < jumlah; ++i)
    {
        *(arrBaru + i) = *(arr + i);
    }

    delete[] arr;
    arr = arrBaru;
    kapasitas = kapasitasBaru;
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

void tambahData(Hewan *&arr, int &jumlah, int &kapasitas)
{
    pastikanKapasitas(arr, kapasitas, jumlah);

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
    baru->next = nullptr;

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

// validasi untuk daftar antrian
int cariHewanById(const Hewan *arr, int jumlah, int targetId)
{
    for (int i = 0; i < jumlah; ++i)
    {
        if ((arr + i)->id == targetId)
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

// antrian dan riwayat start (Single Linked List)
void initQueue(QueuePemeriksaan *antrian)
{
    antrian->front = nullptr;
    antrian->rear = nullptr;
    antrian->jumlah = 0;
}

void initStack(StackRiwayat *riwayat)
{
    riwayat->top = nullptr;
    riwayat->jumlah = 0;
}

void pushRiwayat(StackRiwayat *riwayat, const Pasien *pasien)
{
    Pasien *nodeBaru = new Pasien;
    nodeBaru->id = pasien->id;
    nodeBaru->nama = pasien->nama;
    nodeBaru->tindakan = pasien->tindakan;
    nodeBaru->next = riwayat->top;

    riwayat->top = nodeBaru;
    ++riwayat->jumlah;
    cout << "Riwayat tindakan masuk ke stack.\n";
}

void popRiwayat(StackRiwayat *riwayat)
{
    if (riwayat->top == nullptr)
    {
        cout << "Stack riwayat kosong (underflow).\n";
        return;
    }

    Pasien *hapus = riwayat->top;
    riwayat->top = hapus->next;
    --riwayat->jumlah;

    cout << "Riwayat terakhir dihapus -> ID: " << hapus->id
         << ", Nama: " << hapus->nama
         << ", Tindakan: " << hapus->tindakan << '\n';

    delete hapus;
}

void enqueuePasien(QueuePemeriksaan *antrian, const Hewan *dataHewan, int jumlahData)
{
    int idDaftar = 0;
    cout << "Masukkan ID hewan yang daftar antrian: ";
    cin >> idDaftar;

    if (!cin)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input ID harus angka.\n";
        return;
    }

    int indexHewan = cariHewanById(dataHewan, jumlahData, idDaftar);
    if (indexHewan == -1)
    {
        cout << "ID hewan tidak ditemukan di data utama.\n";
        return;
    }

    Pasien *nodeBaru = new Pasien;
    nodeBaru->id = (dataHewan + indexHewan)->id;
    nodeBaru->nama = (dataHewan + indexHewan)->nama;
    nodeBaru->tindakan = "-";
    nodeBaru->next = nullptr;

    if (antrian->rear == nullptr)
    {
        antrian->front = nodeBaru;
        antrian->rear = nodeBaru;
    }
    else
    {
        antrian->rear->next = nodeBaru;
        antrian->rear = nodeBaru;
    }

    ++antrian->jumlah;

    cout << "Pasien masuk antrian -> ID: " << nodeBaru->id
         << ", Nama: " << nodeBaru->nama << '\n';
}

void dequeuePasien(QueuePemeriksaan *antrian, StackRiwayat *riwayat)
{
    if (antrian->front == nullptr)
    {
        cout << "Antrian kosong (underflow).\n";
        return;
    }

    Pasien *nodeKeluar = antrian->front;
    Pasien dipanggil;
    dipanggil.id = nodeKeluar->id;
    dipanggil.nama = nodeKeluar->nama;
    dipanggil.tindakan = nodeKeluar->tindakan;
    dipanggil.next = nullptr;

    cout << "Pasien dipanggil -> ID: " << dipanggil.id
         << ", Nama: " << dipanggil.nama << '\n';

    antrian->front = nodeKeluar->next;
    if (antrian->front == nullptr)
    {
        antrian->rear = nullptr;
    }
    --antrian->jumlah;
    delete nodeKeluar;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Masukkan tindakan medis: ";
    getline(cin, dipanggil.tindakan);
    pushRiwayat(riwayat, &dipanggil);
}

void peekData(const QueuePemeriksaan *antrian, const StackRiwayat *riwayat)
{
    cout << "\n=== PEEK DATA ===\n";

    if (antrian->front == nullptr)
    {
        cout << "Antrian: kosong (underflow saat peek antrian).\n";
    }
    else
    {
        const Pasien *depan = antrian->front;
        cout << "Antrian terdepan -> ID: " << depan->id
             << ", Nama: " << depan->nama << '\n';
    }

    if (riwayat->top == nullptr)
    {
        cout << "Riwayat: kosong (underflow saat peek stack).\n";
    }
    else
    {
        const Pasien *akhir = riwayat->top;
        cout << "Tindakan terakhir -> ID: " << akhir->id
             << ", Nama: " << akhir->nama
             << ", Tindakan: " << akhir->tindakan << '\n';
    }
}

void tampilAntrian(const QueuePemeriksaan *antrian)
{
    if (antrian->front == nullptr)
    {
        cout << "Antrian pemeriksaan kosong.\n";
        return;
    }

    cout << "\n=== ANTRIAN PEMERIKSAAN (FRONT -> REAR) ===\n";
    cout << left << setw(6) << "ID" << "Nama\n";
    cout << "------------------------------\n";

    const Pasien *current = antrian->front;
    while (current != nullptr)
    {
        cout << left << setw(6) << current->id << current->nama << '\n';
        current = current->next;
    }
}

void tampilRiwayat(const StackRiwayat *riwayat)
{
    if (riwayat->top == nullptr)
    {
        cout << "Riwayat tindakan kosong.\n";
        return;
    }

    cout << "\n=== RIWAYAT TINDAKAN (TOP -> BOTTOM) ===\n";
    cout << left << setw(6) << "ID" << setw(15) << "Nama" << "Tindakan\n";
    cout << "---------------------------------------------------\n";

    const Pasien *current = riwayat->top;
    while (current != nullptr)
    {
        cout << left << setw(6) << current->id << setw(15) << current->nama
             << current->tindakan << '\n';
        current = current->next;
    }
}

void clearQueue(QueuePemeriksaan *antrian)
{
    while (antrian->front != nullptr)
    {
        Pasien *hapus = antrian->front;
        antrian->front = antrian->front->next;
        delete hapus;
    }
    antrian->rear = nullptr;
    antrian->jumlah = 0;
}

void clearStack(StackRiwayat *riwayat)
{
    while (riwayat->top != nullptr)
    {
        Pasien *hapus = riwayat->top;
        riwayat->top = riwayat->top->next;
        delete hapus;
    }
    riwayat->jumlah = 0;
}

// antrian dan riwayat end

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
    cout << "7. Enqueue antrian pemeriksaan\n";
    cout << "8. Dequeue / panggil pasien\n";
    cout << "9. Peek antrian & riwayat\n";
    cout << "10. Tampil semua antrian\n";
    cout << "11. Tampil semua riwayat\n";
    cout << "12. Pop riwayat tindakan terakhir\n";
    cout << "0. Keluar\n";
    cout << "Pilih menu: ";
}

int main()
{
    int kapasitas = 0;
    Hewan *dataHewan = nullptr;
    QueuePemeriksaan antrian;
    StackRiwayat riwayat;
    int jumlahData = 0;
    int pilihan = -1;

    inisialisasiData(dataHewan, kapasitas, jumlahData);
    initQueue(&antrian);
    initStack(&riwayat);

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

        case 7:
            enqueuePasien(&antrian, dataHewan, jumlahData);
            break;

        case 8:
            dequeuePasien(&antrian, &riwayat);
            break;

        case 9:
            peekData(&antrian, &riwayat);
            break;

        case 10:
            tampilAntrian(&antrian);
            break;

        case 11:
            tampilRiwayat(&riwayat);
            break;

        case 12:
            popRiwayat(&riwayat);
            break;

        case 0:
            cout << "Program selesai.\n";
            break;

        default:
            cout << "Menu tidak tersedia.\n";
            break;
        }
    } while (pilihan != 0);

    clearQueue(&antrian);
    clearStack(&riwayat);
    delete[] dataHewan; // bersihkan datanya
    return 0;
}
