#include <iostream>
#include <ejer2.h>
#include <vector>

using namespace std;

int main(){
  //Declaramos un vector y a partir de él creamos la matriz bilineal simétrica de prueba
  int my_ints[]= {1,2,3,4,5};
  vector<int> v(my_ints, my_ints + sizeof(my_ints)/sizeof(int));

  //Creamos la matriz a partir del vector v
  matriz_bilineal_simetrica<int> m(v);

  //Mostramos la matriz
  cout << m;


}
