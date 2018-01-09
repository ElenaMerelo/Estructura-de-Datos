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
/*Basándonos en que es un árbol binario, si éste está completo, tendrá 2^k nodos,
luego si queremos obtener los niveles del árbol hemos de hacer la operación
inversa, el logaritmo en base 2 del número de nodos que tengamos. Si la operación
es exacta es que el árbol está completo, sino redondeamos para que nos salga el
número exacto de niveles. Sumamos dos al final para que el nivel de la raíz sea 1.*/
double ArbolBinario<T>::num_levels(){
  int size= size();
  if(size == 0)
    return 0.0;

  double num= log2(size);
  double parte_entera, decimales= modf(num, &parte_entera);

  parte_entera += 2;
  return parte_entera;
}

template <class T>
Nodo get_nodo(T etiqueta){
  //Recorro el árbol por niveles y almaceno las etiquetas en v
  vector<T> v;
  in_order(laraiz, v);

  //Empiezo a buscar desde la raíz y me muevo por los nodos hijos
  Nodo n_izqda= new nodo;
  n_izqda= laraiz;

  Nodo n_drcha= new nodo;
  n_drcha= laraiz;
  vector<T>::iterator i= v.begin();

  //Buscamos por los hijos izquierda y derecha a la vez
  while(n_izqda != NULL && n_drcha != NULL){
    if(*i == n_izqda->etiqueta)
      return n_izqda;

    if(*i == n_drcha->etiqueta)
      return n_drcha;
    i++;
    n_izqda= n->izqda;
    n_drcha= n->drcha;
  }
  //Si termina el bucle y no ha coincidido ningún nodo con la etiqueta pasada como parámetro devolvemos 0
  return NULL;
}

template <class T>
Nodo ArbolBinario<T>::at(int position){
  assert(position > 0 && position < size());
  //Recorro el árbol por niveles y almaceno las etiquetas en v
  vector<T> v;
  in_order(laraiz, v);

  vector<T>::iterator i= v.begin();
  advance(i, position);
  return get_nodo(*i);
}

//Versión no recursiva
template <class T>
int ArbolBinario<T>::trayectoria(int position){
  //Nos aseguramos de que el nodo esté en el árbol
  assert(position > 0 && position < size());
  int trayectoria= 0;
  Nodo n= new nodo;
  n= at(position);
  
  double level= num_levels();
  while(n->padre != NULL){  //Otra opción sería haber puesto while(level != 0)
    trayectoria += n->etiqueta *level;
    n= n->padre;
    level--;
  }
  return trayectoria;
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
