/*
Enunciado: Implementa un TDA cola usando dos pilas.
Author: Elena Merelo Molina
*/

#include <ejer4.h>

int main(){
  stack<int> s;

  for(int i= 0; i< 5; i++)
    s.push(i+1);

  queue<int> q1(s);
  cout << "\nElementos de q1: ";
  q1.show_elements();

  queue<int> q2, q3(q1);
  cout << "\nTamaño de q2: " << q2.size();
  if(q2.empty())
    cout << "\nq2 está vacía";
  else
    cout << "\nq2 no está vacía";

  q3.push(8);
  q3.pop();

  cout << "\nElementos de q3: ";
  q3.show_elements();
  cout << "\nq3.front(): " << q3.front();
  cout << "\nq3.back(): " << q3.back();


}
