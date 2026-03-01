#include <iostream>
using namespace std;

void tukar(int *a, int *b)
{
    int temp = *a; // simpan ditunjuk a ke temp
    *a = *b; // nilai di alamat a diganti alamat b
    *b = temp; // update temp jadi b
}

int main()
{
    int x, y;

    // input gaess
    cout << "Masukkan nilai x: ";
    cin >> x;
    cout << "Masukkan nilai y: ";
    cin >> y;

    // before
    cout << "Sebelum ditukar:" << endl;
    cout << "x = " << x << " (alamat: " << &x << ")" << endl;
    cout << "y = " << y << " (alamat: " << &y << ")" << endl;

    tukar(&x, &y); // tuker nih masukkan param ny

    //after
    cout << "Sesudah ditukar:" << endl;
    cout << "x = " << x << " (alamat: " << &x << ")" << endl;
    cout << "y = " << y << " (alamat: " << &y << ")" << endl;

    return 0;
}
