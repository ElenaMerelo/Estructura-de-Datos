/*Enunciado del ejercicio: Implementa una función que compruebe si un árbol
binario es simétrico a otro.
Author: Elena Merelo Molina.
*/

#include <ejer5.hpp>
#include<iostream>

using namespace std;

int main(){
  ArbolBinario<int> ab1;
  int e;

  cout << "\nIntroduzca datos enteros para el árbol binario 1(<0 para terminar): ";
  cin>> e;
  while(e>= 0){
    ab1.insertar(e);
    cout << "\nIntroduzca entero(<0 para terminar): ";
    cin >> e;
  }
  cout << "\nÁrbol binario 1: \n";
  ab1.Esquema();

  ArbolBinario<int> ab2;
  cout << "\nIntroduzca datos enteros para el árbol binario 2(<0 para terminar): ";
  cin>> e;
  while(e>= 0){
    ab2.insertar(e);
    cout << "\nIntroduzca entero(<0 para terminar): ";
    cin >> e;
  }
  cout << "\nÁrbol binario 2: \n";
  ab2.Esquema();

  if(son_simetricos(ab1, ab2))
    cout << "\nLos dos árboles son simétricos";
  else
    cout << "\nLos dos árboles no son simétricos";
}
