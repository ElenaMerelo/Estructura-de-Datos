//FUNCIONES PRIVADAS

template <class T>
void ArbolBinario<T>::destruir(Nodo n){
  if (n!=0){
    destruir(n->izqda);
    destruir(n->drcha);
    delete n;
  }
}

template <class T>
int ArbolBinario<T>::contar(Nodo n) const{
  if (n==0)
    return 0;
  else return 1+ contar(n->izqda) + contar(n->drcha);
}

template <class T>
void ArbolBinario<T>::copiar(Nodo &dest, Nodo orig){
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

template <class T>
void ArbolBinario<T>::escribe_arbol(ostream& flujo, Nodo n) const{
  if(n==0)
    flujo << "x ";
  else{
    flujo << "n " << n->etiqueta << " ";
    escribe_arbol(flujo, n->izqda);
    escribe_arbol(flujo, n->drcha);
  }
}

template <class T>
void ArbolBinario<T>::lee_arbol(istream &flujo, Nodo &n){
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

template <class T>
ArbolBinario<T>::ArbolBinario(){
  laraiz = 0;
}

template <class T>
ArbolBinario<T>::ArbolBinario(const T & e){
  laraiz = new nodo;
  laraiz->etiqueta = e;
  laraiz->padre = laraiz->izqda = laraiz->drcha = 0;
}

template <class T>
ArbolBinario<T>::ArbolBinario(const ArbolBinario<T>& t){
  copiar(laraiz,t.laraiz);
  if (laraiz!=0)
    laraiz->padre = 0;
}

template <class T>
ArbolBinario<T>::~ArbolBinario(){
  destruir(laraiz);
}

template <class T>
ArbolBinario<T>& ArbolBinario<T>::operator=(const ArbolBinario<T>& t){
  if(this != &t){
    destruir(laraiz);
    copiar(laraiz,t.laraiz);
    if(laraiz!=0)
      laraiz->padre = 0;
  }
  return *this;
}

template <class T>
typename ArbolBinario<T>::Nodo ArbolBinario<T>::raiz() const{
  return laraiz;
}

template <class T>
typename ArbolBinario<T>::Nodo ArbolBinario<T>::izquierda(const Nodo n) const{
  assert(n!=0);
  return n->izqda;
}

template <class T>
typename ArbolBinario<T>::Nodo ArbolBinario<T>::derecha(const Nodo n) const{
  assert(n!=0);
  return n->drcha;
}

template <class T>
typename ArbolBinario<T>::Nodo ArbolBinario<T>::padre(const Nodo n) const{
  assert(n!=0);
  return n->padre;
}

template <class T>
T& ArbolBinario<T>::etiqueta(const Nodo n) {
  assert(n!=0);
  return n->etiqueta;
}

template <class T>
const T& ArbolBinario<T>::etiqueta(const Nodo n) const{
  assert(n!=0);
  return n->etiqueta;
}

template <class T>
void ArbolBinario<T>::clear(){
  destruir(laraiz);
  laraiz = 0;
}

template <class T>
int ArbolBinario<T>::size() const{
  return contar(laraiz);
}

template <class T>
bool ArbolBinario<T>::vacio() const{
  return laraiz==0;
}

template <class T>
istream& operator>>(istream& flujo, ArbolBinario<T>& t){
  t.clear();
  t.lee_arbol(flujo, t.laraiz);
  return flujo;
}

template <class T>
ostream& operator<<(ostream& flujo, const ArbolBinario<T>& t){
  t.escribe_arbol(flujo, t.laraiz);
  return flujo;
}

template <class T>
const typename ArbolBinario<T>::Nodo ArbolBinario<T>::nodonulo = 0;

/*--------------------------RESOLUCIÓN DEL EJERCICIO---------------------------------*/
template <class T>
void ArbolBinario<T>::insert(T elemento){
  if(laraiz != NULL)
    insert(elemento, laraiz);
  else{
    laraiz= new nodo;
    laraiz->etiqueta= elemento;
    laraiz->izqda= NULL;
    laraiz->drcha= NULL;
  }
}

template <class T>
void ArbolBinario<T>::insert(T elemento, Nodo n){
  if(elemento< n->etiqueta){
    if(n->izqda != NULL)
     insert(elemento, n->izqda);
    else{
      n->izqda= new nodo;
      n->izqda->etiqueta= elemento;
      n->izqda->izqda= NULL;
      n->izqda->drcha= NULL;
    }
  }
  else if(elemento>=n->etiqueta){
    if(n->drcha != NULL)
      insert(elemento, n->drcha);
    else{
      n->drcha= new nodo;
      n->drcha->etiqueta= elemento;
      n->drcha->izqda= NULL;
      n->drcha->drcha= NULL;
    }
  }
}

template <class T>
int ArbolBinario<T>::number_of_paths(Nodo n, int k){
  /*Vamos recorriendo todos los nodos del árbol y obteniendo la suma de las
  etiquetas a partir de él. Si ambas sumas son 0 será porque no tienen más hijos, no hay más caminos
  por recorrer y por lo tanto habremos acabado.*/
  if(n == 0)
    return 0;
  else{
    if(suma_camino_drcha(n) == k)
      return 1 + number_of_paths(n->izqda, k) + number_of_paths(n->drcha, k);
    if(suma_camino_izqda(n) == k)
      return 1 + number_of_paths(n->izqda, k) + number_of_paths(n->drcha, k);
    else
      return 0 + number_of_paths(n->izqda, k) + number_of_paths(n->drcha, k);
  }
}

/*
template <class T>
int ArbolBinario<T>::suma_k(Nodo n, int k){
  if(n == 0)
    return 0;
  else{
    if(suma_camino_izqda(n) == k || suma_camino_drcha(n) == k)
      sum++;
    sum += suma_k(n->izqda, k);
    sum += suma_k(n->drcha, k);
    return sum;
  }
}*/


template <class T>
int ArbolBinario<T>::number_of_paths(int k){
  return number_of_paths(laraiz, k);
}

template <class T>
int ArbolBinario<T>::suma_camino_izqda(Nodo n){
  int sum= 0;
  while(n != 0){
    sum += n->etiqueta;
    n= n->izqda;
  }
  return sum;
}

template <class T>
int ArbolBinario<T>::suma_camino_drcha(Nodo n){
  int sum= 0;
  while(n != 0){
    sum += n->etiqueta;
    n= n->drcha;
  }
  return sum;
}
