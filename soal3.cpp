#include <iostream>
#include <string>
using namespace std;

#define MAX 100

struct Stack {
    int top = -1;
    char data[MAX];
};

void push(Stack &s, char c) {
    if (s.top < MAX - 1) {
        s.data[++s.top] = c;
    }
}

char pop(Stack &s) {
    if (s.top >= 0) {
        return s.data[s.top--];
    }
    return '\0';
}

int main() {
    Stack s;
    string kata;
    
    cout << "Masukkan kata: ";
    cin >> kata;
    
    for (char c : kata) {
        push(s, c);
    }
    
    string kata_dibalik = "";
    while (s.top >= 0) {
        kata_dibalik += pop(s);
    }
    
    cout << "Pengecekan:\nKata dibalik: " << kata_dibalik << endl;
    if (kata == kata_dibalik) {
        cout << "Kesimpulan: KATA INI ADALAH PALINDROM\n";
    } else {
        cout << "Kesimpulan: BUKAN PALINDROM\n";
    }
    
    return 0;
}