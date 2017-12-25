#include <vector>
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
}

template<class T>
pila_doble<T>::pila_doble(pila_doble<T> &other){
  this= other;
}

/*-----------------------SOBRECARGA DE OPERADORES------------------------*/
template<class T>
pila_doble<T>& pila_doble<T>::operator=(pila_doble<T> &other){
  stack<T> aux0, aux1;
  int i;

  //Movemos los elementos de la other.pila0 a aux0. Estarán en orden inverso por ser la pila un LIFO
  for(i= 0; i< other.pila0.size(); i++){
    aux0.push(other.pila0.top());
    other.pila0.pop();
  }

  //Ídem con la pila 1
  for(i= 0; i< other.pila1.size(); i++){
    aux1.push(other.pila1.top());
    other.pila1.pop();
  }

  //Ahora sí, copiamos los elementos de la pila original a la de la clase, en el mismo orden
  for(i= 0; i< aux0.size(); i++){
    pila0.push(aux0.top());
    aux0.pop();
  }

  for(i= 0; i< aux1.size(); i++){
    pila1.push(aux1.top());
    aux1.pop();
  }
}

template<class T>
void pila_doble<T>::show_elements(){
  stack<T> aux0, aux1;
  int i;

  //Pasamos los elementos de p.pila 0 a aux0
  for(i= 0; i< pila0.size(); i++){
    aux0.push(pila0.top());
    pila0.pop();
  }

  //Ahora ya podemos mostrarlos en el orden correcto, a la vez que restauramos p.pila0
  for(i= 0; i< aux0.size(); i++){
    cout << aux0.top();
    pila0.push(aux0.top());
  }

  T element;
  //Mostramos ahora los elementos de p.pila1, a la vez que los metemos en aux1
  for(i= 0; i< pila1.size(); i++){
    element= pila1.top();
    cout << element;
    aux1.push(element);
    pila1.pop();
  }

  //Restablecemos p.pila1
  for(i= 0; i< aux1.size(); i++){
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
  for(int i= 0; i< pila1.size(); i++){
    aux1.push(pila1.top());
    pila1.pop();
  }

  //Añadimos el elemento pasado como argumento
  aux1.push(element);

  //Restauramos la pila1
  for(i= 0; i< aux1.size(); i++){
    pila1.push(aux1.top());
    aux1.pop();
  }
}










//
