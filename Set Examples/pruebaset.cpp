/**
 * @file pruebaset.cpp
 * @doc compilación y enlazado: g++ pruebaset.cpp -o pruebaset, ejecución: ./pruebaset
 * @brief Implementamos algunos métodos usando otros ya implementados en la clase set para practicar con este container
 * @author Elena Merelo Molina
 * @date 15 Noviembre 2017
 *
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <set>

using namespace std;

/**
 * @brief Imprime un conjunto de tipo @c T sobre el flujo de salida
 * @param s flujo de salida. Es MODIFICADO
 * @param s conjunto con los elementos a imprimir
 */
 template <class T>
 ostream& operator<<(ostream &os, const set<T> &s){
   typename set<T>::iterator i;
   os << "{ ";
   for(i= s.begin();i!= s.end(); i++)
    os << (*i) << ", ";

  os <<" }";

    return os;
  }

 /**
  * @brief Inicializa el generador de numero aleatorios
  * Esta función debe ser llamada antes de usar rand()
  */
  void InicializarSemilla(){
    srand(time(0));
  }

  /**
   * @brief Genera número enteros positivos aleatorios en el rango [min,max]
   */
  int GeneraEntero(int min, int max){
      int tam = max - min + 1;
      return ((rand() % tam) + min);
  }

  /**
   * @brief Calcula la intersección de dos conjuntos
   * @param s1 Primer conjunto
   * @param s2 Segundo conjunto
   * @param f Conjunto resultante de la intersección de s1 y s2
   */
   template <class T>
   void interseccion(const set<T> &s1, const set<T> &s2, set<T> &f){
     f.clear();
     typename set<T>::iterator i, j;
     for(i= s1.begin(); i!= s1.end(); i++){
         if(s2.count(*i) > 0)
           f.insert(*i); //No hace falta comprobar si el elemento a introducir está en el conjunto final o no, ésto ya lo hace insert
     }
   }

   /**
    * @brief Devuelve si la intersección de dos conjuntos es vacía
    * @param s1 Primer conjunto
    * @param s2 Segundo conjunto
    * @return true si los conjuntos son disjuntos, false si no lo son, si hay elementos en su intersección
    */
    template <class T>
    bool sonDisjuntos(const set<T> &s1, const set<T> &s2){
      set<T> s3;
      interseccion(s1, s2, s3);
      if(s3.size() == 0)
        return true;

      else
        return false;
    }

    /**
     * @brief Devuelve si un elemento está en la intersección de otros dos
     * @param s1 Primer conjunto
     * @param s2 Segundo conjunto
     * @return true si el elemento está en ambos conjuntos, false en caso contrario.
     */
     template <class T>
     bool estaEnLaInterseccion(const set <T> &s1, const set <T> &s2, T elemento){
       set <T> s3;
       interseccion(s1, s2, s3);
       if(s3.count(elemento))
        return true;

      else
        return false;
     }

   /**
    * @brief Calcula la unión de dos conjuntos
    * @doc Realmente resulta un método muy simple ya que no hace falta ordenar los elementos, se ordenan por defecto de menor a mayor, y si está
    * repetido un elemento a insertar no lo mete en el conjunto.
    * @param s1 Primer conjunto
    * @param s2 Segundo conjunto
    * @param f Conjunto resultante de la unión de s1 y s2
    */
    template <class T>
    void union_(const set<T> &s1, const set<T> &s2, set<T> &f){
      typename set<T>::iterator i, j;
      f.clear();
      for(i= s1.begin(); i!= s1.end(); i++)
        f.insert(*i);

      for(j= s2.begin(); j!= s2.end(); j++)
        f.insert(*j);
    }

   /**
    * @brief Calcula los elementos de tres conjuntos que estén presentes en dos de ellos
    * @param s1 Primer conjunto
    * @param s2 Segundo conjunto
    * @param s3 Tercer conjunto
    * @param f Conjunto unión. Parámetro de salida
    */
    template <class T>
    void elementosEnDosDeLosConjuntos(const set<T> &s1, const set<T> &s2, const set<T> &s3, set<T> &f){
      typename set<T>:: iterator i;
      f.clear();
      //Si un elemento del conjunto 1 está en el conjunto 2 y no en el tres o viceversa lo insertamos en el conjunto final, ídem con s2 y s3
      for(i= s1.begin(); i!= s1.end(); i++){
        if((s2.count(*i) && !s3.count(*i)) || (!s2.count(*i) && s3.count(*i)))
          f.insert(*i);
      }

      for(i= s2.begin(); i!= s2.end(); i++){
        if((s1.count(*i) && !s3.count(*i)) || (!s1.count(*i) && s3.count(*i)))
          f.insert(*i);
      }

      for(i= s3.begin(); i!= s3.end(); i++){
        if((s1.count(*i) && !s2.count(*i)) || (!s1.count(*i) && s2.count(*i)))
          f.insert(*i);
      }
    }

    /**
     * @brief Calcula los elementos de tres conjuntos que estén presentes en los tres
     * @param s1 Primer conjunto
     * @param s2 Segundo conjunto
     * @param s3 Tercer conjunto
     * @param f Conjunto unión. Parámetro de salida
     */
     template <class T>
     void elementosEnTresDeLosConjuntos(const set<T> &s1, const set <T> &s2, const set <T> &s3, set <T> &f){
       f.clear();
       typename set <T>::iterator i;
       for(i= s1.begin(); i!= s1.end(); i++){
         if(estaEnLaInterseccion(s2,s3, *i))
          f.insert(*i);
       }
     }

     /**
      * @brief Acceso al elemento n de un set
      * @return Devuelve una referencia al elemento que se quiere consultar, si no existe el índice
      * al que se quiere acceder se aborta el programa
      * @param n posición de la que se quiere obtener el elemento
      * @param s set del que se quiere obtener el elemento
      */
      template <class T>
      T getElement(const set<T> &s, int n){
        assert(n>= 0 && n< s.size());
        typename set<T>::iterator it= s.begin();  //Me posiciono en el primer elemento del conjunto
        advance(it, n); //Avanzo, muevo el iterador para posicionarme en la posición deseada
        return *it; //Devuelvo el elemento al que apunta el iterador, el que está en la posición n
      }

