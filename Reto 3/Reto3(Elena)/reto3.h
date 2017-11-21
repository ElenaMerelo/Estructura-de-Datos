/**
  * @file reto3.h
  * @brief Fichero cabecera del TDA stack, creado a partir de la clase list de la STL
  * @author Elena Merelo Molina
  **/
#ifndef __RETO3_H
#define __RETO3_H
#include <list>

using namespace std;

template <class T>
class stack{
private:
    list<T> data;

public:
  /**
   * @brief Constructor vacío. Crea una pila con 0 elementos.
   * */
  stack(){};

  /**
   * @brief Constructor de copia. Crea una pila a partir de otra pila pasada como argumento
   * @param other pila que se quiere copiar
   * */
   stack(const stack<T> &other){
     data= other.data;
   };

   /**
    * @brief Operador de asignación
    * @param other pila que se quiere copiar
    * */
    stack& operator=(const stack<T> &other){
      data= other.data;
    }
    /**
     * @brief Chequea si la pila está vacía
     * */
     bool empty() const{
       return data.empty();
     };

    /**
     * @brief Tamaño de la pila.
     * */
     int size() const{
       return data.size();
     };

     /**
      * @brief Devuelve una referencia al elemento tope de la pila.
      * */
      T& top();

      /**
       * @brief Devuelve una referencia constante al elemento tope de la pila.
       * */
      const T& top() const;

      /**
       * @brief Inserta un elemento al final de la pila, por encima de su elemento tope.
       * El contenido de este nuevo elemento se inicializa con una copia de value
       * @param value valor con el que se quiere inicializar el nuevo elemento.
       * */
       void push(const T& value);

       /**
       * @brief Borra el elemento en el tope de la pila
       * */
       void pop();

       /**
       * @brief Intercambia el contenido de *this por los de x.
       * Solo funciona a partir de c++ 11.
       * @param x pila con la que intercambia el contenido
       * */
       //void swap(stack<T>& x);

};

#include <reto3.cpp>

#endif
