#include <list>
#include <iostream>

using namespace std;
/*Enunciado:
Una lista L se dice que está ordenada de forma ascendente por índices (orden
indexado) si la secuencia {L(indices(0)),L(indices(1)),...L(indices(indices.size()-1))}. (siendo L(i)
el elemento en la posición i-ésima), es una secuencia ordenada de forma ascendente.
Necesariamente indices debe ser una lista de enteros que indica una secuencia de índices en L.
Implementa una función booleana que reciba L (L puede ser cualquier tipo de dato) y un índice I y
devuelva true si L está ordenada de forma ascendente con respecto al índice.
Ejemplo: Para L= {2.2, 7.1, 3.4, 9.0, 6.2, 5.1} e I={0, 2, 5, 4, 1, 3}, la función devolvería true.
Author: Elena Merelo Molina.
*/

/*Tomamos los elementos de la lista l en las posiciones de indices y los vamos
metiendo en otra lista auxiliar llamada aux, a la vez que comparamos que cada
elemento nuevo es mayor o igual que el anterior. Si no lo hemos ya tendremos que
la lista no está ordenada ascendentemente por índices, en caso contrario continuamos.*/
bool ordenada_ascendentemente_por_indices(list<double> l, list<int> indices){
  list<int>::iterator i;
  list<double>::iterator j;
  list<double> aux;

  for(i = indices.begin(); i != indices.end(); i++){
    //Nos situamos al principio de la lista l
    j= l.begin();
    //Avanzamos el iterador j tantas veces como indique el elemento i de la lista índices
    advance(j, *i);
    //Si el elemento j de la lista es menor que el anterior ya hemos terminado
    if(aux.back() > *j)
      return false;

    //Si no continuamos y lo añadimos a aux
    aux.push_back(*j);
  }
  //Si termina el for y llega a este punto es porque la lista está ordenada como queremos
  return true;
}

int main(){
  double v1[]= {2.2, 7.1, 3.4, 9.0, 6.2, 5.1};
  int v2[]= {0, 2, 5, 4, 1, 3};

  list<double> l(v1, v1+6);
  list<int> indices(v2, v2+6);

  if(ordenada_ascendentemente_por_indices(l, indices))
    cout << "La lista está ordenada ascendentemente por índices";
  else
    cout << "La lista no está ordenada ascendentemente por índices";

}
