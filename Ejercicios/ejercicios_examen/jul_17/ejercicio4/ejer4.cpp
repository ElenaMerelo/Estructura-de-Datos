template <class T>
queue<T>::queue(stack<T> &s){
  stack<T> aux;
  while(!s.empty()){
    s2.push(s.top());  //En s2 están los elementos en orden inverso
    aux.push(s.top());
    s.pop();
  }

  //Restablecemos la pila original a la vez que metemos los elementos en orden normal en s1
  while(!aux.empty()){
    s1.push(aux.top());
    s.push(aux.top());
    aux.pop();
  }
}

template <class T>
queue<T>::queue(const queue<T> &q){
  *this= q;
}

template <class T>
queue<T>& queue<T>::operator=(const queue<T> &q){
  s1= q.s1;
  s2= q.s2;

  stack<T> aux1= q.s1;
  stack<T> aux2= q.s2;

  //Metemos los elementos en la pila auxiliar
  while(!aux1.empty()){
    s2.push(aux1.top());
    aux1.pop();
  }

  while(!aux2.empty()){
    s1.push(aux2.top());
    aux2.pop();
  }

  return *this;
}

template <class T>
bool queue<T>::empty() const{
  return s1.empty();
}

template <class T>
int queue<T>::size() const{
  return s1.size();
}

template <class T>
T& queue<T>::front(){
  return s2.top();
}

template <class T>
T& queue<T>::back(){
  return s1.top();
}

template <class T>
void queue<T>::push(T element){
  s1.push(element);

  stack<T> aux;
  //Metemos el elemento en la primera posición de s2
  while(!s2.empty()){
    aux.push(s2.top());
    s2.pop();
  }
  aux.push(element);

  while(!aux.empty()){
    s2.push(aux.top());
    aux.pop();
  }
}

template <class T>
void queue<T>::pop(){
  s2.pop();

  stack<T> aux;
  //Borramos ahora el primer elemento de s1
  while(!s1.empty()){
    aux.push(s1.top());
    s1.pop();
  }
  aux.pop();

  while(!aux.empty()){
    s1.push(aux.top());
    aux.pop();
  }
}

template <class T>
void queue<T>::show_elements(){
  stack<T> aux;

  while(!s1.empty()){
    aux.push(s1.top());
    s1.pop();
  }

  while(!aux.empty()){
    cout << aux.top() << " ";
    s1.push(aux.top());
    aux.pop();
  }
}
