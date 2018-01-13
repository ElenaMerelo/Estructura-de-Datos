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

  class iterator{
  private:
    map<int, list<string> >::iterator my_iterator;
    friend class dictionary;

  public:
    iterator(){ }

    //void initialize();

    iterator(const iterator &i);

    iterator& operator=(const iterator &i);

    iterator& operator++();

    pair<int, list<string> > operator*();

    iterator begin(){ return data.begin(); }

    iterator end(){ return data.end(); }

    bool operator==(const iterator &other);

    bool operator!=(const iterator &other);
  };
};
#include <ejer5.cpp>
#endif
