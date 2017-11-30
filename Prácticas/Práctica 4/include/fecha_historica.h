/**
  * @file fecha_historica.h
  * @brief Fichero cabecera del TDA fecha_historica
  *
  * Una instancia @e c del tipo de datos abstracto @c fecha_historica es un objeto
  * con una instancia de un objeto pair, formado por un int y por una instancia de
  * un objeto set.
  * @author Elena Merelo Molina
  * @author Antonio Gámiz Delgado
  * @date 31 de Noviembre de 2017
  *
  */

#ifndef _FECHA_HISTORICA_
#define _FECHA_HISTORICA_

#include <iostream>
#include <string>
#include <cassert>
#include<stdlib.h>
#include<set>

using namespace std;

class fecha_historica{
    private:
      pair<int, set<string> > events; //Par que representa el año de los eventos históricos, y un set de string para almacenar los eventos.
    public:
      /*--------------CONSTRUCTORES--------------*/
      /**
      * @brief Constructor vacío.
      * @return Instancia de la clase.
      */
      fecha_historica(){};


      /**
      * @brief Constructor de copia de la clase
      * @param e objeto de la clase que se quiere copiar
      * @return Crea el evento con los datos de e
      */
      fecha_historica(const pair<int, set<string> > &e){ events = e; }


      /*--------------FUNCIONES--------------*/
      /**
      * @brief Operador de asignación de la clase
      * @param e objeto de la clase que se quiere copiar
      * @return Crea el evento con los datos de e
      */
      fecha_historica& operator=(const pair<int, set<string> > &e){ events = e; return *this; }


      /**
      * @brief Método de acceso al año de la Fecha_Historica
      * @return int con el valor del campo int del pair<int, set<string> >.
      */
      inline int getYear() const { return events.first; }


      /**
      * @brief Método de establecimiento del año de la Fecha_Historica
      * @param a año de la Fecha_Historica
      */
      void setYear(int a){ events.first = a;}


      /**
      * @brief Devuelve los eventos ocurridos en una fecha histórica
      * @return set<string> con los eventos
      */
      inline set<string>& getEvents(){ return events.second; }


      /**
      * @brief Método de acceso al número de eventos de la Fecha_Historica
      * @return int con el valor del campo numeventos
      */
      inline int getNumEvents(){ return events.second.size(); }


      /**
      * @brief Añade un evento
      * @param event string con evento a añadir
      */
      void addEvent(string event);


      /**
      * @brief Comprueba si un evento está repetido en la Fecha_Historica.
      * @param evento evento que queremos saber si aparece más de una vez o no
      * @return Devuelve true si está repetido, false si no lo está
      */
      bool estaRepetido(string evento);


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
      void unionEventos(const fecha_historica &f, fecha_historica &u);


      /**
        * @brief Dadas dos fechas históricas crea otra con los eventos que están en ambos
        * @param f  fecha história cuyos eventos vamos a intesectar con los de la fecha que invoca a la función
        * @param i fecha histórica resultante de la intersección
        */
        void interseccionEventos(fecha_historica f, fecha_historica &i);


      /*--------------OPERADORES E/S--------------*/

      /**
      * @brief Salida de un Fecha_Historica a ostream
      * @param os stream de salida
      * @param e Fecha_Historica a escribir
      * @post Se muestra la Fecha_Historica en formato "año#evento1#evento2#...#eventoN"
      */
      friend ostream& operator<<( ostream& os, const fecha_historica& f);

      /**
      * @brief Entrada de un Fecha_Historica desde istream
      * @param is stream de entrada
      * @param e Fecha_Historica que recibe el valor
      * @retval El Fecha_Historica leído en e
      * @pre La entrada tiene el formato "año#evento1#evento2#...#eventoN
      */
      friend istream& operator>>( istream& is, fecha_historica& f);

      /*--------------ITERADORES--------------*/

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
      iterator begin (){ return events.second.begin(); }

      /**
       * @brief Inicio del conjunto de eventos (constante).
       */
      const_iterator begin () const{ return events.second.begin(); }

      /**
       * @brief Final del conjunto de eventos.
       */
      iterator end (){ return events.second.end(); }

      /**
       * @brief Final del conjunto de eventos (constante).
       */
      const_iterator end () const{ return events.second.end(); }

};

#endif
