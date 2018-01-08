/*
Enunciado: Sea A un APOmin (APO con el orden parcial <=). Diseñar un procedimiento
borramax (A) que elimine el mayor elemento almacenado en A de forma que la
estructura final siga siendo un APOmin.
Author: Elena Merelo Molina
*/
#include <ejer4.h>

int main(){
  //Probamos el constructor a partir de un tamaño
  APOmin<int> a1(5);

  cout << "\nAPOmin 1: ";
  a1.show_elements();
  cout <<"\nSu tamaño es: " << a1.size();

  a1.insert(23);

  //Prueba del constructor por defecto, constructor de copia y operador de asignación
  APOmin<int> a3, a4(a1), a5= a1;
  cout << "\nAPOmin 3: ";
  a3.show_elements();
  cout << "\nAPOmin 4: ";
  a4.show_elements();

  cout << "\nAPOmin 5: ";
  a5.show_elements();

  //Creamos ahora un árbol parcialmente ordenado a partir de un vector
  int v[]= {45,3,99,4,8,0,100};
  vector<int> data(v, v+7);
  APOmin<int> a2(data);

  a2.insert(1);

  cout <<"\nAPOmin 2 después de insertar los elementos del vector: ";
  a2.show_elements();
  //Contamos los niveles tomando el de la raíz como 0
  cout << "\nNúmero de niveles: " << a2.num_levels();
  cout << "\nEl elemento máximo del APOmin 2 es: " << a2.maximo();
  cout << "\nEl elemento máximo está en la posición: " << a2.position_max();
  cout << "\nDespués de eliminar el máximo: ";
  a2.pop_max();
  a2.show_elements();
  cout << "\nEl máximo de APOmin 2 es ahora: " << a2.maximo();


}
