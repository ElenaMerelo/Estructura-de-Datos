/**
  * @file pila_max_vd.cpp
  * @brief Implementación del TDA pila con máximo a partir de un vector dinámico
  *
  */
#include <cassert>
#include <pila_max_vd.h>


//Comprueba si la pila está vacía
bool pila_max_vd::empty() const{
  if(v.size() == 0)
    return true;
  else
    return false;
}

//Devuelve una referencia al elemento del tope de la pila
struct elemento& pila_max_vd::top(){
  assert(!empty());       //Si la pila está vacía, abortar
  return v[v.size()- 1]; //Devuelve el último elemento del vector dinámico
}

//Devuelve una referencia constante al elemento del tope de la pila
const struct elemento& pila_max_vd::top()const{
  assert(!empty());       //Si la pila está vacía, abortar
  return v[v.size()- 1]; //Devuelve el último elemento del vector dinámico
}

//Añade un elemento encima del tope de la pila
void pila_max_vd::push(int number){
  v.resize(v.size()+ 1);
  v[v.size()].element= number;
  if(e.maximo > v[size()- 1].maximo)
    v[v.size()].maximo= number;
  else
    v[v.size()].maximo= v[size()- 1].maximo;
}

//Quita el elemento del tope de la pila
void pop(){
  v.resize(v.size() -1);
}
