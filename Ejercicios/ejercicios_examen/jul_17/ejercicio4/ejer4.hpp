#include <stack>
#include <iostream>

using namespace std;

template <class T>
class queue{
private:
  stack<T> s1;  //Contiene los elementos del primero al último
  stack<T> s2;  //Contiene los elementos del último al primero
public:
  queue(){}

  queue(const queue<T> & q);

  queue<T>& operator=(const queue<T> &q);

  bool empty()const;

  int size()const;

  T& front();

  T& back();

  void push_back();

  void pop_front();
}
#include <ejer4.cpp>
