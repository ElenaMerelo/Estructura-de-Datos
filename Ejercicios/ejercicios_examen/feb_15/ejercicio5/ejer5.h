#include <map>
#include <list>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

class dictionary{
private:
  map<int, list<string> > data;
  //friend class iterator;

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

  bool is_prime(int number);

  //Construye un dictionary a partir de una list<string>
  dictionary(const list<string> &info);

  //Inserta el valor value con la clave key
  void insert(int key, string value);

  //Muestra las claves y sus correspondientes valores
  void show_elements();

  class iterator{
  private:
    typedef typename map<int, list<string> >::iterator my_iterator;
    friend class dictionary;

  public:
    iterator(){ }

    iterator(const iterator &i);

    iterator& operator=(const iterator &i);

    iterator& operator++();

    map<int, list<string> >& operator*();

    iterator begin();

    iterator end();

    bool operator==(const iterator &other);

    bool operator!=(const iterator &other);
  };
};
#include <ejer5.cpp>
