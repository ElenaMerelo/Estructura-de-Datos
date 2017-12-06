//Programa de prueba
#include <problema1,7.h>
#include <iostream>

using namespace std;

int main(){
  my_queue<int> q1;
  my_queue<char> q2(3,'a');


  for(int i= 0; i< 5; i++)
    q1.push(i);

  my_queue<int> q4= q1, q3(q1);
  cout << "\nCola 1: ";
  q1.show_queue();

  cout << "\nCola 2: ";
  q2.show_queue();

  cout << "\nCola 3: ";
  q3.show_queue();

  cout << "\nCola 4: ";
  q4.show_queue();


  cout << "\nq1.back(): " << q1.back();
  cout << "\nq1.front(): " << q1.front();
  q1.pop();
  cout << "\nBorramos el primer elemento de q1: ";
  q1.show_queue();
  if(q2.empty())
    cout << "\nLa cola 2 está vacía";
  else
    cout << "\nLa cola 2 no está vacía, tiene " << q2.size() << " elementos";
}
