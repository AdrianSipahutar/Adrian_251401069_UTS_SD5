#include <iostream>
using namespace std;

int main() {
    int arr[2][3][4];
    int lima = 5;
    int ganjil = 1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            arr[0][i][j] = lima;
            lima += 5;
            
            arr[1][i][j] = ganjil;
            ganjil += 2;
        }
    }

    cout << "Nilai maksimal tiap lapisan:" << endl;
    for (int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++){
            if(arr[0][i][j] > arr[1][i][j]){
                cout << arr[0][i][j] << " ";
            }
            else{
            cout << arr[1][i][j] << " ";
            }
        }
    cout << endl;
    }
}