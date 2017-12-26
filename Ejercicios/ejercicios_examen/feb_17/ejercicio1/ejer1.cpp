#include <stack>
#include <iostream>
#include <assert.h>

using namespace std;

/*----------------------CONSTRUCTORES------------------------*/
template<class T>
pila_doble<T>::pila_doble(int size, T element){
  int i;
  for(i= 0; i< size/2; i++)
    pila0.push(element);

  for(i= size/2; i< size; i++)
    pila1.push(element);

  if(size%2 != 0)
    pila1.push(element);
}

template<class T>
pila_doble<T>::pila_doble(pila_doble<T> &other){
  *this= other;
}

/*-----------------------SOBRECARGA DE OPERADORES------------------------*/
template<class T>
pila_doble<T>& pila_doble<T>::operator=(pila_doble<T> &other){
  stack<T> aux0, aux1;

  //Movemos los elementos de la other.pila0 a aux0. Estarán en orden inverso por ser la pila un LIFO
  while(!other.pila0.empty()){
    aux0.push(other.pila0.top());
    other.pila0.pop();
  }

  //Ídem con la pila 1
  while(!other.pila1.empty()){
    aux1.push(other.pila1.top());
    other.pila1.pop();
  }

  //Ahora sí, copiamos los elementos de la pila original a la de la clase, en el mismo orden
  while(!aux0.empty()){
    pila0.push(aux0.top());
    aux0.pop();
  }

  while(!aux1.empty()){
    pila1.push(aux1.top());
    aux1.pop();
  }
}

template<class T>
void pila_doble<T>::show_elements(){
  stack<T> aux0, aux1;

  //Pasamos los elementos de pila 0 a aux0
  while(!pila0.empty()){
    aux0.push(pila0.top());
    pila0.pop();
  }

  //Ahora ya podemos mostrarlos en el orden correcto, a la vez que restauramos pila0
  while(!aux0.empty()){
    cout << aux0.top();
    pila0.push(aux0.top());
    aux0.pop();
  }

  T element;
  //Mostramos ahora los elementos de pila1, a la vez que los metemos en aux1
  while(!pila1.empty()){
    element= pila1.top();
    cout << element;
    aux1.push(element);
    pila1.pop();
  }

  cout <<"\n";

  //Restablecemos pila1
  while(!aux1.empty()){
    pila1.push(aux1.top());
    aux1.pop();
  }
}

/*-----------------------------OTROS MÉTODOS------------------------------*/
template<class T>
void pila_doble<T>::pop(int indice_pila){
  assert(indice_pila == 0 || indice_pila == 1);
  if(indice_pila == 0)
    pila0.pop();

  else
    pila1.pop();
}

template <class T>
void pila_doble<T>::pop(){
  stack<T> aux;

  /*Metemos los elementos de la pila 1 en una pila auxiliar, ya que queremos
  eliminar el primer elemento que se insertó en ella.*/
  while(!pila1.empty()){
    aux.push(pila1.top());
    pila1.pop();
  }

  aux.pop();

  //Restablecemos la pila 1 con el elemento eliminado
  while(!aux.empty()){
    pila1.push(aux.top());
    aux.pop();
  }
}

template<class T>
void pila_doble<T>::push(int indice_pila, T element){
  assert(indice_pila == 0 || indice_pila == 1);

  if(indice_pila == 0)
    pila0.push(element);

  else
    pila1.push(element);
}

template<class T>
void pila_doble<T>::push(T element){
  stack<T> aux1;
  int i;

  //Metemos los elementos de pila1 en aux1
  while(!pila1.empty()){
    aux1.push(pila1.top());
    pila1.pop();
  }

  //Añadimos el elemento pasado como argumento
  aux1.push(element);

  //Restauramos la pila1
  while(!aux1.empty()){
    pila1.push(aux1.top());
    aux1.pop();
  }
}

template <class T>
int pila_doble<T>::size(){
  return pila1.size() + pila0.size();
}

template <class T>
int pila_doble<T>::size_pila(int indice_pila){
  assert(indice_pila == 0 || indice_pila == 1);

  if(indice_pila == 0)
    return pila0.size();
  else
    return pila1.size();
}


template <class T>
T pila_doble<T>::top(){
  stack<T> aux1;
  int i;

  //Metemos los elementos de pila1 en aux1
  while(!pila1.empty()){
    aux1.push(pila1.top());
    pila1.pop();
  }

  T result= aux1.top();

  //Restauramos la pila1
  while(!aux1.empty()){
    pila1.push(aux1.top());
    aux1.pop();
  }
  return result;
}

template <class T>
T& pila_doble<T>::top(int indice_pila){
  assert(indice_pila == 0 || indice_pila == 1);

  if(indice_pila == 0)
    return pila0.top();
  else
    return pila1.top();
}

template <class T>
bool pila_doble<T>::empty(){
  return pila1.size() + pila0.size() == 0;
}

template <class T>
bool pila_doble<T>::empty(int indice_pila){
  assert(indice_pila == 0 || indice_pila == 1);

  if(indice_pila == 0)
    return pila0.size() == 0;

  else
    return pila1.size() == 0;
}








//
