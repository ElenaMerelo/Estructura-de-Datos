/**
  * @file vector_dinamico.cpp
  * @brief Implementación del TDA VectorDinámico
  *
  */
#include <cassert>

/* _________________________________________________________________________ */

template <class T>
void Vector_Dinamico<T>::copy(const Vector_Dinamico<T> &other){
  num_elements= other.num_elements;
  if(num_elements> 0){
    data= new T [num_elements];
    for(int i= 0; i< num_elements; i++)
      data[i]= other.data[i];
  }
  else
    data=0;
}
/* _________________________________________________________________________ */

template <class T>
void Vector_Dinamico<T>::freeMemory(){
  delete [] data;
}

/* _________________________________________________________________________ */
template <class T>
Vector_Dinamico<T>::Vector_Dinamico(int n){
  assert(n>=0);

  data= new T [n];
  num_elements= n;
}
/* _________________________________________________________________________ */

template <class T>
Vector_Dinamico<T>::Vector_Dinamico(const Vector_Dinamico<T> &other){
  freeMemory();
  copy(other);
}
/* _________________________________________________________________________ */

template <class T>
Vector_Dinamico<T>::~Vector_Dinamico(){
  freeMemory();
}
/* _________________________________________________________________________ */

template <class T>
int Vector_Dinamico<T>::size() const{
  return num_elements;
}
/* _________________________________________________________________________ */

template <class T>
T& Vector_Dinamico<T>::operator[](int i){
  assert (0<=i && i<num_elements);
  return data[i];
}
/* _________________________________________________________________________ */

template <class T>
const T& Vector_Dinamico<T>::operator[](int i) const{
  assert (0<=i && i<num_elements);
  return data[i];
}
/* _________________________________________________________________________ */

template <class T>
void Vector_Dinamico<T>::resize(int n){
  assert (n>= 0);
  if(n!= num_elements){
    if(n!= 0){
      T* aux= new T [n];
      if(num_elements> 0){
        int minimo;
        minimo= num_elements< n? num_elements: n;
        for (int i= 0; i< minimo;i++)
          aux[i]= data[i];

        delete [] data;
      }
      num_elements= n;
      data= aux;
    }
    else{
      if(num_elements>0)
	     delete[] data;

      data= 0;
      num_elements= 0;
    }
  }
}
/* _________________________________________________________________________ */

template <class T>
Vector_Dinamico<T>& Vector_Dinamico<T>::operator=(const Vector_Dinamico<T> &other){
  if(this!= &other){
    freeMemory();
    copy(other);
  }
  return *this;
}
