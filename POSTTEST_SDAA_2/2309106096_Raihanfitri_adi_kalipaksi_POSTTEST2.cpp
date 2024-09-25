#include <iostream>
#include <string>

using namespace std;

struct Pengunjung {
    int nomor_karcis;
    string nama;
    string tanggal;
};

Pengunjung* pengunjung[1000];
int JumlahPengunjung = 0;

void tambahkanPengunjung() {
    if (JumlahPengunjung >= 1000) {
        cout << "Jumlah pengunjung sudah mencapai batas" << endl;
    } else {
        Pengunjung* peng = new Pengunjung;
        peng->nomor_karcis = JumlahPengunjung + 1;

        cout << "Masukkan nama pengunjung: ";
        cin.ignore();
        getline(cin, peng->nama);
        for (int i = 0; i < JumlahPengunjung; ++i) {
            if (peng->nama == pengunjung[i]->nama) {
                cout << "Nama pengunjung sudah terdaftar. Silakan masukkan nama yang berbeda." << endl;
                delete peng;
                return;
            }
        }

        cout << "Masukkan tanggal kunjungan (dd-mm-yyyy): ";
        getline(cin, peng->tanggal);

        pengunjung[JumlahPengunjung] = peng;
        JumlahPengunjung++;
        cout << "Nama sudah didaftarkan" << endl;
    }
}

void lihatPengunjung() {
    if (JumlahPengunjung == 0) {
        cout << "Belum ada nama pengunjung yang dimasukkan." << endl;
    } else {
        for (int i = 0; i < JumlahPengunjung; ++i) {
            cout << "Nomor Karcis: " << pengunjung[i]->nomor_karcis << endl;
            cout << "Nama: " << pengunjung[i]->nama << endl;
            cout << "Tanggal: " << pengunjung[i]->tanggal << endl;
            cout << "-------------------------" << endl;
        }
    }
}

void updatePengunjung() {
    int nomor;
    cout << "Masukkan nomor karcis pengunjung yang ingin diupdate: ";
    cin >> nomor;
    cin.ignore();

    for (int i = 0; i < JumlahPengunjung; ++i) {
        if (pengunjung[i]->nomor_karcis == nomor) {
            cout << "Masukkan nama baru: ";
            getline(cin, pengunjung[i]->nama);
            cout << "Masukkan tanggal baru (dd-mm-yyyy): ";
            getline(cin, pengunjung[i]->tanggal);
            cout << "Data pengunjung telah diupdate." << endl;
            return;
        }
    }
    cout << "Pengunjung dengan nomor karcis tersebut tidak ditemukan." << endl;
}

void hapusPengunjung() {
    int nomor;
    cout << "Masukkan nomor karcis pengunjung yang ingin dihapus: ";
    cin >> nomor;

    for (int i = 0; i < JumlahPengunjung; ++i) {
        if (pengunjung[i]->nomor_karcis == nomor) {
            delete pengunjung[i];
            for (int j = i; j < JumlahPengunjung - 1; ++j) {
                pengunjung[j] = pengunjung[j + 1];
            }
            pengunjung[JumlahPengunjung - 1] = nullptr;
            JumlahPengunjung--;
            cout << "Pengunjung telah dihapus." << endl;
            return;
        }
    }
    cout << "Pengunjung dengan nomor karcis tersebut tidak ditemukan." << endl;
}

int main() {
    int pilihan;
    do {
        cout << "Menu:" << endl;
        cout << "1. Tambah Pengunjung" << endl;
        cout << "2. Lihat Pengunjung" << endl;
        cout << "3. Update Pengunjung" << endl;
        cout << "4. Hapus Pengunjung" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahkanPengunjung();
                break;
            case 2:
                lihatPengunjung();
                break;
            case 3:
                updatePengunjung();
                break;
            case 4:
                hapusPengunjung();
                break;
            case 5:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 5);

    return 0;
}