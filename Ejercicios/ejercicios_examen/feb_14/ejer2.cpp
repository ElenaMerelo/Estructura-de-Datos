/*Enunciado:
Dados dos multiset con elementos enteros, implementar la función:
multiset<int> multi_interseccion (const multiset<int> & m1, const multiset<int> &m2)
que calcula la intersección de dos multiset: elementos comunes en los dos multiset repetidos tantas
veces como aparezcan en el multiset con menor número de apariciones del elemento.
Por ejemplo siendo m1={2,2,3,3} y m2={1,2,3,3,3,4} entonces m1∩m2={2,3,3} ó
si m1={2,2,2,3,3} y m2={1,2,2,2,2,3,3,3,4} entonces m1∩m2={2,2,2,3,3}
Author: Elena Merelo Molina
*/
#include <set>
#include <vector>
#include <iostream>

using namespace std;

//Función que inserta en un multiset el número 'number' 'times' veces
void insert(multiset<int> &m, int number, int times){
  vector<int> v;
  for(int i= 0; i< times; i++)
    v.push_back(number);

  m.insert(v.begin(), v.end());
}

/*Metiendo los elementos de ambos en un set podemos comparar más rápidamente cuáles
tienen en común, una vez sabemos qué elementos están en la intersección contamos
en cual aparece menos veces y lo metemos en el multiset auxiliar.*/
multiset<int> multi_interseccion(const multiset<int> &m1, const multiset<int> &m2){
  set<int> s1, s2;
  multiset<int> result;

  //Metemos los elementos del primer multiset en un set para eliminar los repetidos y ordenarlos de menor a mayor
  s1.insert(m1.begin(), m1.end());
  s2.insert(m2.begin(), m2.end());

  //Buscamos qué elemento del set de menor tamaño están en el de mayor tamaño
  set<int> aux= s1.size() < s2.size() ? s1 : s2;
  set<int> other= s1.size() >= s2.size() ? s1 : s2;

  set<int>::iterator i, j;
  int times;
  for(i= aux.begin(); i != aux.end(); i++){
    j= s2.find(*i);
    //Si el elemento *i del set 1 está en el set 2
    if(j != s2.end()){
      //Vemos en qué multiset aparece más veces
      times= m1.count(*i) < m2.count(*i) ? m1.count(*i) : m2.count(*i);
      insert(result, *i, times);
    }
  }
  return result;
}

void show_elements(const multiset<int> &m){
  multiset<int>::iterator i;
  for(i = m.begin(); i != m.end(); i++)
    cout << " " << *i;
}

int main(){
  //m1={2,2,3,3} y m2={1,2,3,3,3,4}
  multiset<int> m1, m2;
  insert(m1, 2, 2);
  insert(m1, 3, 2);

  insert(m2, 1, 1);
  insert(m2, 2, 1);
  insert(m2, 3, 3);
  insert(m2, 4, 1);

  cout << "\nMultiset 1: ";
  show_elements(m1);

  cout << "\nMultiset 2: ";
  show_elements(m2);

  multiset<int> multi_inter= multi_interseccion(m1, m2);
  cout << "\nMultiset resultante de la multi-intersección: ";
  show_elements(multi_inter);



}
