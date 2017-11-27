#include <iostream>
#include <sstream>
#include <string>
#include "fecha_historica.h"

using namespace std;

//Constructor con parametros año, cadena de eventos y número de eventos a añadir
  fecha_historica::fecha_historica(int anio, string *s, int n){
     assert(a >= 0 && a<= 9999);
     fecha(a, (s, s+n));
  }

//Constructor de copia
   fecha_historica::fecha_historica(const fecha_historica &e){
    fecha(e.fecha);
   }

//Operador de asignación
   fecha_historica& fecha_historica::operator=(const fecha_historica &e){
      if(this != &e)
        fecha= e.fecha;

       return *this;
   }

//Destructor
   fecha_historica::~fecha_historica(){
    fecha.first= 0;
    fecha.second.clear();
   }

//Método de acceso a año
   int fecha_historica::getAnio(){
    return fecha.first;
   }

//Inicializamos anio al valor pasado como parámetro
   void fecha_historica::setAnio(int anio){
    assert(a>=0 && a<= 9999);
     fecha.first= anio;
   }

//Método de acceso al número de eventos acaecidos en un año
  int fecha_historica::getNumEventos(){
    return fecha.second.size();
  }

//Añade un evento
  void fecha_historica::addEvent(string &event){
     fecha.second.insert(event);
  }

//Dado un evento busca si está en los de la fecha histórica
  bool fecha_historica::estaRepetido(string evento){
    bool repetido=false;
    for(int i= 0; i< fecha.second.size()  && !repetido; i++){
      if(evento.compare(getElement(i)) == 0)
        repetido=true;
    }
    return repetido;
  }

//Método de acceso a los eventos ocurridos en la Fecha_Historica
  set<string> fecha_historica::getEventos(){
    return fecha.second;
  }

//Método de acceso al evento n
  string getElement(int n){
     assert(n>= 0 && n< fecha.second.size());
     typename set<string>::iterator it= fecha.second.begin();  //Me posiciono en el primer elemento del conjunto
     advance(it, n); //Avanzo, muevo el iterador para posicionarme en la posición deseada
     return *it; //Devuelvo el elemento al que apunta el iterador, el que está en la posición n
   }

//Dadas dos fechas históricas crea otra con la unión ordenada y sin eventos repetidos de ambas
  void fecha_historica::unionEventos(const fecha_historica &f1, const fecha_historica &f2, fecha_historica &u ){
    for(int i= 0; i< f1.fecha.second.size(); i++){
      if(! u.estaRepetido(f1.getElement(i)))
        u.addEvent(f1.getElement(i));
    }

    for(int i= 0; i< f2.fecha.second.size(); i++){
      if(! u.estaRepetido(f2.getElement(i)))
        u.addEvent(f2.getElement(i));
    }
  }

//Dadas dos fechas históricas crea una con los eventos que ambas tienen en común
void fecha_historica::interseccionEventos(fecha_historica f, fecha_historica &i){
    if(fecha.second.size() < f.fecha.second.size()){
      for(int j= 0; j< fecha.second.size(); j++){
        if(f.estaRepetido(getElement(j)) && ! i.estaRepetido(getElement(j)))
          i.addEvent(getElement(j));
      }
    }
    else{
      for(int j= 0; j< f.fecha.second.size(); j++){
        if(estaRepetido(f.getElement(j)) && ! i.estaRepetido(f.getElement(j)))
          i.addEvent(f.getElement(j));
      }
    }
  }

//Buscador de eventos
  bool fecha_historica::buscarEventos(string s, fecha_historica &matches){
     bool encontrado= false;
     for (int i=0; i < fecha.second.size(); ++i){
        if(getElement(i).find(s) != -1 ){
           matches.addEvent(getElement(i));
           encontrado = true;
        }
     }
     if (encontrado){
        matches.fecha.first=anio;
      }
    return encontrado;
   }

//Operador <<
  friend ostream& operator<< (ostream& os, const fecha_historica& e){
    os << e.fecha.first;
    for(int i=0; i<e.fecha.second.size(); i++)
        os << '#' << e.getElement(i);
    os << endl;
    return os;
  }

//Operador >>
  friend istream& operator>>( istream& is, fecha_historica& f){
  string aux;
  getline(is, aux, '#');
  f.fecha.first = atoi(aux.c_str());

  while(!is.eof()){
      getline(is, aux, '#');
      f.addEvent(aux);
  }

  return is;
}
