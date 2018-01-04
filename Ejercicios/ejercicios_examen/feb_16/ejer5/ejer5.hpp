#ifndef ArbolBinario_hpp
#define ArbolBinario_hpp

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

template <class Tbase>
class ArbolBinario {
private:
  struct nodo{
    Tbase etiqueta;
    struct nodo* izqda;
    struct nodo* drcha;
    struct nodo* padre;
  };
  struct nodo* laraiz;

public:
  typedef struct nodo* Nodo;

  static const Nodo nodonulo;

  /**
   @brief Constructor por defecto

   Reserva los recursos necesarios e inicializa el árbol como un árbol
   vacío. O(1)
   */
  ArbolBinario();

  /**
   @brief Constructor de raíz
   @param e etiqueta de la raíz del nuevo árbol

   Reserva los recursos necesarios e inicializa el árbol con un único
   nodo raíz que tiene etiqueta e. O(1)
   */
  ArbolBinario(const Tbase & e);

  /**
   @brief Constructor de copia
   @param t árbol a copiar

   Reserva los recursos necesarios e inicializa el árbol duplicando el
   contenido de t. O(n), con n el número de nodos de t
   */
  ArbolBinario(const ArbolBinario<Tbase> & t);

  /**
   @brief Destructor

   Libera los recursos del árbol. O(n), con n el número de nodos del árbol
   */
  ~ArbolBinario();

  /**
   @brief Operador de asignación
   @param t árbol a copiar

   Asigna el valor del árbol duplicando el contenido de t en el árbol
   original. O(n), con n el número de nodos de t
   */
  ArbolBinario<Tbase> & operator=(const ArbolBinario<Tbase> & t);

  /**
   @brief Raíz del árbol

   Devuelve el nodo raíz, que será nodonulo si el árbol está vacío. O(1)
   */
  Nodo raiz() const;

  /**
   @brief Hijo izquierdo
   @param n nodo del que se quiere obtener el hijo izquierdo. n no es nodonulo
   @return Nodo hijo izquierdo

   Devuelve el nodo hijo izquierdo de n, que será nodonulo si n no tiene
   hijo izquierdo. O(1)
   */
  Nodo izquierda(const Nodo n) const;

  /**
   @brief Hijo derecho
   @param n nodo del que se quiere obtener el hijo derecho. n no es nodonulo
   @return Nodo hijo derecho

   Devuelve el nodo hijo derecho de n, que será nodonulo si n no tiene
   hijo derecho. O(1)
   */
  Nodo derecha(const Nodo n) const;

  /**
   @brief Nodo padre
   @param n nodo del que se quiere obtener el padre. n no es nodonulo
   @return Nodo padre

   Devuelve el nodo padre de n, que será nodonulo si n es la raíz del
   árbol. O(1)
   */
  Nodo padre(const Nodo n) const;

  /**
   @brief Etiqueta de un nodo
   @param n nodo del que se quiere obtener la etiqueta. n no es nodonulo
   @return Referencia a la etiqueta del nodo

   Devuelve una referencia a la etiqueta del nodo n. Al devolverse una
   referencia, podemos consultar o modificar su valor. O(1)
   */
  Tbase & etiqueta(const Nodo n);

  /**
   @brief Etiqueta de un nodo
   @param n nodo del que se quiere obtener la etiqueta. n no es nodonulo
   @return Referencia constante a la etiqueta del nodo

   Devuelve una referencia constante a la etiqueta del nodo n. Al devolverse una
   referencia constante, sólo podemos consultar su valor, no modificarlo. O(1)
   */
  const Tbase & etiqueta(const Nodo n) const;

  /**
   @brief Borra todos los nodos

   Borra todos los elementos del árbol. Deja el árbol vacío. O(n), con n
   el número de nodos del árbol
   */
  void clear();

  /**
   @brief Número de nodos
   @return Número de elementos del árbol

   O(n), con n el número de nodos del árbol. @see ArbolBinario<Tbase>::contar()
   */
  int size() const;

  /**
   @brief Comprueba si es el árbol vacío
   @return devuelve true si el árbol no tiene nodos y false en caso contrario

   O(1)
   */
  bool vacio() const;

  /**
   @brief Operador de entrada
   @param flujo stream desde el que se lee
   @param t árbol en el que leer
   @return Devuelve una referencia al flujo para permitir el encadenamiento
   del operador

   Lee un árbol de flujo y lo almacena en t. El formato de entrada se
   puede consultar en la función de salida. @see ArbolBinario<Tbase>::operator<<
   */
  template <class T>
  friend istream& operator>>(istream& flujo, ArbolBinario<T> & t);

  /**
   @brief Operador de salida
   @param flujo stream en el que se escribe
   @param t árbol que escribir
   @return Devuelve una referencia al flujo para permitir el encadenamiento
   del operador

   Escribe un árbol en flujo siguiendo un recorrido en preorden. Si un
   nodo es nulo se escribe "x". Si el nodo no es nulo se escribe "n" seguido
   de un espacio en blanco y la etiqueta del nodo.
   @see ArbolBinario<Tbase>::escribe_arbol
   */
  template <class T>
  friend ostream& operator<<(ostream& flujo, ArbolBinario<T> & t);

