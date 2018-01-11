/*
Enunciado: Implementar un iterador que itere sobre las claves que sean números primos
en una clase Diccionario definida como:
class Diccionario{
private:
map<int, list<string> > datos;
.............
.............
}
Han de implementarse (aparte de las de la clase iterador) las funciones begin() y end().
Se supone implementada una función bool primo (int x) que devuelve true si el entero x
es primo.
Author: Elena Merelo Molina
*/
#include <ejer5.h>

int main(){
  list<string> my_list;
  my_list.push_back("patata");
  my_list.push_back("luriluri");

  //Probamos todos los constructores y el operador de asignación
  dictionary d2(my_list), d3(d2);
  dictionary d1, d4= d1;

  cout << "\nDiccionario 1: ";
  d1.show_elements();

  cout << "\nDiccionario 2: ";
  d2.show_elements();

  cout << "\nDiccionario 3: ";
  d3.show_elements();

  cout << "\nDiccionario 4: ";
  d4.show_elements();


}
