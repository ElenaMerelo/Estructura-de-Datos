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

  //Elimina el último elemento de la pila doble
  void pop();

  //Método que elimina el elemento tope de una pila u otra según el índice pasado como argumento
  void pop(int indice_pila);

  //Método que añade un elemento al final de la pila doble, esto es, al principio de la pila 1
  void push(T element);

  //Método que inserta un elemento en una pila u otra según el entero pasado como parámetro
  void push(int indice_pila, T element);

  //Método para obtener el tamaño total de la pila doble
  int size();

  //Devuelve el tamaño de la pila según el índice que se de
  int size_pila(int indice_pila);

  T top();

  T& top(int indice_pila);

  //Métodos para comprobar si las pilas están vacías
  bool empty();

  bool empty(int indice_pila);


};
#endif
#include <ejer1.cpp>