  /**
   @brief Recorre un árbol binario in order
   @param n nodo a partir del cual se recorre
   @param v vector en el que se almacena el recorrido
   */
  void in_order(Nodo n, vector<Tbase> &v);

  /**
   @brief Compara los recorridos in order de dos árboles binarios
   @param a, b árboles a comparar
   @return true si tienen el mismo recorrido, false sino
   */
  bool mismo_recorrido_in_order(const ArbolBinario<Tbase> &a, const ArbolBinario<Tbase> &b);

  /**
   @brief Comprueba si dos árboles binarios son simétricos
   @param aárbol a comparar con el de la clase
   @return true si son simétricos, false si no lo son
   */
  bool es_simetrico_a(const ArbolBinario<Tbase> &a);

  /**
   @brief Inserta un nuevo nodo en el árbol
   @param elemento valor a insertar
   */
  void insertar(Tbase elemento);

private:
  /**
   @brief Destruye el subárbol
   @param n nodo a destruir, junto con sus descendientes

   Libera los recursos que ocupan n y sus descendientes
   */
  void destruir(Nodo n);

  /**
   @brief Copia un subárbol
   @param dest referencia al nodo del que se cuelga la copia
   @param orig puntero a la raíz del subárbol a copiar

   Hace una copia del subárbol que cuelga de orig en el puntero dest
   */
  void copiar(Nodo& dest, Nodo orig);

  /**
   @brief Cuenta el número de nodos
   @param n nodo del que cuelga el subárbol que se desea contabilizar

   Cuenta cuántos nodos cuelgan de n, incluido el propio n
   */
  int contar(Nodo n);

  /**
   @brief Escribe un subárbol
   @param flujo stream de salida en el que escribir
   @param n nodo del que cuelga el subárbol a escribir

   Escribe los nodos del subárbol en el flujo de salida siguiendo un
   recorrido en preorden. Si un nodo es nulo se escribe "x". Si el nodo no
   es nulo se escribe "n" seguido de un espacio en blanco y la etiqueta del nodo
   */
  void escribe_arbol(ostream& flujo, Nodo n) const;
  /**
   @brief Lee un subárbol
   @param flujo stream de entrada desde el que leer
   @param n referencia al nodo que contendrá el subárbol leído

   Lee de la entrada el contenido de un árbol en el formato descrito en
   la función de escritura. @see ArbolBinario<Tbase>::escribe_arbol
   */
  void lee_arbol(istream& flujo, Nodo& n);

  /**
   @brief Inserta un elemento en un nodo
   @param elemento a insertar en en nodo n
   */
   void insertar(Tbase elemento, Nodo n);

};

/////////////////////////////////////
/////////////////////////////////////
//   IMPLEMENTACIÓN
/////////////////////////////////////
/////////////////////////////////////

//FUNCIONES PRIVADAS

template <class Tbase>
void ArbolBinario<Tbase>::destruir(Nodo n){
  if (n!=0){
    destruir(n->izqda);
    destruir(n->drcha);
    delete n;
  }
}

template <class Tbase>
int ArbolBinario<Tbase>::contar(Nodo n){
  if (n==0)
    return 0;
  else return 1+ contar(n->izqda) + contar(n->drcha);
}

template <class Tbase>
void ArbolBinario<Tbase>::copiar(Nodo &dest, Nodo orig){
  if (orig==0)
    dest = 0;
  else{
    dest = new nodo;
    dest->etiqueta = orig->etiqueta;
    copiar(dest->izqda, orig->izqda);
    copiar(dest->drcha, orig->drcha);
    if (dest->izqda!=0)
      dest->izqda->padre = dest;
    if (dest->drcha!=0)
      dest->drcha->padre = dest;
  }
}

template <class Tbase>
void ArbolBinario<Tbase>::escribe_arbol(ostream& flujo, Nodo n) const{
  if(n==0)
    flujo << "x ";
  else{
    flujo << "n " << n->etiqueta << " ";
    escribe_arbol(flujo, n->izqda);
    escribe_arbol(flujo, n->drcha);
  }
}

template <class Tbase>
void ArbolBinario<Tbase>::lee_arbol(istream &flujo, Nodo &n){
  char c;
  flujo >> c;
  if (c=='n'){
    n = new nodo;
    flujo >> n->etiqueta;
    lee_arbol(flujo, n->izqda);
    lee_arbol(flujo, n->drcha);
    if(n->izqda!=0)
      n->izqda->padre = n;
    if(n->drcha!=0)
      n->drcha->padre = n;
  }
  else n = 0;
}

//FUNCIONES PÚBLICAS

template <class Tbase>
ArbolBinario<Tbase>::ArbolBinario(){
  laraiz = 0;
}

template <class Tbase>
ArbolBinario<Tbase>::ArbolBinario(const Tbase & e){
  laraiz = new nodo;
  laraiz->etiqueta = e;
  laraiz->padre = laraiz->izqda = laraiz->drcha = 0;
}

