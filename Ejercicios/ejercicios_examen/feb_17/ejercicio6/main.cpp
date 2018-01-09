/*
Enunciado: Se define la trayectoria de una hoja en un árbol binario como la
suma del contenido de todos los nodos desde la raíz hasta la hoja multiplicada
por el nivel en cada nodo se encuentra. Implementar (usando el TDA bintree) un
procedimiento que, dado un árbol binario devuelva la hoja con mayor trayectoria.
  7
 / \
 1 3
/ / \
4 2 1
Tra(4)=4*3+1*2+7*1=21 (**)
Tra(2)=2*3+3*2+7*1=19
Tra(1)=1*3+3*2+7*1=16
Author: Elena Merelo Molina
*/
#include <ejer6.h>

int main(){
  ArbolBinario<int> ab1;
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
  cout << "\nLa trayectoria del nodo en la posición 3 es: " << ab1.trayectoria(3);

}
