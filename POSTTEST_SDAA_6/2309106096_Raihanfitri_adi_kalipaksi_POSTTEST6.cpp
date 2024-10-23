#include <iostream>
#include <string>
#include <vector>
#include <cmath>

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

Node* sortedMerge(Node* a, Node* b) {
    Node* result = nullptr;
    if (a == nullptr)
        return b;
    else if (b == nullptr)
        return a;

    if (a->nomor_karcis <= b->nomor_karcis) {
        result = a;
        result->next = sortedMerge(a->next, b);
    } else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}

void split(Node* source, Node** frontRef, Node** backRef) {
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;

    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = nullptr;
}

void mergeSort(Node** headRef) {
    Node* head = *headRef;
    Node* a;
    Node* b;

    if ((head == nullptr) || (head->next == nullptr)) {
        return;
    }

    split(head, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *headRef = sortedMerge(a, b);
}
Node* getTail(Node* cur) {
    while (cur != nullptr && cur->next != nullptr)
        cur = cur->next;
    return cur;
}

Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
    Node* pivot = end;
    Node* prev = nullptr;
    Node* cur = head;
    Node* tail = pivot;

    while (cur != pivot) {
        if (cur->nomor_karcis > pivot->nomor_karcis) {
            if ((*newHead) == nullptr)
                (*newHead) = cur;

            prev = cur;
            cur = cur->next;
        } else {
            if (prev)
                prev->next = cur->next;
            Node* temp = cur->next;
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            cur = temp;
        }
    }

    if ((*newHead) == nullptr)
        (*newHead) = pivot;

    (*newEnd) = tail;

    return pivot;
}

Node* quickSortRecur(Node* head, Node* end) {
    if (!head || head == end)
        return head;

    Node* newHead = nullptr;
    Node* newEnd = nullptr;

    Node* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        Node* temp = newHead;
        while (temp->next != pivot)
            temp = temp->next;
        temp->next = nullptr;

        newHead = quickSortRecur(newHead, temp);

        temp = getTail(newHead);
        temp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}

void quickSort(Node** headRef) {
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
}

int min(int x, int y) { return (x <= y) ? x : y; }

int fibonacciSearch(vector<int>& arr, int x) {
    int n = arr.size();
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;

    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;

    while (fibM > 1) {
        int i = min(offset + fibMMm2, n - 1);

        if (arr[i] < x) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        } else if (arr[i] > x) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        } else
            return i;
    }

    if (fibMMm1 && arr[offset + 1] == x)
        return offset + 1;

    return -1;
}

int jumpSearch(vector<int>& arr, int x) {
    int n = arr.size();
    int step = sqrt(n);
    int prev = 0;

    while (arr[min(step, n) - 1] < x) {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }

    while (arr[prev] < x) {
        prev++;
        if (prev == min(step, n))
            return -1;
    }

    if (arr[prev] == x)
        return prev;

    return -1;
}

vector<int> preprocessBadChar(string str) {
    vector<int> badChar(256, -1);
    for (int i = 0; i < str.size(); i++) {
        badChar[(int)str[i]] = i;
    }
    return badChar;
}

int boyerMooreSearch(string text, string pattern) {
    int m = pattern.size();
    int n = text.size();

    vector<int> badChar = preprocessBadChar(pattern);

    int s = 0;
    while (s <= (n - m)) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[s + j])
            j--;

        if (j < 0) {
            return s;
            s += (s + m < n) ? m - badChar[text[s + m]] : 1;
        } else {
            s += max(1, j - badChar[text[s + j]]);
        }
    }

    return -1;
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
        cout << "5. Urutkan Pengunjung (Ascending)" << endl;
        cout << "6. Urutkan Pengunjung (Descending)" << endl;
        cout << "7. Cari Pengunjung (Fibonacci Search)" << endl;
        cout << "8. Cari Pengunjung (Jump Search)" << endl;
        cout << "9. Cari Pengunjung (Boyer-Moore Search)" << endl;
        cout << "10. Keluar" << endl;
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
                mergeSort(&head);
                cout << "Data berhasil diurutkan secara ascending." << endl;
                break;
            case 6:
                quickSort(&head);
                cout << "Data berhasil diurutkan secara descending." << endl;
                break;
            case 7: {
                vector<int> karcisList;
                Node* temp = head;
                while (temp != nullptr) {
                    karcisList.push_back(temp->nomor_karcis);
                    temp = temp->next;
                }
                int karcis;
                cout << "Masukkan nomor karcis yang ingin dicari: ";
                cin >> karcis;
                int index = fibonacciSearch(karcisList, karcis);
                if (index != -1) {
                    cout << "Nomor karcis ditemukan pada indeks: " << index << endl;
                } else {
                    cout << "Nomor karcis tidak ditemukan." << endl;
                }
                break;
            }
            case 8: {
                vector<int> karcisList;
                Node* temp = head;
                while (temp != nullptr) {
                    karcisList.push_back(temp->nomor_karcis);
                    temp = temp->next;
                }
                int karcis;
                cout << "Masukkan nomor karcis yang ingin dicari: ";
                cin >> karcis;
                int index = jumpSearch(karcisList, karcis);
                if (index != -1) {
                    cout << "Nomor karcis ditemukan pada indeks: " << index << endl;
                } else {
                    cout << "Nomor karcis tidak ditemukan." << endl;
                }
                break;
            }
            case 9: {
                string nama;
                cout << "Masukkan nama pengunjung yang ingin dicari: ";
                cin.ignore();
                getline(cin, nama);
                Node* temp = head;
                int index = -1;
                int pos = 0;
                while (temp != nullptr) {
                    if (boyerMooreSearch(temp->nama, nama) != -1) {
                        index = pos;
                        break;
                    }
                    temp = temp->next;
                    pos++;
                }
                if (index != -1) {
                    cout << "Nama pengunjung ditemukan pada indeks: " << index << endl;
                } else {
                    cout << "Nama pengunjung tidak ditemukan." << endl;
                }
                break;
            }
            case 10:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 10);

    return 0;
}
