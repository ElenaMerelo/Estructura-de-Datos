/*
front--Access next element (public member function )
back--Access last element (public member function )
push--Insert element (public member function )
pop--Remove next element (public member function )
*/
#include <iostream>
using namespace std;


//Construye una cola con n veces element
template <class T>
my_queue<T>::my_queue(int n, T element){
  for(int i= 0; i< n; i++)
    data.push_back(element);
}

//Muestra la cola
template <class T>
void my_queue<T>::show_queue(){
  typename list<T>::const_iterator i;
  for(i= data.begin(); i!= data.end(); i++)
    cout << *i << " ";
}
