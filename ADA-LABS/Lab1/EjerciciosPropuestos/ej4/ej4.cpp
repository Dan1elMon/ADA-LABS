#include <iostream>
using namespace std;
void myFunction();

int main() {
int x;
    int arr[5];
    string list;
    for (int i = 0; i < 5; i = i + 1) {
        
        cout << "Escriba un numero: ";
        cin >> x;
        arr[i]=x;
    }

    cout << "------------------";
    myFunction(arr[5]);

    return 0;
}
void myFunction(int arr) {
    int min;
  for(int i=0;i<5;i++){
    if(arr[i]<arr[i]){
        min=arr[i];
    }
  }
  cout<<"El menor es";
  cout<< min;
}