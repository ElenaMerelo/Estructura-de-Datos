#include <iostream>
#include "pila_max_cola.h"

using namespace std;

int main(){
  Pila_max p;

  p.push(2);
  p.push(1);
  p.push(3);
  p.push(0);
  p.push(4);
  p.push(10);

  cout << "Elemento: " << p.top().ele << " Máximo: " << p.top().maximo << endl; p.pop();
  cout << "Elemento: " << p.top().ele << " Máximo: " << p.top().maximo << endl; p.pop();
  cout << "Elemento: " << p.top().ele << " Máximo: " << p.top().maximo << endl; p.pop();
  cout << "Elemento: " << p.top().ele << " Máximo: " << p.top().maximo << endl; p.pop();
  cout << "Elemento: " << p.top().ele << " Máximo: " << p.top().maximo << endl; p.pop();
  cout << "Elemento: " << p.top().ele << " Máximo: " << p.top().maximo << endl; p.pop();
  
}
