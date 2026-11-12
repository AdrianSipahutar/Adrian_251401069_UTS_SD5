#include <iostream>
using namespace std;

struct node {
    int data;
    node* kiri;
    node* kanan;
};

node* akar = NULL;


void addNode(node **akar, int value) {
    if(*akar == NULL) {
        node* baru = new node;
        baru -> data = value;
        baru -> kiri = NULL;
        baru -> kanan = NULL;
        *akar = baru;
    }
    if (value < (*akar)->data) {
        addNode(&((*akar)->kiri), value);
    } 
    else if (value > (*akar)->data) {
        addNode(&((*akar)->kanan), value);
    }
}

void inOrder(node* akar) {
    if (akar != NULL){
        inOrder(akar -> kiri);
        cout << akar -> data << " ";
        inOrder(akar -> kanan);
    }
}

void postOrder(node* akar) {
    if (akar != NULL) {
        postOrder(akar -> kiri);
        postOrder(akar -> kanan);
        cout << akar -> data << " ";
    }
}

int angkaMin(node* akar) {
    while (akar->kiri != NULL) {
        akar = akar->kiri;
    }
    return akar->data;
}

int angkaMax(node* akar) {
    while (akar->kanan != NULL) {
        akar = akar->kanan;
    }
    return akar->data;
}

int main() {
    node* akar = NULL;
    int num;
    
    cout << "Masukkan angka (ketik 0 kalau mau stop): \n";
    while (cin >> num && num != 0) {
        addNode(&akar, num);
    }
    
    if (akar != NULL) {
        cout << "Data (In-Order): ";
        inOrder(akar);
        cout << "\nNilai Terkecil: " << angkaMin(akar) << endl;
        cout << "Nilai Terbesar: " << angkaMax(akar) << endl;
    }
    
    return 0;
}