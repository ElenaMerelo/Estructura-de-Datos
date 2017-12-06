/*
Enunciado: Un palı́ndromo es una cadena de caracteres que se lee igual hacia delante que hacia atrás
(pudiéndose modificar los espacios en blanco). Por ejemplo: Dábale arroz a la zorra el abad. Escribir un
programa para detectar si una cadena de caracteres es un palı́ndromo o no. (Nota: un mecanismo efectivo
de solución consiste en el uso simultáneo de una pila y una cola).
Compilación y enlazado: g++ problema1,4.cpp -o problema1,4
Ejecución: ./problema1,4
By: Elena Merelo Molina
*/
#include <stack>
#include <queue>
#include <string.h>
#include <iostream>
#include <ctype.h>
#include <algorithm>
using namespace std;

/*Función que elimina los espacios en blanco de un string, iterando sobre sus componentes.
Por sí sola remove_if no modifica el tamaño del string, por ello usamos erase. Otra forma
equivalente de hacerlo:

string::iterator end_pos = remove(s.begin(), s.end(), ' ');
s.erase(end_pos, s.end());

*/
void remove_whitespaces(string &s){
  s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());
}

/* Para comprobar si la cadena de caracteres es palíndroma, usaremos que en las pilas
el último elemento que se mete es el primero que sale, que en las colas el primer
elemento insertado es el primero que sale. Así, crearemos una pila y una cola conteniendo
a la cadena pasada como parámetro, iremos extrayendo los elementos de ambas y comparándolos.*/
bool is_palindrome(string &cadena){
  stack<char> s;
  queue<char> q;
  bool palindrome= true;
  remove_whitespaces(cadena);
  //Metemos los caracteres que no son espacios en blanco en la pila y en la cola
  for(int i= 0; i< cadena.size(); i++){
      s.push(cadena[i]);
      q.push(cadena[i]);
  }

  for(int i= 0; i< cadena.size()/2 && palindrome; i++){
    if(s.top() != q.front())
      palindrome= false;

    s.pop();
    q.pop();
  }
  return palindrome;
}

//Programa de prueba
int main(){
  string cadena1= "dabale arroz a la zorra el abad";
  string cadena2= "luriluri";

  if(is_palindrome(cadena1))
    cout << "La cadena 1 es palíndroma";
  else
    cout << "La cadena 1 no es palíndroma";

  cout << "\n";

  if(is_palindrome(cadena2))
    cout << "La cadena 2 es palíndroma";
  else
    cout << "La cadena 2 no es palíndroma";
}
