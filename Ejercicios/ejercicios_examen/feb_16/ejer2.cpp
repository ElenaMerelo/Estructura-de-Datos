/*Enunciado: Implementa una función bool sumaIgual(const list<list<int> > &L) que
devuelve true si todas las sumas por filas y por columnas da el mismo resultado (se
asume que todas las listas tienen igual longitud). Por ejemplo, en la siguiente lista si se
suma cada fila y cada columna siempre se obtiene 3
L=< <0,1,1,1>,
<2,1,0,0>,
<1,0,2,0>,
<0,1,0,2> >
Author: Elena Merelo Molina
*/

#include <list>
#include <iostream>
#include <iterator>

using namespace std;

bool suma_igual(const list<list<int> > &l){
  list<list<int> >::const_iterator i;
  list<int>::const_iterator j;
  int suma, suma_anterior= 0;

  //Sumamos la primera columna para tener punto de partida con el que comparar
  for(i= l.begin(); i!= l.end(); i++){
    for(j= i->begin(); j != i->begin()+1; j++)
      suma_anterior += *j;
  }

  //Sumamos las columnas
  for(i= l.begin(); i!= l.end(); i++){
    suma= 0;
    for(j= i->begin()+1; j!= i->end(); j++)
      suma += *j;
      cout << suma << " " << suma_anterior;
    if(suma != suma_anterior)
      return false;

    suma= suma_anterior;
  }
  return true;
}

void show_elements(const list<list<int> > &l){
  list<list<int> >::const_iterator i;
  list<int>::const_iterator j;

  for(i= l.begin(); i!= l.end(); i++){
    for(j= i->begin(); j!= i->end(); j++)
      cout << *j << " ";

    cout << "\n";
  }

}

int main(){
  list<int> columnas(3,5);
  list<list<int> > filas(3, columnas);

  show_elements(filas);

  if(suma_igual(filas))
    cout << "\nEl resultado de sumar las filas y columnas es el mismo";
  else
    cout << "\nNo suman los mismo las filas y las columnas";


}
