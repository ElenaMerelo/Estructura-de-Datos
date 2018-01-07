/*
Enunciado: Sea A un APOmin (APO con el orden parcial <=). Diseñar un procedimiento
borramax (A) que elimine el mayor elemento almacenado en A de forma que la
estructura final siga siendo un APOmin.
Author: Elena Merelo Molina
*/
#include <ejer4.h>

int main(){
  APOmin<int> a1, a2(4);

  cout << "\nAPOmin 1: ";
  a1.show_elements();
  cout <<"\nSu tamaño es: " << a1.size();


  cout << "\nAPOmin 2: ";
  a2.show_elements();
  cout <<"\nNúmero de niveles: " << a2.num_levels();

  a2.insert(3);
  a2.insert(8);
  a2.insert(4);
  a2.insert(45);

  cout << "\nEl elemento máximo de APOmin 2 es: " << a2.maximo();

}
