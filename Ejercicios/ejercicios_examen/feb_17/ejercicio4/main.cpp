/*
Enunciado: Sea A un APOmin (APO con el orden parcial <=). Diseñar un procedimiento
borramax (A) que elimine el mayor elemento almacenado en A de forma que la
estructura final siga siendo un APOmin.
Author: Elena Merelo Molina
*/
#include <ejer4.h>

int main(){
  //Probamos el constructor de copia y el que se le pasa el tamaño del árbol
  APOmin<int> a2, a1(5);

  cout << "\nAPOmin 1: ";
  a1.show_elements();
  cout <<"\nSu tamaño es: " << a1.size();


  cout << "\nAPOmin 2: ";
  a2.show_elements();
  cout <<"\nNúmero de niveles: " << a2.num_levels();

  //Prueba del operador de asignación y el constructor de copia
  APOmin<int> a3= a1, a4(a2);
  cout << "\nAPOmin 3: ";
  a3.show_elements();
  cout << "\nAPOmin 4: ";
  a4.show_elements();

  //cout << "\nEl elemento máximo del APOmin 2 es: " << a2.maximo();

  a2.insert(45);
  a2.insert(3);
  a2.insert(99);
  a2.insert(8);
  a2.insert(4);

  cout <<"\nAPOmin 2 después de insertar elementos: ";
  a2.show_elements();
  cout << "\nEl elemento máximo del APOmin 2 es: " << a2.maximo();


}
