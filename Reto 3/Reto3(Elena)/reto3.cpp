//Implementar clase pila a partir de la clase lista
using namespace std;

//La función list::back() devuelve una referencia al último elemento de la lista.
template <class T>
T& stack<T>::top(){
  return data.back();
}

template <class T>
const T& stack<T>::top() const{
  return data.back;
}

/*La función list::push_back(const T& value) añade un nuevo elemento al final de la lista.
El contenido de value es copiado(o movido) al nuevo elemento.*/
template <class T>
void stack<T>::push(const T& value){
  data.push_back(value);
}

// La función list::pop_back elimina el último elemento de la lista.
template <class T>
void stack<T>::pop(){
  data.pop_back();
}

/* La función list::swap(list& x) intercambia el contenido del container
por el de x, que es otra lista del mismo tipo. Los tamaños pueden ser diferentes.
Después de la llamada a esta función, los elementos en el container son los que
había en x antes de la llamada, y los de x son los elementos de *this. Solo funciona a partir
de c++ 11*/
/*template <class T>
void swap(stack<T>& x){
  data.swap(x.data);
}*/
