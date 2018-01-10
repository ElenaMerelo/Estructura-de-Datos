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
int ArbolBinario<T>::num_levels(){
  int num_nodos= size();
  double number= log2(num_nodos);
  double parte_entera, parte_decimal= modf(number, &parte_entera);

  return parte_entera;
}

template <class T>
void ArbolBinario<T>::etiquetas_entre(int n1, int n2, vector<T> &v){
  //Nos aseguramos de que los niveles están en el árbol
  int num_niveles= num_levels();
  assert(n1< n2 && n1 >= 0 && n2 >= 0 && n1 <= num_niveles && n2 <= num_niveles);

  //Recorro el árbol en in_order y almaceno las etiquetas en un vector auxiliar
  vector<T> aux;
  in_order(laraiz, aux);

  /*Hacemos ahora la operación inversa a la de obtener el número de niveles; por ser
  un árbol binario y ya lo hemos recorrido in order, para acceder al nodo en el
  nivel k hemos de ir a la posición 2^k -1, hasta la posición 2^k.*/
  typename vector<T>::iterator i= aux.begin(), j=aux.begin();
  advance(i, pow(2, n1) -1);
  advance(j, pow(2,n2)+1);
  while( i != j){
    v.push_back(*i);
    i++;
  }
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
