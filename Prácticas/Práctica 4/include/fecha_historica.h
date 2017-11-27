/**
  * @file fecha_historica.h
  * @brief Fichero cabecera del TDA fecha_historica
  * @author Elena Merelo Molina
  * @author Antonio Gámiz Delgado
  * @date Noviembre de octubre de 2017
  *
  */

#ifndef _FECHA_HISTORICA_
#define _FECHA_HISTORICA_

#include <iostream>
#include <string>
#include <cassert>
#include <utility>
#include <set>

using namespace std;

/**
  *  @brief T.D.A. fecha_historica
  *
  * Una instancia @e c del tipo de datos abstracto @c Fecha_Historica es un objeto
  * con cuatro campos, tres enteros y un vector de string
  * Uno de los enteros es la fecha base del conjunto de eventos y los otros dos son la base del
  * vector dinamico
  * Un ejemplo de su uso:
  * @include pruebacronologia.cpp
  */

class fecha_historica {
 private:
   pair<int, set <string> > fecha;

 public:
/**
  * @brief Constructor de la clase
  * @param anio año del evento a construir
  * @param s vector de string con el evento o eventos de ese año
  * @param n número de eventos que contienen el vector s que se pasa como parámetro
  * @return Crea el evento con año a y n eventos asociados
  * @pre a debe ser mayor o igual que 0 y menor o igual que 9999, n debe ser un número positivo
  * igual al número de eventos contenidos en el vector de string s
  */
  fecha_historica(int anio, string *s, int n);


/**
  * @brief Constructor de copia de la clase
  * @param e objeto de la clase que se quiere copiar
  * @return Crea el evento con los datos de e
  */
  fecha_historica(const fecha_historica& e);


/**
  * @brief Operador de asignación de la clase
  * @param e objeto de la clase que se quiere copiar
  * @return Crea el evento con los datos de e
  */
  fecha_historica& operator=(const fecha_historica& e);


/**
  * @brief Destructor de la clase
  */
  ~fecha_historica();


/**
  * @brief Método de acceso al año de la Fecha_Historica
  * @return int con el valor del campo anio
  */
  int getYear ();


/**
  * @brief Método de establecimiento del año de la Fecha_Historica
  * @param a año de la Fecha_Historica con el que queremos inicializar la variable privada anio
  */
  void setYear(int a);


/**
  * @brief Método de acceso al número de eventos de la Fecha_Historica
  * @return int con el valor del campo numeventos
  */
  int getNumEvents();


/**
  * @brief Añade un evento
  * @param event string con evento a añadir
  */
  void addEvent(string& event);


/**
  * @brief Busca si un evento está repetido en la Fecha_Historica.
  * @param evento evento que queremos saber si aparece más de una vez o no
  * @return Devuelve true si está repetido, false si no lo está
  */
  bool estaRepetido(string evento);


/**
  * @brief Devuelve los eventos ocurridos en una fecha histórica
  * @return string* vector de string con los eventos
  */
  set<string> getEventos();


/**
  * @brief Acceso al elemento n de un set
  * @return Devuelve una referencia al elemento que se quiere consultar, si no existe el índice
  * al que se quiere acceder se aborta el programa
  * @param n posición de la que se quiere obtener el elemento
  */
  string getElement(int n);



/**
  * @brief Dadas dos fechas históricas une sus eventos sin que haya ninguno repetido
  * @param f1, f2 fechas histórias cuyos eventos vamos a unir
  * @param u fecha histórica resultante de la unión de f1 y f2
  */
  void unionEventos(const fecha_historica &f1, const fecha_historica &f2, fecha_historica &u );


 /**
   * @brief Dadas dos fechas históricas crea otra con los eventos que están en ambos
   * @param f  fecha história cuyos eventos vamos a intesectar con los de la fecha que invoca a la función
   * @param i fecha histórica resultante de la intersección
   */
   void interseccionEventos(fecha_historica f, fecha_historica &i);


 /**
   * @brief Busca un evento dentro de todos los de una fecha histórica.
   * @param event string con el evento a buscar
   * @return Devuelve true o false indicando si está o no repetido
   */
   bool buscarEventos(string s, fecha_historica &matches);


/**
  * @brief Salida de un Fecha_Historica a ostream
  * @param os stream de salida
  * @param e Fecha_Historica a escribir
  * @post Se muestra la Fecha_Historica en formato "año#evento1#evento2#...#eventoN"
  */
  friend ostream& operator<< (ostream& os, const fecha_historica& e);


/**
  * @brief Entrada de un Fecha_Historica desde istream
  * @param is stream de entrada
  * @param e Fecha_Historica que recibe el valor
  * @retval El Fecha_Historica leído en e
  * @pre La entrada tiene el formato "año#evento1#evento2#...#eventoN
  */
  friend istream& operator>> (istream& is, fecha_historica& e);
 
 
 /**
   * @brief Iterador para recorrer el set<string> que contiene los eventos.
   */
   typedef typename set<string>::iterator iterator;

 
/**
  * @brief Iterador constante para recorrer el set<string> que contiene los eventos.
  */        
  typedef typename set<string>::const_iterator const_iterator;

 
/**
  * @brief Inicio del conjunto de eventos.
  */
  iterator begin (){ return data.second.begin(); }
  
 
/**
  * @brief Inicio del conjunto de eventos (constante).
  */
  const_iterator begin () const{ return data.second.begin(); }
        
/**
  * @brief Final del conjunto de eventos.
  */
  iterator end (){ return data.second.end(); }

/**
  * @brief Final del conjunto de eventos (constante).
  */
  const_iterator end () const{ return data.second.end(); }

 
};

#endif
