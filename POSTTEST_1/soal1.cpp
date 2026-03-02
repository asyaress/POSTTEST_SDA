#include <iostream>
using namespace std;

int FindMin(int A[], int n, int &indexMin) // sesuai soal disuruh bikin findmin
{
  int nilaiMin = A[0]; //index 0 jadiin nilai minimum awal
  indexMin = 0; // anggap dia ada di posisi 0

  for (int i = 1; i < n; i++) // loop untuk bandigin elemennya
  {
    if (A[i] < nilaiMin) 
    {
      nilaiMin = A[i]; //kalau bener, perbarui sesuai elemen yang lagi jalan
      indexMin = i; //kan tadi 0, update jadi minimum baru
    }
  }

  return nilaiMin;
}

int main()
{
  int A[] = {1, 1, 2, 3, 5, 8, 13, 21}; //angka fibonacci sesuai soal
  int n = 8; // sesuai angka ada 8

  cout << "Isi array: "; 
  for (int i = 0; i < n; i++)
  {
    cout << A[i];
    if (i < n - 1)
      cout << " ";
  }
  cout << endl;  // cetak dlu array nya

  int indexMin; // sama ini nilai minimum nya
  int nilaiMin = FindMin(A, n, indexMin); // tinggal isi parameter sesyau fungsinya

  cout << "Nilai minimum: " << nilaiMin << endl;
  cout << "Indeks minimum: " << indexMin << endl;
  cout << "Kompleksitas: O(n)" << endl;

  //diatas ya tinggal print
  return 0;
}

/*
HASIL ANALISIS KOMPLEKSITAS MANUWAL:

Best Case:
Tmin(n) = (C1 + C2 + C3 + C10 + C11) + (C4 + C9)n + (C5 + C8) (n−1)
Linear  =  O(n)

Worst Case:
Tmax(n) = (C1 + C2 + C3 + C10 + C11) + (C4 + C9)n + (C5 + C6 +C7 + C8) (n−1)
Linear = O(n)

KESIMPULAN BIG-O:
- Best Case  : O(n)
- Worst Case : O(n)
Alasan: Kedua persamaan merupakan fungsi linear terhadap n.

Kalau mau liat detail ada di POSTTEST_SDA/POSTTEST_1/Jawaban-Min-Max.pdf
*/