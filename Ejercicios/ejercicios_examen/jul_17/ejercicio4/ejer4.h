#include <stack>
#include <iostream>

using namespace std;

#ifndef ejer4_h
#define ejer4_h

template <class T>
class queue{
private:
  stack<T> s1;  //Contiene los elementos del primero al último
  stack<T> s2;  //Contiene los elementos del último al primero
public:
  queue(){}

  queue(stack<T> &s);

  queue(const queue<T> & q);

  queue<T>& operator=(const queue<T> &q);

  bool empty() const;

  int size() const;

  T& front();

  T& back();

  void push(T element);

  void pop();

  void show_elements();
};
#include <ejer4.cpp>
#endif
