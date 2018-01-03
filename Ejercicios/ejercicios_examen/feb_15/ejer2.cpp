/*Enunciado: Dada una lista que contiene pilas con enteros y que se encuentra
ordenada de menor a mayor por el tope de cada pila, implementar una función
borrar, que elimina el tope de cada pila en la lista, con valores iguales al dado
como parámetro. La cabecera de la función sería:
void Borrar(list<stack<int> > & L, int elemento)
Así por ejemplo:
tope
L=
2 2 2 3 4 8
9 1
9 2 2
1 0
10
7
Antes de la llamada
a la función con elemento=2
tope
L=
1 3 4 8 9
0 9 2 2 1
10
7
Después de la llamada
Nota: la lista tiene que quedar ordenada por el tope de las pilas tras la ejecución de
la función.
Author: Elena Merelo Molina
*/

#include <list>
#include <stack>
#include <iostream>
#include <iterator>

using namespace std;

//Ordena la lista de pilas según el valor de los topes, de menor a mayor
void sort(list<stack<int> > &l){
  typename list<stack<int> >::iterator i, j;

  for(i= l.begin(); i != l.end(); i++)
    for(j= ++i; j != l.end(); j++)
      if(i->top() > j->top()){
        advance(i,1);
        l.insert(i, *j);
        l.remove(*j);
      }
}

//Borra los topes iguales a element
void erase(list<stack<int> > &l, int element){
  typename list<stack<int> >::iterator i;

  for(i= l.begin(); i != l.end(); i++){
    if(i->top() == element)
      i->pop();
  }

  //sort(l);
}

//Construye una pila a partir de un vector
void create_stack_from_vector(stack<int> &s, int v[], int size){
  for(int i= 0; i< size; i++)
    s.push(v[i]);
}

//Muestra los elementos de una pila
void show_stack(stack<int> &s){
  stack<int> aux;

  //Metemos los elementos de la pila en una auxiliar para mostrarlos en el orden correcto
  while(!s.empty()){
    aux.push(s.top());
    s.pop();
  }

  //Restauramos la pila s a la vez que mostramos los elementos de aux
  while(!aux.empty()){
    cout << " " << aux.top();
    s.push(aux.top());
    aux.pop();
  }
}

//Muestra los elementos de la lista de stacks
void show_elements(list<stack<int> > &l){
  typename list<stack<int> >::iterator i;

  for(i= l.begin(); i != l.end(); i++){
    show_stack(*i);
    cout << "\n";
  }
}

int main(){
  int v1[]= {2,9,1};
  int v2[]= {2,1,0};
  int v3[]= {2};
  int v4[]= {3,9,10,7};
  int v5[]= {4,2};
  int v6[]= {8,2};
  stack<int> s1, s2, s3, s4, s5, s6;

  create_stack_from_vector(s1,v1,3);
  create_stack_from_vector(s2,v2,3);
  create_stack_from_vector(s3,v3,1);
  create_stack_from_vector(s4,v4,4);
  create_stack_from_vector(s5,v5,2);
  create_stack_from_vector(s6,v6,2);

  list<stack<int> > l;

  l.push_back(s1);
  l.push_back(s2);
  l.push_back(s3);
  l.push_back(s4);
  l.push_back(s5);
  l.push_back(s6);

  show_elements(l);
  erase(l,2);
  show_elements(l);


}








//
