/*Enunciado del ejercicio: Implementa una función que compruebe si un árbol
binario es simétrico a otro.
Author: Elena Merelo Molina.
*/

#include <ejer5.hpp>
#include<iostream>

using namespace std;

int main(){
  //Creamos el primer árbol binario
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
  cout << ab1;

  //Creamos el segundo árbol binario
  ArbolBinario<int> ab2;
  cout << "\nIntroduzca datos enteros para el árbol binario 2(<0 para terminar): ";
  cin>> e;
  while(e>= 0){
    ab2.insertar(e);
    cout << "\nIntroduzca entero(<0 para terminar): ";
    cin >> e;
  }
  cout << "\nÁrbol binario 2: \n";
  cout << ab2;

  if(ab1.es_simetrico_a(ab2))
    cout << "\nLos árboles 1 y 2 son simétricos";
  else
    cout << "\nLos árboles 1 y 2 no son simétricos";

  //Probamos los otros casos posibles
  ArbolBinario<int> ab3, ab4;
  if(ab3.es_simetrico_a(ab4))
    cout << "\nLos árboles 3 y 4 son simétricos";
  else
    cout << "\nLos árboles 3 y 4 no son simétricos";

    if(ab1.es_simetrico_a(ab3))
      cout << "\nLos árboles 1 y 3 son simétricos";
    else
      cout << "\nLos árboles 1 y 3 no son simétricos";


}
