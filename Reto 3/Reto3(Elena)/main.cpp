#include <iostream>
#include <reto3.h>

using namespace std;

int main(){
  stack<int> s1;

  for(int i= 0; i< 5; i++)
    s1.push(i);

//Comprobamos así que funciona el constructor de copia
  stack<int> s2(s1);

  cout << "\nEl elemento tope de la pila 2 antes de insertar más elementos es: " << s2.top();

  s2.push(8);
  s2.push(9);

  stack<int> s3= s2;

  cout << "\nEl elemento tope de la pila 3 es: " << s3.top();

  cout << "\nImprimimos la pila 3: ";
  while(!s3.empty()){
    cout << s3.top() << " ";
    s3.pop();
  }
}
