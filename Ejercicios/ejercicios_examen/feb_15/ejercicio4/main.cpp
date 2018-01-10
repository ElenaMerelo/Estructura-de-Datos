/*
Enunciado: Se dice que un árbol binario de enteros es inferior a otro si (teniendo la
misma estructura de ramificación), los elementos del primero, en los nodos
coincidentes en posición, son menores que los del segundo. Diseñar una función
booleana que dados dos árboles binarios, devuelva true si el primero es inferior al
segundo
bool es_inferior(bintree<int> & ab1, bintree<int> & ab2)
Author: Elena Merelo Molina
*/
#include <ejer4.h>

int main(){
  ArbolBinario<int> ab1, ab2;
  int e;
  cout << "\nIntroduzca datos enteros para el árbol binario 1(número <0 para terminar): ";
  cin>> e;

  while(e >= 0){
    ab1.insertar(e);
    cout << "\nIntroduzca entero(<0 para terminar): ";
    cin >> e;
  }
  cout << "\nÁrbol binario 1: \n";
  cout << ab1;

  cout << "\nIntroduzca datos enteros para el árbol binario 2(número <0 para terminar): ";
  cin>> e;

  while(e >= 0){
    ab2.insertar(e);
    cout << "\nIntroduzca entero(<0 para terminar): ";
    cin >> e;
  }
  cout << "\nÁrbol binario 2: \n";
  cout << ab2;

  if(ab1.es_inferior(ab2))
    cout << "\nEl árbol binario 1 es inferior al 2";

  else
    cout << "\nEl árbol binario 1 no es inferior al 2";
}
