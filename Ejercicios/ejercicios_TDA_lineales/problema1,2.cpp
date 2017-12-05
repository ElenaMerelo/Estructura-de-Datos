/*
* @file problema1,2.cpp
* @brief Enunciado del ejercicio: Diseñar tres funciones que eliminen todas las apariciones de un elemento x en una lista,
* una pila y una cola respectivamente.
* @author: Elena Merelo Molina
* @doc Compilación y enlazado con g++ problema1,2.cpp -o problema1,2
* ejecución con ./problema1,2
 */
#include <list>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

/* Función que elimina todas las apariciones de un elemento x en una lista. Para ello creamos una nueva lista, y metemos en ella todos los elementos
de la original que no sean x, borramos la original y le asignamos el valor de la lista sin los x.*/
template <class T>
void delete_x_list(list<T> &l, T x){
  typename list<T>::iterator i;
  list<T> aux;
  for(i= l.begin(); i!= l.end(); i++){
    if(*i != x)
      aux.push_back(*i);
  }
  l.clear();
  l= aux;
}

/* Función que elimina las apariciones de un elemento x en una pila(LIFO). Para ello creamos una nueva pila en la que vamos metiendo los elementos de la original
que no sean x, y éstos los volvemos a meter en la original, que hemos ido vaciando.*/
template <class T>
void delete_x_stack(stack<T> &s, T x){
  stack<T> aux;

  while(!s.empty()){
    if(s.top() != x)
      aux.push(s.top());

    s.pop();
  }

  while(!aux.empty()){
    s.push(aux.top());
    aux.pop();
  }
}

/* Función que elimina las apariciones de un elemento x en una cola(FIFO). Para ello creamos una nueva cola, y metemos en ella los elementos de la original que no sean
x, a la vez que la vamos vaciando, para luego meter en ella estos elementos.*/
template <class T>
void delete_x_queue(queue<T> &q, T x){
  queue<T> aux;

  while(! q.empty()){
    if(q.front() != x)
      aux.push(q.front());

    q.pop();
  }

  while(!aux.empty()){
    q.push(aux.front());
    aux.pop();
  }
}

//Función que muestra una lista iterando sobre sus componentes
template <class T>
void show_list(const list<T> &l){
  typename list<T>::const_iterator i;
  for(i= l.begin(); i!= l.end(); i++)
    cout << *i << " ";

  cout << "\n";
}
/*En la pila(cola) uso otra pila(cola) auxiliar ya que no puedo iterar sobre sus elementos,
únicamente puedo hacer operaciones sobre el último elemento(sobre el primero). */

/* Función que muestra una pila metiendo sus elementos en otra pila auxiliar,
mostrando los elementos conforme se eliminan de esta pila auxiliar y se vuelven
a insertar en la original. Lo hemos hecho así para que no salgan en orden inverso. */
template <class T>
void show_stack(stack<T> &s){
  stack<T> aux;

  while(!s.empty()){
    aux.push(s.top());
    s.pop();
  }
  //Volvemos a meter en s sus elementos
  while(!aux.empty()){
    cout << aux.top() << " ";
    s.push(aux.top());
    aux.pop();
  }
}

//Función que muestra una cola.
template <class T>
void show_queue(queue<T> &q){
  queue<T> aux;
  cout <<"\n";
  while(!q.empty()){
    cout << q.front() << " ";
    aux.push(q.front());
    q.pop();
  }
  //Restablezco la cola original
  while(!aux.empty()){
    q.push(aux.front());
    aux.pop();
  }
}

//Programa de prueba
int main(){
  //Probamos el funcionamiento de delete_x_list y show_list
  list<int> l;
  for(int i= 0; i< 5; i++)
    l.push_back(i+1);

  for(int i= 0; i< 4; i++)
  l.push_back(8);

  show_list(l);
  delete_x_list(l, 8);
  cout << "\nBorramos los 8: \n";
  show_list(l);

  //Probamos el funcionamiento de delete_x_stack y show_stack
  stack<char> s;
  for(char i= 'a'; i< 'e'; i++)
    s.push(i);

  s.push('a');
  s.push('z');
  s.push('a');

  show_stack(s);
  delete_x_stack(s,'a');
  cout <<"\nBorramos las 'a': \n";
  show_stack(s);

  //Probamos el funcionamiento de delete_x_queue y show_queue
  queue<double> q;
  for(double i= 1.3; i< 6.3; i++)
    q.push(i);

  q.front()= 45.5;
  q.back()= 45.5;
  show_queue(q);
  delete_x_queue(q,45.5);
  cout << "\nBorrando 45.5 la cola queda: \n";
  show_queue(q);


}











//
