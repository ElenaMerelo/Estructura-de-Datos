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

/*--------------FUNCIONES AUXILIARES, NO LAS PIDE EL PROBLEMA-----------------*/
//Construye una pila a partir de un vector
void create_stack_from_vector(stack<int> &s, int v[], int size){
  for(int i= size-1; i>= 0; i--)
    s.push(v[i]);
}

//Muestra los elementos de una pila
void show_stack(stack<int> &s){
  stack<int> aux;

  //Metemos los elementos de la pila en una auxiliar para mostrarlos en el orden correcto
  while(!s.empty()){
    cout << " " << s.top();
    aux.push(s.top());
    s.pop();
  }

  //Restauramos la pila s a la vez que mostramos los elementos de aux
  while(!aux.empty()){
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

/*-------------FUNCIONES PEDIDAS POR EL PROBLEMA--------------*/
//Ordena la lista de pilas según el valor de los topes, de menor a mayor
struct compare_tops{
  bool operator()(stack<int> &s1, stack<int> &s2){
    stack<int> aux1, aux2;
    int top1, top2;

    //Metemos en las pilas auxiliares las pasadas como parámetro
    while(!s1.empty()){
      aux1.push(s1.top());
      s1.pop();
    }
    top1= aux1.top();

    while(!s2.empty()){
      aux2.push(s2.top());
      s2.pop();
    }
    top2= aux2.top();

    //Restablecemos las pilas originales
    while(!aux1.empty()){
      s1.push(aux1.top());
      aux1.pop();
    }

    while(!aux2.empty()){
      s2.push(aux2.top());
      aux2.pop();
    }
    if(top1 < top2)
      return true;

    else
      return false;
  }
};

//Borra los topes iguales a element
void erase(list<stack<int> > &l, int element){
  typename list<stack<int> >::iterator i;

  for(i= l.begin(); i != l.end(); i++){
    if(i->top() == element)
      i->pop();
  }
  l.sort(compare_tops());
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
  //l.sort(compare_tops);
  cout << "\nBorrando el 2 de los topes de las pilas(en nuestra forma de mostrar el list de stacks el tope de la pila es el final): \n";
  show_elements(l);


}








//
