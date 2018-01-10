/*
Enunciado: Implementar una función que muestre las etiquetas de los nodos de un
árbol binario de enteros que estén entre dos niveles dados n1 y n2 (0<=n1<n2),
ambos inclusive.
Author: Elena Merelo Molina
*/
#include <ejer3.h>

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

  cout << "\nNúmero de niveles del árbol: " << ab1.num_levels();

  int n1, n2;
  cout << "\nIntroduzca niveles de los cuales quiere conocer las etiquetas: ";
  cin >> n1;
  cin >> n2;

  vector<int> etiquetas, recorrido;
  ab1.in_order(ab1.raiz(), recorrido);
  ab1.etiquetas_entre(n1,n2,etiquetas);

  typename vector<int>::iterator i;
  cout << "\nRecorrido in order del árbol: ";
  for(i= recorrido.begin(); i != recorrido.end(); i++)
    cout << " " << *i;

  cout << "\nEtiquetas entre los niveles " << n1 << " y " << n2 << ": ";

  for(i= etiquetas.begin(); i != etiquetas.end(); i++)
    cout << " " << *i;
}
