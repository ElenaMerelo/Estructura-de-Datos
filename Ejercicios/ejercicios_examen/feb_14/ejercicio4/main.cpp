/*
Enunciado:
a) Dado un árbol binario de enteros (positivos y negativos) implementar una
función que obtenga el número de caminos, en los que la suma de las etiquetas
de los nodos que los componen sea exactamente k.
int NumeroCaminos(bintree<int> & ab, int k)
b) Construir el AVL y el APO que resultan de insertar (en ese orden) los
elementos del conjunto de enteros {45,23,12,20,15,22,24,55,52}.
Author: Elena Merelo Molina
*/
#include <ejer4.h>

int main(){
  ArbolBinario<int> ab1;
  int e;
  cout << "\nIntroduzca datos enteros para el árbol binario 1(número <0 para terminar): ";
  cin>> e;

  while(e >= 0){
    ab1.insert(e);
    cout << "\nIntroduzca entero(<0 para terminar): ";
    cin >> e;
  }
  cout << "\nÁrbol binario 1: \n";
  cout << ab1;
  cout << "\nLos elementos del árbol in order: ";
  ab1.show_elements_in_order(ab1.raiz());
  cout << "\nEl número de caminos que suman 5 es: " << ab1.number_of_paths(5);


}
