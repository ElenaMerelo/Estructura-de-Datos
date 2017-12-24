/*Enunciado: Se define una matriz bilineal simétrica como una matriz nxn en la que
todos los elementos significativos (distintos de un valor por defecto) están situados en
las 2 diagonales principales y tales que al recorrer ambas diagonales en orden creciente
de filas, presentan los mismos elementos. Un ejemplo de este tipo de matrices es la
matriz del ejemplo. Es una matriz 6x6 de valores enteros y con el 0 como valor por
defecto.
2 0 0 0 0 2
0 4 0 0 4 0
0 0 7 7 0 0
0 0 1 1 0 0
0 9 0 0 9 0
6 0 0 0 0 6
Implementar un iterador que itere sobre los elementos significativos de la matriz. Han
de implementarse (aparte de las de la clase iteradora) las funciones begin() y end().

By: Elena Merelo Molina
*/
/*#include <iostream>
#include <vector>
#include <iterator>*/

using namespace std;

template <class T>
matriz_bilineal_simetrica<T>::matriz_bilineal_simetrica(vector<T> v){
  typename vector<T>::iterator i= v.begin();
  //typename vector<vector<T> >::iterator j;
  //typename vector<T>::iterator k;
  int size= v.size();

  while(i != v.end()){
    /*Creamos una fila del tamaño del vector pasado como argumento, toda llena
    de ceros por defecto.Así, lo único que tendremos que hacer será añadir el
    elemento del vector en las diagonales principales.*/
    /*for(j= filas.begin(); j != filas.begin()+size; j++){
      vector<T> columna(size);
      for(k= j->begin(); k != j->begin()+ size; k++){
        if(j==k){
          columna.insert(j, v[i]);
          columna.insert(size-j-1, v[i]);
        }
        i++;
      }

    }*/
    for(int j= 0; j < size; j++){
      vector<T> columna(size);
      for(int k= 0; k < size; k++){
        if(j==k){
          columna[j]= *i;
          columna[size-j-1]= *i;
        }
        i++;
      }
      filas.push_back(columna);
    }
  }
}

template <class T>
void matriz_bilineal_simetrica<T>::clear(){
  columnas.clear();
  filas.clear();
}


template <class T>
ostream& operator <<(ostream &os,const matriz_bilineal_simetrica<T> &m){
  typename vector<T>::iterator j;
  typename vector<vector<T> >::iterator i;

  for(int i= m.filas.begin(); i != m.filas.end(); i++){
    for(j = 0; j < m.filas.size(); i++)
      os << m[i][j] << " ";
    os << "\n";
  }
  return os;
}

/*template <class T>
istream& operator >>(istream &is, matriz_bilineal_simetrica &m){
  m.clear();

}*/

//Método que desplaza el iterador n posiciones en la diagonal principal
template <class T>
void matriz_bilineal_simetrica<T>::advance(my_iterator &it, int n){
  //Nos aseguramos que se itere sobre elementos de la matriz distintos de cero
  assert(n < distance(it, filas.end()) && *it != 0);

  typename vector<T>::iterator j= columnas->begin();

  //Calculamos la posición del elemento que queremos mover, su distancia desde 0
  int distancia= distance(j, it);
  typename vector<vector<T> >::iterator aux= filas.begin()+distancia;
  typename vector<T>::iterator result= aux->begin();
  advance(result, distancia);

  it= result;

}



//
