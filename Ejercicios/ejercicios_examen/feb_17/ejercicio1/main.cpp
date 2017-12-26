#include <ejer1.h>
#include <stack>
#include <iostream>

using namespace std;

int main(){
  pila_doble<int> p1;

  //Funcionamiento del constructor con parámetros
  pila_doble<int> p2(3,4);
  p2.show_elements();
  cout << "Tamaño total de la pila: " << p2.size() << " , tamaño de la pila 0: " << p2.size_pila(0);
  cout << " , tamaño de la pila 1: " << p2.size_pila(1) << "\n";

  //Probamos el funcionamiento del constructor de copia
  pila_doble<int> p3(p2);
  p3.show_elements();

  //Prueba del operador de asignación
  pila_doble<int> p4= p3;
  p4.show_elements();

  //Probamos ahora los diferentes métodos push
  p4.push(5);
  p4.push(0,3);
  p4.push(1,6);
  p4.show_elements();

  //Prueba de los top
  cout << "\nTope de la pila 0: "<< p4.top(0);
  cout << "\nTope de la pila 1: "<< p4.top(1);
  cout << "\nTope de la pila doble: " << p4.top() << endl;

  //Prueba de los pop
  p4.pop(0);
  p4.pop(1);
  p4.pop();
  cout << "Elementos de p4 tras borrar: ";
  p4.show_elements();

  //Prueba de los empty()
  if(p4.empty())
    cout << "\nLa pila 4 está vacía";
  else
    cout << "\nLa pila 4 no está vacía";

  pila_doble<int> p5;
  if(p5.empty(0))
    cout << "\nLa pila 0 de la pila 5 está vacía";
  else
    cout << "\nLa pila 0 de la pila 5 no está vacía";

  if(p4.empty(1))
    cout << "\nLa pila 1 de la pila 4 está vacía";
  else
    cout << "\nLa pila 1 de la pila 4 no está vacía";



}
