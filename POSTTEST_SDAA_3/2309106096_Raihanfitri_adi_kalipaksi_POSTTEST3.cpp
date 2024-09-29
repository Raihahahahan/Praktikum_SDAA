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





void addlast(Node *&head, int nomor_karcis, string nama, string tanggal){
    Node* newNode= new Node();
    newNode->nomor_karcis = nomor_karcis;
    newNode->nama = nama;
    newNode->tanggal = tanggal;
    newNode->next = nullptr;
    if(head == nullptr){
        head = newNode;
    }
    else{
        Node* temp = head;
        while (temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
        
        
    }
}

void addafter(Node *&head, int nomor_karcis, string nama, string tanggal, int check){
    Node* newNode= new Node();
    newNode->nomor_karcis = nomor_karcis;
    newNode->nama = nama;
    newNode->tanggal = tanggal;
    newNode->next = nullptr;
    if(head == nullptr){
        head = newNode;
    }

    Node* temp = head;
    while (temp != nullptr && temp->nomor_karcis != check){
        temp = temp -> next;
    }

    if (temp == nullptr) {
        cout << "Nomor karcis tidak ditemukan" << endl;
        return;
    }


    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Data Berhasil Di Tambahkan" << endl; 
}

void addfirst(Node *&head, int nomor_karcis, string nama, string tanggal){
    Node* newNode= new Node();
    newNode->nomor_karcis = nomor_karcis;
    newNode->nama = nama;
    newNode->tanggal = tanggal;
    newNode->next = head;
    head = newNode;
}


void tambahpengunjung(Node *&head){
    int karcis,pilihan;
    cout << "Masukkan nomor karcis: ";
    cin >> karcis;

    cout << "Masukkan nama pengunjung: ";
    cin.ignore();
    string nama;
    getline(cin, nama);

    cout << "Masukkan tanggal (dd-mm-yyyy): ";
    string tanggal;
    getline(cin, tanggal);



    cout <<"1. Tambah Di Akhir Data"<<endl;
    cout <<"2. Tambah Di Awal Data"<<endl;
    cout <<"3. Tambah Setelah Data"<<endl;
    cout <<"Pilih : ";
    cin >> pilihan;
    switch (pilihan)
    {
    case 1:
        addlast(head, karcis, nama, tanggal);
        cout << "Data Berhasil Di Tambahkan" << endl;
        break;
    
    case 2:
        addfirst(head, karcis, nama, tanggal);
        cout << "Data Berhasil Di Tambahkan" << endl;
        break;
    case 3:{
        if (head == nullptr) {
            cout << "Belum ada data pengunjung." << endl;
            return;
        }
        lihatPengunjung(head);
        int check;
        cout << "Masukkan nomor karcis yang ingin di tambahkan setelahnya: ";
        cin >> check;
        addafter(head, karcis, nama, tanggal, check);
        
        break;
    }
    default:
        cout << "Pilihan tidak valid." << endl;
        break;
    }

}



void deletelast(Node *&head){
    if(head == nullptr){
        cout << "Data Kosong" << endl;
        return;
    }
    else if(head->next == nullptr){
        delete head;
        head = nullptr;
    }
    else{
        Node* temp = head;
        while(temp->next->next != nullptr){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;

    }
    cout << "Data Berhasil Di Hapus" << endl;

}


void deletefirst(Node *&head){
    if(head == nullptr){
        cout << "Data Kosong" << endl;
        return;
    }
    else{
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    cout << "Data Berhasil Di Hapus" << endl;

}

void deleteafter(Node *&head, int check) {
    if (head == nullptr) {
        cout << "Data Kosong" << endl;
        return;
    }

    Node* temp = head;
    while (temp != nullptr && temp->nomor_karcis != check) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Nomor karcis tidak ditemukan" << endl;
        return;
    }

    if (temp->next == nullptr) {
        cout << "Data setelahnya kosong" << endl;
        return;
    }

    Node* hapus = temp->next;
    temp->next = temp->next->next;
    delete hapus;

    cout << "Data Berhasil Di Hapus" << endl;
}

void hapuspengunjung(Node *&head){
    int pilihan;
    


    cout <<"1. Hapus Di Akhir Data"<<endl;
    cout <<"2. Hapus Di Awal Data"<<endl;
    cout <<"3. Hapus Setelah Data"<<endl;
    cout <<"Pilih : ";
    cin >> pilihan;
    switch (pilihan)
    {
    case 1:
        deletelast(head);
        break;
    
    case 2:
        deletefirst(head);
        break;
    case 3:{
        if (head == nullptr) {
            cout << "Belum ada data pengunjung." << endl;
            return;
        }
        lihatPengunjung(head);
        int check;
        cout << "Masukkan nomor karcis yang ingin di hapus setelahnya: ";
        cin >> check;
        deleteafter(head, check);
        break;
    }
    default:
        cout << "Pilihan tidak valid." << endl;
        break;
    }
}




void updatePengunjung(Node *&head) {
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
            case 1: {
                tambahpengunjung(head);
                break;
            }
            case 2:
                lihatPengunjung(head);
                break;
            case 3:
                updatePengunjung(head);
                break;
            case 4:
                hapuspengunjung(head);
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