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
int ArbolBinario<Tbase>::contar(Nodo n) const{
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
istream& operator>>(istream& flujo, ArbolBinario<Tbase>& t){
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

template <class T>
bool ArbolBinario<T>::es_inferior(ArbolBinario<T> &ab){
  int num_nodos= size();
  assert(num_nodos == ab.size());
  vector<T> v1, v2;
  in_order(laraiz, v1);
  in_order(ab.raiz(), v2);
  typename vector<T>::iterator i= v1.begin(), j= v2.begin();
  while(i != v1.end()){
    if(*i > *j)
      return false;
    i++;
    j++;
  }
  return true;
}
