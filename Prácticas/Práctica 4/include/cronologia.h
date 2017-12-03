
/**
  * @file cronologia.h
  * @brief Fichero cabecera del TDA cronologia
  *
  * Una instancia @e c del tipo de datos abstracto @c cronologia es un objeto
  * con una instancia de un objeto map, formado por objetos de tipo fecha_historica.
  *
  * @author Elena Merelo Molina
  * @author Antonio Gámiz Delgado
  * @date 31 de Noviembre de 2017
  *
  */

#ifndef _CRONOLOGIA_
#define _CRONOLOGIA_

#include<iostream>
#include<string>
#include<map>
#include<fecha_historica.h>

using namespace std;


class cronologia{
  private:
    map<int, fecha_historica> data; //Mapa que representa un conjunto de objetos de tipo fecha_historica.
  public:
    /*--------------CONSTRUCTORES--------------*/
    /**
    * @brief Constructor vacío
    * @return Instancia de la clase
    */
    cronologia(){};

    /**
    * @brief Constructor de copia de la clase
    * @param d objeto de la clase que se quiere copiar
    * @return Crea el evento con los datos de d
    */
    cronologia(const map<int, fecha_historica> &d){ data = d; }

    /*--------------FUNCIONES--------------*/
    /**
    * @brief Operador de asignación de la clase
    * @param d objeto de la clase que se quiere copiar
    * @return Crea la cronología con los datos de d
    */
    cronologia& operator=(const map<int, fecha_historica> &d){ data = d; return *this; }

    /**
    * @brief Añade una fecha_historica
    * @param f Objeto del tipo fecha_historica
    */
    void addFechaHistorica(fecha_historica& f);

    /**
    * @brief Devuelve un objeto fecha_historica con año a, si existe
    * @param a año del objeto fecha_historica
    * @return fecha_historica vector de string con los eventos
    */
    fecha_historica& searchFechaHistorica(int a);

    /**
    * @brief Dadas dos cronologías une sus eventos sin que haya ninguno repetido
    * @param c1, c2 cronologías cuyos elementos vamos a unir
    * @param u cronologia resultante de la unión de c1 y c2
    */
    void unionCronologias(const cronologia &c, cronologia &u);

    /**
    * @brief Dadas dos cronologías interseca sus eventos sin que haya ninguno repetido
    * @param c1, c2 cronologías cuyos elementos vamos a intersectar
    * @param u cronologia resultante de la intersección de c1 y c2
    */
    void interseccionCronologias(const cronologia& c, cronologia &u);

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
    typedef typename map<int, fecha_historica>::iterator it;

    /**
     * @brief Iterador constante para recorrer el set<string> que contiene los eventos.
    */
    typedef typename map<int, fecha_historica>::const_iterator const_it;


    it begin (){ return data.begin(); }

    /**
     * @brief Inicio del conjunto de eventos (constante).
     */
    const_it begin () const{ return data.begin(); }

    /**
     * @brief Final del conjunto de eventos.
     */
    it end (){ return data.end(); }

    /**
     * @brief Final del conjunto de eventos (constante).
     */
    const_it end () const{ return data.end(); }

};

#endif
