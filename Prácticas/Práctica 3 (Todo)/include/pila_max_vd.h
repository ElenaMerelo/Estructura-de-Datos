/**
  * @file Pila_max.h
  * @brief Fichero cabecera del TDA Pila con
  * máximo creada a partir de un vector dinámico
  * @author Elena Merelo Molina y Antonio Gámiz Delgado
  * @date Noviembre de 2017
  */

#ifndef __PILA_MAX_VD_H__
#define __PILA_MAX_VD_H__

#include <cassert>
#include <vectordinamico.h>

/**
 *  @brief T.D.A. Pila
 *
 * En una pila (LIFO, Last In, First Out), tendremos acceso únicamente al elemento del @e Tope. El borrado o
 * consulta de un elemento será sobre el último elemento de la pila, y la
 * inserción de un nuevo elemento se hará por encima de éste, quedando el elemento
 * insertado como @e Tope de la pila.
 * El espacio requerido para el almacenamiento es O(n), donde n es el número de
 * elementos de la Pila.
 */
 struct elemento{
   int element;
   int maximo;
 };

class Pila_max{
  private:
    Vector_Dinamico <elemento> v;   //Vector dinámico que almacenará los elementos

  public:
    /**
     * @brief Constructor por defecto
     */
    Pila_max(): v(0){}

    /**
     * @brief Constructor de copia
     * @param otra Pila de la que se hará la copia.
     */
    Pila_max(const Pila_max &otra){
      v(otra.v);
    };

    /**
     * @brief Operador de asignación
     * @param otra Pila que se va a asignar.
     */
    Pila_max& operator=(const Pila_max  &otra){
      v= otra.v;
    };

    /**
     * @brief Comprueba si la pila está vacía
     */
    bool empty() const{ return v.size() == 0;};

    /**
     * @brief Devuelve el elemento del tope de la pila
     */
    elemento& top();

    /**
     * @brief Devuelve el elemento del tope de una pila constante
     */
    const elemento& top() const;

    /**
     * @brief Añade un elemento "encima" del tope de la pila
     * @param number Elemento que se va a añadir.
     */
    void push(int number);

    /**
     * @brief Quita el elemento del tope de la pila
     */
    void pop();

    /**
     * @brief Devuelve el número de elementos de la pila
     */
    int size() const{
      return v.size();
    }
};

#endif
