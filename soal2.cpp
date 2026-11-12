#include <iostream>
#include <string>
#include <limits> // Diperlukan untuk membersihkan buffer input

using namespace std;

struct Node {
    string nama;
    int harga;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

void insertTail(string nama, int harga) {
    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->harga = harga;
    newNode->next = NULL;
    if (head == NULL) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void deleteHead() {
    if (head == NULL) {
        cout << "List Kosong !" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    if (head == NULL) {
        tail = NULL;
    }
}

void deleteTail() {
    if (head == NULL) {
        cout << "List Kosong !" << endl;
        return;
    }
    if (head == tail) {
        delete head;
        head = tail = NULL;
        return;
    }
    Node* p = head;
    while (p->next != tail) {
        p = p->next;
    }
    delete tail;
    tail = p;
    tail->next = NULL;
}

void tampilkanBarang() {
    cout << "\nList barang mewah:" << endl;
    Node* temp = head;
    bool ditemukan = false;
    int n = 1;
    while (temp != NULL) {
        if (temp->harga > 100000) {
            
            cout << n << "|" << temp->nama << " (Rp" << temp->harga << ")"<< endl;
            ditemukan = true;
            n += 1;
        }
        temp = temp->next;
    }
    if (!ditemukan) {
        cout << "Tidak ada barang dengan harga di atas 100000." << endl;
    }
}

int main() {
    int pilihan;
    string nama;
    int harga;

    do {
        cout << "\nMenu Aplikasi \n1. Insert Tail\n2. Delete Head\n3. Delete Tail\n4. Tampilkan Barang Mewah\n5. Keluar\nPilih: ";
        cin >> pilihan;

        if (pilihan == 1) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Masukkan nama: ";
            getline (cin, nama);
            cout << "Masukkan harga: ";
            cin >> harga;
            insertTail(nama, harga);
        } else if (pilihan == 2) {
            deleteHead();
        } else if (pilihan == 3) {
            deleteTail();
        } else if (pilihan == 4) {
            tampilkanBarang();
            system ("pause");
        }
    } while (pilihan != 5);

    return 0;
}
