#include <vector>
#include <iostream>
//#include <iterator>

using namespace std;

int main(){
  vector<vector<int> > v;

  //Añadimos columnas a la matriz
  for(int i= 0; i< 10; i++){
    vector<int> row;
    for(int j= 0; j< 10; j++)
      row.push_back(i+1);

    v.push_back(row);
  }

  //Prueba para ver qué devuelve el iterator de un vector de vectores
  vector<vector<int> >::iterator i;
  vector<int>::iterator j;

  for(i= v.begin(); i != v.end(); i++){
    for(j= i->begin(); j != i->end(); j++)
      cout << *j << " ";
    cout << "\n";
  }
  cout << "\nDistancia del iterador al comienzo: " << distance(v.begin(), v.end());

  //Prueba del funcionamiento de advance en un vector de vectores
  vector<vector<int> >::iterator it= v.begin();
  vector<int>::iterator other= it->begin();
  advance(other, 5);
  cout << "\nAvanzando 5 posiciones el iterador apuntamos al elemento: " << *other;

  /*Queremos ahora devolver el segundo elemento de la diagonal principal. Para ello
  avanzamos n posiciones el iterador de las filas y luego el de las columnas
  el mismo número de posiciones(los elementos de la diagonal principal son los de las posiciones [n][n])*/
  vector<vector<int> >::iterator rows= v.begin()+2;
  vector<int>::iterator columns= rows->begin();
  advance(columns,2);

  cout << "\nEl tercer elemento(el que está en la posición 2) de la diagonal principal es: " << *columns;
}
