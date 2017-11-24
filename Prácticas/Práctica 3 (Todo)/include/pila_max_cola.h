/**
  * @file pila.h
  * @brief Fichero cabecera del TDA Pila_Max
  * @author Elena Merelo Molina y Antonio Gámiz Delgado
  * @date Noviembre de 2017

  */

#ifndef __Pila_H__
#define __Pila_H__

#include <cassert>
#include <cola.h>
#include <iostream>

/**
 *  @brief T.D.A. Pila_Max
 *
 *
 * Una instancia @e v del tipo de datos abstracto Pila sobre el tipo @c T es 
 * una lista de elementos del mismo con un funcionamiento @e LIFO (Last In, 
 * First Out). En una pila, las operaciones de inserción y borrado de elementos
 * tienen lugar en uno de los extremos denominado @e Tope. Una pila de longitud
 * @e n la denotamos

 * - [a1,a2,a3,..,an>

 * donde @e ai es el elemento de la posición i-ésima.

 * En esta pila, tendremos acceso únicamente al elemento del @e Tope, es decir, 
 * a @e an. El borrado o consulta de un elemento será sobre  @e an, y la
 * inserción de un nuevo elemento se hará sobre éste. Quedando el elemento
 * insertado como @e Tope de la pila.

 * Si @e n=0 diremos que la pila está vacía.

 * El espacio requerido para el almacenamiento es O(n). Donde n es el número de
 * elementos de la Pila.
 */

struct elemento{
    int element;    ///< Elemento.
    int maximo; ///< Máximo asociado a @e ele
};

class Pila_max{
    private:
        Cola<elemento> queue; ///< Cola que almacenará los elementos.
    public:
        // ---------------  Constructores ----------------
        /**
         * @brief Constructor por defecto
         */
        Pila_max(){};
 
        /**
         * @brief Constructor de copias
         * @param otra La pila de la que se har� la copia.
         */
        Pila_max(const Pila_max & other) : queue(other.queue){};

        // --------------- Otras funciones ---------------
        /**
         * @brief Operador de asignación
         * @param otra La pila que se va a asignar.
         */
        Pila_max& operator= (const Pila_max& other){queue = other.queue;}
 
        /**
         * @brief Comprueba si la pila está vacía
         */
        bool empty() const{ return queue.vacia(); }
 
        /**
         * @brief Devuelve el elemento del tope de la pila
         */
        elemento top ();
 
        /**
         * @brief Devuelve el elemento del tope de una pila constante
         */
        const elemento top () const;
 
        /**
         * @brief Añade un elemento "encima" del tope de la pila
         * @param elem Elemento que se va a añadir.
         */
        void push(int num);
 
        /**
         * @brief Quita el elemento del tope de la pila
         */
        void pop();
        /**
         * @brief Devuelve el número de elementos de la pila
         */
        int size() const{ return queue.num_elementos(); }
};

#endif
