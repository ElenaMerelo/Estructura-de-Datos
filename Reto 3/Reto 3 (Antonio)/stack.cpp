/**
  * @file stack.cpp
  * @brief Implementación del TDA Pila a partir de list<>.
  *
  */
/* ____________________________________________________________ */

template<class T>
T& stack<T>::top(){
    assert(!empty()); //Comprobamos si está vacía.
    return data.back(); //Devolvemos el último elemento de la lista.
}

/* ____________________________________________________________ */

template<class T>
const T& stack<T>::top() const {
    assert(!empty());   //Comprobamos si está vacía.
    return data.back(); //Devolvemos el último elemento de la lista.
}

/* ____________________________________________________________ */

template<class T>
void stack<T>::push(const T& elem){
    data.push_back(elem);   //Añadimos un 'elem' al final de la lista.
}

/* ____________________________________________________________ */

template<class T>
void stack<T>::pop(){
    data.pop_back();    //Borramos el último elemento de la lista.
}

/* ____________________________________________________________ */
