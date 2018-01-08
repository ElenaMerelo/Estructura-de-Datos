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
APOmin<T>::APOmin(vector<T> v){
  insert(v);
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
  if(data.size() == 0)
    return 0.0;

  double num= log2(data.size());
  double parte_entera, decimales= modf(num, &parte_entera);


  return parte_entera++;
}

template <class T>
//Forma con iteradores, más eficiente
//Al estar ordenados los elementos de menor a mayor, buscamos únicamente en el último nivel
T APOmin<T>::maximo(){
  typename vector<T>::iterator i= data.begin();
  T max= *i;

  //Movemos i al último nivel
  advance(i,pow(2,num_levels()-1)-2);
  while(i != data.end()){
    if(*i > max)
      max= *i;
    i++;
  }

  return max;
}

/*FORMA FÁCIL
template <class T>
T APOmin<T>::maximo(){
  T max= data[0];
  for(int i= 1; i< data.size(); i++)
    if(data[i] > max)
      max= data[i];

  return max;
}*/

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
  data.push_back(element);
  int i= data.size() -1;

  while((data[i]< data[(i-1)/2]) && i>0){
    swap(data[i], data[(i-1)/2]);
    i=(i-1)/2;
  }
}

template <class T>
void APOmin<T>::insert(vector<T> v){
  typename vector<T>::iterator i;

  for(i= v.begin(); i != v.end(); i++)
    insert(*i);
}

template <class T>
void APOmin<T>::show_elements(){
  typename vector<T>::iterator i= data.begin();

  while(i != data.end()){
    cout << " " << *i;
    i++;
  }
}
