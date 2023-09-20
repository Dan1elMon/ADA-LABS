#include <iostream>
using namespace std;

int main() {
    int x;
    int arr[5];
    string print;
    for (int i = 0; i < 5; i = i + 1) {
        
        cout << "Escriba un numero: ";
        cin >> x;
        arr[i]=x;
    } 
    for (int i = 0; i <= 5; i = i + 1) {
        
        print= i+" -> "+arr[i];
        cout << print;
    } 
}
