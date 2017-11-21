/**
  * @file pila.h
  * @brief Fichero cabecera del TDA Pila
  *
  * Gestiona una secuencia de elementos con facilidades para la inserción y
  * borrado de elementos en un extremo.
  *
  * @author Antonio Gámiz Delgado
  */
#ifndef __STACK_H_
#define __STACK_H__

#include<cassert>
#include<list>

template<class T>
class stack{
    private:
        typename std::list<T> data;
    public:
        // ---------------  Constructores ----------------
        /**
         * @brief Constructor por defecto
         */
        stack(){};
        /**
         * @brief Constructor de copias
         * @param otra La pila de la que se har� la copia.
         */
        stack(const stack<T>& other) { data=other.data; }
        // --------------- Otras funciones ---------------
        /**
         * @brief Operador de asignaci�n
         * @param otra La pila que se va a asignar.
         */
        stack& operator=(const stack<T>& other) { data=other.data; }
        /**
         * @brief Comprueba si la pila está vacía.
         */
        bool empty() const { return data.empty(); }
        /**
        * @brief Devuelve el elemento del tope de la pila
        */
        T& top ();
        /**
        * @brief Devuelve el elemento del tope de la pila constante.
        */
        const T& top() const;
        /**
        * @brief A�ade un elemento "encima" del tope de la pila
        * @param elem Elemento que se va a a�adir.
        */
        void push(const T& elem);
        /**
         * @brief Quita el elemento del tope de la pila.
         */
        void pop();
        /**
         * @brief Devuelve el número de elementos de la pila.
         */
        int size() { return data.size(); }
};

#include<stack.cpp>
#endif