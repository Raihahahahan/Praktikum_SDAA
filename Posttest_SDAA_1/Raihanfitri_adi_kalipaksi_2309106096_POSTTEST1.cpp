#include <iostream>
using namespace std;

void hitungpascal(int a, int b, int x, int y, int perulangan, int& bagian1, int& bagian2, int& bagian3) {
    if (perulangan > 2) return;

    if (perulangan == 0) {
        bagian1 = a * a * x * x;
        hitungpascal(a, b, x, y, perulangan + 1, bagian1, bagian2, bagian3);
    }
    else if (perulangan == 1) {
        bagian2 = 2 * a * b * x * y;
        hitungpascal(a, b, x, y, perulangan + 1, bagian1, bagian2, bagian3);
    }
    else if (perulangan == 2) {
        bagian3 = b * b * y * y;
    }
}

void printpascal(int a, int b, int x, int y) {
    int bagian1 = 0, bagian2 = 0, bagian3 = 0;

    hitungpascal(a, b, x, y, 0, bagian1, bagian2, bagian3);

    cout << "Hasil dari (" << a << "x + " << b << "y)^2 adalah: ";
    cout << bagian1 << "x^2";

    if (bagian2 != 0) {
        if (bagian2 > 0) cout << " + " << bagian2 << "xy";
        else cout << " - " << -bagian2 << "xy";
    }

    if (bagian3 != 0) {
        if (bagian3 > 0) cout << " + " << bagian3 << "y^2";
        else cout << " - " << -bagian3 << "y^2";
    }
    cout << endl;
}



int gambarpascal(int pangkat) {
    if (pangkat == 0) {
        cout << "1" << endl;
        return 1;
    } else {
        
        int prev = gambarpascal(pangkat - 1);
        for (int i = 0; i <= pangkat; ++i) {
            if (i == 0 || i == pangkat) {
                cout << "1 ";
            } else {
                cout << prev * (pangkat - i + 1) / i << " ";
            }
        }
        cout << endl;
        return 1;
    }
}

int main() {
    int a, b, x, y, tambahataukurang;
    
    

    cout << "Masukkan nilai a (koefisien untuk x): ";
    cin >> a;
    x =1;
    cout << "Masukkan nilai b (koefisien untuk y): ";
    cin >> b;
    y = 1 ;
    
    gambarpascal(2);

    printpascal(a, b, x, y);

    return 0;
}
