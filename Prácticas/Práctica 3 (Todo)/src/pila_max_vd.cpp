/**
  * @file pila_max_vd.cpp
  * @brief Implementación del TDA pila con máximo a partir de un vector dinámico
  *
  */
#include <cassert>
#include <pila_max_vd.h>



//Devuelve una referencia al elemento del tope de la pila
struct elemento& Pila_max::top(){
  assert(!empty());       //Si la pila está vacía, abortar
  return v[v.size()- 1]; //Devuelve el último elemento del vector dinámico
}

//Devuelve una referencia constante al elemento del tope de la pila
const struct elemento& Pila_max::top() const{
  assert(!empty());       //Si la pila está vacía, abortar
  return v[v.size()- 1]; //Devuelve el último elemento del vector dinámico
}

//Añade un elemento encima del tope de la pila
void Pila_max::push(int number){

  v.resize(v.size()+ 1);
  v[v.size()-1].element= number; 
  
  if(v.size() > 1){
    if(number > v[size()- 2].maximo)
      v[v.size()-1].maximo= number;
    else
      v[v.size()-1].maximo= v[size()-2].maximo;
  } else{
    v[0].maximo=number;
  }
}

//Quita el elemento del tope de la pila
void Pila_max::pop(){
  v.resize(v.size() -1);
}
