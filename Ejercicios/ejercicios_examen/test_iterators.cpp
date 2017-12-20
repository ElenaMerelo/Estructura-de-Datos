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



}
