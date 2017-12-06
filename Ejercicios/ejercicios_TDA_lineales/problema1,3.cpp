/*
Enunciado: Diseñar una función swap que intercambie los contenidos de dos listas. Implementarlo
mediante una función independiente y como función miembro (o función amiga) de listas. ¿Qué eficiencia
tienen?
Autora: Elena Merelo Molina
Compilación y enlazado: g++ problema1,3.cpp -o problema1,3
Ejecución: ./problema1,3
*/
#include <list>
#include <iostream>

using namespace std;

/*La función se queda realmente simple gracias a que el tipo list tiene sobrecargado
el operador de asignación.*/
template <class T>
void swap(list<T> &l1, list<T> &l2){
  list<T> aux= l1;
  l1= l2;
  l2= aux;
}

//Función para mostrar una lista
template <class T>
void show_list(const list<T> &l){
  typename list<T>::const_iterator i;

  for(i= l.begin(); i!= l.end(); i++)
    cout << *i << " ";

  cout << "\n";
}

//Programa de prueba
int main(){
  int v1[]= {1,2,3,4};
  int v2[]= {5,6,7,8};
  list<int> l1(v1, v1 + 4), l2(v2, v2 + sizeof(v2 )/sizeof(int)); //Son formas equivalentes de construir una lista a partir de un vector

  cout << "Lista 1: ";
  show_list(l1);
  cout << "Lista 2: ";
  show_list(l2);

  cout << "\nIntercambiamos las listas\n"
  swap(l1, l2);

  cout << "Lista 1: ";
  show_list(l1);
  cout << "Lista 2: ";
  show_list(l2);
}
