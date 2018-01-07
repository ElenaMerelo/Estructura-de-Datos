template <class T>
APOmin<T>::APOmin(int size){
  vector<T> aux(size);
  data= aux;
}

template <class T>
APOmin<T>::APOmin(const APOmin<T> &a){
  data= a.data;
}

template <class T>
APOmin<T>& APOmin<T>::operator=(const APOmin<T> &a){
  data= a.data;
}

template <class T>
/*Basándonos en que un árbol parcialmente ordenado es un árbol binario, si éste está
completo, tendrá 2^k nodos, luego si queremos obtener los niveles del árbol hemos
de hacer la operación inversa, esto es, el logaritmo en base 2 del número de nodos
que tengamos. Si la operación es exacta es que el árbol está completo, sino redondeamos
para que nos salga el número exacto de niveles.*/
double APOmin<T>::num_levels(){
  double num= log2(data.size());
  double parte_entera;
  double decimales= modf(num, &parte_entera);
  if(decimales != 0)
    parte_entera++;

  return parte_entera;
}

template <class T>
//Al estar ordenados los elementos de menor a mayor, buscamos únicamente en el último nivel
T& APOmin<T>::maximo(){
  typename vector<T>::iterator i= data.begin();
  T max= *i;

  //Movemos i al último nivel
  advance(i,pow(2,num_levels()-1)-1);
  while(i != data.end()){
    if(*i > max)
      max= *i;
  }
  return max;
}

template <class T>
int APOmin<T>::size(){
  return data.size();
}

template <class T>
void APOmin<T>::clear(){
  data.clear();
}

template <class T>
void APOmin<T>::swap(T &a, T &b){
  T aux= a;
  a= b;
  b= aux;
}

template <class T>
void APOmin<T>::insert(const T& element){
  typename vector<T>::iterator i= data.begin();

  while(*i < element)
    i++;

  i= data.insert(i, element);
}


template <class T>
void APOmin<T>::show_elements(){
  typename vector<T>::iterator i;

  cout << "\n";
  for(i= data.begin(); i != data.end(); i++)
    cout << " " << *i;
}
