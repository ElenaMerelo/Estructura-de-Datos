#include <iostream>
#include <vector>
#include <iterator>
#include <assert.h>

using namespace std;

#ifndef _EJER2_H__
#define _EJER2_H__

template <class T>
class matriz_bilineal_simetrica{
private:
  vector<T> columnas;
  vector<vector<T> > filas;

public:
  //Constructor vacío. Crea una matriz de 0 filas y 0 columnas
  matriz_bilineal_simetrica(){}

  //Constructor de copia. Crea una matriz a partir de otra pasada como argumento
  matriz_bilineal_simetrica(const matriz_bilineal_simetrica<T> &other){
    columnas= other.columnas; //Usamos el operador de asignación ya implementado en el container vector
    filas= other.filas;
  }

  //Constructor que crea una matriz bilineal simétrica a partir de un vector
  matriz_bilineal_simetrica(vector<T> v);

  //Operador de asignación. Iguala una matriz a otra
  matriz_bilineal_simetrica& operator=(const matriz_bilineal_simetrica<T> &other){
    columnas= other.columnas;
    filas= other.filas;
  }

  //Método para obtener el tamaño de la matriz. Hace uso del hecho de que el container vector tiene implementado size()
  int size(){
    return filas.size();
  }

  //Borra todos los elementos de la matriz
  void clear();

  //Operador de salida
  friend ostream& operator <<(ostream &os, const matriz_bilineal_simetrica<T> &m);

  //Operador de entrada
  //friend istream& operator >>(istream &is, matriz_bilineal_simetrica<T> &m);


  /*----------------------------ITERADORES-------------------------------*/

  //Iterador para recorrer el vector<vector<T> > que contiene los eventos
  typedef typename vector<T>::iterator my_iterator;


  //Iterador constante para recorrer el vector<vector<T> > que contiene los eventos
  typedef typename vector<T>::const_iterator my_const_iterator;

  //Iterador que recorre la matriz en orden inverso
  typedef typename vector<T>::reverse_iterator my_reverse_iterator;

  //Iterador que recorre la matriz en orden inverso
  typedef typename vector<T>::const_reverse_iterator my_const_reverse_iterator;

  /*ITERATORS*/
  //Inicio de la matriz, esto es, la columna 0 y fila 0
  my_iterator begin(){
    typename vector<vector<T> >::iterator i=filas.begin();
    return i->begin();
  }

  //Iterador al final de la matriz, la columna size y fila size
  my_iterator end(){
    typename vector<vector<T> >::iterator i=filas.end();
    return i->end();
  }

  //Método para desplazar n posiciones my_iterator por la diagonal principal de la matriz
  void advance(my_iterator &it, int n);

  //Método para desplazar my_iterator n posiciones por la diagonal secundaria de la matriz
  //my_iterator& radvance(int n);

/*
  /*REVERSE_ITERATORS
  //Recorre la diagonal secundaria, devuelve el último elemento de la primera fila
  my_reverse_iterator rbegin ();

  //Iterador al final de la matriz, la columna size y fila size
  my_reverse_iterator rend ();

  //Sobrecargamos el operador para movernos con my_reverse_iterator por los datos significativos de la matriz
  my_reverse_iterator& operator++();

  /*------------------------ITERADORES CONSTANTES--------------------------
  /*CONST_ITERATORS
  //Iterador constante al inicio de la matriz
  my_const_iterator begin () const;

  //Iterador constante al final de la matriz
  my_const_iterator end () const;

  //Sobrecargamos el operador para movernos con my_const_iterator por los datos significativos de la matriz
  my_const_iterator& operator++();

  /*CONST_REVERSE_ITERATORS
  //Iterador constante al fin de la matriz
  my_const_reverse_iterator rbegin() const;

  //Iterador constante al inicio de la matriz
  my_const_reverse_iterator rend() const;

  //Sobrecargamos el operador para movernos con my_const_reverse_iterator por los datos significativos de la matriz
  my_const_reverse_iterator& operator++();
*/
};

#endif
#include <ejer2.cpp>
