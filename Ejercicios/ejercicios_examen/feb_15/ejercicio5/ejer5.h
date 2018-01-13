#include <map>
#include <list>
#include <string>
#include <utility>
#include <iostream>
#include <cmath>

using namespace std;

#ifndef ejer5_h
#define ejer5_h

bool is_prime(int number);

class dictionary{
private:
  map<int, list<string> > data;

public:
  //Constructor vacío
  dictionary(){ }

  //Constructor de copia
  dictionary(const dictionary &d){
    data= d.data;
  }

  //Operador de asignación
  dictionary& operator=(const dictionary &d){
    data= d.data;
    return *this;
  }

  //Construye un dictionary a partir de una list<string>
  dictionary(list<string> info);

  //Inserta la list de string value con la clave key
  void insert(int key, list<string> value);

  //Muestra las claves y sus correspondientes valores
  void show_elements_normal();

  //Muestra las claves y sus correspondientes valores iterando sobre las claves primas
  void show_elements_my_it();

  class iterator{
  private:
    map<int, list<string> >::iterator i;
    list<string>::iterator j;
    
  public:
    iterator(){ }

    iterator(const iterator &other):i(other.i), j(other.j){}

    iterator(map<int, list<string> >::iterator other_i, list<string>::iterator other_j){
      i= other_i;
      j= other_j;
    }

    iterator& operator=(iterator other);

    iterator& operator=(const map<int, list<string> >::iterator &other);

    iterator& operator++();

    pair<int, list<string> > operator*();

    bool operator==(iterator other);

    bool operator!=(const map<int, list<string> >::iterator &other);

    //Devuelve la clave del mapa
    int first();

    //Valor correspondiente a una clave 
    list <string> second();

    list<string>::iterator begin();

    list<string>::iterator end();
  };

  //Iterador al comienzo del diccionario, esto es, a la primera clave y primer string de la lista
  iterator begin();

  //Iterador al final del diccionario, esto es, a la última clave y último string de la lista
  iterator end();

};
#include <ejer5.cpp>
#endif
