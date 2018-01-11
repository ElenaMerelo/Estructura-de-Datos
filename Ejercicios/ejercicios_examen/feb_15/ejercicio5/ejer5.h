#include <map>
#include <list>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

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
  map<int, list<string> >& operator=(const dictionary &d){
    data= d.data;
    return *this;
  }

  bool is_prime(int number);

  //Construye un dictionary a partir de una list<string>
  dictionary(const list<string> info);

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

    iterator begin(){ return data.begin(); }

    iterator end(){ return data.end(); }
  };


};
