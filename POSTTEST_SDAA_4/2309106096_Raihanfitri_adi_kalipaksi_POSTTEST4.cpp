#include <iostream>
#include <string>

using namespace std;

struct Node {
    int nomor_karcis;
    string nama;
    string tanggal;
    Node* next;
};

void lihatPengunjung(Node* head) {
    if (head == nullptr) {
        cout << "Tidak ada pengunjung." << endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << "Nomor Karcis: " << temp->nomor_karcis << endl;
        cout << "Nama: " << temp->nama << endl;
        cout << "Tanggal: " << temp->tanggal << endl;
        cout << "-------------------------" << endl;
        temp = temp->next;
    }
}

void push(Node*& head, int nomor_karcis, string nama, string tanggal) {
    Node* newNode = new Node();
    newNode->nomor_karcis = nomor_karcis;
    newNode->nama = nama;
    newNode->tanggal = tanggal;
    newNode->next = head;
    head = newNode;
    cout << "Data Berhasil Di Tambahkan" << endl;
}

void pop(Node*& head) {
    if (head == nullptr) {
        cout << "Data Kosong" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    cout << "Data Berhasil Di Hapus" << endl;
}

void enqueue(Node*& head, int nomor_karcis, string nama, string tanggal) {
    Node* newNode = new Node();
    newNode->nomor_karcis = nomor_karcis;
    newNode->nama = nama;
    newNode->tanggal = tanggal;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Data Berhasil Di Tambahkan" << endl;
}

void dequeue(Node*& head) {
    if (head == nullptr) {
        cout << "Data Kosong" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    cout << "Data Berhasil Di Hapus" << endl;
}

void updatePengunjung(Node*& head) {
    if (head == nullptr) {
        cout << "Tidak ada pengunjung." << endl;
        return;
    }

    lihatPengunjung(head);

    int nomor_karcis;
    cout << "Masukkan nomor karcis yang ingin diupdate: ";
    cin >> nomor_karcis;

    Node* temp = head;
    while (temp != nullptr && temp->nomor_karcis != nomor_karcis) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Nomor karcis tidak ditemukan." << endl;
        return;
    }

    cout << "Masukkan nama baru: ";
    cin.ignore();
    string nama;
    getline(cin, nama);

    cout << "Masukkan tanggal baru (dd-mm-yyyy): ";
    string tanggal;
    getline(cin, tanggal);

    temp->nama = nama;
    temp->tanggal = tanggal;

    cout << "Data Berhasil Diupdate" << endl;
}

int main() {
    Node* head = nullptr;
    int pilihan, struktur;

    cout << "Pilih Struktur Data:" << endl;
    cout << "1. Stack" << endl;
    cout << "2. Queue" << endl;
    cout << "Pilih opsi: ";
    cin >> struktur;

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
            case 1: {
                int karcis;
                cout << "Masukkan nomor karcis: ";
                cin >> karcis;

                cout << "Masukkan nama pengunjung: ";
                cin.ignore();
                string nama;
                getline(cin, nama);

                cout << "Masukkan tanggal (dd-mm-yyyy): ";
                string tanggal;
                getline(cin, tanggal);

                if (struktur == 1) {
                    push(head, karcis, nama, tanggal);
                } else if (struktur == 2) {
                    enqueue(head, karcis, nama, tanggal);
                }
                break;
            }
            case 2:
                lihatPengunjung(head);
                break;
            case 3:
                updatePengunjung(head);
                break;
            case 4:
                if (struktur == 1) {
                    pop(head);
                } else if (struktur == 2) {
                    dequeue(head);
                }
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
