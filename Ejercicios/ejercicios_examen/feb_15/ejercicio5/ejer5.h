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
  void show_elements();

  friend class iterator{
  private:
    map<int, list<string> >::iterator i;
    dictionary& parent;

  public:
    iterator(dictionary& d, map<int, list<string> >::iterator other): parent(d), i(other){}

    iterator(dictionary &other):parent(other), i(map<int, list<string> >::iterator it= other.data.begin()){}

    iterator(dictionary &other, bool): parent(other), i(map<int, list<string> >::iterator it= other.data.end()){}

    iterator(){ }
    iterator& operator=(iterator &other);

    iterator& operator++();

    pair<int, list<string> > operator*();

    bool operator==(iterator &other);

    bool operator!=(iterator &other);
  };

  iterator begin(){ return iterator(*this); }

  iterator end(){ return iterator(*this, true); }
};
#include <ejer5.cpp>
#endif
