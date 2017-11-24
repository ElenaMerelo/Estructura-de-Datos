#include <iostream>

#define CUAL_COMPILA 2
#if CUAL_COMPILA==1
#include<pila_max_vd.h>
#else
#include<pila_max_cola.h>
#endif
using namespace std;

int main(){
  Pila_max p;

  p.push(2);
  p.push(1);
  p.push(3);
  p.push(0);
  p.push(4);
  p.push(10);

  cout << "Elemento: " << p.top().element << " Máximo: " << p.top().maximo << endl; p.pop();
  cout << "Elemento: " << p.top().element << " Máximo: " << p.top().maximo << endl; p.pop();
  cout << "Elemento: " << p.top().element << " Máximo: " << p.top().maximo << endl; p.pop();
  cout << "Elemento: " << p.top().element << " Máximo: " << p.top().maximo << endl; p.pop();
  cout << "Elemento: " << p.top().element << " Máximo: " << p.top().maximo << endl; p.pop();
  cout << "Elemento: " << p.top().element << " Máximo: " << p.top().maximo << endl; p.pop();
  
}
