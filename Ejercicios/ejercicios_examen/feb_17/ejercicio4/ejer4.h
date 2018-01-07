#ifndef ejer4_h
#define ejer4_h
#include <vector>
#include <cmath>  //pow, modf, log2
#include <iterator>   //advance
#include <iostream> //cout

using namespace std;

template <class T>
class APOmin{
private:
  vector<T> data;
public:
  //Constructor vacío
  APOmin(){ }

  //Construye un APOmin del tamaño especificado
  APOmin(int size);

  //Constructor de copia
  APOmin(const APOmin<T> &a);

  //Operador de asignación
  APOmin<T>& operator=(const APOmin<T> &p);

  //Destructor
  ~APOmin(){ }

  //Obtiene el número de niveles del árbol
  double num_levels();

  //Método que devuelve el máximo elemento de un APOmin
  T& maximo();

  //Devuelve el tamaño del árbol, su número de nodos
  int size();

  //Vacía el árbol
  void clear();

  //Intercambia dos elementos dados
  void swap(T &a, T &b);

  //Inserta un nuevo elemento
  void insert(const T& element);

  //Muestra el árbol parcialmente ordenado
  void show_elements();

  //Elimina el máximo elemento de un APOmin
  //void pop_max();

};
#endif
#include <ejer4.cpp>
