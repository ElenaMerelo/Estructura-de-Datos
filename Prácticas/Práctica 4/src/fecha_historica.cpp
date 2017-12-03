#include<iostream>
#include<fecha_historica.h>
#include<cassert>
#include<string>
#include<sstream>

using namespace std;

//Dado un vector de strings s, un año a y el tamaño n de s crea una fecha con dichos datos
fecha_historica::fecha_historica(int a, string *s, int n){
  for(int i= 0; i< n; i++)
    events.second.insert(s[i]);
}

//Añade un evento a set<string>
void fecha_historica::addEvent(string event){
  events.second.insert(event);
}

//Dado un evento busca si está en los de la fecha histórica
  bool fecha_historica::estaRepetido(string evento){
    bool repetido=false;
    fecha_historica::const_iterator i;
    for(i= events.second.begin(); i!= events.second.end()  && !repetido; i++){
      if(evento.compare(*i) == 0)
        repetido=true;
    }
    return repetido;
  }

//Método de acceso al evento n
  string fecha_historica::getElement(int n){
    assert(n>= 0 && n< events.second.size());
    fecha_historica::const_iterator i= events.second.begin();  //Me posiciono en el primer elemento del conjunto
    advance(i, n); //Avanzo, muevo el iterador para posicionarme en la posición deseada
    return *i; //Devuelvo el elemento al que apunta el iterador, el que está en la posición n
  }

//Dadas dos fechas históricas crea otra con la unión ordenada y sin eventos repetidos de ambas
  void fecha_historica::unionEventos(const fecha_historica &f, fecha_historica &u ){
    assert(events.first == f.getYear());
    fecha_historica::const_iterator i;
    u.setYear(f.getYear());
    for(i= f.events.second.begin(); i!= f.events.second.end(); i++){
      if(! u.estaRepetido(*i))
        u.addEvent(*i);
    }

    for(i= events.second.begin(); i!= events.second.end(); i++){
      if(! u.estaRepetido(*i))
        u.addEvent(*i);
    }
  }

  //Dadas dos fechas históricas crea una con los eventos que ambas tienen en común
  void fecha_historica::interseccionEventos(fecha_historica f, fecha_historica &i){
    fecha_historica::const_iterator j;
    if(events.second.size() < f.events.second.size()){
      for(j= events.second.begin(); j!= events.second.end(); j++){
        if(f.estaRepetido(*j))
          i.addEvent(*j);
      }
    }
    else{
      for(j= f.events.second.begin(); j!= f.events.second.end(); j++){
        if(estaRepetido(*j))
          i.addEvent(*j);
      }
    }
  }

//Buscador de eventos
  bool fecha_historica::searchEvent(string s, fecha_historica &matches){
    bool encontrado= false;
    fecha_historica::const_iterator i;
    for (i= events.second.begin(); i!= events.second.end(); i++){
      if((*i).find(s) != -1 ){
        matches.addEvent(*i);
        encontrado = true;
      }
    }
    if (encontrado)
      matches.events.first=events.first;

    return encontrado;
  }

//Operador de salida
ostream& operator<<( ostream& os, const fecha_historica& f){
  os << f.getYear();
  fecha_historica::const_iterator i;
  for(i= f.events.second.begin(); i!= f.events.second.end(); ++i)
    os << '#' << (*i);
  return os;
}

//Operador de entrada
istream& operator>>( istream& is, fecha_historica& f){
  f.clear();
  string aux;
  getline(is, aux, '#');
  f.events.first = atoi(aux.c_str());

  getline(is,aux);
  stringstream ss(aux);

  while(!ss.eof()){
    getline(ss, aux, '#');
    f.addEvent(aux);
  }

  return is;
}
