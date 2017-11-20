/**
 * @doc Dados tres conjuntos de enteros:
 *Implementa una función para calcular el conjunto intersección de tres conjuntos.
 *Implementa una función para calcular el conjunto resultante de la unión diferencial de tres conjuntos A, B y C
 *formada por los elementos de A que no están ni en B ni en C unión
 *con los de B que no están ni en A ni en C unión con los de C que no están ni en A ni en B

 *Ejemplo:

 * A = {1, 2, 4, 5, 8}               B = {4, 5, 6, 9}                   C = {3, 4, 7, 8, 9}

 * La intersección (A,B,C) da como resultado el conjunto {4}
 * La unionDiferencial (A,B,C) da como resultado el conjunto {1, 2, 3, 6, 7}
 * @author Elena Merelo Molina
 * @date 20 noviembre 2017
* */
#include <iostream>
#include <set>
#include <ctime>
#include <cstdlib>
using namespace std;

/**
 * @brief Imprime un conjunto de tipo T sobre el flujo de salida
 * @param s: flujo de salida. Es MODIFICADO
 * @param l: el conjunto con los elementos a imprimi
 * */
template <class T>
ostream& operator<<(ostream &os, const set<T> &s){
  typename set<T>::iterator i;
  os << "{ ";
  for(i= s.begin();i!= s.end(); i++)
   os << " " << (*i);

 os <<" }";

   return os;
 }

/**
 * @brief Inicializar el generador de numero aleatorios
 *        Esta funcion debe ser llamada antes de usar rand
**/

void InicializarSemilla(){
  srand(time(0));
}

/**
 * @brief Genera numero enteros positivos aleatorios en el rango [min,max]
**/

int generaEntero(int min, int max){
    int tam= max -min+1;
    return ((rand()%tam)+min);
}
/**
 * @brief Dados tres conjuntos calcula el conjunto resultante de intersectarlos
 * @param s1 primer conjunto
 * @param s2 segundo conjunto
 * @param s3 tercer conjunto
 * @param f conjunto con los elementos que están en la intersección de los tres
 * */
template <class T>
void interseccion(const set<T> &s1, const set<T> &s2, const set<T> &s3, set<T> &f){
  typename set<T>:: iterator i;
  f.clear();

  for(i= s1.begin(); i!= s1.end(); i++){
    if(s2.count(*i) && s3.count(*i))
      f.insert(*i);
  }
}

/**
 * @brief Calcula el conjunto resultante de la unión diferencial de tres conjuntos A, B y C, formada por los elementos de A
 * que no están ni en B ni en C unión con los de B que no están ni en A ni en C unión con los de C que no están ni en A ni en B.
 * @param s1 primer conjunto
 * @param s2 segundo conjunto
 * @param s3 tercer conjunto
 * @param f conjunto con los elementos que están en la unión diferencial
 * */
template <class T>
void unionDiferencial(const set<T> &s1, const set<T> &s2, const set<T> &s3, set<T> &f){
  typename set<T>::iterator i;

  for(i= s1.begin(); i!= s1.end(); i++){
    if(!s2.count(*i) && !s3.count(*i))
      f.insert(*i);
  }

  for(i= s2.begin(); i!= s2.end(); i++){
    if(!s1.count(*i) && !s3.count(*i))
      f.insert(*i);
  }

  for(i= s3.begin(); i!= s3.end(); i++){
    if(!s1.count(*i) && !s2.count(*i))
      f.insert(*i);
  }
}

int main(){
  set<int> s1, s2, s3;

  int v1[]= {1, 2, 4, 5, 8};
  int v2[]= {4, 5, 6, 9};
  int v3[]= {3, 4, 7, 8, 9};

  set<int> a(v1, v1+5);
  set<int> b(v2, v2+4);
  set<int> c(v3, v3+5);


  InicializarSemilla();

  for (int i=0;i<10;i++){
    s1.insert(generaEntero(1,100)); //inserta un entero generado aleatoriamente en el rango 1-100
    s2.insert(generaEntero(1,100));
    s3.insert(generaEntero(1,100));
  }

  cout << "\nConjunto 1: " << s1 << "\nConjunto 2: " << s2 << "\nConjunto 3: " << s3;
  cout << "\nConjunto a: " << a << "\nConjunto b: " << b << "\nConjunto c: " << c;


  set <int> inter;
  interseccion(s1, s2, s3, inter);
  cout << "\nConjunto resultante de intersectar los conjuntos 1, 2 y 3: " << inter;

  set <int> inter_;
  interseccion(a, b, c, inter_);
  cout << "\nConjunto resultante de intersectar los conjuntos a, b y c: " << inter_;

  set <int> uniondif;
  unionDiferencial(s1, s2, s3, uniondif);
  cout << "\nConjunto resultante de hacer la unión diferencial de los conjuntos 1, 2 y 3: " << uniondif;

  set <int> uniondif_;
  unionDiferencial(a, b, c, uniondif_);
  cout << "\nConjunto resultante de hacer la unión diferencial de los conjuntos a, b y c: " << uniondif_;

}
