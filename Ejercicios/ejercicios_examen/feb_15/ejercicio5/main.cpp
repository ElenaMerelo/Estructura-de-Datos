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
  list<string> l1, l2, l3;
  l1.push_back("patata");
  l1.push_back("luriluri");

  l2.push_back("dvddafjksd");
  l2.push_back("hola");
  l2.push_back("mantecado");

  l3.push_back("otra");
  l3.push_back("lista");
  l3.push_back("no sé qué más poner");

  //Probamos todos los constructores y el operador de asignación
  dictionary d2(l1), d3(d2);
  dictionary d1, d4= d1;

  d1.insert(2, l2);
  d1.insert(6, l3);
  dictionary::iterator it;
  list<string>::iterator j;

  cout << "\nDiccionario 1 usando mi iterador: \n";
  for(it= d1.begin(); it != d1.end(); it++){
    cout << it->first << " ";
    for(j= it->second.begin(); j != it->second.end(); j++)
      cout << *j;
  }

  cout << "\nDiccionario 1 iterando normal: \n";
  d1.show_elements();

  /*cout << "\nDiccionario 2: ";
  d2.show_elements();

  cout << "\nDiccionario 3: ";
  d3.show_elements();

  cout << "\nDiccionario 4: ";
  d4.show_elements();*/
}
