#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
int main()
{
int numeros[] = {1,2,3,4,5,6,7,8,9,10};
int suma = 0;
for (int i=0; i<=9; i++)
{
suma += numeros[i];
}
cout<<"La suma es: "<<suma;
printf("\n");
getch();
return 0;
}