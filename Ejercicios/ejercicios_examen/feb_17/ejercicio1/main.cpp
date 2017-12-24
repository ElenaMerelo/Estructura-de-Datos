#include <ejer1.h>
#include <stack>
#include <iostream>

using namespace std;

int main(){
  pila_doble<int> p;

  for(int i= 0; i< 5; i++)
    p.push(i+1);

  p.show_elements();
}
