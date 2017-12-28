#include <map>
#include <utility>
#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

#ifndef EJER1_H
#define EJER1_H

typedef pair<string, string> info;
typedef map<string, info> people;

class agenda{
private:
  //Map que contiene el nombre de la persona, su teléfono y dirección respectivamente
  people p;

public:
  agenda(){}

  agenda(const agenda &a){ p = a.p; }

  agenda& operator=(const agenda &a){ p= a.p; }

  //Dado el nombre de una persona devuelve su teléfono y dirección
  info& find_name(string name);

  //Devuelve el nombre de la persona con teléfono num
  string find_telephone(string num);

  //Inserta una persona en la agenda
  void insert(pair<string, info> person);

};
#endif

#include <ejer1.cpp>
