
/**
  * @file cronologia.h
  * @brief Fichero cabecera del TDA cronologia
  *
  */

#ifndef _CRONOLOGIA_
#define _CRONOLOGIA_

#include<iostream>
#include<string>
#include<map>
#include<fecha_historica.h>

using namespace std;

/**
  *  @brief T.D.A. cronologia
  *
  * Una instancia @e c del tipo de datos abstracto @c cronologia es un objeto
  * con una instancia de un objeto map, formado por objetos de tipo fecha_historica.
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

class cronologia{
    private:
        map<int, fecha_historica, less<int> > data; //Mapa que representa un conjunto de objetos de tipo fecha_historica.
    public:

        /*--------------CONSTRUCTORES--------------*/
        
        /**
        * @brief Constructor vacío.
        * @return Instancia de la clase.
        */
        cronologia(){};
        
        /**
        * @brief Constructor de copia de la clase
        * @param e objeto de la clase que se quiere copiar
        * @return Crea el evento con los datos de e
        */
        cronologia(const map<int, fecha_historica, less<int> > &d){ data = d; }

        /*--------------FUNCIONES--------------*/
        
        /**
        * @brief Operador de asignación de la clase
        * @param e objeto de la clase que se quiere copiar
        * @return Crea la cronología con los datos de e
        */
        cronologia& operator=(const map<int, fecha_historica, less<int> > &d){ data = d; return *this; }
        
        /**
        * @brief Añade una fecha_historica.
        * @param f Objeto del tipo fecha_historica
        */
        void addEvent(fecha_historica& f);

        /**
        * @brief Devuelve los eventos ocurridos en un año
        * @param a año del que se quieren saber los eventos
        * @return string* vector de string con los eventos
        */
        fecha_historica getEventos(int a);

        /*--------------OPERADORES E/S--------------*/

        /**
         * @brief Salida de una Cronologia a ostream
        * @param os stream de salida
        * @param c Cronologia a escribir
        * @post Se obtienen varios años seguidos de la cadena de Eventos_Historico con el formato
        * de Fecha_Historica
        */
        friend ostream& operator<< (ostream& os, const cronologia& c);

        /**
         * @brief Entrada de una Cronologia desde istream
        * @param is stream de entrada
        * @param c Cronologia que recibe el valor
        * @retval La Cronologia leída en c
        * @pre La entrada tiene el formato de Fecha_Historica neventos numero de veces
        */

        friend istream& operator>> (istream& is, cronologia& c);

        /*--------------ITERADORES--------------*/
        
        /**
         * @brief Iterador para recorrer el set<string> que contiene los eventos.
        */
        typedef typename map<int, fecha_historica, less<int> >::iterator iterator;

        /**
         * @brief Iterador constante para recorrer el set<string> que contiene los eventos.
        */        
        typedef typename map<int, fecha_historica, less<int> >::const_iterator const_iterator;

};

#endif