int main(){
  set<int> s1, s2, s3;

  for(int i= 0; i< 20; i++){
    s1.insert(GeneraEntero(1,50));
    s2.insert(GeneraEntero(1,50));
    s3.insert(GeneraEntero(1,50));
  }

  cout << "Conjunto 1: " << s1 << "\nConjunto 2: " << s2 << "\nConjunto 3: " << s3;
  cout << "El décimo elemento del conjunto 1(empezando a contar desde cero) es: " << getElement(s1, 10);

  //Probamos que funciona la unión de conjuntos
  set<int> u;
  union_(s1, s2, u);
  cout << "\nConjunto resultante de unir el conjunto 1 y el 3: " << u;
  //Probamos que funciona la intersección de conjuntos
  set<int> s4;
  interseccion(s2, s3, s4);
  cout << "\nConjunto resultante  de instersectar el conjunto 2 y 3: " << s4;

  if(sonDisjuntos(s1, s2))
    cout << "El conjunto 1 y el 2 son disjuntos";
  else{
    set<int> s5;
    interseccion(s1, s2, s5);
    cout << "\nLos conjuntos 1 y2 tienen los elementos " << s5 << " en común";
  }

  set<int> dos;
  elementosEnDosDeLosConjuntos(s1, s2, s3, dos);
  cout << "\nLos elementos que están en dos de los conjuntos son: " << dos;

  set<int> tres;
  elementosEnTresDeLosConjuntos(s1, s2, s3, tres);
  cout << "\nLos elementos que están en tres de los conjuntos son: " << tres;

}
