#include <stack>
#include <iostream>

using namespace std;

#ifndef EJER1_H
#define EJER1_H

template <class T>
class pila_doble{
private:
  stack<T> pila0, pila1;
public:
  //Constructor vacío
  pila_doble(){}

  //Constructor de una pila doble a con el elemento element size veces
  pila_doble(int size, T element);

  //Constructor de copia
  pila_doble(pila_doble<T> &other);

  //Operador de asignación
  pila_doble& operator=(pila_doble<T> &other);

  void show_elements();

  //Método que elimina el elemento tope de una pila u otra según el índice pasado como argumento
  void pop(int indice_pila);

  //Método que inserta un elemento en una pila u otra según el entero pasado como parámetro
  void push(int indice_pila, T element);

  //Método que añade un elemento al final de la pila doble, esto es, al principio de la pila 1
  void push(T element);

};
#endif
#include <ejer1.cpp>
