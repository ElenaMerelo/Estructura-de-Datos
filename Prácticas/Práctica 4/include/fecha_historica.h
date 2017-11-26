#ifndef _FECHA_HISTORICA_
#define _FECHA_HISTORICA_

#include <iostream>
#include <string>
#include <cassert>
#include<stdlib.h>
#include<set>

using namespace std;

/**
  *  @brief T.D.A. Fecha_Historica
  *
  * Una instancia @e c del tipo de datos abstracto @c Fecha_Historica es un objeto
  * con una instancia de un objeto pair, formado por un int y por una instancia de
  * un objeto set.
  *
  * Año
  * num_eventos
  * evento/s:
  * *)Fecha_Historica_1
  * ...
  * ...
  * *)Fecha_Historica_N
  *
  * @author Elena Merelo Molina
  * @author Antonio Gámiz Delgado
  * @date 31 de Noviembre de 2017
  */

class fecha_historica{
    private:
        pair<int, set<string> > data; //Par que representa el año de los eventos históricos, y un set de string para almacenar los eventos.
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
        fecha_historica(const pair<int, set<string> > &d){ data = d; }
        
        /*--------------FUNCIONES--------------*/
        
        /**
        * @brief Operador de asignación de la clase
        * @param e objeto de la clase que se quiere copiar
        * @return Crea el evento con los datos de e
        */
        fecha_historica& operator=(const pair<int, set<string> > &d){ data = d; return *this; }
        
        /**
        * @brief Método de acceso al año de la Fecha_Historica
        * @return int con el valor del campo int del pair<int, set<string> >.
        */
        int getAge() const { return data.first; }
        
        /**
        * @brief Método de establecimiento del año de la Fecha_Historica
        * @param a año de la Fecha_Historica
        */
        void setAge(int a){ data.first = a;}
        
        /**
        * @brief Devuelve los eventos ocurridos en una fecha histórica
        * @return set<string> con los eventos
        */
        set<string>& getEvents(){ return data.second; }
        
        /**
        * @brief Método de acceso al número de eventos de la Fecha_Historica
        * @return int con el valor del campo numeventos
        */
        int getNumEvents(){ return data.second.size(); }
        
        /**
        * @brief Añade un evento
        * @param event string con evento a añadir
        */
        void addEvent(string event);
        
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

};

#endif