template <class Tbase>
ArbolBinario<Tbase>::ArbolBinario(const ArbolBinario<Tbase>& t){
  copiar(laraiz,t.laraiz);
  if (laraiz!=0)
    laraiz->padre = 0;
}

template <class Tbase>
ArbolBinario<Tbase>::~ArbolBinario(){
  destruir(laraiz);
}

template <class Tbase>
ArbolBinario<Tbase>& ArbolBinario<Tbase>::operator=(const ArbolBinario<Tbase>& t){
  if(this!=&t){
    destruir(laraiz);
    copiar(laraiz,t.laraiz);
    if(laraiz!=0)
      laraiz->padre = 0;
  }
  return *this;
}

template <class Tbase>
typename ArbolBinario<Tbase>::Nodo ArbolBinario<Tbase>::raiz() const{
  return laraiz;
}

template <class Tbase>
typename ArbolBinario<Tbase>::Nodo ArbolBinario<Tbase>::izquierda(const Nodo n) const{
  assert(n!=0);
  return n->izqda;
}

template <class Tbase>
typename ArbolBinario<Tbase>::Nodo ArbolBinario<Tbase>::derecha(const Nodo n) const{
  assert(n!=0);
  return n->drcha;
}

template <class Tbase>
typename ArbolBinario<Tbase>::Nodo ArbolBinario<Tbase>::padre(const Nodo n) const{
  assert(n!=0);
  return n->padre;
}

template <class Tbase>
Tbase& ArbolBinario<Tbase>::etiqueta(const Nodo n) {
  assert(n!=0);
  return n->etiqueta;
}

template <class Tbase>
const Tbase& ArbolBinario<Tbase>::etiqueta(const Nodo n) const{
  assert(n!=0);
  return n->etiqueta;
}

template <class Tbase>
void ArbolBinario<Tbase>::clear(){
  destruir(laraiz);
  laraiz = 0;
}

template <class Tbase>
int ArbolBinario<Tbase>::size() const{
  return contar(laraiz);
}

template <class Tbase>
bool ArbolBinario<Tbase>::vacio() const{
  return laraiz==0;
}

template <class Tbase>
istream & operator>>(istream& flujo, ArbolBinario<Tbase>& t){
  t.clear();
  t.lee_arbol(flujo, t.laraiz);
  return flujo;
}

template <class Tbase>
ostream& operator<<(ostream& flujo, const ArbolBinario<Tbase>& t){
  t.escribe_arbol(flujo, t.laraiz);
  return flujo;
}

template <class Tbase>
const typename ArbolBinario<Tbase>::Nodo ArbolBinario<Tbase>::nodonulo = 0;

/*--------------------------RESOLUCIÓN DEL EJERCICIO---------------------------------*/
//Devuelve un vector con el recorrido in-order del árbol
template <class Tbase>
void ArbolBinario<Tbase>::in_order(Nodo n, vector<Tbase> &v){
  //Fin de la recursión si llegamos a un nodo nulo
  if(n== 0)
    return;
  in_order(n->izqda, v);
  v.push_back(n->etiqueta);
  in_order(n->drcha, v);
}

//Compara los vectores con los recorridos in-order de dos árboles binarios
template <class Tbase>
bool ArbolBinario<Tbase>::mismo_recorrido_in_order(const ArbolBinario<Tbase> &a, const ArbolBinario<Tbase> &b){
    if(a.vacio() && b.vacio())
      return true;
    else if(a.size() != b.size())
      return false;
    else{
      vector<Tbase> v1, v2;
      in_order(a.laraiz, v1);
      in_order(b.laraiz, v2);

      typename vector<Tbase>::iterator i= v1.begin(), j= v2.begin();
      while(i != v2.end() && j != v1.end()){
        if(*i != *j)
          return false;
        i++;
        j++;
      }
      return true;
    }
}

template <class Tbase>
bool ArbolBinario<Tbase>::es_simetrico_a(const ArbolBinario<Tbase> &a){
    return mismo_recorrido_in_order(a,*this);
}

template <class Tbase>
void ArbolBinario<Tbase>::insertar(Tbase elemento){
  if(laraiz != NULL)
    insertar(elemento, laraiz);
  else{
    laraiz= new nodo;
    laraiz->etiqueta= elemento;
    laraiz->izqda= NULL;
    laraiz->drcha= NULL;
  }
}

template <class Tbase>
void ArbolBinario<Tbase>::insertar(Tbase elemento, Nodo n){
  if(elemento< n->etiqueta){
    if(n->izqda != NULL)
     insertar(elemento, n->izqda);
    else{
      n->izqda= new nodo;
      n->izqda->etiqueta= elemento;
      n->izqda->izqda= NULL;
      n->izqda->drcha= NULL;
    }
  }
  else if(elemento>=n->etiqueta){
    if(n->drcha != NULL)
      insertar(elemento, n->drcha);
    else{
      n->drcha= new nodo;
      n->drcha->etiqueta= elemento;
      n->drcha->izqda= NULL;
      n->drcha->drcha= NULL;
    }
  }
}

#endif /* ArbolBinario_hpp */
